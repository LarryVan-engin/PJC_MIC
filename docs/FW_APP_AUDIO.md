---
type: firmware
status: done
last_updated: 2026-05-10
---

# FW_APP_AUDIO

Tags: #done #firmware #app

Real-time audio routing task (ADC -> Mixer -> DAC). 
Files: `Application/app_audio/src/app_audio.c`, `Application/app_audio/include/app_audio.h`.
Links: [[FW_BSP_I2S]], [[FW_AUDIO_MIXER]].
Hardware: [[HW_ESP32P4]], [[HW_I2S_BUS]].

---

## Task Logic

- **Priority**: High (`configMAX_PRIORITIES - 1`).
- **Stack Size**: 8192 bytes.
- **Function**:
    1. Read Mic from [[FW_BSP_ES8388]] (I2S0).
    2. Read BT from [[FW_BT_A2DP_SINK]] (via I2S2).
    3. Read SD if active via [[FW_SDCARD_MANAGER]].
    4. Mix all streams via [[FW_AUDIO_MIXER]].
    5. Apply effects via [[FW_DSP_EFFECTS]].
    6. Write result to [[FW_BSP_PCM5102A]] (I2S1).

## Implementation Details

Uses DMA-driven I2S transfers to ensure zero dropouts at 96kHz.
Link to signal flow: [[ARCH_AUDIO_PIPELINE]].
