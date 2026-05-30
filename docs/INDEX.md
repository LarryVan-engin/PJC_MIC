---
type: hub
status: done
last_updated: 2026-05-28
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
| [[HW_ILI9225]] | TFT Color Display (176×220) |
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
| [[FW_UI_ENGINE]] | ILI9225 TFT & Rotary Encoder Interface |
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

## Root Cause Analysis
| Note | Bug | Phase Fixed |
|------|-----|-------------|
| [[RCA_BtCtrl_Stub_Linker]] | `app_bt_ctrl.c` + `bt_a2dp_sink.c` stub → linker error | Phase 1 |
| [[RCA_PowerUart_Stub_Linker]] | `app_power.c` + `bsp_uart.c` stub → linker error | Phase 1 |
| [[RCA_I2C_BSP_MissingIncludes]] | Missing `<stdlib.h>/<string.h>` in `bsp_i2c.c`; missing `log` in CMakeLists | Phase 1 |
| [[RCA_I2S_MCLK_GPIO_Conflict]] | MCLK GPIO20 driven by 3 ports; MCLK ratio 192× wrong (should be 256×) | Phase 2 |
| [[RCA_ES8388_Master_Codec_Mismatch]] | ES8388 set as I2S Master (dual master bus contention); wrong codec ES8311 in build | Phase 2 |
| [[RCA_BT_Callback_I2S_Deadlock]] | A2DP callback blocked on I2S write in BT task context | Phase 3 |
| [[RCA_AudioPipeline_OOM_And_I2C_Thrash]] | Audio task malloc OOM risk; per-transaction I2C device handle churn | Phase 3 |
| [[RCA_Task_Lifecycle_And_BT_Controller_Mode]] | Audio stop path blocked on infinite I/O; I2S RX handle leak; UI task untracked; BT controller mode mismatch | Phase 5 |
