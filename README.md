# FOX M4 - Hướng dẫn Khởi động và Nạp Code (Build & Flash)

Dự án FOX M4 sử dụng kiến trúc **Dual-MCU** (hai vi điều khiển phối hợp) để tối ưu hóa hiệu năng xử lý âm thanh và kết nối Bluetooth. Tài liệu này hướng dẫn cách thiết lập môi trường và nạp code cho cả hai chip.

---

## 1. Tổng quan Kiến trúc

| Thành phần | Chip | Vai trò chính |
|------------|------|---------------|
| **Main MCU** | ESP32-P4 | Xử lý DSP, trộn âm thanh (Mixer), điều khiển màn hình UI, quản lý nguồn. |
| **BT Companion** | ESP32-WROOM-32E | Nhận tín hiệu Bluetooth A2DP, chuyển tiếp âm thanh qua I2S tới Main MCU. |

---

## 2. Chuẩn bị Môi trường

Dự án yêu cầu **ESP-IDF phiên bản v5.2 trở lên**.

### Bước 1: Cài đặt ESP-IDF
Nếu chưa có môi trường, hãy tải và cài đặt theo hướng dẫn chính thức của Espressif:
- [ESP-IDF Installation Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)

### Bước 2: Thiết lập Biến môi trường
Trước khi build, bạn cần "source" môi trường ESP-IDF trong terminal:

**Windows (PowerShell):**
```powershell
. $HOME\esp\esp-idf\export.ps1
```

**Linux/WSL/macOS:**
```bash
source ~/esp-idf/export.sh
```

### 2.3. Cách xác định và chỉ định Cổng Serial (Port)

Trước khi nạp code, bạn cần xác định chip đang kết nối với máy tính qua cổng nào.

#### Cách tìm Port trên Windows:
1. Mở **Device Manager** -> **Ports (COM & LPT)**.
2. Tìm thiết bị có tên như " USB Serial Device" hoặc "USB-SERIAL CH340". Ghi lại số COM (ví dụ: `COM3`, `COM5`).
3. Hoặc dùng PowerShell: `Get-WMIObject Win32_SerialPort | Select-Object Name, DeviceID`

#### Cách tìm Port trên Linux / WSL:
1. Chạy lệnh: `ls /dev/ttyUSB*` hoặc `ls /dev/ttyACM*`.
2. Thông thường sẽ là `/dev/ttyUSB0`, `/dev/ttyUSB1`.
3. Nếu dùng WSL, bạn cần công cụ **usbipd-win** để gắn (attach) cổng COM từ Windows vào môi trường Linux.

#### Hướng dẫn Attach Port cho WSL (Dành cho máy ảo/WSL):
**Lưu ý quan trọng:** Các lệnh `usbipd` bên dưới phải được chạy trên **PowerShell (Admin)** của **Windows**, không phải chạy bên trong terminal WSL.

1. **Liệt kê danh sách thiết bị (Windows PowerShell):**
   ```powershell
   usbipd list
   ```
   Tìm thiết bị có BUSID tương ứng với "USB Serial Device" hoặc "CH340".

2. **Bind thiết bị (chỉ làm lần đầu):**
   ```powershell with admin
   usbipd bind --busid <BUSID>
   ```

3. **Attach thiết bị vào WSL:**
   ```powershell with admin
   usbipd attach --wsl --busid <BUSID>
   ```úb

4. **Kiểm tra trong WSL:**
   Mở terminal WSL và chạy `ls /dev/ttyUSB*`. Nếu thấy xuất hiện cổng (ví dụ `/dev/ttyUSB0`) là đã thành công.

5. **Cấp quyền truy cập cổng (Chỉ làm 1 lần trên WSL):**
   Nếu gặp lỗi `Path '/dev/ttyUSB0' is not readable`, bạn cần cấp quyền cho user hiện tại:
   ```bash
   sudo usermod -aG dialout $USER
   ```
   *Sau đó hãy khởi động lại WSL (hoặc log out và log in lại) để quyền có hiệu lực.*

*Lưu ý: Bạn phải giữ PowerShell mở hoặc thiết bị sẽ bị detach khi rút cáp.*

#### Cách trỏ Port khi Flash:
Sử dụng tham số `-p` (hoặc `--port`) theo sau là tên cổng bạn vừa tìm được:
- Windows: `idf.py -p COM3 flash`
- Linux/WSL: `idf.py -p /dev/ttyUSB0 flash`

---

## 3. Quy trình Build và Flash cho ESP32-P4 (Main MCU)

Thư mục: `C_code/micro-fox-m4-esp32p4-main`

### 3.1. Thiết lập Target
```bash
cd C_code/micro-fox-m4-esp32p4-main
idf.py set-target esp32p4
```

### 3.2. Build Code
```bash
idf.py build
```

### 3.3. Flash và Giám sát (Monitor)
Thay `PORT` bằng cổng COM tương ứng (ví dụ: `COM3` trên Windows hoặc `/dev/ttyUSB0` trên Linux).
```bash
idf.py -p PORT flash monitor
```

---

## 4. Quy trình Build và Flash cho ESP32-WROOM (Bluetooth Companion)

Thư mục: `C_code/micro-fox-m4-esp32-bluetooth`

### 4.1. Thiết lập Target
```bash
cd C_code/micro-fox-m4-esp32-bluetooth
idf.py set-target esp32
```

### 4.2. Build Code
```bash
idf.py build
```

### 4.3. Flash và Giám sát (Monitor)
```bash
idf.py -p PORT flash monitor
```

---

## 5. Sử dụng Script Build Tự động (Linux/WSL)

Mỗi dự án đều có sẵn file `build.sh` để tự động hóa quá trình build và copy firmware ra thư mục chung:

```bash
# Ví dụ cho ESP32-P4
cd C_code/micro-fox-m4-esp32p4-main
chmod +x build.sh
./build.sh
```

Kết quả firmware (.bin) sẽ được copy vào thư mục `firmware_bin/` ở thư mục gốc của dự án.

---

## 6. Lưu ý quan trọng

*   **ESP32-P4 Flash Revision**: Một số phiên bản phần cứng ESP32-P4 có thể yêu cầu cấu hình flash cụ thể (DIO/QIO). Nếu gặp lỗi khi boot, hãy kiểm tra lại `menuconfig`.
*   **Cổng Serial**: Khi kết nối cả hai chip vào máy tính, hãy xác định đúng cổng COM cho từng chip để tránh nạp nhầm firmware.
*   **Nguồn điện**: Đảm bảo bo mạch được cấp đủ nguồn khi flash, đặc biệt là ESP32-P4 khi đang chạy màn hình và DSP.

---

## 7. Hướng dẫn Kiểm tra (Test) sau khi Flash

### 7.1. Kết nối phần cứng (Nếu dùng kit rời)
Để âm thanh truyền được từ Bluetooth sang Mixer, bạn cần nối các chân I2S sau:

| ESP32-WROOM (BT) | ESP32-P4 (Main) | Tín hiệu |
| :--- | :--- | :--- |
| **Pin 26** | **Pin 46** | I2S Bit Clock (BCK) |
| **Pin 25** | **Pin 47** | I2S Word Select (WS) |
| **Pin 22** | **Pin 53** | I2S Data Out (DOUT) |
| **GND** | **GND** | Chân đất chung |

### 7.2. Kết nối Màn hình OLED (SSD1306 SPI)
Nếu bạn sử dụng màn hình OLED rời, hãy nối các chân sau vào **ESP32-P4**:

| OLED (7-pin SPI) | ESP32-P4 | Tín hiệu |
| :--- | :--- | :--- |
| **VCC** | **3.3V** | Nguồn dương |
| **GND** | **GND** | Chân đất chung |
| **D0 (SCLK)** | **Pin 5** | SPI Clock |
| **D1 (MOSI)** | **Pin 3** | SPI Data |
| **RES (Reset)** | **Pin 14** | Reset Display |
| **DC (Data/Cmd)** | **Pin 13** | Data/Command Select |
| **CS** | **Pin 2** | Chip Select |

---

### 7.3. Quy trình kiểm tra thực tế

1. **Cấp nguồn cho cả 2 chip.**
2. **Kết nối Bluetooth:**
   - Mở Bluetooth trên điện thoại, tìm thiết bị: **"FOX-M4-AUDIO"**.
   - Khi kết nối thành công, log của ESP32-WROOM sẽ hiện: `I (xxx) bt_sink: A2DP Connected`.
3. **Thử nghiệm Âm thanh:**
   - Phát nhạc từ điện thoại.
   - ESP32-WROOM sẽ giải mã và gửi dữ liệu qua I2S tới ESP32-P4.
   - Kiểm tra cổng ra âm thanh của ESP32-P4 (qua DAC PCM5102A).

---

## 8. Xử lý sự cố (Troubleshooting)

| Lỗi | Nguyên nhân | Giải pháp |
| :--- | :--- | :--- |
| `INVALID_ARG` khi init BT | Sai mode Controller | Chạy `idf.py menuconfig` -> Bluetooth -> Controller Mode -> Dual Mode. Sau đó `idf.py fullclean`. |
| `Path is not readable` | Lỗi quyền Serial | Chạy `sudo usermod -aG dialout $USER` trong WSL. |
| Không thấy Bluetooth | Thiếu xung I2S | ESP32-WROOM (Slave) cần xung từ ESP32-P4 (Master). Hãy đảm bảo dây BCK/WS đã nối đúng và ESP32-P4 đã khởi động. |

---

## Tài liệu bổ sung
- Chi tiết kiến trúc Firmware: [docs/FIRMWARE_GUIDE.md](C_code/micro-fox-m4-esp32p4-main/FIRMWARE_GUIDE.md)
- Sơ đồ Hardware: [docs/INDEX.md](docs/INDEX.md)
