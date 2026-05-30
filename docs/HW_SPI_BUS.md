---
type: hardware
status: done
last_updated: 2026-05-28
---

# HW_SPI_BUS

Tags: #done #hardware #bus

SPI Bus configuration on [[HW_ESP32P4]]. Driver: [[FW_BSP_SPI]].

---

## Devices
- [[HW_SDCARD]]: High-speed SPI.
- [[HW_ILI9225]]: TFT color display control (176×220, RGB565).

## Shared Resources
Bus sharing is handled by the [[FW_BSP_SPI]] driver using CS (Chip Select) logic.
