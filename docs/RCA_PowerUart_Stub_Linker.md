---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_PowerUart_Stub_Linker

Tags: #done #bug #high

Linker errors due to unimplemented stub files for power management task and UART BSP driver.
Module: [[FW_APP_POWER]], [[FW_BSP_UART]]. Hardware: [[HW_IP5306]], [[HW_ESP32_WROOM_32E]].

---

## Symptoms
- Build fails if `app_power_task_start()`, `app_power_task_stop()`, `bsp_uart_init()`, `bsp_uart_send()`, `bsp_uart_receive()`, `bsp_uart_deinit()` are called from anywhere — undefined references at link.

## Root Cause
`app_power.c` and `bsp_uart.c` contained only a single `#include` line. CMakeLists.txt included these files via `file(GLOB ...)`, so they were compiled but contributed no symbols.

## Fix Applied

### `app_power.c` (ESP32-P4)
- `app_power_task_start()`: Creates `power_management_task` (stack 2048, priority 2).
- Task polls `bsp_ip5306_get_battery_level()` and `bsp_ip5306_is_charging()` every **10 seconds**.
- Logs changes only when level or charging state transitions (avoids log spam).
- `app_power_task_stop()`: Sets `s_task_running = false`.

### `bsp_uart.c` (ESP32-WROOM)
- **Port**: `UART_NUM_1` (UART0 reserved for ESP-IDF log/monitor).
- **Pins**: TX = GPIO17, RX = GPIO16 (defined as `BSP_UART_TX_IO` / `BSP_UART_RX_IO` within the file).
- **Baud**: 115200, 8N1, no flow control.
- **Buffer**: 256 bytes TX + 256 bytes RX ring buffer via `uart_driver_install()`.
- `bsp_uart_send()`: Uses `uart_write_bytes()`, validates `written == len`.
- `bsp_uart_receive()`: Uses `uart_read_bytes()` with ms timeout converted via `pdMS_TO_TICKS()`.

## Pin Note
UART1 TX/RX (GPIO17/16) must be confirmed against the physical wiring to ESP32-P4 UART RX/TX. See [[ARCH_INTER_MCU_COMM]] for the inter-MCU UART protocol.

## Verification
- Build completes without undefined references for power and uart symbols.
- Runtime: "Power Management Task started" in log; IP5306 battery level readable via I2C ([[HW_IP5306]], [[FW_BSP_I2C]]).

## Lessons Learned
- `bsp_uart.c` needs its own pin defines (`BSP_UART_TX_IO`, `BSP_UART_RX_IO`) since ESP32-WROOM-32E does not share `bsp_config.h` with the P4 project. Consider adding a `bsp_config_bt.h` for the ESP32 project.
