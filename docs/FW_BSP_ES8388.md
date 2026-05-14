---
type: firmware
status: done
last_updated: 2026-05-09
---

# FW_BSP_ES8388

Tags: #done #firmware #bsp

Driver for ES8388 Audio Codec. 
Files: `BSP/bsp_es8388/src/bsp_es8388.c`, `BSP/bsp_es8388/include/bsp_es8388_reg.h`.
Hardware: [[HW_ES8388]], [[HW_I2C_BUS]].

---

## Functions
- `bsp_es8388_init()`: Configures I2C control and internal ADC routing.
- `bsp_es8388_set_mic_gain()`: Adjusts analog gain for microphone input.

Links: [[FW_APP_AUDIO]], [[FW_BSP_I2C]].
