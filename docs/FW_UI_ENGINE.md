---
type: firmware
status: done
last_updated: 2026-05-28
---

# FW_UI_ENGINE

Tags: #done #firmware #middleware #ui

UI Engine middleware — manages [[HW_ILI9225]] TFT display and rotary encoder.
Files: `Middleware/ui_engine/include/ui_engine.h`, `Middleware/ui_engine/src/ui_engine.c`,
`Middleware/ui_engine/include/fox_logo.h`.
Hardware: [[HW_ESP32P4]], [[HW_ILI9225]].

---

## Responsibilities

- Renders full UI to a 77,440-byte RGB565 framebuffer and flushes to the ILI9225 via SPI2 DMA.
- Decodes rotary encoder rotation and button press/long-press from GPIO ISRs.
- Dispatches UI events via a FreeRTOS queue consumed by the UI task loop.
- Exposes setter functions so audio and power tasks can push live data (VU levels, MIC signal strength, battery level, mode number) without taking the display lock.

## Task

| Property | Value |
|----------|-------|
| Priority | 5 |
| Stack | 4096 bytes |
| Core | 0 |
| Refresh period | ~8 ms (`pdMS_TO_TICKS(8)`) |

## Screen Layout (Portrait 176×220)

```
┌──────────────────────────────────────────┐  ← y=0
│  [Fox Logo] MODE N  M1 ▁▃▅▇  M2 ▁▃▅▇ 🔋 │  Header (18 px, white bg, black text)
├──────────────────────────────────────────┤  ← y=18 (1px gray separator)
│  MASTER row  (48 px)                     │
│  ──────────────────────────────────────  │
│  MICRO  row  (48 px)                     │
│  ──────────────────────────────────────  │
│  EFFECT row  (48 px)                     │
│  ──────────────────────────────────────  │
│  MUSIC  row  (48 px)                     │
├──────────────────────────────────────────┤  ← y=210
│  [PRESS=select  TURN=adjust  LONG=menu]  │  Hint bar (10 px)
└──────────────────────────────────────────┘  ← y=220
```

### Header (18 px)
- White background, 1px gray separator at bottom.
- **Fox Sound logo** (24×10 px, 1bpp bitmap from `fox_logo.h`) drawn at x=1, vertically centred.
- Black text: `MODE N` (active preset), `M1`/`M2` (2.4GHz MIC signal bars), battery icon.

### Channel Row (48 px each)

Each row contains, from top to bottom:

| Element | Offset Y | Height | Color | Meaning |
|---------|----------|--------|-------|---------|
| Input (cyan) bar | +7 px | 6 px | `COLOR_CYAN` | Auto input level, read from `ui_engine_set_input_levels()` |
| Output (orange) slider | +19 px | 5 px | `COLOR_ORANGE` | User-controlled output volume |
| Output handle | centred on slider | r=8 | orange ring / gray | Knob; orange when selected, gray otherwise |
| Numeric value box | right side (x=137) | 20 px | white bg when selected | `0`–`100` volume value |
| Channel label | below handle | 8 px | white/yellow | MASTER / MICRO / EFFECT / MUSIC |

Both bars sit on a `COLOR_DARK_GRAY` background track (`TR_X=8`, `TR_W=125`).

### Layout Constants (ui_engine.c)

```c
#define HDR_H        18   /* header height */
#define ROW_H        48   /* channel row height */
#define IN_BAR_OFF_Y  7   /* cyan bar top offset within row */
#define IN_BAR_H      6   /* cyan bar height */
#define TR_X          8   /* slider track left edge */
#define TR_W          125 /* slider track width */
#define TR_H          5   /* orange slider height */
#define TR_OFF_Y      19  /* orange slider top offset within row */
#define HND_R         8   /* handle radius */
#define VAL_X         137 /* value box left edge */
#define VAL_W         34  /* value box width */
#define VAL_OFF_Y     7   /* value box top offset within row */
#define VAL_BOX_H     20  /* value box height */
```

## State Machine (ui_state_t)

```
UI_STATE_HOME
  └─ PRESS → UI_STATE_MENU_MASTER / MICRO / EFFECT / MUSIC  (channel select)
       └─ LONG_PRESS → UI_STATE_MENU_MASTER (top-level menu)
            ├─ UI_STATE_SAVE_DIALOG
            ├─ UI_STATE_PAIRING_DIALOG
            └─ UI_STATE_STYLE_DROPDOWN
```

| State | Description |
|-------|-------------|
| `UI_STATE_HOME` | Four-channel mixer screen |
| `UI_STATE_MENU_MASTER` | MASTER channel settings menu |
| `UI_STATE_MENU_MICRO` | MICRO channel settings menu |
| `UI_STATE_MENU_EFFECT` | EFFECT channel settings menu |
| `UI_STATE_MENU_MUSIC` | MUSIC channel settings menu |
| `UI_STATE_SAVE_DIALOG` | Save preset dialog |
| `UI_STATE_PAIRING_DIALOG` | Wireless MIC pairing dialog |
| `UI_STATE_STYLE_DROPDOWN` | Color theme selector |

Menu headers use `COLOR_RED_DARK` (`0xA000`) for the metallic red header bar.

## Public API

```c
esp_err_t ui_engine_init(void);
esp_err_t ui_engine_deinit(void);
esp_err_t ui_engine_register_callback(ui_event_callback_t callback);
esp_err_t ui_engine_refresh(void);
esp_err_t ui_engine_draw_text(uint8_t x, uint8_t y, const char *text, uint16_t color);
esp_err_t ui_engine_clear(uint16_t color);
void      ui_engine_task_start(void);

/* Setters called from other tasks (thread-safe via atomic writes) */
void ui_engine_set_input_levels(int master, int mic, int effect, int music);
void ui_engine_set_mic_signal(int mic1_bars, int mic2_bars);   /* 0=no signal, 3=full */
void ui_engine_set_battery(int level_0_to_4);
void ui_engine_set_mode(int mode);                             /* 1–9 */
```

## Fox Sound Logo Bitmap

The header logo is a 24×10 px 1bpp bitmap stored in `fox_logo.h` (guard `FOX_LOGO_BITMAP_H`).
To regenerate from a new PNG:

```bash
python3 tools/convert_logo.py tools/fox_logo.png 24 10
```

The script flattens the PNG alpha channel onto a white background, resizes, thresholds at 128, and writes the C array.

> **Guard naming:** The file uses guard `FOX_LOGO_BITMAP_H` (not `FOX_LOGO_H`) to avoid collision with the `#define FOX_LOGO_H 10` height constant inside the same file.

## Key Implementation Notes

- **Debounce**: `(now - last_enc_tick) * portTICK_PERIOD_MS < 8u` — multiply tick delta *before* comparing milliseconds to avoid integer truncation to zero at 100 Hz tick rate.
- **Chunked DMA flush**: 5 × 44-row chunks (15,488 bytes each) stay within ESP32-P4 GDMA 32 KB limit.
- **Framebuffer endian**: RGB565 values are byte-swapped before writing (SPI big-endian, host little-endian).

## Related

- [[HW_ILI9225]] — display hardware spec
- [[HW_SPI_BUS]] — SPI2 bus configuration
- [[FW_BSP_SPI]] — SPI driver
- [[FW_APP_MAIN]] — initialises UI engine and starts task
- [[RCA_Task_Lifecycle_And_BT_Controller_Mode]] — Phase-5 fix: `ui_task_handle` now tracked for lifecycle control
