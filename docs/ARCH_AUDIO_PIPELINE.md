---
type: architecture
status: done
last_updated: 2026-05-09
---

# ARCH_AUDIO_PIPELINE

Tags: #done #architecture #audio

The 24-bit / 96kHz Hi-Res audio signal flow in FOX M4.

---

## Signal Map

1. **Input Stage**:
    - [[HW_ES8388]] (ADC) -> I2S0 -> [[FW_APP_AUDIO]]
    - [[HW_ESP32_WROOM_32E]] (BT) -> I2S2 -> [[FW_APP_AUDIO]]
    - [[HW_SDCARD]] -> SPI -> [[FW_SDCARD_MANAGER]] -> [[FW_APP_AUDIO]]

2. **Processing Stage**:
    - [[FW_AUDIO_MIXER]]: Sums inputs.
    - [[FW_DSP_EFFECTS]]: Applies Parametric EQ and Reverb.

3. **Output Stage**:
    - [[FW_APP_AUDIO]] -> I2S1 -> [[HW_PCM5102A]] (DAC)

## Clocking Strategy
Synchronous clocking across all nodes using the 24.576 MHz MCLK from [[HW_ESP32P4]]. This prevents buffer underflows and ensures phase coherence.

Related: [[HW_I2S_BUS]], [[ARCH_INTER_MCU_COMM]].
