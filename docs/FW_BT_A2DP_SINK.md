---
type: firmware
status: done
last_updated: 2026-05-10
---

# FW_BT_A2DP_SINK

Tags: #done #firmware #bluetooth

Bluetooth A2DP Sink implementation for ESP32-WROOM-32E.
Files: `C_code/micro-fox-m4-esp32-bluetooth/`.
Hardware: [[HW_ESP32_WROOM_32E]], [[HW_I2S_BUS]].

## Logic Flow

- Receives SBC/AAC streams from paired device.
- Decodes to PCM.
- Upsamples/Resamples to **24-bit / 96kHz** (if necessary) to match system clock.
- Outputs via I2S to [[FW_APP_AUDIO]] on the Main MCU.

## Inter-MCU Control
Uses [[FW_BSP_UART]] for status reporting (connected, play, pause) to the Main MCU.
Link: [[ARCH_INTER_MCU_COMM]].
