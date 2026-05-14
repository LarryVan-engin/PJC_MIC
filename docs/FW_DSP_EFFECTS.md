---
type: firmware
status: done
last_updated: 2026-05-09
---

# FW_DSP_EFFECTS

Tags: #done #firmware #audio

Audio processing module for Reverb and EQ on ESP32-P4.

---

## Processing
Receives mixed audio from [[FW_AUDIO_MIXER]] and applies:
- 10-band Parametric EQ.
- Plate/Room Reverb.

Output is sent back to [[FW_APP_AUDIO]] for I2S transmission to [[HW_PCM5102A]].
