# Gợi ý Test Audio Output Jack 3.5mm ESP32-P4

Ngày lập: 2026-05-16

## Mục tiêu

Xác định xem âm thanh đã đi đúng luồng nội bộ từ ESP32-P4 tới ES8311 và ra jack 3.5mm hay chưa, đồng thời kiểm tra cấu hình chân GPIO và kết nối I2S.

Nội dung báo cáo này đề xuất:
- một chế độ test tone nội bộ tách khỏi luồng Bluetooth/I2S2
- các log cần bổ sung ở từng đoạn đường tín hiệu
- cách chẩn đoán theo kết quả nghe được hoặc không nghe được

## 1. Ý tưởng chung

Hiện tại luồng audio trong firmware là:

```text
I2S2 RX trên P4 (ESP32-BT) -> buffer forward -> I2S0 TX -> ES8311 -> OUTP/OUTN -> jack J1 / PA path
```

Để tách lỗi, cần thêm một chế độ test nội bộ chỉ chạy:

```text
I2S0 TX -> ES8311 -> jack J1
```

và so sánh với luồng bình thường:

```text
I2S2 RX -> I2S0 TX -> ES8311 -> jack J1
```

## 2. Vị trí nên chỉnh sửa

Chỉ thay đổi tối thiểu trong 2 file chính:
- `C_code/micro-fox-m4-esp32p4-main/Application/app_main/src/app_main_logic.c`
- `C_code/micro-fox-m4-esp32p4-main/Application/app_audio/src/app_audio.c`

Ngoài ra, có thể thêm log ở:
- `C_code/micro-fox-m4-esp32p4-main/BSP/bsp_es8311/src/bsp_es8311.c`
- `C_code/micro-fox-m4-esp32p4-main/BSP/bsp_i2s/src/bsp_i2s.c`

## 3. Thêm macro bật/tắt test tone

Trong `app_main_logic.c` hoặc `app_audio.c`, khai báo:

```c
#define ENABLE_JACK_TEST_TONE 1
```

Ý nghĩa:
- `1`: chạу chế độ test tone nội bộ và không khởi tạo task forward BT
- `0`: chạу luồng audio bình thường như hiện tại

## 4. Quy trình khởi tạo đề xuất

Trong `app_init()`:
1. Khởi tạo I2C (`bsp_i2c_init()`) - ESP32-P4 điều khiển ES8311
2. Khởi tạo ES8311 (`bsp_es8311_init()`) trước khi bật I2S
3. Khởi tạo I2S (`bsp_i2s_init()`) với cấu hình:
   - I2S0 Master TX → ES8311 SDIN
   - I2S2 Slave RX ← ESP32-WROOM-32E
4. Bật `PA_CTRL` sau khi I2S sẵn sàng
5. Nếu test tone thì start task phát tone; nếu không thì start task forward audio

## 5. Gợi ý thiết kế task test tone nội bộ

Tạo một task mới trong `app_audio.c`:
- tên: `audio_tone_test_task`
- buffer: `AUDIO_BUF_FRAMES = 256` stereo → `AUDIO_BUF_BYTES = 1024`
- nội dung buffer: cả kênh L/R giống nhau
- tần số test: 1 kHz
- biên độ: `8000 .. 12000` trên `int16_t`
- gọi `bsp_i2s_dac_write()` để gửi xuống I2S0
- log mỗi vòng hoặc mỗi 2 giây trạng thái write

### Ví dụ nội dung buffer

- Sine wave 1 kHz:
  - `sample = 12000 * sin(2 * pi * freq * i / 44100)`
- Hoặc square wave 1 kHz:
  - `sample = (i % period < period/2) ? 12000 : -12000`

### Log cần có

- `Tone test started on I2S0 -> ES8311`
- `tone write ret=%d written=%u/%u`
- `if (written != AUDIO_BUF_BYTES) log warning` 
- `if (ret != ESP_OK) log error`

## 6. Log startup và xác nhận chân GPIO

Bổ sung log ngay trong `app_main_logic.c` sau khi init:
- `I2C initialized on SDA=GPIO7 SCL=GPIO8`
- `ES8311 configured via I2C`
- `I2S initialized: I2S0 TX→ES8311 (13/12/10/9), I2S2 RX←BT (46/47/48)`
- `PA_Ctrl GPIO53 HIGH — NS4150B amp enabled`
- `Mode: JACK_TEST_TONE` hoặc `Mode: AUDIO_FORWARD`

Thêm log kiểm tra define pin từ `bsp_config.h`:

```c
ESP_LOGI(TAG, "Pin mapping: I2S0 BCK=%d WS=%d DOUT=%d MCLK=%d", BSP_I2S0_BCK_IO, BSP_I2S0_WS_IO, BSP_I2S0_DOUT_IO, BSP_I2S_MCLK_IO);
ESP_LOGI(TAG, "Pin mapping: I2S2 BCK=%d WS=%d DIN=%d", BSP_I2S2_BCK_IO, BSP_I2S2_WS_IO, BSP_I2S2_DIN_IO);
```

## 7. Log kiểm tra ES8311 init chi tiết

Trong `bsp_es8311_init()` nên có các checkpoint log:
- `ES8311 RESET sequence done`
- `ES8311 clock regs OK`
- `ES8311 serial port regs OK`
- `ES8311 power regs OK`
- `ES8311 DAC regs OK`

Nếu có thể, thêm readback các register quan trọng sau init:
- `REG00`
- `REG09`
- `REG0A`
- `REG37`
- `REG11`
- `REG44`

Ví dụ:

```c
uint8_t val;
ESP_ERROR_CHECK(es8311_read_reg(ES8311_RESET_REG00, &val));
ESP_LOGI(TAG, "ES8311 REG00=0x%02X", val);
```

## 8. Log kiểm tra I2S0 đường xuất

Trong `bsp_i2s_init()` hoặc task test tone, kiểm tra transition trên chân I2S0:
- `BSP_I2S0_BCK_IO = 12`
- `BSP_I2S0_WS_IO = 10`

Gợi ý đoạn check nhanh:

```c
int transitions = 0;
int prev = gpio_get_level(BSP_I2S0_BCK_IO);
for (int i = 0; i < 64; i++) {
    esp_rom_delay_us(1);
    int cur = gpio_get_level(BSP_I2S0_BCK_IO);
    if (cur != prev) { transitions++; prev = cur; }
}
ESP_LOGI(TAG, "CHK0 I2S0 BCK12 transitions/64us=%d", transitions);
```

Nếu BCK/WS không đổi, I2S0 không phát đúng.

## 9. Log `bsp_i2s_dac_write()` cần thiết

Đây là điểm nối quan trọng giữa I2S0 và ES8311.
- Log `ret` của `bsp_i2s_dac_write()`
- Log `written` và so sánh với `bytes_read` hoặc `AUDIO_BUF_BYTES`
- Nếu `written != expected` thì nghi I2S0/GPIO/kết nối sai
- Nếu `ret != ESP_OK` thì nghi driver I2S hoặc cài đặt kênh

## 10. Log đường BT và forwarding hiện có

Task hiện có `audio_forward_task()` đã tốt, nên giữ và có thể mở rộng như sau:
- `CHK3 CLK probe` (BCK/WS transitions)
- `CHK3 DIN probe` (GPIO48 transitions)
- `LINK I2S UP/DOWN`
- `CHK3 I2S2 RX` với `L=.. R=.. peak=.. AUDIO ✓`

Những log này cho biết rõ:
- tín hiệu BT lên đến P4 có clock hay không
- data trên GPIO48 có thay đổi không
- dữ liệu buffer có phải audio thật hay chỉ noise

## 11. Chuỗi chẩn đoán theo kết quả

### Trường hợp A: Nghe được tone nội bộ

Kết luận:
- I2S0 → ES8311 → jack J1 hoạt động
- ES8311 init / route output cơ bản OK

Nên kiểm tra tiếp:
- luồng `I2S2 RX -> I2S0 TX`
- sự khác biệt giữa format/data từ BT với tone
- `audio_forward_task()` và `bsp_i2s_bt_read()`

### Trường hợp B: Không nghe tone nhưng `bsp_i2s_dac_write()` OK

Kết luận:
- I2S0 driver có thể đã hoạt động
- rất có thể ES8311 config sai hoặc DAC mute / đường output khoá

Nên kiểm tra:
- `REG00 = 0x80` power-on
- `REG09/REG0A` 16-bit
- `REG37 = 0x08`
- `REG11` DAC/HP on
- `REG44` hoặc register route output đúng

### Trường hợp C: Không nghe tone và `bsp_i2s_dac_write()` lỗi

Kết luận:
- lỗi nằm ở I2S0 khởi tạo, chân GPIO hoặc driver
- có thể chân MCLK/BCK/WS/DOUT sai định nghĩa

Nên kiểm tra:
- pin mapping I2S0 trong `bsp_config.h`
- `BSP_I2S0_BCK_IO`, `BSP_I2S0_WS_IO`, `BSP_I2S0_DOUT_IO`, `BSP_I2S_MCLK_IO`
- log transitions trên chân BCK/WS

## 12. Kiểm tra chân/GPIO/kết nối theo report

Phải xác nhận các chân sau là đúng với phần cứng hiện tại:
- I2C: `GPIO7` = SDA, `GPIO8` = SCL
- I2S0 → ES8311:
  - `GPIO13` = MCLK
  - `GPIO12` = BCK
  - `GPIO10` = WS/LRCK
  - `GPIO9`  = DOUT/SDIN
- I2S2 ← ESP32-BT:
  - `GPIO46` = BCK
  - `GPIO47` = WS
  - `GPIO48` = DIN
- `GPIO53` = `PA_CTRL`

Nếu cắm tai nghe jack 3.5 mm thì cần lưu ý:
- jack J1 là ngõ audio/headphone, không nhất thiết là output công suất speaker
- loa passive cắm thẳng vào jack có thể im dù codec hoạt động
- nên dùng tai nghe hoặc loa active 3.5 mm để test

## 13. Gợi ý sửa tối thiểu

Ưu tiên:
1. Thêm task test tone trong `app_audio.c`
2. Thêm macro chọn chế độ trong `app_main_logic.c`
3. Thêm log startup, log pin mapping và log I2S0 transitions
4. Thêm log checkpoint trong `bsp_es8311_init()`
5. Giữ nguyên `audio_forward_task()` hiện tại cho đường Bluetooth

## 14. Khi nào nên đánh giá lại

- Nếu nghe được tone nội bộ nhưng vẫn không nghe audio Bluetooth, lỗi sẽ nằm ở đường forward `I2S2 → I2S0` hoặc khác biệt format giữa BT và ES8311.
- Nếu không nghe được tone nội bộ, lỗi nằm ở ES8311 init, I2S0 TX, analog output hoặc jack/speaker.

---

File này là kế hoạch test và log chi tiết để kiểm tra luồng audio nội bộ và định vị lỗi output jack 3.5mm.
