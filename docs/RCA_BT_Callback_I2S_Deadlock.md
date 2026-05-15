---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_BT_Callback_I2S_Deadlock

Tags: #done #bug #critical

`audio_data_cb` in [[FW_BT_A2DP_SINK]] called `bsp_i2s_write(portMAX_DELAY)` directly
inside the BT stack callback — blocking I2S in BT task context.
Module: `micro-fox-esp32-bluetooth/Application/app_main/src/app_main_logic.c`.
Fix: [[FW_BSP_I2S_BT]], [[ARCH_INTER_MCU_COMM]].

---

## Symptom
- BT watchdog timeout (`Task watchdog got triggered`) at boot or during streaming.
- System stalls or reboots when phone connects and starts sending audio.
- BT stack may log `A2DP callback timeout` in verbose mode.

## Root Cause
The A2DP data callback runs inside the internal BT stack task. This task has its own
stack (configured via `BT_CTRL_TASK_STACK_SIZE`) and a FreeRTOS watchdog timer.

`bsp_i2s_write(..., portMAX_DELAY)` blocks until the I2S DMA descriptor is free.
If the I2S pipeline is stalled (DMA buffer full, clock issue, or I2S task preempted),
this blocks the BT task indefinitely → BT watchdog fires → reboot.

Even without a watchdog, blocking I2S write inside the BT callback increases callback
latency, which can starve the BT stack of processing time and cause audio glitches or
disconnections.

## Code (Wrong)
```c
static void audio_data_cb(const uint8_t *data, uint32_t len)
{
    size_t written = 0;
    bsp_i2s_write(data, len, &written, portMAX_DELAY); // blocks BT task
}
```

## Code (Fixed)
```c
#define BT_STREAM_BUF_BYTES   (1024 * 16)   /* ~90ms @ 44.1kHz 16-bit stereo */
#define BT_STREAM_CHUNK_BYTES (2048)

static StreamBufferHandle_t s_bt_stream = NULL;

/* Callback: non-blocking push into stream buffer */
static void audio_data_cb(const uint8_t *data, uint32_t len)
{
    if (s_bt_stream == NULL) return;
    xStreamBufferSend(s_bt_stream, data, len, 0); // timeout=0, never blocks
}

/* Dedicated task: blocking I2S write in safe context */
static void bt_i2s_writer_task(void *pvParameters)
{
    uint8_t *buf = malloc(BT_STREAM_CHUNK_BYTES);
    while (1) {
        size_t received = xStreamBufferReceive(s_bt_stream, buf,
                                               BT_STREAM_CHUNK_BYTES,
                                               pdMS_TO_TICKS(100));
        if (received > 0) {
            size_t written = 0;
            bsp_i2s_write(buf, received, &written, pdMS_TO_TICKS(200));
        }
    }
}
```

## Buffer Sizing Rationale
| Parameter | Value | Rationale |
|-----------|-------|-----------|
| Stream buffer | 16 KB | ~90ms @ 44.1kHz 16-bit stereo (176400 B/s) — absorbs A2DP jitter |
| Chunk size | 2048 B | Matches typical A2DP SBC frame batch size (~512 samples × 4 bytes) |
| I2S write timeout | 200 ms | Long enough to drain DMA, short enough to not stall the writer task |

## Data Drop Behavior
When `xStreamBufferSend(..., 0)` is called and the buffer is full, incoming BT data
is silently dropped. This produces a brief audio glitch but keeps the BT stack responsive.
The alternative — blocking the callback — risks system stability and is never acceptable.

## Lessons Learned
- **Never block in a BT/WiFi stack callback.** These callbacks run in driver task context with watchdogs.
- `portMAX_DELAY` in any synchronization primitive inside a driver callback is a latent deadlock.
- The fix pattern (callback → ring buffer → dedicated consumer task) is universally applicable
  to all driver callbacks: BT, WiFi, USB, etc.
