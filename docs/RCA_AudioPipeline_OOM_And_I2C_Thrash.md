---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_AudioPipeline_OOM_And_I2C_Thrash

Tags: #done #bug #high

Two co-located issues in the audio pipeline and I2C driver that could cause
silent crashes or severe performance degradation.
Modules: [[FW_APP_AUDIO]], [[FW_BSP_I2C]].

---

## Issue 1 — [P1-3] No NULL check after malloc in audio_pipeline_task

### Symptom
System crashes with `LoadProhibited` or `StoreProhibited` exception immediately
after audio task starts, with no log output indicating the cause.

### Root Cause
`audio_pipeline_task` allocates three buffers totalling 12288 bytes:
```c
int32_t *adc_buf    = malloc(512 * 2 * 4);  // 4096 bytes
int32_t *bt_buf_raw = malloc(512 * 2 * 4);  // 4096 bytes
int32_t *out_buf    = malloc(512 * 2 * 4);  // 4096 bytes
```
If the heap is fragmented (BT stack, FreeRTOS queues, and other tasks have already
allocated from it), any of these can return NULL. Without a NULL check, the next
`memcpy`/`i2s_read` dereferences the NULL pointer → exception.

### Fix
```c
if (adc_buf == NULL || bt_buf_raw == NULL || out_buf == NULL) {
    ESP_LOGE(TAG, "audio_pipeline_task: malloc failed (%u bytes free)",
             (unsigned)esp_get_free_heap_size());
    free(adc_buf); free(bt_buf_raw); free(out_buf);
    is_running = false;
    vTaskDelete(NULL);
    return;
}
```
Note: `free(NULL)` is safe per C standard — no guard needed before each `free`.

---

## Issue 2 — [P1-4] I2C driver creates/destroys device handle per transaction

### Symptom
ES8388 initialization (24 register writes) takes >5ms instead of <1ms.
Log shows repeated `Registered I2C device 0x10` messages (previous debug version).
In worst case: `i2c_master_bus_add_device()` fails under memory pressure for the
30th call → codec init incomplete → no mic audio.

### Root Cause
```c
// Old bsp_i2c_write() — executed on EVERY codec register write:
i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle);  // alloc + mutex
// ... transmit ...
i2c_master_bus_rm_device(dev_handle);  // dealloc + mutex
```
`i2c_master_bus_add_device()` allocates an internal device descriptor from heap
and acquires the bus mutex. Calling this for every single-byte register write
multiplies overhead ~30× during ES8388 init and risks heap exhaustion.

### Fix — Lazy-init device handle cache
```c
#define BSP_I2C_MAX_DEVICES 8

typedef struct { uint8_t addr; i2c_master_dev_handle_t handle; } i2c_dev_entry_t;
static i2c_dev_entry_t s_devices[BSP_I2C_MAX_DEVICES];
static int s_dev_count = 0;

// get_or_add_device(): O(n) lookup in small table; creates handle on first call,
// returns cached handle on subsequent calls. No per-transaction alloc.
```
Additionally, `bsp_i2c_write()` now uses a fixed stack buffer instead of `malloc`,
eliminating heap allocation entirely from the hot path:
```c
uint8_t write_buf[BSP_I2C_MAX_WRITE_LEN + 1];  // on stack, 17 bytes
write_buf[0] = reg_addr;
memcpy(&write_buf[1], data, len);
return i2c_master_transmit(dev, write_buf, len + 1, -1);
```

### Cleanup
`bsp_i2c_deinit()` now iterates the cache and calls `i2c_master_bus_rm_device()`
for each registered handle before destroying the bus.

---

## Lessons Learned
- Always check `malloc()` return value at system boundaries (task startup, init functions).
- I2C/SPI device handles in ESP-IDF new driver API are **persistent resources** —
  create once, use many times. The old `compat` API hid this by managing handles
  internally; the new API exposes it explicitly.
- Stack allocation is preferable over heap allocation for small, bounded-size buffers
  in driver hot paths (avoids fragmentation, avoids NULL check, zero overhead).
