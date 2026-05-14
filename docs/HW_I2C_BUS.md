---
type: hardware
status: done
last_updated: 2026-05-09
---

# HW_I2C_BUS

Tags: #done #hardware #bus

I2C0 Bus configuration on [[HW_ESP32P4]]. Driver: [[FW_BSP_I2C]].

---

## Devices
| Device | Address | Note |
|--------|---------|------|
| [[HW_ES8388]] | 0x10 | Audio Codec |
| [[HW_IP5306]] | 0x75 | Power Management |

## Configuration
- **SDA**: GPIO7
- **SCL**: GPIO8
- **Speed**: 400kHz (Fast Mode).
- **Pull-ups**: Internal enabled (plus external on DevKit).
