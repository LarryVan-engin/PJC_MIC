---
type: firmware
status: done
last_updated: 2026-05-15
---

# FW_BSP_I2S

Tags: #done #firmware #bsp

Low-level I2S driver for ESP32-P4 and ESP32. Hardware: [[HW_I2S_BUS]].
Files: `BSP/bsp_i2s/src/bsp_i2s.c`, `BSP/bsp_config.h`.
Bugs fixed: [[RCA_I2S_MCLK_GPIO_Conflict]], [[RCA_Task_Lifecycle_And_BT_Controller_Mode]].

---

## Configuration (ESP32-P4)

| Port | Role | Device | Rate | Bits | MCLK |
|------|------|--------|------|------|------|
| I2S0 | Master RX | [[HW_ES8388]] (ADC) | 96kHz | 24-bit | I2S_GPIO_UNUSED |
| I2S1 | Master TX | [[HW_PCM5102A]] (DAC) | 96kHz | 24-bit | GPIO20 (24.576 MHz) |
| I2S2 | Master RX | [[HW_ESP32_WROOM_32E]] (BT) | 44.1kHz | 16-bit | I2S_GPIO_UNUSED |

## Phase-2 Fixes
- **[P0-4]** `rx0_std_cfg.gpio_cfg.mclk = I2S_GPIO_UNUSED` and `rx2_std_cfg.gpio_cfg.mclk = I2S_GPIO_UNUSED` added. GPIO20 is now driven exclusively by I2S1.
- **[P2-6]** `I2S_MCLK_MULTIPLE_192` → `I2S_MCLK_MULTIPLE_256`. MCLK = 256 × 96000 = **24.576 MHz**, matching [[HW_I2S_BUS]] spec and ES8388 `ADCCONTROL5=0x00` (MCLK/256 = 96kHz).

## Phase-5 Fixes
- **[P1-2]** `bsp_i2s_deinit()` now disables and deletes all three channel handles: `tx_handle`, `rx0_handle`, and `rx2_handle`.

Links: [[FW_APP_AUDIO]], [[HW_ESP32P4]], [[HW_I2S_BUS]].
