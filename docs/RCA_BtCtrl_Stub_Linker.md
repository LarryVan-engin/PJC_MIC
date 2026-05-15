---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_BtCtrl_Stub_Linker

Tags: #done #bug #high

Linker errors do to unimplemented stub functions in two Bluetooth modules.
Module: [[FW_APP_BT_CTRL]], [[FW_BT_A2DP_SINK]]. Hardware: [[HW_ESP32_WROOM_32E]].

---

## Symptoms
- Build fails at link stage with `undefined reference to app_bt_ctrl_task_start`, `app_bt_ctrl_task_stop`, `bt_a2dp_sink_deinit`, `bt_a2dp_sink_register_state_callback`, `bt_a2dp_sink_start_discovery`, `bt_a2dp_sink_disconnect`.

## Root Cause
Both `app_bt_ctrl.c` and `bt_a2dp_sink.c` were skeleton files containing only `#include` statements. The function signatures were declared in their respective headers but had no implementation body. CMakeLists.txt compiled these files into the binary, causing the linker to fail when referenced symbols were missing.

## Fix Applied

### `app_bt_ctrl.c` — New implementation
- `app_bt_ctrl_task_start()`: Creates a FreeRTOS task (`bt_ctrl_task`, stack 2048, priority 5) that polls `bt_a2dp_sink_get_state()` every 500ms and logs state transitions.
- `app_bt_ctrl_task_stop()`: Sets `s_task_running = false` to signal the task to exit.
- State machine uses `const char* state_str[]` for human-readable log output.

### `bt_a2dp_sink.c` — Added implementations
- Added `static esp_bd_addr_t s_remote_bda` to track connected device BDA.
- `a2d_app_callback` now saves `param->conn_stat.remote_bda` on `CONNECTED` event and clears it on `DISCONNECTED`.
- State callback `state_cb` is now fired on both connection and audio state events.
- `bt_a2dp_sink_register_state_callback()`: Stores the state callback pointer.
- `bt_a2dp_sink_start_discovery()`: Calls `esp_bt_gap_set_scan_mode(CONNECTABLE, GENERAL_DISCOVERABLE)`.
- `bt_a2dp_sink_disconnect()`: Validates `s_remote_bda` is non-zero before calling `esp_a2d_sink_disconnect()`.
- `bt_a2dp_sink_deinit()`: Calls `esp_a2d_sink_deinit()` → `esp_bluedroid_disable/deinit()` → `esp_bt_controller_disable/deinit()` in correct teardown order.

## Verification
- Build should succeed with no undefined reference errors for the above symbols.
- Runtime: `app_bt_ctrl_task_start()` log should appear with "BT Control Task started".

## Lessons Learned
- When generating stub/skeleton files, leave a `#error "NOT IMPLEMENTED"` or a `// TODO` that causes a build warning, not a silent empty file that only fails at link time.
- `bt_a2dp_sink` state callback pattern requires storing remote BDA at connection time; `esp_a2d_sink_disconnect()` requires the remote device address.
