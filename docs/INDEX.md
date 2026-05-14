---
type: hub
status: done
last_updated: 2026-05-09
---

# FOX M4 -- Knowledge Base

Tags: #done #system

> Target: ESP32-P4 + ESP32 | Board: Fox M4 | Toolchain: ESP-IDF v5.2+

## Getting Started
- [Hướng dẫn Khởi động và Nạp Code (Vietnamese)](../README.md)

## Hardware Layer
| Note | Covers |
|------|--------|
| [[HW_ESP32P4]] | Main MCU (DSP, UI, Power) |
| [[HW_ESP32_WROOM_32E]] | Bluetooth Companion MCU |
| [[HW_ES8388]] | Audio Codec (ADC/DAC Control) |
| [[HW_PCM5102A]] | Main Audio DAC |
| [[HW_IP5306]] | Power Management IC |
| [[HW_SSD1306]] | OLED Display (128x64) |
| [[HW_SDCARD]] | SD Card Storage (FAT32) |
| [[HW_I2S_BUS]] | I2S Routing & Port Mapping |
| [[HW_I2C_BUS]] | I2C Bus Configuration |
| [[HW_SPI_BUS]] | SPI Bus Configuration |

## Firmware Layer
| Note | Files |
|------|-------|
| [[FW_APP_MAIN]] | System Initialization |
| [[FW_APP_AUDIO]] | Real-time Audio Task |
| [[FW_APP_POWER]] | Power Management Task |
| [[FW_APP_BT_CTRL]] | Bluetooth Control Task |
| [[FW_AUDIO_MIXER]] | Audio Mixing Engine |
| [[FW_DSP_EFFECTS]] | Reverb & Parametric EQ |
| [[FW_SDCARD_MANAGER]] | SD Card File Operations |
| [[FW_UI_ENGINE]] | OLED & Encoder Interface |
| [[FW_BSP_I2S]] | I2S Peripheral Driver |
| [[FW_BSP_I2C]] | I2C Peripheral Driver |
| [[FW_BSP_SPI]] | SPI Peripheral Driver |
| [[FW_BSP_ES8388]] | Codec Hardware Driver |
| [[FW_BSP_PCM5102A]] | DAC Hardware Driver |
| [[FW_BSP_IP5306]] | PMIC Hardware Driver |
| [[FW_BT_A2DP_SINK]] | Bluetooth Audio Sink |

## Architecture
| Note | Decision |
|------|----------|
| [[ARCH_DUAL_MCU]] | ESP32-P4 + ESP32 Architecture |
| [[ARCH_AUDIO_PIPELINE]] | 24-bit / 96kHz Signal Flow |
| [[ARCH_INTER_MCU_COMM]] | I2S & UART Bridge Logic |
