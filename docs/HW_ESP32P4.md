---
type: hardware
status: done
last_updated: 2026-05-09
---

# HW_ESP32P4

Tags: #done #hardware #mcu

Main Application Processor for FOX M4. Handles DSP, UI, and system coordination. Driver: [[FW_APP_MAIN]].

---

## Peripheral Overview

- **Core**: High-performance dual-core RISC-V.
- **Audio**: Supports multiple I2S ports for Hi-Res audio.
- **MCLK Output**: GPIO20 configured at **24.576 MHz** (256 × 96kHz).

## Register Map / Constraints

| Interface | Port | Purpose |
|-----------|------|---------|
| I2S0      | RX   | Input from [[HW_ES8388]] |
| I2S1      | TX   | Output to [[HW_PCM5102A]] |
| I2S2      | RX   | Input from [[HW_ESP32_WROOM_32E]] |
| I2C0      | Master | Control for ES8388, IP5306 |
| SPI       | Master | SD Card, SSD1306 |

## Critical Constraints

### Audio Clocking
Must provide stable 24.576 MHz MCLK to all audio components for 96kHz sampling. See [[HW_I2S_BUS]].

## References
ESP32-P4 Technical Reference Manual.
