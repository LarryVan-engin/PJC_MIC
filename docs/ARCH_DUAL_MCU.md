---
type: architecture
status: done
last_updated: 2026-05-09
---

# ARCH_DUAL_MCU

Tags: #done #architecture

System design using two MCUs to separate compute-intensive DSP from Bluetooth stack overhead.

---

## Components

- **Main MCU ([[HW_ESP32P4]])**:
    - High-performance audio processing.
    - Low-latency I2S switching.
    - UI and Power management.
- **Companion MCU ([[HW_ESP32_WROOM_32E]])**:
    - Dedicated Bluetooth stack handling.
    - UART Control interface.

## Rationale
ESP32-P4 lacks integrated Bluetooth but excels in DSP and high-speed peripherals. Using a dedicated ESP32 for BT ensures the main audio pipeline is never interrupted by radio stack jitter.

Links: [[ARCH_INTER_MCU_COMM]], [[FW_APP_MAIN]].
