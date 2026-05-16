# Chẩn Đoán ES8311/J1 Không Có Âm Thanh

Ngày lập: 2026-05-16  
Phạm vi: chỉ review tài liệu, firmware và log; không sửa code C.

## 1. Tóm Tắt Kết Luận

Log hiện tại cho thấy đường Bluetooth -> I2S2 RX trên ESP32-P4 đã có audio thật. Khi phát nhạc, P4 nhận được clock, data và sample L/R có biên độ lớn (`AUDIO`, `peak` lên gần full-scale). Vì vậy lỗi "không nghe ở jack 3.5 mm" không còn nằm ở A2DP hay dây I2S input nữa, mà nằm ở nửa sau của pipeline:

```text
I2S2 RX trên P4 -> buffer forward -> I2S0 TX -> ES8311 -> OUTP/OUTN -> jack J1 / PA path
```

Nghi vấn cao nhất hiện tại là **init ES8311 chưa đúng/chưa đủ**, đặc biệt là các register power-on, serial word length và DAC mute/output path. Nghi vấn phụ là jack/speaker đang cắm vào đường không đúng với kiểu output OUTP/OUTN của board.

## 2. Đã Xác Nhận Đúng

### 2.1 Codec đúng là ES8311

Schematic `Codec` cho thấy U13 là ES8311, I2C control ở GPIO7/GPIO8 và I2S ở GPIO13/12/11/10/9. README cũ ghi ES8388 là thông tin cũ và đã được thay thế.

Firmware hiện tại cũng build ES8311:

- `main/CMakeLists.txt` include `BSP/bsp_es8311/src/*.c`.
- `Application/app_main/src/app_main_logic.c` gọi `bsp_es8311_init()`.
- Log P4 có `Cached I2C device 0x18` và `ES8311 ready`.

### 2.2 Kết nối ESP32-BT -> P4 đang theo firmware mới

Firmware hiện tại:

| Tín hiệu | ESP32-BT | ESP32-P4 |
|:---|:---|:---|
| BCK | GPIO26 | GPIO46 |
| WS/LRCK | GPIO25 | GPIO47 |
| DATA | GPIO5 | GPIO48 |
| GND | GND | GND |

Log P4 xác nhận đường này hoạt động khi có nhạc:

```text
[CHK3 DIN probe] GPIO48 transitions/... DATA PRESENT
[LINK I2S] UP - BT Master -> P4 Slave
[CHK3 I2S2 RX] ... L=... R=... real_samples=... peak=... AUDIO
```

Nếu log đang có `AUDIO` nhưng jack im lặng thì không nên tập trung vào GPIO22/GPIO53 nữa. GPIO53 hiện đang là `PA_CTRL`, không phải I2S data.

## 3. Điểm Bất Thường Trong ES8311 Init

### 3.1 Thiếu lệnh power-on `RESET_REG00 = 0x80`

Code hiện tại:

```c
es8311_write_reg(ES8311_RESET_REG00, 0x1F);
...
es8311_write_reg(ES8311_RESET_REG00, 0x00);
```

Driver tham chiếu của Espressif sau reset có thêm lệnh:

```c
es8311_write_reg(..., ES8311_RESET_REG00, 0x80); // Power-on command
```

ESPHome driver cũng ghi `REG00 = 0x80` ở cuối chuỗi setup để power on. Đây là nghi vấn P0: codec có thể ACK I2C và vẫn chưa thật sự vào trạng thái DAC/output running.

### 3.2 Sai cấu hình 16-bit serial data trên REG09/REG0A

Code hiện tại đang ghi:

```c
ES8311_SDP_CONFIG_REG09 = 0x00
ES8311_SDP_CONFIG_REG0A = 0x00
```

Nhưng driver tham chiếu của Espressif encode 16-bit bằng `(3 << 2)`, tức `0x0C`, cho cả input/output serial port. ESPHome driver cũng dùng logic tương tự: 16-bit -> `3 << 2`.

Trong khi đó I2S0 của P4 đang phát `I2S_DATA_BIT_WIDTH_16BIT`. Nếu ES8311 đang được để ở format/word-length khác, codec có thể lock clock nhưng giải mã sample sai hoặc im.

### 3.3 Ghi sai/ý nghĩa mơ hồ register `0x44`

Code hiện tại định nghĩa:

```c
#define ES8311_DAC_REG44 0x44
...
es8311_write_reg(ES8311_DAC_REG44, 0x08);
```

Comment nói đây là route DAC mono output -> headphone output path. Tuy nhiên reg map tham chiếu của Espressif định nghĩa `0x44` là `ES8311_GPIO_REG44`, không phải DAC route. Register DAC liên quan mute/volume/ramp là `0x31`, `0x32`, `0x37`.

ESPHome dùng `REG37 = 0x08` để bypass DAC equalizer. Espressif driver cũng ghi `ES8311_DAC_REG37 = 0x08`. Code hiện tại không có `REG37`.

### 3.4 Một số power/output register khác với driver tham chiếu

Code hiện tại:

```c
REG0E = 0x00
REG0F = 0x9E
REG10 = 0x1F
REG11 = 0x7F
REG12 = 0x00
REG13 = 0x10
```

Driver Espressif/ESPHome có nhóm ghi quan trọng:

```c
REG0D = 0x01
REG0E = 0x02
REG12 = 0x00
REG13 = 0x10
REG37 = 0x08
```

`REG12 = 0x00` và `REG13 = 0x10` của code hiện tại trùng với tham chiếu, nhưng `REG0E`, `REG37` và `REG00=0x80` không trùng. Do đó "ES8311 ready" trong log chỉ chứng minh I2C write không fail, chưa chứng minh analog output đã mở đúng.

## 4. PA NS4150B Có Phải Nguyên Nhân Không?

Có thể có ảnh hưởng đến loa công suất, nhưng không phải nghi vấn chính cho jack 3.5 mm.

Theo schematic PA:

- `OUTP/OUTN` từ ES8311 được ghép AC sang `PA_INL+/-`.
- NS4150B được điều khiển bởi `AND_PA_CTRL`.
- `PA_CTRL` từ GPIO53 đi qua logic AND.
- `EarPhone_Detect` có thể tác động vào logic để tắt PA khi cắm tai nghe.

Code hiện tại đã set:

```c
gpio_set_level(BSP_PA_CTRL_IO, 1);
```

Nghĩa là firmware đã có điều khiển PA mức GPIO cơ bản. Tuy nhiên nếu cắm jack 3.5 mm thì hardware detect có thể chủ động tắt PA, và jack J1 không nên phụ thuộc vào PA speaker path. Nếu bạn cắm loa passive vào jack headphone thì có thể không nghe vì jack không phải đầu ra công suất.

## 5. Phép Đo Để Chốt Nguyên Nhân

Nên đo theo thứ tự này, vì mỗi bước tách một khối lỗi:

1. Đo I2S0 vào ES8311:
   - GPIO13: MCLK ~11.2896 MHz.
   - GPIO12: BCK.
   - GPIO10: LRCK ~44.1 kHz.
   - GPIO9: SDIN có data khi log P4 bảo `AUDIO`.

2. Đo analog ES8311:
   - Đo trên OUTP/OUTN trước tụ ghép.
   - Đo sau tụ ghép C85/C86 ra nét OUTP/OUTN/J1.
   - Nếu I2S0 có data nhưng OUTP/OUTN không có waveform, gần như chắc là ES8311 init/mute/output path.

3. Đo PA path nếu test speaker công suất:
   - GPIO53 `PA_CTRL` = HIGH.
   - `AND_PA_CTRL` có thay đổi theo EarPhone_Detect không.
   - VCC_5V cấp cho NS4150B có đủ không.
   - PA_OUTL+/PA_OUTL- có waveform không.

4. Kiểm tra loại loa/jack:
   - J1 là đường audio/headphone, không phải chắc chắn là speaker power out.
   - Nếu dùng loa passive, nên test qua connector speaker/PA đúng trên board.
   - Nếu dùng loa active 3.5 mm, cần xác nhận pinout J1/OUTP/OUTN có phù hợp với input L/R/GND của loa.

## 6. Test Không Có Oscilloscope

Nếu chỉ có speaker/tai nghe jack 3.5 mm, cách test tốt nhất là tách Bluetooth ra khỏi bài toán và cho ESP32-P4 tự phát test tone nội bộ ra I2S0 -> ES8311 -> jack J1.

Dùng prompt ý tưởng sau để tạo một chế độ test tạm thời:

```text
Hãy thêm một chế độ test tạm thời cho firmware ESP32-P4 để kiểm tra jack 3.5mm J1 mà không cần ESP32 Bluetooth và không cần oscilloscope.

Mục tiêu:
- ESP32-P4 tự phát test tone ra I2S0 -> ES8311 -> jack 3.5mm.
- Không dùng input Bluetooth/I2S2.
- Không sửa kiến trúc lâu dài, chỉ tạo test code để bật/tắt.
- Phát tone đủ để nghe qua speaker/loa active 3.5mm.

Yêu cầu kỹ thuật:
- Dùng đúng hardware hiện tại:
  - Codec: ES8311, I2C address 0x18
  - I2C: SDA GPIO7, SCL GPIO8
  - I2S0 TX -> ES8311:
    - MCLK GPIO13
    - BCK GPIO12
    - LRCK/WS GPIO10
    - DOUT GPIO9
  - Sample rate 44100 Hz
  - 16-bit stereo
- Trong app_init(), sau khi init I2C, ES8311 và I2S0, thay vì start audio_forward_task, chạy vòng lặp phát test tone.
- Test tone nên là 1 kHz sine hoặc square wave, volume vừa phải, ví dụ biên độ 8000-12000 trên int16_t.
- Ghi liên tục buffer stereo L/R giống nhau bằng hàm bsp_i2s_dac_write().
- Log mỗi 2 giây: số bytes đã write, trạng thái written == sizeof(buffer), và hướng dẫn "nếu nghe tone thì jack/ES8311 output hoạt động".
- Có macro bật/tắt, ví dụ:
  #define ENABLE_JACK_TEST_TONE 1
  Khi macro = 0 thì firmware chạy lại audio forward bình thường.

Yêu cầu chẩn đoán:
- Nếu speaker nghe tone: kết luận jack 3.5mm + ES8311 output path cơ bản hoạt động.
- Nếu không nghe tone nhưng I2S write vẫn OK: nghi vấn ES8311 init/register output route/mute hoặc speaker/jack không phù hợp.
- Nếu I2S write lỗi: nghi vấn I2S0 init hoặc driver.

Chỉ chỉnh các file cần thiết, ưu tiên sửa tối thiểu trong app_main_logic.c hoặc app_audio.c. Không thay đổi kết nối ESP32-BT.
```

Lưu ý khi test:

- Nên dùng loa active 3.5 mm hoặc tai nghe có dây.
- Không nên kết luận với loa passive cắm thẳng vào jack, vì nó có thể im hoặc rất nhỏ dù output codec vẫn hoạt động.
- Đặt volume loa vừa phải trước khi flash firmware test tone.
- Nếu nghe được tone nội bộ nhưng vẫn không nghe Bluetooth, lỗi nằm ở đường forward buffer/I2S format giữa I2S2 RX và I2S0 TX.
- Nếu không nghe được tone nội bộ, lỗi nằm ở ES8311 init, I2S0 TX, analog output hoặc jack/speaker.

## 7. Đề Xuất Hướng Sửa Sau Khi Review

Chưa sửa code trong lần này. Nếu chấp nhận sửa firmware, nên làm theo thứ tự ít rủi ro:

1. Thêm readback/dump register ES8311 sau init để biết giá trị thực tế.
2. Đổi init ES8311 theo driver tham chiếu:
   - Sau reset ghi `REG00 = 0x80`.
   - `REG01 = 0x3F` khi dùng MCLK pin.
   - `REG09/0A = 0x0C` cho 16-bit.
   - Thêm `REG37 = 0x08`.
   - Xem lại `REG0E`, `REG0F`, `REG10`, `REG11` theo datasheet/driver chuẩn.
3. Thêm log/checkpoint cho `bsp_i2s_dac_write()` và tùy chọn test tone nội bộ trên I2S0, để tách lỗi BT input khỏi lỗi ES8311 output.
4. Nếu vẫn im, do hardware OUTP/OUTN và PA/J1 như mục 5.

## 8. Nguồn Đối Chiếu

- Local code:
  - `C_code/micro-fox-m4-esp32p4-main/BSP/bsp_es8311/src/bsp_es8311.c`
  - `C_code/micro-fox-m4-esp32p4-main/BSP/bsp_i2s/src/bsp_i2s.c`
  - `C_code/micro-fox-m4-esp32p4-main/Application/app_audio/src/app_audio.c`
  - `LOG_ESP32P4.md`
- Schematic:
  - `ESP32-P4-WIFI6-DEV-KIT-datasheet.pdf`
  - Screenshot `Codec`
  - Screenshot `PA&SPEAKER&MIC`
- Espressif ES8311 component registry:
  - https://components.espressif.com/components/espressif/es8311/versions/1.0.0~1/readme
- Espressif ES8311 driver source:
  - https://github.com/espressif/esp-bsp/tree/4dabefca0599b2249d356cb6a08268dd5e56bbaf/components/es8311
- ESPHome ES8311 implementation, dùng làm đối chiếu phụ:
  - https://api-docs-dev.esphome.io/es8311_8cpp_source
