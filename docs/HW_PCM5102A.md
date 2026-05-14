---
type: hardware
status: done
last_updated: 2026-05-09
---

# HW_PCM5102A

Tags: #done #hardware #dac

Main system DAC for high-quality audio output. Driver: [[FW_BSP_PCM5102A]].

---

## Overview
- **Interface**: I2S1 on [[HW_ESP32P4]].
- **Format**: 24-bit / 96kHz.
- **Clocking**: Slave mode, receives MCLK from P4.

## Connections
- **Data**: I2S1 on [[HW_ESP32P4]].
- **Control**: Hardware strapping, plus **XSMT (Mute)** on GPIO27.
- **Role**: Output stage for mixed audio stream from [[ARCH_AUDIO_PIPELINE]].
