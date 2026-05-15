---
type: rca
status: done
last_updated: 2026-05-15
---

# RCA_I2C_BSP_MissingIncludes

Tags: #done #bug #medium

Missing `<stdlib.h>` and `<string.h>` in BSP I2C driver; missing `log` component in CMakeLists.
Module: [[FW_BSP_I2C]]. Hardware: [[HW_I2C_BUS]].

---

## Symptoms
- Potential implicit-declaration warnings (or errors with `-Werror`) for `malloc`, `memcpy`, `free` in `bsp_i2c.c`.
- Build warnings about `esp_log.h` component not declared as dependency in `CMakeLists.txt`.

## Root Cause

### Missing includes in `bsp_i2c.c`
`bsp_i2c_write()` uses `malloc()` and `memcpy()` but the file only included:
```c
#include "bsp_i2c.h"
#include "bsp_config.h"
#include "driver/i2c_master.h"
#include "esp_log.h"
```
`malloc` / `free` require `<stdlib.h>`, `memcpy` requires `<string.h>`. In GCC/Xtensa toolchains these may be available transitively from other headers, but relying on transitive inclusion is fragile and non-portable.

### Missing `log` in CMakeLists.txt REQUIRES
`esp_log.h` is used in virtually every source file in the ESP32-P4 project. Without declaring `log` as an explicit dependency in `idf_component_register(REQUIRES ...)`, the build relies on transitive inclusion from `driver`. This can break with ESP-IDF version upgrades or `--strict-components` flags.

## Fix Applied
```c
/* bsp_i2c.c — added after existing includes */
#include <stdlib.h>
#include <string.h>
```
```cmake
# main/CMakeLists.txt — added to REQUIRES list
log
```

## Verification
- Rebuild with `-Wall -Wextra` should produce no implicit-declaration warnings for `malloc`/`memcpy`.
- CMakeLists dependency graph includes `log` explicitly.

## Lessons Learned
- Always include the C standard library headers explicitly. Do not rely on transitive inclusion from ESP-IDF component headers.
- Every ESP-IDF component that calls `ESP_LOGI/E/W` must list `log` in its `REQUIRES`.

## Related
- [[FW_BSP_I2C]] — also has a more serious design issue (per-transaction device handle creation) tracked in Phase 3 fix.
