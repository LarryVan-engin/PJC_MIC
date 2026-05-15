---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_Task_Lifecycle_And_BT_Controller_Mode

Tags: #done #bug #stability

Phase 5 fixes for task shutdown behavior, I2S channel lifecycle cleanup, UI task observability,
and Bluetooth controller mode consistency.
Modules: [[FW_APP_AUDIO]], [[FW_BSP_I2S]], [[FW_APP_MAIN]], [[FW_BT_A2DP_SINK]].

---

## Symptoms
- `app_audio_task_stop()` sets a flag but the audio task can remain blocked in I2S read/write forever.
- `bsp_i2s_deinit()` only deletes TX channel, leaking RX0 and RX2 handles across reinit.
- `ui_task` is created without a handle, so it cannot be monitored or deleted later.
- Bluetooth companion `sdkconfig` enables A2DP Classic while controller mode is `BLE_ONLY`, which is internally contradictory.

## Root Cause

### Audio Task Stop Path
`is_running` was a plain `bool`, shared across task contexts. The audio task also used `portMAX_DELAY`
on blocking I2S calls, so even if the flag changed, the task could remain blocked indefinitely.

### I2S Deinit Leak
`bsp_i2s_deinit()` released only `tx_handle`. The two RX channel handles remained allocated, leaking
ESP-IDF channel objects and preventing clean reinitialization.

### UI Task Handle
`xTaskCreate(..., NULL)` discarded the created task handle. That made later lifecycle operations
(delete, suspend, monitor stack high-water mark) impossible.

### Bluetooth Controller Mode
The Bluetooth companion had:
```ini
CONFIG_BT_CLASSIC_ENABLED=y
CONFIG_BT_A2DP_ENABLE=y
CONFIG_BTDM_CTRL_MODE_BLE_ONLY=y
```
A2DP sink requires BR/EDR. `BLE_ONLY` disables the Classic controller path, so this config is invalid
for the intended product behavior.

## Fix
- `is_running` changed to `volatile` and audio I/O moved from `portMAX_DELAY` to 100 ms bounded timeouts.
- `app_audio_task_stop()` now waits briefly for task exit after clearing the run flag.
- `audio_pipeline_task()` clears `audio_task_handle` on exit.
- `bsp_i2s_deinit()` now disables and deletes `rx0_handle` and `rx2_handle` as well as TX.
- `app_main_logic.c` now stores `ui_task_handle` and checks `xTaskCreate()` return value.
- `micro-fox-esp32-bluetooth/sdkconfig` and `sdkconfig.defaults` now use BR/EDR-only mode with BLE disabled.

## Verification Targets
- Calling `app_audio_task_stop()` should return after the task exits within roughly one I/O timeout window.
- Re-running `bsp_i2s_init()` after `bsp_i2s_deinit()` should not leak or fail due to stale channels.
- `ui_task_handle` is available for future monitor/delete operations.
- Bluetooth companion config contains:
```ini
CONFIG_BT_CLASSIC_ENABLED=y
CONFIG_BT_A2DP_ENABLE=y
CONFIG_BTDM_CTRL_MODE_BR_EDR_ONLY=y
# CONFIG_BT_BLE_ENABLED is not set
```

## Lessons Learned
- A stop flag alone is insufficient if the task blocks forever on driver I/O.
- Deinit paths must mirror init paths one-for-one.
- Task handles are part of system observability, not optional bookkeeping.
- For A2DP products, controller mode and profile selection must be checked together, not independently.
