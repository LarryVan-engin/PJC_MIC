---
type: firmware
status: done
last_updated: 2026-05-09
---

# FW_BSP_I2S

Tags: #done #firmware #bsp

Low-level I2S driver for ESP32-P4 and ESP32. Hardware: [[HW_I2S_BUS]].
Files: `BSP/bsp_i2s/src/bsp_i2s.c`, `BSP/bsp_config.h`.

---

## Configuration

- **Port 0**: Standard I2S, 24-bit, 96kHz.
- **Port 1**: Standard I2S, 24-bit, 96kHz.
- **Port 2**: Standard I2S, 24-bit, 96kHz (Slave mode on ESP32).

## Implementation Detail
Uses ESP-IDF `i2s_std` driver. MCLK is routed to GPIO20 on P4 via the `i2s_mclk_gpio_select` logic.

Links: [[FW_APP_AUDIO]], [[HW_ESP32P4]].
