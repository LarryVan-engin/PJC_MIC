# FOX M4 - Build & Flash Guide (Prototype 2-Board)

Prototype này dùng 2 board:

- ESP32-P4-WiFi6-DEV-KIT (Waveshare) làm main MCU và phát audio ra mạch ES8311 trên board.
- ESP32-WROOM-32E làm Bluetooth A2DP sink và đẩy PCM sang ESP32-P4 bằng I2S.

## 1. Kiến Trúc Hiện Tại

```text
[Phone/PC]
    |
    | Bluetooth A2DP
    v
[ESP32-WROOM-32E]
  A2DP sink "FOX-M4-AUDIO"
  I2S0 Master TX, 44.1 kHz, 16-bit stereo
    |
    | BCK/WS/DATA
    v
[ESP32-P4-WiFi6-DEV-KIT]
  I2S2 Slave RX
  forward PCM buffer
  I2S0 Master TX
    |
    v
[ES8311 codec on-board]
    |
    +--> 3.5 mm AUDIO jack J1
    +--> NS4150B PA / speaker path, enabled by PA_Ctrl GPIO53
```

## 2. Kết Nối Phần Cứng

### 2.1 I2S Audio: ESP32-WROOM-32E -> ESP32-P4

Firmware hiện tại để **ESP32-WROOM-32E là I2S master TX** và **ESP32-P4 là I2S2 slave RX**. Kết nối theo bảng này, không dùng sơ đồ backup cũ GPIO22 -> GPIO53.

| ESP32-WROOM-32E | Hướng | ESP32-P4-WiFi6-DEV-KIT | Tín hiệu |
|:---|:---:|:---|:---|
| GPIO26 | -> | GPIO46 | I2S BCK, do ESP32-BT phát |
| GPIO25 | -> | GPIO47 | I2S WS/LRCK, do ESP32-BT phát |
| GPIO5 | -> | GPIO48 | I2S DOUT data, PCM từ ESP32-BT sang P4 |
| GND | -- | GND | Đất chung |

Trên header P6 của Waveshare board, các chân liên quan đang dùng là GPIO46, GPIO47, GPIO48 và GND.

### 2.2 UART Điều Khiển

UART không bắt buộc cho đường audio cơ bản. Theo firmware P4 hiện tại:

| ESP32-P4-WiFi6-DEV-KIT | Hướng | ESP32-WROOM-32E | Tín hiệu |
|:---|:---:|:---|:---|
| GPIO32 | -> | GPIO16 | UART command P4 TX -> ESP32 RX |
| GPIO36 | <- | GPIO17 | UART status ESP32 TX -> P4 RX |
| GND | -- | GND | Đất chung |

## 3. ES8311, Jack 3.5 mm và PA

Schematic của Waveshare ESP32-P4-WiFi6-DEV-KIT dùng **ES8311**, không phải ES8388.

### 3.1 I2S0 nội bộ từ ESP32-P4 đến ES8311

Không cần dây ngoài cho các tín hiệu này.

| ESP32-P4 GPIO | Chức năng | ES8311 net | Mô tả |
|:---|:---|:---|:---|
| GPIO13 | I2S0 MCLK | MCLK | 11.2896 MHz = 256 x 44.1 kHz |
| GPIO12 | I2S0 BCK | SCLK | Bit clock |
| GPIO10 | I2S0 WS/LRCK | LRCK | Word select |
| GPIO9 | I2S0 DOUT | SDIN | PCM từ ESP32-P4 vào ES8311 |
| GPIO11 | I2S0 DIN | SDOUT | Đường record, hiện chưa dùng |
| GPIO7 | I2C SDA | SDA | Cấu hình ES8311 |
| GPIO8 | I2C SCL | SCL | Cấu hình ES8311 |

### 3.2 Output analog

- ES8311 xuất analog qua OUTP/OUTN ra mạch AUDIO jack J1.
- NS4150B là power amplifier cho đường speaker. PA được enable bằng `PA_Ctrl = GPIO53`.
- Khi cắm jack 3.5 mm, mạch `EarPhone_Detect` có thể tác động đến `AND_PA_CTRL` để tắt/giữ PA tuỳ trạng thái jack. Đây là hành vi hardware, không phải lỗi I2S.

## 4. Build & Flash

Yêu cầu ESP-IDF phù hợp với project đang build.

### ESP32-P4 Main MCU

```bash
cd C_code/micro-fox-m4-esp32p4-main
idf.py set-target esp32p4
idf.py build
idf.py -p <PORT> flash monitor
```

### ESP32-WROOM-32E Bluetooth Companion

```bash
cd C_code/micro-fox-m4-esp32-bluetooth
idf.py set-target esp32
idf.py build
idf.py -p <PORT> flash monitor
```

Bluetooth controller mode nên để BR/EDR Only hoặc Dual Mode có Classic BT.

## 5. Quy Trình Test

1. Cấp nguồn cho cả 2 board.
2. Nối I2S theo mục 2.1: GPIO26 -> 46, GPIO25 -> 47, GPIO5 -> 48, GND chung.
3. Cắm tai nghe/loa vào jack J1 hoặc test speaker path theo đúng connector của board.
4. Kết nối Bluetooth đến thiết bị `FOX-M4-AUDIO`.
5. Phát nhạc và theo dõi log hai board.

Log ESP32-BT khi có stream:

```text
I (...) bt_sink: A2DP Connected
I (...) bt_sink: A2DP Streaming Started
I (...) app_main: [CHK2 buf->I2S] recv=... sent=... err=0
```

Log ESP32-P4 khi nhận được I2S:

```text
I (...) bsp_i2s: I2S0 TX->ES8311 (MCLK=13,BCK=12,WS=10,DOUT=9), I2S2 Slave RX<-ESP32-BT (BCK=46,WS=47,DIN=48)
I (...) app_audio: [CHK3 DIN probe] GPIO48 transitions/... DATA PRESENT
I (...) app_audio: [CHK3 I2S2 RX] ... L=... R=... peak=... AUDIO
```

## 6. Chẩn Đoán Nhanh

| Hiện tượng | Khả năng | Cần kiểm tra |
|:---|:---|:---|
| P4 log `CLOCK PRESENT` nhưng DIN stuck | Sai dây data hoặc BT không streaming | Kiểm tra ESP32 GPIO5 -> P4 GPIO48 |
| P4 log `AUDIO` nhưng jack im lặng | Vấn đề sau I2S input: I2S0->ES8311, ES8311 init, analog output, jack/PA | Xem `docs/DIAG_ES8311_JACK_NO_AUDIO.md` |
| I2C ES8311 fail | Codec không ACK ở 0x18 hoặc I2C lỗi | Kiểm tra GPIO7/GPIO8 và địa chỉ 0x18 |
| PA speaker im lặng | PA_CTRL/detect/nguồn 5V/đường J11 | Đo GPIO53, `AND_PA_CTRL`, VCC_5V |

## 7. Tài Liệu

- Schematic Waveshare board: `ESP32-P4-WIFI6-DEV-KIT-datasheet.pdf`
- Log P4: `LOG_ESP32P4.md`
- Log Bluetooth: `LOG_ESP32_BLUETOOTH.md`
- Report chẩn đoán hiện tại: `docs/DIAG_ES8311_JACK_NO_AUDIO.md`
