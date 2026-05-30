---
type: firmware
status: done
last_updated: 2026-05-15
---

# FW_APP_MAIN

Tags: #done #firmware

Initialization and coordination task for ESP32-P4. Hardware: [[HW_ESP32P4]].

---

## Startup Sequence
1. Init [[FW_BSP_I2C]] and [[FW_BSP_SPI]].
2. Init `ui_engine` ([[HW_ILI9225]] TFT display, 176×220).
3. Init [[FW_BSP_I2S]] — sets up I2S0/1/2, MCLK=24.576MHz on GPIO20.
4. Init [[FW_BSP_ES8388]] — mic ADC codec, I2S Slave. **(Phase-2 fix: was incorrectly ES8311)**
5. Init [[FW_BSP_PCM5102A]] — DAC, receives I2S1.
6. Init [[FW_AUDIO_MIXER]] and start [[FW_APP_AUDIO]] task.
7. Unmute PCM5102A after the pipeline is running.
8. Start UI update task and retain `ui_task_handle` for lifecycle control.

## Phase-5 Fixes
- **[P3-4]** `ui_task` handle is now stored and task creation is checked for failure.

Links: [[ARCH_DUAL_MCU]], [[FW_APP_POWER]].
