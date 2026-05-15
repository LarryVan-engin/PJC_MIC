---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_I2S_MCLK_GPIO_Conflict

Tags: #done #bug #critical

Three I2S ports simultaneously configured MCLK on GPIO20, causing GPIO contention.
MCLK multiple also deviated from design spec (192× instead of 256×).
Module: [[FW_BSP_I2S]]. Hardware: [[HW_I2S_BUS]], [[HW_ESP32P4]].

---

## Symptoms
- `i2s_channel_init_std_mode()` on I2S0 or I2S2 returns error or hangs at boot.
- MCLK signal on GPIO20 corrupted or missing — audio codecs fail to lock PLL.
- ES8388 and PCM5102A may not initialize correctly (wrong MCLK frequency).

## Root Cause

### GPIO Conflict [P0-4]
`bsp_i2s_init()` initializes `rx0_std_cfg` and `rx2_std_cfg` as direct copies of `std_cfg` (I2S1 TX config) using `= std_cfg`. The TX config has `mclk = BSP_I2S_MCLK_IO (GPIO20)`. Neither RX config overrode `mclk` before calling `i2s_channel_init_std_mode()`.

Result: all three I2S controllers attempted to configure GPIO20 as an MCLK output simultaneously.
Only I2S1 (TX/DAC) should drive GPIO20. I2S0 and I2S2 are receive-only and do not need to generate MCLK.

### Wrong MCLK Ratio [P2-6]
`std_cfg.clk_cfg.mclk_multiple = I2S_MCLK_MULTIPLE_192` generates:
```
MCLK = 192 × 96000 = 18.432 MHz
```
Design specification (per [[HW_I2S_BUS]] and [[HW_ESP32P4]]) requires **256×**:
```
MCLK = 256 × 96000 = 24.576 MHz
```
ES8388 `ADCCONTROL5 = 0x00` configures `ADC_FS = MCLK / 256`. At 18.432 MHz this would give 72kHz, not 96kHz. At 24.576 MHz → 96kHz ✓.

## Code (Wrong)
```c
i2s_std_config_t rx0_std_cfg = std_cfg;          // inherits mclk = GPIO20
rx0_std_cfg.gpio_cfg.bclk = BSP_I2S0_BCK_IO;     // mclk NOT overridden
// ...

.mclk_multiple = I2S_MCLK_MULTIPLE_192,          // 18.432 MHz — wrong
```

## Code (Fixed)
```c
i2s_std_config_t rx0_std_cfg = std_cfg;
rx0_std_cfg.gpio_cfg.mclk = I2S_GPIO_UNUSED;     // [P0-4] RX ports do not drive MCLK
rx0_std_cfg.gpio_cfg.bclk = BSP_I2S0_BCK_IO;
// same pattern for rx2_std_cfg

.mclk_multiple = I2S_MCLK_MULTIPLE_256,          // [P2-6] 24.576 MHz matches design spec
```

## Verification
- At boot, `i2s_channel_init_std_mode()` should succeed for all three ports.
- MCLK on GPIO20 = 24.576 MHz (verify with oscilloscope).
- ES8388 ADC should lock at 96kHz (ADCCONTROL5=0x00 → MCLK/256 = 96kHz).

## Lessons Learned
- When copying an I2S config struct for RX channels, **always explicitly clear** `gpio_cfg.mclk = I2S_GPIO_UNUSED` and `gpio_cfg.dout = I2S_GPIO_UNUSED`.
- MCLK multiple must be cross-checked against codec register values (e.g., ES8388 ADCCONTROL5 `MCLK/Fs` field) — one change in code must align with the other.
