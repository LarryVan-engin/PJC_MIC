---
type: firmware
status: done
last_updated: 2026-05-10
---

# FW_AUDIO_MIXER

Tags: #done #firmware #audio

Middleware component for summing multiple 24-bit audio streams. 
Files: `Middleware/audio_mixer/src/audio_mixer.c`, `Middleware/audio_mixer/include/audio_mixer.h`.

---

## Logic
Summation is performed in 32-bit or floating-point space to prevent clipping before final 24-bit truncation.

## Inputs
1. Mic: [[FW_BSP_ES8388]]
2. Bluetooth: [[FW_BT_A2DP_SINK]]
3. SD Playback: [[FW_SDCARD_MANAGER]]

Output is sent to [[FW_DSP_EFFECTS]].
