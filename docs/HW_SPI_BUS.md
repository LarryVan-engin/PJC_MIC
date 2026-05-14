---
type: hardware
status: done
last_updated: 2026-05-09
---

# HW_SPI_BUS

Tags: #done #hardware #bus

SPI Bus configuration on [[HW_ESP32P4]]. Driver: [[FW_BSP_SPI]].

---

## Devices
- [[HW_SDCARD]]: High-speed SPI.
- [[HW_SSD1306]]: OLED Display control.

## Shared Resources
Bus sharing is handled by the [[FW_BSP_SPI]] driver using CS (Chip Select) logic.
