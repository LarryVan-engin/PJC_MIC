---
type: firmware
status: done
last_updated: 2026-05-15
---

# FW_BSP_ES8388

Tags: #done #firmware #bsp

Driver for ES8388 Stereo Audio Codec — **active mic ADC codec** for FOX M4.
Files: `BSP/bsp_es8388/src/bsp_es8388.c`, `BSP/bsp_es8388/include/bsp_es8388_reg.h`.
Hardware: [[HW_ES8388]], [[HW_I2C_BUS]].
Bugs fixed: [[RCA_ES8388_Master_Codec_Mismatch]].

---

## Functions
- `bsp_es8388_init()`: Configures ES8388 as I2S Slave, 24-bit, 96kHz. Sets ADC input routing.
- `bsp_es8388_set_mic_gain()`: Adjusts PGA gain (0–30 dB, step=3 dB).
- `bsp_es8388_set_adc_volume()`: Digital ADC volume (both L+R channels).
- `bsp_es8388_set_dac_volume()`: Digital DAC volume (both L+R channels).

## Phase-2 Fix
- **[P0-3]** `MASTERMODE` changed from `0x80` (I2S Master) to `0x00` (I2S Slave). ESP32-P4 I2S0 is the bus master.

## Init Sequence Key Registers
| Register | Value | Reason |
|----------|-------|--------|
| `MASTERMODE` | `0x00` | Slave mode — ESP32-P4 drives BCLK+LRCK |
| `ADCCONTROL5` | `0x00` | ADC_FS = MCLK/256 = 24.576M/256 = **96kHz** |
| `ADCCONTROL4` | `0x08` | I2S Standard, 24-bit |

Links: [[FW_APP_AUDIO]], [[FW_BSP_I2C]], [[FW_APP_MAIN]].
