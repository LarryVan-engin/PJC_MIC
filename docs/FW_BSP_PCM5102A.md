---
type: firmware
status: done
last_updated: 2026-05-09
---

# FW_BSP_PCM5102A

Tags: #done #firmware #bsp

Driver for PCM5102A DAC. 
Files: `BSP/bsp_pcm5102a/src/bsp_pcm5102a.c`, `BSP/bsp_config.h`.
Hardware: [[HW_PCM5102A]].

---

## Functions
- `bsp_pcm5102a_init()`: Configures I2S1 on [[HW_ESP32P4]] for high-resolution output.

Links: [[FW_APP_AUDIO]], [[ARCH_AUDIO_PIPELINE]].
