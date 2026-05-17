#include <Arduino.h>
#include <Wire.h>

extern "C" {
#include "driver/i2s.h"
#include "soc/soc_caps.h"
}

// Waveshare ESP32-P4-WIFI6-DEV-KIT pins (from your current firmware)
static constexpr int PIN_I2C_SDA = 7;
static constexpr int PIN_I2C_SCL = 8;
static constexpr int PIN_PA_CTRL = 53;

static constexpr int PIN_I2S_MCLK = 13;
static constexpr int PIN_I2S_BCK  = 12;
static constexpr int PIN_I2S_WS   = 10;
static constexpr int PIN_I2S_DOUT = 9;

static constexpr uint8_t ES8311_ADDR = 0x18;
static constexpr int SAMPLE_RATE = 44100;
static constexpr int TONE_FREQ_HZ = 1000;
static constexpr int TONE_AMPLITUDE = 12000;
/* Optional: if you physically wire J1 EarPhone_Detect net to an ESP32-P4 GPIO,
 * set that GPIO number here. Keep -1 when not wired (default on this board). */
static constexpr int JACK_DETECT_GPIO = -1;

static constexpr i2s_port_t I2S_PORT = I2S_NUM_0;

static int countTransitions(int pin, int samples, int delay_us) {
  int prev = digitalRead(pin);
  int transitions = 0;
  for (int i = 0; i < samples; ++i) {
    delayMicroseconds(delay_us);
    int cur = digitalRead(pin);
    if (cur != prev) {
      transitions++;
      prev = cur;
    }
  }
  return transitions;
}

static bool es8311WriteReg(uint8_t reg, uint8_t val) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  Wire.write(val);
  return (Wire.endTransmission() == 0);
}

static bool es8311ReadReg(uint8_t reg, uint8_t &val) {
  Wire.beginTransmission(ES8311_ADDR);
  Wire.write(reg);
  if (Wire.endTransmission(false) != 0) {
    return false;
  }
  if (Wire.requestFrom((int)ES8311_ADDR, 1) != 1) {
    return false;
  }
  val = Wire.read();
  return true;
}

static bool initEs8311Phase1() {
  // Reset + power-on command (same idea as Espressif reference)
  if (!es8311WriteReg(0x00, 0x1F)) return false;
  delay(20);
  if (!es8311WriteReg(0x00, 0x00)) return false;
  if (!es8311WriteReg(0x00, 0x80)) return false;
  delay(5);

  // Clock manager
  if (!es8311WriteReg(0x01, 0x30)) return false;
  if (!es8311WriteReg(0x02, 0x00)) return false;
  if (!es8311WriteReg(0x03, 0x10)) return false;
  if (!es8311WriteReg(0x04, 0x10)) return false;
  if (!es8311WriteReg(0x05, 0x00)) return false;
  if (!es8311WriteReg(0x06, 0x03)) return false;
  if (!es8311WriteReg(0x07, 0x00)) return false;
  if (!es8311WriteReg(0x08, 0xFF)) return false;

  // 16-bit I2S format
  if (!es8311WriteReg(0x09, 0x0C)) return false;
  if (!es8311WriteReg(0x0A, 0x0C)) return false;

  // Analog + DAC path
  if (!es8311WriteReg(0x0B, 0x00)) return false;
  if (!es8311WriteReg(0x0C, 0x00)) return false;
  if (!es8311WriteReg(0x0D, 0x01)) return false;
  if (!es8311WriteReg(0x0E, 0x02)) return false;
  if (!es8311WriteReg(0x0F, 0x9E)) return false;
  if (!es8311WriteReg(0x10, 0x07)) return false;
  if (!es8311WriteReg(0x11, 0x7F)) return false;
  if (!es8311WriteReg(0x12, 0x00)) return false;
  if (!es8311WriteReg(0x13, 0x10)) return false;

  if (!es8311WriteReg(0x31, 0x60)) return false;
  if (!es8311WriteReg(0x32, 0xFF)) return false;
  if (!es8311WriteReg(0x37, 0x08)) return false;

  // ADC regs written in reference for known state
  if (!es8311WriteReg(0x14, 0x1A)) return false;
  if (!es8311WriteReg(0x15, 0x00)) return false;
  if (!es8311WriteReg(0x16, 0x24)) return false;
  if (!es8311WriteReg(0x17, 0xB8)) return false;

  return true;
}

static bool initI2S() {
  i2s_config_t cfg = {};
  cfg.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX);
  cfg.sample_rate = SAMPLE_RATE;
  cfg.bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT;
  cfg.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT;
  cfg.communication_format = I2S_COMM_FORMAT_STAND_I2S;
  cfg.intr_alloc_flags = 0;
  cfg.dma_buf_count = 8;
  cfg.dma_buf_len = 256;
  cfg.use_apll = true;
  cfg.tx_desc_auto_clear = true;
  cfg.fixed_mclk = SAMPLE_RATE * 256;

  if (i2s_driver_install(I2S_PORT, &cfg, 0, nullptr) != ESP_OK) {
    return false;
  }

  i2s_pin_config_t pin_cfg = {};
#if SOC_I2S_SUPPORTS_MCLK
  pin_cfg.mck_io_num = PIN_I2S_MCLK;
#endif
  pin_cfg.bck_io_num = PIN_I2S_BCK;
  pin_cfg.ws_io_num = PIN_I2S_WS;
  pin_cfg.data_out_num = PIN_I2S_DOUT;
  pin_cfg.data_in_num = I2S_PIN_NO_CHANGE;

  if (i2s_set_pin(I2S_PORT, &pin_cfg) != ESP_OK) {
    return false;
  }

  // Re-apply runtime clock tuple so BCK/LRCK (and MCLK when supported) are active deterministically.
  if (i2s_set_clk(I2S_PORT, SAMPLE_RATE, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_STEREO) != ESP_OK) {
    return false;
  }

  return (i2s_zero_dma_buffer(I2S_PORT) == ESP_OK);
}

static bool es8311EnableCSMAndVerify() {
  if (!es8311WriteReg(0x00, 0x80)) return false;
  delay(50);

  // Re-assert key regs after CSM start
  if (!es8311WriteReg(0x09, 0x0C)) return false;
  if (!es8311WriteReg(0x0A, 0x0C)) return false;
  if (!es8311WriteReg(0x31, 0x60)) return false;
  if (!es8311WriteReg(0x32, 0xFF)) return false;
  if (!es8311WriteReg(0x37, 0x08)) return false;
  if (!es8311WriteReg(0x0E, 0x02)) return false;
  if (!es8311WriteReg(0x11, 0x7F)) return false;

  uint8_t r00 = 0, r01 = 0, r09 = 0, r0d = 0, r0e = 0, r11 = 0, r31 = 0, r32 = 0, r37 = 0;
  bool ok = es8311ReadReg(0x00, r00) && es8311ReadReg(0x09, r09) &&
            es8311ReadReg(0x01, r01) && es8311ReadReg(0x0D, r0d) &&
            es8311ReadReg(0x0E, r0e) && es8311ReadReg(0x11, r11) &&
            es8311ReadReg(0x31, r31) && es8311ReadReg(0x32, r32) &&
            es8311ReadReg(0x37, r37);

  if (!ok) return false;

  Serial.printf("ES8311: R00=0x%02X R01=0x%02X R09=0x%02X R0D=0x%02X R0E=0x%02X R11=0x%02X R31=0x%02X R32=0x%02X R37=0x%02X\n",
                r00, r01, r09, r0d, r0e, r11, r31, r32, r37);

  return (r00 == 0x80 && r09 == 0x0C && r0e == 0x02 && r11 == 0x7F && r31 == 0x60 && r37 == 0x08);
}

void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println();
  Serial.println("=== ESP32-P4 ES8311 JACK TEST (Arduino) ===");
  Serial.println("NOTE: J1 appears to be codec OUTP/OUTN path (differential), not guaranteed L/R/GND line-out.");
  Serial.println("If active speaker is single-ended TRS, test with wired headphone first.");

  pinMode(PIN_PA_CTRL, OUTPUT);
  digitalWrite(PIN_PA_CTRL, HIGH);
  Serial.printf("PA_CTRL GPIO%d = HIGH\n", PIN_PA_CTRL);
  if (JACK_DETECT_GPIO >= 0) {
    pinMode(JACK_DETECT_GPIO, INPUT_PULLUP);
    Serial.printf("Jack detect GPIO%d enabled (HIGH=plugged, LOW=unplugged per schematic note)\n", JACK_DETECT_GPIO);
  } else {
    Serial.println("Jack detect is hardware-only in current design (EarPhone_Detect not routed to MCU GPIO)");
  }

  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL, 400000);
  Serial.printf("I2C init SDA=%d SCL=%d\n", PIN_I2C_SDA, PIN_I2C_SCL);

  if (!initEs8311Phase1()) {
    Serial.println("FAIL: ES8311 phase1 init failed (I2C write)");
    while (true) delay(1000);
  }

  if (!initI2S()) {
    Serial.println("FAIL: I2S init failed");
    while (true) delay(1000);
  }

  if (!es8311EnableCSMAndVerify()) {
    Serial.println("WARN: ES8311 verify mismatch, but continue tone test");
  }

  // Quick pin activity probe to confirm MCU is really driving I2S clocks/data.
  int mclk_t = countTransitions(PIN_I2S_MCLK, 200, 2);
  int bck_t = countTransitions(PIN_I2S_BCK, 200, 4);
  int ws_t = countTransitions(PIN_I2S_WS, 200, 10);
  Serial.printf("I2S pin transitions: MCLK=%d BCK=%d WS=%d (non-zero expected)\n", mclk_t, bck_t, ws_t);

  Serial.println("START: fixed 1kHz sine -> I2S0 -> ES8311 -> J1");
  Serial.println("Plug wired headphones into J1");
}

void loop() {
  static int16_t buf[512]; // 256 stereo frames
  static float phase = 0.0f;
  static uint32_t mode_start_ms = 0;
  static uint8_t mode = 0; // 0: L+R, 1: Left only, 2: Right only
  const float phase_inc = 2.0f * PI * ((float)TONE_FREQ_HZ / (float)SAMPLE_RATE);

  uint32_t now = millis();
  if (mode_start_ms == 0) {
    mode_start_ms = now;
    Serial.println("Tone mode: L+R (both channels)");
  } else if ((now - mode_start_ms) >= 3000) {
    mode = (uint8_t)((mode + 1) % 3);
    mode_start_ms = now;
    if (mode == 0) {
      Serial.println("Tone mode: L+R (both channels)");
    } else if (mode == 1) {
      Serial.println("Tone mode: Left only");
    } else {
      Serial.println("Tone mode: Right only");
    }
  }

  for (int i = 0; i < 256; i++) {
    int16_t s = (int16_t)(TONE_AMPLITUDE * sinf(phase));
    if (mode == 0) {
      buf[2 * i] = s;
      buf[2 * i + 1] = s;
    } else if (mode == 1) {
      buf[2 * i] = s;
      buf[2 * i + 1] = 0;
    } else {
      buf[2 * i] = 0;
      buf[2 * i + 1] = s;
    }
    phase += phase_inc;
    if (phase > 2.0f * PI) {
      phase -= 2.0f * PI;
    }
  }

  size_t written = 0;
  esp_err_t ret = i2s_write(I2S_PORT, buf, sizeof(buf), &written, portMAX_DELAY);
  static uint32_t ok_count = 0;
  if (ret == ESP_OK && written == sizeof(buf)) {
    ok_count++;
    if ((ok_count % 500) == 0 && JACK_DETECT_GPIO >= 0) {
      int jd = digitalRead(JACK_DETECT_GPIO);
      Serial.printf("jack detect GPIO%d = %d\n", JACK_DETECT_GPIO, jd);
    }
    if ((ok_count % 200) == 0) {
      Serial.printf("tone write OK x %lu (freq=%d Hz, mode=%u)\n", (unsigned long)ok_count, TONE_FREQ_HZ, (unsigned)mode);
    }
  } else {
    Serial.printf("tone write FAIL ret=%d written=%u/%u\n",
                  (int)ret, (unsigned)written, (unsigned)sizeof(buf));
    delay(100);
  }
}
