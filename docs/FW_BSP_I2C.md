---
type: firmware
status: done
last_updated: 2026-05-15
---

# FW_BSP_I2C

Tags: #done #firmware #bsp

Low-level I2C master driver for ESP32-P4.
Files: `BSP/bsp_i2c/src/bsp_i2c.c`, `BSP/bsp_config.h`.
Hardware: [[HW_I2C_BUS]].
Bugs fixed: [[RCA_I2C_BSP_MissingIncludes]].

---

## Functions
- `bsp_i2c_init()`: Initializes I2C master bus. SDA=GPIO7, SCL=GPIO8, 400kHz.
- `bsp_i2c_write()`: Generic register write (dev_addr, reg_addr, data, len).
- `bsp_i2c_read()`: Generic register read.

## Phase-1 Fix Applied
- Added `#include <stdlib.h>` and `#include <string.h>` (was missing, could cause implicit-declaration warnings).

## ⚠️ Known Issues (Phase 3)
- **[P1-4]** `bsp_i2c_write/read` create and destroy `i2c_master_dev_handle_t` **on every call**. This is incorrect — the handle should be created once per device at init and cached. Current design also lacks NULL check after `malloc()` → crash on OOM.

Links: [[FW_APP_MAIN]], [[HW_I2C_BUS]], [[FW_BSP_ES8388]].
