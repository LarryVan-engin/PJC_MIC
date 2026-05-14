---
type: hardware
status: done
last_updated: 2026-05-09
---

# HW_ESP32_WROOM_32E

Tags: #done #hardware #bluetooth

Bluetooth Companion MCU. Handles A2DP Sink and forwards audio to Main MCU. Driver: [[FW_APP_BT_CTRL]].

---

## Overview

- **Chip**: ESP32-WROOM-32E.
- **Interfaces**:
    - **I2S Out**: To [[HW_ESP32P4]] (I2S2).
    - **UART**: Control channel to Main MCU.
- **Role**: Bluetooth audio gateway.

## Clocking
Receives BCLK/WS from [[HW_ESP32P4]] (Slave mode).
Links: [[FW_BT_A2DP_SINK]], [[ARCH_INTER_MCU_COMM]].
