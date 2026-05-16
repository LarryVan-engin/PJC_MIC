I (85674) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (85674) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (85674) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (85684) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (90684) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (90684) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (90684) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (90694) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (95694) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (95694) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (95694) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (95704) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
ets Jul 29 2019 12:21:46

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0040,len:6376
load:0x40078000,len:15900
ho 0 tail 12 room 4
load:0x40080400,len:3920
entry 0x40080644
I (29) boot: ESP-IDF v6.0-beta1-1452-g48e7e0618d-dir 2nd stage bootloader
I (29) boot: compile time May 16 2026 14:17:42
I (29) boot: Multicore bootloader
I (33) boot: chip revision: v3.1
I (36) boot.esp32: SPI Speed      : 40MHz
I (39) boot.esp32: SPI Mode       : DIO
I (43) boot.esp32: SPI Flash Size : 4MB
I (46) boot: Enabling RNG early entropy source...
I (51) boot: Partition Table:
I (53) boot: ## Label            Usage          Type ST Offset   Length
I (60) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (66) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (73) boot:  2 factory          factory app      00 00 00010000 00100000
I (79) boot: End of partition table
I (83) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1ffbch (131004) map
I (137) esp_image: segment 1: paddr=0002ffe4 vaddr=3ffbdb60 size=00034h (    52) load
I (137) esp_image: segment 2: paddr=00030020 vaddr=400d0020 size=76614h (484884) map
I (313) esp_image: segment 3: paddr=000a663c vaddr=3ffbdb94 size=04ad8h ( 19160) load
I (321) esp_image: segment 4: paddr=000ab11c vaddr=40080000 size=15100h ( 86272) load
I (356) esp_image: segment 5: paddr=000c0224 vaddr=50000000 size=00028h (    40) load
I (367) boot: Loaded app from partition at offset 0x10000
I (368) boot: Disabling RNG early entropy source...
I (378) cpu_start: Multicore app
I (386) cpu_start: GPIO 3 and 1 are used as console UART I/O pins
I (387) cpu_start: Pro cpu start user code
I (387) cpu_start: cpu freq: 160000000 Hz
I (389) app_init: Application information:
I (392) app_init: Project name:     micro-fox-esp32-bluetooth
I (398) app_init: App version:      cd07e08-dirty
I (402) app_init: Compile time:     May 16 2026 16:30:55
I (407) app_init: ELF file SHA256:  e0705ec1c...
I (412) app_init: ESP-IDF:          v6.0-beta1-1452-g48e7e0618d-dir
I (418) efuse_init: Min chip rev:     v1.0
I (421) efuse_init: Max chip rev:     v3.99 
I (425) efuse_init: Chip rev:         v3.1
I (430) heap_init: Initializing. RAM available for dynamic allocation:
I (436) heap_init: At 3FFAFF10 len 000000F0 (0 KiB): DRAM
I (441) heap_init: At 3FFB6388 len 00001C78 (7 KiB): DRAM
I (446) heap_init: At 3FFB9A20 len 00004108 (16 KiB): DRAM
I (451) heap_init: At 3FFCAC30 len 000153D0 (84 KiB): DRAM
I (456) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (462) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (467) heap_init: At 40095100 len 0000AF00 (43 KiB): IRAM
I (474) spi_flash: detected chip: generic
I (476) spi_flash: flash io: dio
I (480) coexist: coex firmware version: 093e3d2
I (484) main_task: Started on CPU0
I (494) main_task: Calling app_main()
I (494) fox-m4-bt: FOX M4 - ESP32 Bluetooth Companion starting...
I (494) app_main: Initializing Bluetooth Companion...
I (514) bsp_i2s: Initializing I2S Master Mode (BT drives BCK/WS)...
I (514) bt_sink: Initializing A2DP Sink: FOX-M4-AUDIO
I (514) BTDM_INIT: BT controller compile version [c28b205]
I (514) BTDM_INIT: Bluetooth MAC: 78:1c:3c:b7:d6:76
I (524) phy_init: phy_version 4863,a3a4459,Oct 28 2025,14:30:06
W (1124) BT_BTC: A2DP Enable without AVRC
I (1134) app_main: Bluetooth Companion Ready. Search for 'FOX-M4-AUDIO'
I (5514) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (5514) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (5514) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (5524) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (10524) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (10524) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (10524) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (10534) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (15534) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (15534) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (15534) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (15544) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (20544) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (20544) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (20544) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (20554) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (25554) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (25554) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (25554) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (25564) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (30564) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (30564) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (30564) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (30574) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (35574) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (35574) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (35574) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (35584) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (40584) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (40584) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (40584) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (40594) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (45594) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (45594) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (45594) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (45604) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (50604) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (50604) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (50604) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (50614) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (55614) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (55614) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (55614) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (55624) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
W (60184) BT_HCI: hcif conn complete: hdl 0x80, st 0x0
I (60184) bt_sink: ACL connected — waiting for A2DP profile
I (60624) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (60624) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (60624) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (60634) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (60634) bt_sink: Auth success: DESKTOP-V5SRC84
W (61374) BT_APPL: new conn_srvc id:19, app_id:0
I (61374) bt_sink: A2DP Connected
W (61384) BT_BTC: AVRC not Init, not using it.
I (61644) BT_LOG: bta_av_link_role_ok hndl:x41 role:1 conn_audio:x1 bits:1 features:x8400

W (61654) BT_APPL: new conn_srvc id:19, app_id:1
I (61654) bt_sink: A2DP Streaming Started
I (65634) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (65644) app_main: [CHK1 A2DP→buf ] cb=680 KB  drop=0 B  L=-79 R=-182
I (65644) app_main: [CHK2 buf→I2S  ] recv=678 KB  sent=678 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (65654) app_main: [LINK TX ] BT Master TX active ✓ (slave confirmation is on P4 [LINK I2S])
I (65664) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (70664) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (70664) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-21 R=-124
I (70664) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (70674) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (75684) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (75684) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=0 R=-2
I (75684) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (75694) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (80694) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (80694) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=336 R=-263
I (80694) app_main: [CHK2 buf→I2S  ] recv=862 KB  sent=862 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (80704) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (85714) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (85714) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-1251 R=-597
I (85714) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (85724) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (90734) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (90734) app_main: [CHK1 A2DP→buf ] cb=868 KB  drop=0 B  L=-1531 R=-1136
I (90734) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (90744) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (95754) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (95754) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=256 R=96
I (95754) app_main: [CHK2 buf→I2S  ] recv=862 KB  sent=862 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (95764) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (100764) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (100764) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-438 R=-192
I (100774) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (100784) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (105784) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (105784) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-26 R=313
I (105784) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (105794) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (110794) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (110794) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=315 R=733
I (110804) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (110814) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (115814) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (115814) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-833 R=-1552
I (115824) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (115824) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (120844) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (120844) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-70 R=25
I (120844) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (120854) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (125854) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (125854) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=459 R=1116
I (125864) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (125864) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (130874) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (130874) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-485 R=281
I (130874) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (130884) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (135884) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (135884) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-842 R=618
I (135894) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (135904) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (140904) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (140904) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=509 R=59
I (140904) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (140914) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (143964) bt_sink: A2DP Streaming Stopped
I (145984) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (145984) app_main: [CHK1 A2DP→buf ] cb=520 KB  drop=0 B  L=0 R=0
I (145984) app_main: [CHK2 buf→I2S  ] recv=530 KB  sent=530 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (145994) app_main:   ↳ Audio path OK on ESP32-BT side ✓
W (147154) BT_HCI: hci cmd send: sniff: hdl 0x80, intv(30 54)
W (147184) BT_HCI: hcif mode change: hdl 0x80, mode 2, intv 54, status 0x0
I (150994) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (150994) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (150994) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (151004) app_main: [LINK TX ] BT Master TX not active yet (no A2DP payload or I2S write issue)
W (151004) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (156014) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (156014) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (156014) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (156024) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (161024) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (161024) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (161024) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (161034) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
I (166034) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (166034) app_main: [CHK1 A2DP→buf ] cb=0 KB  drop=0 B  L=0 R=0
I (166034) app_main: [CHK2 buf→I2S  ] recv=0 KB  sent=0 KB  short=0  err=0  last_err=ESP_OK(0x0)
W (166044) app_main:   ↳ No audio from BT stack — A2DP not streaming yet
W (167424) BT_HCI: hcif mode change: hdl 0x80, mode 0, intv 0, status 0x0
I (167424) BT_LOG: bta_av_link_role_ok hndl:x41 role:1 conn_audio:x1 bits:1 features:x8400

I (167434) bt_sink: A2DP Streaming Started
I (171044) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (171044) app_main: [CHK1 A2DP→buf ] cb=620 KB  drop=0 B  L=-695 R=-272
I (171044) app_main: [CHK2 buf→I2S  ] recv=618 KB  sent=618 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (171054) app_main: [LINK TX ] BT Master TX active ✓ (slave confirmation is on P4 [LINK I2S])
I (171064) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (176074) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (176074) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-256 R=-480
I (176074) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (176084) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (181094) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (181094) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-63 R=341
I (181094) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (181104) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (186104) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (186104) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-707 R=60
I (186114) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (186124) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (191124) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (191124) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=424 R=-506
I (191124) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (191134) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (196134) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (196134) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-455 R=97
I (196144) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (196154) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (201154) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (201154) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-252 R=-963
I (201154) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (201164) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (206164) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (206164) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=148 R=297
I (206174) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (206184) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (211184) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (211194) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=844 R=507
I (211194) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (211204) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (216204) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (216204) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-83 R=-771
I (216214) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (216224) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (221224) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (221224) app_main: [CHK1 A2DP→buf ] cb=868 KB  drop=0 B  L=-387 R=1007
I (221224) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (221234) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (226244) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (226244) app_main: [CHK1 A2DP→buf ] cb=856 KB  drop=0 B  L=185 R=-784
I (226244) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (226254) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (231264) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (231264) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=0 R=-1338
I (231274) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (231274) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (236284) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (236284) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-897 R=-1209
I (236284) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (236294) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (241314) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (241314) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-441 R=835
I (241314) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (241324) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (246334) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (246334) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-606 R=-345
I (246344) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (246344) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (251354) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (251354) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-632 R=281
I (251354) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (251374) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (256374) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (256374) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=940 R=1038
I (256374) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (256384) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (261394) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (261394) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-1354 R=-240
I (261394) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (261404) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (266414) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (266414) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-570 R=311
I (266414) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (266424) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (271444) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (271444) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-186 R=218
I (271444) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (271454) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (276464) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (276464) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-603 R=1202
I (276464) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (276474) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (281474) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (281474) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-19 R=-770
I (281474) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (281484) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (286494) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (286494) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-275 R=-1089
I (286494) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (286504) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (291504) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (291504) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-450 R=-814
I (291504) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (291514) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (296524) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (296524) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=531 R=761
I (296524) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (296534) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (301534) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (301534) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1300 R=475
I (301544) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (301544) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (306554) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (306554) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-176 R=-763
I (306554) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (306564) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (311564) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (311564) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-42 R=-43
I (311574) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (311574) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (316594) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (316594) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=34 R=15
I (316594) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (316614) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (321614) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (321614) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1 R=34
I (321624) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (321634) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (326634) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (326634) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=35 R=25
I (326634) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (326644) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (331654) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (331654) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=48 R=137
I (331654) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (331664) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (336674) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (336674) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=76 R=-57
I (336684) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (336694) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (341694) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (341694) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=3 R=9
I (341694) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (341714) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (346724) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (346724) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-823 R=-802
I (346724) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (346734) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (351744) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (351744) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-128 R=-58
I (351744) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (351754) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (356754) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (356764) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=340 R=148
I (356764) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (356774) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (361774) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (361774) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=869 R=1517
I (361784) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (361794) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (366794) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (366794) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-136 R=-108
I (366794) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (366814) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (371814) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (371814) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-270 R=-245
I (371824) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (371834) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (376834) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (376834) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1407 R=1335
I (376834) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (376844) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (381854) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (381864) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=1103 R=1240
I (381864) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (381874) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (386884) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (386884) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1324 R=444
I (386884) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (386904) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (391904) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (391904) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=294 R=-331
I (391904) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (391914) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (396914) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (396914) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=2633 R=429
I (396914) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (396934) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (401934) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (401934) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1932 R=1977
I (401934) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (401944) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (406944) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (406944) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=892 R=623
I (406954) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (406954) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (411964) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (411964) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=1023 R=172
I (411964) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (411974) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (416974) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (416974) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-172 R=-248
I (416984) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (416994) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (421994) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (421994) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=644 R=668
I (421994) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (422004) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (427004) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (427004) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-232 R=-552
I (427014) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (427014) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (432024) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (432024) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-4081 R=-595
I (432024) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (432034) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (437044) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (437044) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-28 R=328
I (437054) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (437064) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (442064) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (442064) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=97 R=201
I (442064) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (442074) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (447084) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (447084) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=92 R=177
I (447084) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (447104) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (452104) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (452104) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-401 R=-476
I (452114) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (452114) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (457124) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (457124) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-26 R=-48
I (457124) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (457134) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (462154) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (462154) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-42 R=-19
I (462154) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (462164) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (467174) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (467174) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-79 R=-6
I (467174) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (467184) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (472194) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (472194) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=52 R=-87
I (472194) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (472204) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (477214) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (477214) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-232 R=426
I (477224) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (477224) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (482224) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (482224) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=18 R=13
I (482224) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (482234) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (487244) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (487244) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=160 R=359
I (487244) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (487254) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (492254) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (492254) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=377 R=212
I (492254) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (492264) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (497274) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (497274) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-451 R=-666
I (497274) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (497284) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (502284) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (502294) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-396 R=-62
I (502294) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (502304) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (507304) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (507304) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-202 R=-202
I (507314) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (507314) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (512314) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (512324) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-728 R=-888
I (512324) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (512334) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (517334) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (517334) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=847 R=797
I (517344) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (517344) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (522364) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (522364) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=277 R=-20
I (522364) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (522374) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (527374) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (527374) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=298 R=621
I (527384) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (527394) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (532394) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (532394) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-156 R=-105
I (532394) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (532404) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (537414) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (537424) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=670 R=426
I (537424) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (537434) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (542434) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (542434) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-623 R=-472
I (542444) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (542444) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (547464) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (547464) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=714 R=215
I (547464) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (547474) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (552484) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (552484) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-66 R=-162
I (552494) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (552504) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (557504) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (557504) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-376 R=-633
I (557504) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (557514) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (562524) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (562524) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=349 R=475
I (562524) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (562534) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (567544) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (567544) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=374 R=937
I (567544) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (567554) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (572564) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (572564) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=689 R=570
I (572564) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (572574) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (577594) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (577594) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=657 R=310
I (577594) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (577604) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (582614) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (582614) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-1005 R=-801
I (582614) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (582624) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (587634) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (587634) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-164 R=-653
I (587634) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (587644) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (592654) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (592654) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1176 R=877
I (592654) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (592664) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (597664) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (597664) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-48 R=305
I (597664) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (597674) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (602684) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (602684) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=417 R=508
I (602684) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (602694) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (607694) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (607694) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-255 R=-409
I (607694) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (607704) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (612714) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (612714) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=901 R=1065
I (612714) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (612724) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (617724) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (617734) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=268 R=1210
I (617734) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (617744) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (622744) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (622744) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=1023 R=998
I (622744) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (622754) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (627754) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (627764) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=318 R=-192
I (627764) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (627774) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (632784) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (632784) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=917 R=1025
I (632784) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (632794) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (637804) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (637804) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=321 R=342
I (637804) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (637814) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (639134) bt_sink: A2DP Streaming Stopped
I (639554) BT_LOG: bta_av_link_role_ok hndl:x41 role:1 conn_audio:x1 bits:1 features:x8400

I (639564) bt_sink: A2DP Streaming Started
I (642824) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (642824) app_main: [CHK1 A2DP→buf ] cb=776 KB  drop=0 B  L=257 R=592
I (642824) app_main: [CHK2 buf→I2S  ] recv=784 KB  sent=784 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (642834) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (647844) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (647844) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=389 R=526
I (647844) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (647854) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (652854) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (652854) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-110 R=-145
I (652864) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (652874) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (657874) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (657874) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-124 R=-143
I (657874) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (657884) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (662884) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (662884) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-136 R=-180
I (662894) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (662904) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (667904) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (667904) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-601 R=-787
I (667904) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (667914) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (672914) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (672924) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=404 R=297
I (672924) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (672934) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (677934) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (677934) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=471 R=235
I (677934) app_main: [CHK2 buf→I2S  ] recv=862 KB  sent=862 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (677944) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (682954) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (682954) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=437 R=171
I (682954) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (682964) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (687974) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (687974) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-389 R=-566
I (687974) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (687984) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (692984) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (692984) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=113 R=278
I (692984) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (692994) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (698004) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (698004) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=27 R=-38
I (698004) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (698014) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (703024) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (703024) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-58 R=-31
I (703024) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (703034) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (708034) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (708034) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=0 R=0
I (708034) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (708044) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (713054) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (713054) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=228 R=326
I (713054) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (713064) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (718064) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (718064) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=268 R=234
I (718064) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (718074) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (723084) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (723084) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-164 R=223
I (723084) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (723094) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (728094) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (728094) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=161 R=409
I (728104) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (728104) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (733114) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (733114) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-191 R=-224
I (733114) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (733124) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (738124) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (738124) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-230 R=-290
I (738134) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (738134) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (743144) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (743144) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=237 R=96
I (743144) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (743154) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (748154) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (748154) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=245 R=893
I (748164) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (748164) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (753174) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (753174) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-92 R=-174
I (753174) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (753184) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (758194) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (758194) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=-157 R=137
I (758204) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (758214) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (763214) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (763214) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-357 R=-349
I (763214) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (763224) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (768234) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (768234) app_main: [CHK1 A2DP→buf ] cb=864 KB  drop=0 B  L=363 R=-43
I (768234) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (768244) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (773254) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (773254) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-123 R=-215
I (773264) app_main: [CHK2 buf→I2S  ] recv=866 KB  sent=866 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (773264) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (778274) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (778274) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=241 R=96
I (778274) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (778284) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (783294) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (783294) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-459 R=-700
I (783294) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (783304) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (788314) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (788314) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-348 R=-626
I (788314) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (788324) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (793324) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (793324) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-293 R=-329
I (793324) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (793334) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (798344) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (798344) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-22 R=201
I (798344) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (798354) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (803354) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (803354) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=904 R=819
I (803354) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (803364) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (808374) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (808374) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=427 R=271
I (808374) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (808384) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (813384) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=1
I (813384) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=-17 R=-383
I (813394) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (813394) app_main:   ↳ Audio path OK on ESP32-BT side ✓
I (818404) app_main: [CHK0 GPIO      ] BCK(26)=TOGGLE✓(0)  WS(25)=0  DOUT(5)=0
I (818404) app_main: [CHK1 A2DP→buf ] cb=860 KB  drop=0 B  L=574 R=540
I (818404) app_main: [CHK2 buf→I2S  ] recv=864 KB  sent=864 KB  short=0  err=0  last_err=ESP_OK(0x0)
I (818414) app_main:   ↳ Audio path OK on ESP32-BT side ✓
