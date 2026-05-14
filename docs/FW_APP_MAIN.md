---
type: firmware
status: done
last_updated: 2026-05-09
---

# FW_APP_MAIN

Tags: #done #firmware

Initialization and coordination task for ESP32-P4. Hardware: [[HW_ESP32P4]].

---

## Startup Sequence
1. Init [[FW_BSP_I2C]] and [[FW_BSP_SPI]].
2. Init [[FW_BSP_IP5306]] to check battery status.
3. Init [[FW_BSP_ES8388]] and [[FW_BSP_PCM5102A]].
4. Start [[FW_APP_AUDIO]] and [[FW_UI_ENGINE]].

Links: [[ARCH_DUAL_MCU]], [[FW_APP_POWER]].
