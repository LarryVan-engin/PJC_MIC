---
type: architecture
status: done
last_updated: 2026-05-09
---

# ARCH_INTER_MCU_COMM

Tags: #done #architecture #comm

Mechanism for audio and command transfer between ESP32 and ESP32-P4.

---

## Data Transfer (I2S)

- **Direction**: [[HW_ESP32_WROOM_32E]] -> [[HW_ESP32P4]] (I2S2).
- **Format**: I2S Philips, 24-bit, 96kHz.
- **Clocking**: ESP32-P4 is Master; ESP32 is Slave. BCLK/WS are provided by P4.

## Control Transfer (UART)

- **Baudrate**: 115200.
- **Commands**:
    - BT Pair/Unpair.
    - Status (Battery, Signal Strength).
    - Playback control.

## Synchronization
Since the ESP32 is a slave on the I2S bus, it must resample its internal Bluetooth 44.1/48kHz stream to exactly 96kHz to match the Master clock provided by the P4. This avoids clock drift artifacts.

Links: [[FW_BSP_I2S]], [[FW_BT_A2DP_SINK]], [[HW_I2S_BUS]].
