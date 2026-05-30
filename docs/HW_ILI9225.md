---
type: hardware
status: done
last_updated: 2026-05-28
---

# HW_ILI9225

Tags: #done #hardware #display

ILI9225 TFT color display (176×220 px, RGB565). Connected to [[HW_ESP32P4]] via SPI2.
Driver managed by [[FW_UI_ENGINE]] through [[FW_BSP_SPI]].

---

## Specifications

| Parameter | Value |
|-----------|-------|
| Controller | ILI9225 |
| Resolution | 176 × 220 pixels (portrait) |
| Color depth | 16-bit RGB565 |
| Interface | 4-wire SPI (MOSI, SCLK, CS, RS/DC) |
| SPI Bus | SPI2 on ESP32-P4 |
| SPI Clock | 10 MHz |
| Backlight | Always-on (GPIO not controlled in firmware) |

## Pin Connections (ESP32-P4)

| LCD Pin | GPIO | Signal |
|---------|------|--------|
| CLK (SCK) | 22 | SPI2 SCLK |
| SDA (MOSI) | 20 | SPI2 MOSI |
| RS / DC | 24 | Data/Command select (HIGH=data, LOW=command) |
| RST | 25 | Hardware reset (active LOW) |
| CS | 23 | SPI2 Chip Select |

## GRAM Write Protocol

ILI9225 requires a 3-step sequence for writing pixel data:
1. Set window registers `0x0036`–`0x0039` (column/row range) and cursor `0x0020`/`0x0021`.
2. Send GRAM-write index `0x0022` with RS=LOW (command).
3. Send pixel data (16-bit RGB565 per pixel, big-endian) with RS=HIGH.

> **Startup note:** Register `0x0007 = 0x1017` (Display ON) must be written *after* the first GRAM write to avoid the all-white startup artefact.

## Framebuffer

The firmware maintains a full 176×220 RGB565 framebuffer in heap:
- Size: 176 × 220 × 2 = **77,440 bytes**
- DMA-aligned allocation via `heap_caps_malloc(…, MALLOC_CAP_DMA)`
- Flushed in **5 chunks** of 44 rows (15,488 bytes each) to stay within the ESP32-P4 GDMA 32 KB/transaction limit

## Related

- [[FW_UI_ENGINE]] — full UI rendering and encoder logic
- [[HW_SPI_BUS]] — SPI2 bus shared with [[HW_SDCARD]]
- [[FW_BSP_SPI]] — low-level SPI driver
