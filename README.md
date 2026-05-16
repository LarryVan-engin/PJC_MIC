# FOX M4 — Hướng dẫn Build & Flash (Prototype 2-Board)

Phiên bản prototype chỉ dùng **2 board**: ESP32-P4-WiFi6-DEV-KIT (Waveshare) và ESP32-WROOM-32E.

---

## 1. Tổng quan Kiến trúc Prototype

```
[Điện thoại/PC]
    │  Bluetooth A2DP
    ▼
[ESP32-WROOM-32E] ── I2S Slave TX ──► [ESP32-P4-WiFi6-DEV-KIT]
  BT A2DP Sink        44.1kHz 16-bit    I2S Master RX (I2S2)
  "FOX-M4-AUDIO"      stereo PCM             │
                                             │ I2S0 Master TX
                                             ▼
                                       [ES8388 Codec]  ← on-board
                                             │
                                             ▼
                                      3.5mm AUDIO Jack (J1)
```

| Board | Chip | Vai trò |
|---|---|---|
| **ESP32-P4-WiFi6-DEV-KIT** | ESP32-P4 | I2S Master, điều khiển ES8388, phát ra 3.5mm |
| **ESP32-WROOM-32E** | ESP32 | BT A2DP Sink, I2S Slave TX sang ESP32-P4 |

---

## 2. Kết nối Phần cứng

### 2.1 Kênh I2S Audio (ESP32-WROOM-32E → ESP32-P4)

> ESP32-P4 là **I2S Master** (phát BCK + WS). ESP32-WROOM-32E là **I2S Slave** (nhận clock, phát dữ liệu).

| ESP32-WROOM-32E | Dây nối | ESP32-P4-WiFi6-DEV-KIT | Tín hiệu |
|:---|:---:|:---|:---|
| **GPIO26** | ←── | **GPIO46** (header P6) | I2S BCK (clock, từ P4 → ESP32) |
| **GPIO25** | ←── | **GPIO47** (header P6) | I2S WS/LRCK (word select, từ P4 → ESP32) |
| **GPIO22** | ──► | **GPIO53** (header P6) | I2S DOUT data (từ ESP32 → P4) |
| **GND** | ──── | **GND** | Chân đất chung |

**Lưu ý**: Trên header P6 của Waveshare board:
- Hàng trên: `...GND 46 27 45`
- Hàng dưới: `...48 53 47 GND`

### 2.2 Kênh UART Điều khiển (ESP32-P4 → ESP32-WROOM-32E)

> Dùng để gửi lệnh BT_ON / BT_OFF / VOL_SET. Không bắt buộc cho luồng audio cơ bản.

| ESP32-P4-WiFi6-DEV-KIT | Dây nối | ESP32-WROOM-32E | Tín hiệu |
|:---|:---:|:---|:---|
| **GPIO26** (UART1 TX) | ──► | **GPIO16** (UART1 RX) | Lệnh điều khiển P4 → ESP32 |
| **GPIO24** (UART1 RX) | ←── | **GPIO17** (UART1 TX) | ACK/Status ESP32 → P4 |
| **GND** | ──── | **GND** | Chân đất chung |

> **Chú ý**: GPIO26 được dùng cho UART1 TX (ESP32-P4) — **không nối đồng thời với I2S BCK** (GPIO46 là BCK). Hai tín hiệu này nằm trên các chân khác nhau.

---

## 3. Thông tin Jack 3.5mm (J1 – AUDIO) trên Waveshare ESP32-P4-WiFi6-DEV-KIT

Từ schematic `ESP32-P4-WIFI6-DEV-KIT-datasheet.pdf`:

- **J1** (nhãn "AUDIO" trên PCB) là jack TRS 3.5mm headphone.
- Kết nối với **ES8388** codec (on-board) qua đường analog:
  - **Tip (L)**: ES8388 HPOUT1L → tụ lọc → J1 Tip
  - **Ring (R)**: ES8388 HPOUT1R → tụ lọc → J1 Ring
  - **Sleeve**: GND

### Chân ESP32-P4 kết nối ES8388 (I2S0 — bên trong board, không cần dây ngoài):

| ESP32-P4 GPIO | Chức năng I2S0 | ES8388 Pin | Mô tả |
|:---|:---|:---|:---|
| **GPIO20** | MCLK out | MCLK | 11.2896 MHz (= 256 × 44100) |
| **GPIO21** | BCLK out | SCLK | Bit clock từ ESP32-P4 |
| **GPIO22** | WS/LRCK out | LRCK | Word select từ ESP32-P4 |
| **GPIO25** | DOUT (data ra) | SDIN | Dữ liệu PCM ESP32-P4 → ES8388 (playback) |
| **GPIO23** | DIN (data vào) | SDOUT | ES8388 → ESP32-P4 (ADC/record, không dùng trong prototype) |
| **GPIO7** | I2C SDA | SDA | Cấu hình ES8388 qua I2C |
| **GPIO8** | I2C SCL | SCL | Cấu hình ES8388 qua I2C |

> Tất cả kết nối I2S0 ↔ ES8388 đều nằm bên trong board Waveshare — **không cần dây ngoài**. Chỉ cần cắm jack 3.5mm vào J1.

---

## 4. Chuẩn bị Môi trường

Yêu cầu **ESP-IDF v5.2+**.

```powershell
# Windows PowerShell
. $HOME\esp\esp-idf\export.ps1
```

```bash
# Linux/WSL/macOS
source ~/esp-idf/export.sh
```

---

## 5. Build & Flash ESP32-P4 (Main MCU)

```bash
cd C_code/micro-fox-m4-esp32p4
idf.py set-target esp32p4
idf.py build
idf.py -p <PORT> flash monitor
```

---

## 6. Build & Flash ESP32-WROOM-32E (Bluetooth Companion)

```bash
cd C_code/micro-fox-esp32-bluetooth
idf.py set-target esp32
idf.py build
idf.py -p <PORT> flash monitor
```

> **Lưu ý menuconfig BT**: Vào `idf.py menuconfig` → Component config → Bluetooth → Bluetooth controller → Controller Mode → chọn **BR/EDR Only** (hoặc Dual Mode). Sau đó `idf.py fullclean && idf.py build`.

---

## 7. Xác định Cổng Serial (COM Port)

**Windows**: Device Manager → Ports (COM & LPT) → ghi lại COM số.

```powershell
Get-WMIObject Win32_SerialPort | Select-Object Name, DeviceID
```

**Linux/WSL**:
```bash
ls /dev/ttyUSB*
```

Khi cắm cả 2 board, cần phân biệt đúng cổng của từng board trước khi flash.

---

## 8. Quy trình Test sau Flash

1. **Cấp nguồn** cho cả 2 board.
2. **Nối 4 dây** theo bảng mục 2.1 (BCK, WS, DOUT, GND).
3. **Cắm tai nghe/loa** vào jack **J1 (AUDIO)** trên Waveshare board.
4. **Kết nối Bluetooth** từ điện thoại:
   - Mở Bluetooth → tìm thiết bị **"FOX-M4-AUDIO"** → kết nối.
   - Log ESP32 hiện: `I (xxx) bt_sink: A2DP Connected`
5. **Phát nhạc** từ điện thoại → âm thanh xuất ra jack 3.5mm.

### Log bình thường khi hoạt động:

**ESP32-WROOM-32E:**
```
I (xxx) bt_sink: A2DP Connected
I (xxx) bt_sink: A2DP Streaming Started
```

**ESP32-P4:**
```
I (xxx) bsp_i2s: I2S0 TX→ES8311 @44.1kHz/16-bit, I2S2 RX←ESP32-BT @44.1kHz/16-bit
I (xxx) bsp_es8311: ES8311 ready — audio plays on 3.5mm AUDIO jack (J1)
I (xxx) app_audio: Audio forward task running on core 1
```

---

## 9. Xử lý Sự cố

| Lỗi | Nguyên nhân | Giải pháp |
|:---|:---|:---|
| Không có âm thanh trên J1 | I2S hoặc codec chưa khởi động | Kiểm tra log: phải có `ES8311 ready` trước `I2S0 TX→ES8311` |
| Không nghe thấy Bluetooth | ESP32 chưa nhận clock I2S | Đảm bảo ESP32-P4 khởi động trước và cắm đúng GPIO46→GPIO26, GPIO47→GPIO25 |
| `INVALID_ARG` init BT | Sai BT Controller mode | `idf.py menuconfig` → BT Controller → **BR/EDR Only** → `fullclean` |
| Tiếng rè/nhiễu | Format I2S không khớp | Kiểm tra ESP32 dùng `I2S_STD_MSB_SLOT_DEFAULT_CONFIG`, ESP32-P4 I2S2 cũng dùng MSB |
| ES8311 không khởi động (`ESP_ERR_INVALID_RESPONSE`) | Lỗi I2C — sai địa chỉ hoặc dây SDA/SCL | ES8311 ở địa chỉ **0x18** trên GPIO7/GPIO8; chạy I2C scan để xác nhận |
| `Path is not readable` (WSL) | Thiếu quyền serial | `sudo usermod -aG dialout $USER` rồi restart WSL |

---

## 10. Tài liệu bổ sung

- Schematic Waveshare board: `ESP32-P4-WIFI6-DEV-KIT-datasheet.pdf`
- Block diagram đầy đủ: `FOX_M4_Block_Diagram.drawio (1).pdf`
- Khi phát triển lên hệ thống đầy đủ (mixer, DSP, OLED, SDCard): xem các component còn lại trong `C_code/micro-fox-m4-esp32p4/` (bsp_es8311, bsp_pcm5102a, audio_mixer, ui_engine, v.v.)
