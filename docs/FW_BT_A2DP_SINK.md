---
type: firmware
status: done
last_updated: 2026-05-15
---

# FW_BT_A2DP_SINK

Tags: #done #firmware #bluetooth

Bluetooth A2DP Sink implementation for ESP32-WROOM-32E.
Files: `micro-fox-esp32-bluetooth/Middleware/bt_a2dp_sink/`.
Hardware: [[HW_ESP32_WROOM_32E]], [[HW_I2S_BUS]].
Bugs fixed: [[RCA_BtCtrl_Stub_Linker]], [[RCA_BT_Callback_I2S_Deadlock]], [[RCA_Task_Lifecycle_And_BT_Controller_Mode]].

## Logic Flow

- Receives SBC/AAC streams from paired device.
- Decodes to PCM (44.1kHz / 16-bit stereo).
- Forwards raw PCM via I2S Slave to ESP32-P4 I2S2.
- Link: [[ARCH_INTER_MCU_COMM]].

## API

```c
esp_err_t bt_a2dp_sink_init(const char *device_name);
esp_err_t bt_a2dp_sink_deinit(void);                          // Phase-1 fix
esp_err_t bt_a2dp_sink_register_data_callback(cb);             // existing
esp_err_t bt_a2dp_sink_register_state_callback(cb);            // Phase-1 fix
esp_err_t bt_a2dp_sink_start_discovery(void);                  // Phase-1 fix
esp_err_t bt_a2dp_sink_disconnect(void);                       // Phase-1 fix
bt_a2dp_state_t bt_a2dp_sink_get_state(void);
```

## State Machine

```
IDLE -> DISCOVERABLE -> CONNECTING -> CONNECTED -> STREAMING
                    <-                          <-
```
State changes fire `bt_a2dp_state_callback_t` if registered.
Remote BDA (`s_remote_bda[6]`) is saved on CONNECTED and cleared on DISCONNECTED.

## Inter-MCU Control
Uses [[FW_BSP_UART]] for status reporting (connected, play, pause) to the Main MCU.
Link: [[ARCH_INTER_MCU_COMM]].

## Configuration Notes
- **[P3-3]** The Bluetooth companion now uses BR/EDR-only controller mode for A2DP sink operation:
    `CONFIG_BT_CLASSIC_ENABLED=y`, `CONFIG_BT_A2DP_ENABLE=y`, `CONFIG_BTDM_CTRL_MODE_BR_EDR_ONLY=y`, BLE disabled.
