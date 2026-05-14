---
type: hardware
status: done
last_updated: 2026-05-09
---

# HW_I2S_BUS

Tags: #done #hardware #audio

I2S Port mapping and clocking configuration for the FOX M4 system. Driver: [[FW_BSP_I2S]].

---

## Bus Topology

The [[HW_ESP32P4]] acts as the I2S Master for all ports.

| Port | Dir | Device | Role |
|------|-----|--------|------|
| **I2S0** | RX | [[HW_ES8388]] | Microphone Input |
| **I2S1** | TX | [[HW_PCM5102A]] | Mixed Audio Output |
| **I2S2** | RX | [[HW_ESP32_WROOM_32E]] | Bluetooth Audio Input |

## Clock Configuration

- **MCLK Source**: ESP32-P4 Internal PLL.
- **MCLK Freq**: 24.576 MHz.
- **Sample Rate (Fs)**: 96,000 Hz.
- **MCLK/Fs Ratio**: 256.

## Pin Mapping (ESP32-P4 DevKit)

- **MCLK**: GPIO20
- **I2S0 (ADC)**: BCK:21, WS:22, DIN:23
- **I2S1 (DAC)**: BCK:32, WS:33, DOUT:36
- **I2S2 (BT)**: BCK:46, WS:47, DIN:53

---

## Inter-MCU Link
The link to [[HW_ESP32_WROOM_32E]] carries 24-bit/96kHz PCM data. See [[ARCH_INTER_MCU_COMM]].
