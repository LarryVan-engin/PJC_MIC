---
type: firmware
status: done
last_updated: 2026-05-09
---

# FW_BSP_I2C

Tags: #done #firmware #bsp

Low-level I2C master driver for ESP32-P4.
Files: `BSP/bsp_i2c/src/bsp_i2c.c`, `BSP/bsp_config.h`.
Hardware: [[HW_I2C_BUS]].

---

## Functions
- `bsp_i2c_init()`: Initializes the I2C master bus on pins defined in [[bsp_config.h]].
- `bsp_i2c_write()`: Generic register write.
- `bsp_i2c_read()`: Generic register read.

Links: [[FW_APP_MAIN]], [[HW_I2C_BUS]].
