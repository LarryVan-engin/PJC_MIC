---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_ES8388_Master_Codec_Mismatch

Tags: #done #bug #critical

ES8388 configured as I2S Master while ESP32-P4 I2S0 is also Master on the same bus.
Active codec in firmware was ES8311 (wrong) instead of ES8388 (hardware design).
Module: [[FW_BSP_ES8388]], [[FW_APP_MAIN]]. Hardware: [[HW_ES8388]], [[HW_I2S_BUS]].

---

## Symptoms

### P0-3 — Dual Master Bus Contention
- BCLK and LRCK on I2S0 bus driven by both ESP32-P4 (as I2S Master) and ES8388 (as I2S Master).
- Bus contention → undefined signal levels → I2S communication fails, no audio from mic.
- Possible hardware damage due to output-to-output short.

### P2-3 — Wrong Codec Initialized
- `bsp_es8311_init()` called for mic ADC input but ES8388 is the hardware codec (per schematics and [[HW_ES8388]]).
- ES8311 I2C address = 0x18; ES8388 I2C address = 0x10. If ES8311 driver is called but ES8388 is on the board, all I2C register writes are sent to a non-existent device → ACK failures or silent corruption.
- CMakeLists compiled `BSP/bsp_es8311/` but not `BSP/bsp_es8388/`.

## Root Cause

### P0-3
`bsp_es8388.c` register write at init:
```c
ESP_ERROR_CHECK(es8388_write_reg(ES8388_MASTERMODE, 0x80)); // Master mode
```
`ES8388_MASTERMODE (REG08)` bit 7 = 1 sets ES8388 as I2S Master (generates BCLK and LRCK).
But `bsp_i2s.c` I2S0 is `I2S_ROLE_MASTER` — ESP32-P4 also generates BCLK and LRCK on the same GPIOs (BSP_I2S0_BCK_IO=21, BSP_I2S0_WS_IO=22).

Two masters on the same I2S clock lines = bus contention.

### P2-3
Developer created both `bsp_es8311/` and `bsp_es8388/` drivers. CMakeLists included ES8311 instead of ES8388. `app_main_logic.c` called `bsp_es8311_init()`. Design authority documents ([[HW_ES8388]], [[HW_I2S_BUS]], [[FW_APP_MAIN]]) all specify ES8388.

## Code (Wrong)
```c
/* bsp_es8388.c */
ESP_ERROR_CHECK(es8388_write_reg(ES8388_MASTERMODE, 0x80)); // Master — WRONG

/* CMakeLists.txt */
file(GLOB BSP_ES8311_SRCS "../BSP/bsp_es8311/src/*.c")
${BSP_ES8311_SRCS}

/* app_main_logic.c */
#include "bsp_es8311.h"
ESP_ERROR_CHECK(bsp_es8311_init());  // Wrong codec
```

## Code (Fixed)
```c
/* bsp_es8388.c */
ESP_ERROR_CHECK(es8388_write_reg(ES8388_MASTERMODE, 0x00)); // Slave mode ✓

/* CMakeLists.txt */
file(GLOB BSP_ES8388_SRCS "../BSP/bsp_es8388/src/*.c")
${BSP_ES8388_SRCS}

/* app_main_logic.c */
#include "bsp_es8388.h"
ESP_ERROR_CHECK(bsp_es8388_init());  // Correct codec ✓
```

## Verification
- ES8388 I2C writes must ACK (address 0x10 must respond).
- After init, `MASTERMODE` register should read back 0x00.
- I2S0 BCLK and LRCK should be driven only by ESP32-P4 (verify with logic analyzer: single driver, no contention).

## Lessons Learned
- Hardware note [[HW_ES8388]] had `MASTERMODE=0x80` documented as the register value — this was incorrect. The register table in HW_ notes must reflect the *intended correct* value, not the current (buggy) code state. **HW_ notes are the contract, not a copy of buggy code.**
- Always check: if MCU I2S port is `I2S_ROLE_MASTER`, the attached codec/peripheral **must** be configured as slave.
