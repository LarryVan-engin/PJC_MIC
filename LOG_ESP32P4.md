I (10870) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (10870) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (10880) app_audio: [CHK3 I2S2 RX  ] 1400 kbps (~855 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (15890) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=12  WS47 trans/64us=12  CLOCK PRESENT ✓
I (15890) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (15890) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (20910) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (20910) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (20920) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
ESP-ROM:esp32p4-eco2-20240710
Build:Jul 10 2024
rst:0x1 (POWERON),boot:0x30f (SPI_FAST_FLASH_BOOT)
SPI mode:DIO, clock div:2
load:0x4ff342f0,len:0x1968
load:0x4ff29ed0,len:0x186c
load:0x4ff2cbd0,len:0x3630
entry 0x4ff29eda
I (29) boot: ESP-IDF v6.0-beta1-1452-g48e7e0618d-dir 2nd stage bootloader
I (30) boot: compile time May 16 2026 11:27:46
I (30) boot: Multicore bootloader
I (33) boot: chip revision: v1.0
I (35) boot: efuse block revision: v0.3
I (38) boot.esp32p4: SPI Speed      : 40MHz
I (42) boot.esp32p4: SPI Mode       : DIO
I (46) boot.esp32p4: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
[boot-support] WDT configured (P4)
[boot-support] USB switch enabled (GPIO 3 = HIGH)
[boot] Entering flash bridge mode for slave programming
[boot-support] Entering slave bootloader mode
[boot-support] Slave in bootloader mode
[boot] Starting UART flash bridge
[boot-support] UART2: 115200 baud, 8N1, TX=GPIO41, RX=GPIO42
[boot-support] USB Serial/JTAG initialized
[boot-support] Dual-mode bridge active (UART + USB)
[boot-support] Detected UART connection

[boot-support] GPIO0 pressed - exiting bridge
[boot-support] Stats: PC->Slave=1, Slave->PC=0 bytes
[boot-support] Resetting slave to normal mode
[boot-support] Slave reset to normal mode
[boot] Starting master boot sequence
I (498) boot: Partition Table:
I (498) boot: ## Label            Usage          Type ST Offset   Length
I (502) boot:  0 nvs              WiFi data        01 02 0000b000 00006000
I (509) boot:  1 phy_init         RF data          01 01 00011000 00001000
I (515) boot:  2 factory          factory app      00 00 00020000 00100000
I (523) boot: End of partition table
[boot] ESP32 Master-Slave Bootloader
I (529) esp_image: segment 0: paddr=00020020 vaddr=40020020 size=0d15ch ( 53596) map
I (549) esp_image: segment 1: paddr=0002d184 vaddr=30100000 size=00044h (    68) load
I (551) esp_image: segment 2: paddr=0002d1d0 vaddr=4ff00000 size=02e48h ( 11848) load
I (557) esp_image: segment 3: paddr=00030020 vaddr=40000020 size=1fed0h (130768) map
I (590) esp_image: segment 4: paddr=0004fef8 vaddr=4ff02e48 size=0af18h ( 44824) load
I (602) esp_image: segment 5: paddr=0005ae18 vaddr=4ff0dd80 size=022fch (  8956) load
I (609) boot: Loaded app from partition at offset 0x20000
I (610) boot: Disabling RNG early entropy source...
I (623) cpu_start: Multicore app
I (633) cpu_start: GPIO 38 and 37 are used as console UART I/O pins
I (633) cpu_start: Pro cpu start user code
I (633) cpu_start: cpu freq: 360000000 Hz
I (635) app_init: Application information:
I (639) app_init: Project name:     micro-fox-m4-esp32p4
I (644) app_init: App version:      3288fe8-dirty
I (648) app_init: Compile time:     May 16 2026 16:29:47
I (653) app_init: ELF file SHA256:  a7daa0983...
I (657) app_init: ESP-IDF:          v6.0-beta1-1452-g48e7e0618d-dir
I (663) efuse_init: Min chip rev:     v1.0
I (667) efuse_init: Max chip rev:     v1.99 
I (671) efuse_init: Chip rev:         v1.0
I (675) heap_init: Initializing. RAM available for dynamic allocation:
I (682) heap_init: At 4FF11910 len 000296B0 (165 KiB): RETENT_RAM
I (687) heap_init: At 4FF3AFC0 len 00004BF0 (18 KiB): RAM
I (692) heap_init: At 4FF40000 len 00060000 (384 KiB): RAM
I (698) heap_init: At 50108080 len 00007F80 (31 KiB): RTCRAM
I (703) heap_init: At 30100044 len 00001FBC (7 KiB): TCM
I (710) spi_flash: detected chip: generic
I (712) spi_flash: flash io: dio
W (715) spi_flash: Detected size(16384k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (727) sleep_gpio: Configure to isolate all GPIO pins in sleep state
I (733) sleep_gpio: Enable automatic switching of GPIO sleep configuration
I (740) main_task: Started on CPU0
I (760) main_task: Calling app_main()
I (760) fox-m4-main: FOX M4 - ESP32-P4 DSP Mixer starting...
I (760) app_main: FOX M4 Prototype — ESP32-P4 starting
I (760) bsp_i2c: I2C initialized on SDA:7, SCL:8
I (770) bsp_es8311: Initializing ES8311 (44.1 kHz 16-bit, DAC→3.5mm)...
I (770) bsp_i2c: Cached I2C device 0x18 (slot 0)
I (810) bsp_es8311: ES8311 ready — audio plays on 3.5mm AUDIO jack (J1)
W (810) i2s_std: the current bclk division is too small, adjust the bclk division to 8
I (810) bsp_i2s: I2S0 TX→ES8311 (MCLK=13,BCK=12,WS=10,DOUT=9), I2S2 Slave RX←ESP32-BT (BCK=46,WS=47,DIN=48)
I (820) app_main: PA_Ctrl GPIO53 HIGH — NS4150B amp enabled
I (820) app_main: Ready — connect phone via BT to 'FOX-M4-AUDIO', audio plays on J1
I (820) app_audio: Audio forward task running on core 1
I (5840) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=13  CLOCK PRESENT ✓
I (5840) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (5850) app_audio: [LINK CLK ] P4 Slave sees BT Master clocks on GPIO46/47 ✓
I (5850) app_audio: [CHK3 I2S2 RX  ] 1399 kbps (~854 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (10870) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (10870) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (10880) app_audio: [CHK3 I2S2 RX  ] 1400 kbps (~855 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (15890) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (15890) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (15900) app_audio: [CHK3 I2S2 RX  ] 1399 kbps (~854 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (20910) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (20910) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (20920) app_audio: [CHK3 I2S2 RX  ] 1395 kbps (~852 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (25930) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (25930) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (25940) app_audio: [CHK3 I2S2 RX  ] 1395 kbps (~852 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (30950) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (30950) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (30960) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (35970) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=12  WS47 trans/64us=11  CLOCK PRESENT ✓
I (35970) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (35980) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (40990) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (40990) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (41000) app_audio: [CHK3 I2S2 RX  ] 1395 kbps (~852 KB/5s)  L=0 R=0  real_samples=0/160  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (46010) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (46010) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (46020) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (51030) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (51030) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (51040) app_audio: [CHK3 I2S2 RX  ] 1395 kbps (~852 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (56050) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=12  WS47 trans/64us=12  CLOCK PRESENT ✓
I (56050) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (56060) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (61070) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (61070) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (61080) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (66090) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (66090) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (66100) app_audio: [LINK I2S ] UP ✓ BT Master → P4 Slave (clock + data valid)
I (66100) app_audio: [CHK3 I2S2 RX  ] 1233 kbps (~753 KB/5s)  L=8319 R=-480  real_samples=350/352  peak=32742  AUDIO ✓
I (71110) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (71110) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (71120) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=58 R=128  real_samples=504/512  peak=32759  AUDIO ✓
I (76130) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (76130) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
W (76140) app_audio: [LINK I2S ] DOWN ✗ no valid audio payload from BT Master
I (76140) app_audio: [CHK3 I2S2 RX  ] 1318 kbps (~805 KB/5s)  L=0 R=0  real_samples=0/512  peak=2  ← noise (0/±1 only) — floating DIN or no BT clock
I (81160) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (81160) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (81170) app_audio: [LINK I2S ] UP ✓ BT Master → P4 Slave (clock + data valid)
I (81170) app_audio: [CHK3 I2S2 RX  ] 1289 kbps (~787 KB/5s)  L=-19 R=766  real_samples=512/512  peak=32258  AUDIO ✓
I (86180) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (86180) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (86190) app_audio: [CHK3 I2S2 RX  ] 1233 kbps (~753 KB/5s)  L=-243 R=240  real_samples=509/512  peak=32760  AUDIO ✓
I (91200) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (91200) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (91210) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=-143 R=-487  real_samples=351/352  peak=30680  AUDIO ✓
I (96220) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (96220) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (96230) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=-643 R=-1048  real_samples=512/512  peak=32225  AUDIO ✓
I (101240) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (101240) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=31  DATA PRESENT ✓
I (101250) app_audio: [CHK3 I2S2 RX  ] 1169 kbps (~714 KB/5s)  L=-594 R=67  real_samples=415/416  peak=28786  AUDIO ✓
I (106260) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (106260) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (106270) app_audio: [CHK3 I2S2 RX  ] 1020 kbps (~623 KB/5s)  L=334 R=125  real_samples=509/512  peak=32764  AUDIO ✓
I (111280) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (111280) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (111290) app_audio: [CHK3 I2S2 RX  ] 1087 kbps (~664 KB/5s)  L=-448 R=24  real_samples=508/512  peak=31233  AUDIO ✓
I (116300) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (116300) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (116310) app_audio: [CHK3 I2S2 RX  ] 1148 kbps (~701 KB/5s)  L=547 R=347  real_samples=507/512  peak=32761  AUDIO ✓
I (121320) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (121320) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (121330) app_audio: [CHK3 I2S2 RX  ] 1176 kbps (~718 KB/5s)  L=644 R=506  real_samples=505/512  peak=26623  AUDIO ✓
I (126340) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (126340) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=30  DATA PRESENT ✓
I (126350) app_audio: [CHK3 I2S2 RX  ] 1207 kbps (~737 KB/5s)  L=-267 R=-940  real_samples=348/352  peak=32689  AUDIO ✓
I (131360) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (131360) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (131370) app_audio: [CHK3 I2S2 RX  ] 1181 kbps (~721 KB/5s)  L=16400 R=45  real_samples=510/512  peak=32736  AUDIO ✓
I (136380) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=14  CLOCK PRESENT ✓
I (136380) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (136390) app_audio: [CHK3 I2S2 RX  ] 1194 kbps (~729 KB/5s)  L=-430 R=-385  real_samples=510/512  peak=32720  AUDIO ✓
I (141400) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (141400) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=32  DATA PRESENT ✓
I (141410) app_audio: [CHK3 I2S2 RX  ] 1225 kbps (~748 KB/5s)  L=-795 R=-489  real_samples=510/512  peak=32735  AUDIO ✓
I (146420) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (146420) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
W (146430) app_audio: [LINK I2S ] DOWN ✗ no valid audio payload from BT Master
I (146430) app_audio: [CHK3 I2S2 RX  ] 1313 kbps (~802 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (151450) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (151450) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (151460) app_audio: [CHK3 I2S2 RX  ] 1400 kbps (~855 KB/5s)  L=0 R=0  real_samples=1/512  peak=8  ← noise (0/±1 only) — floating DIN or no BT clock
I (156470) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (156470) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (156480) app_audio: [CHK3 I2S2 RX  ] 1395 kbps (~852 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (161490) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (161490) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (161490) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (166510) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (166510) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=0  STUCK — BT GPIO5 not wired to P4 GPIO48?
I (166520) app_audio: [CHK3 I2S2 RX  ] 1397 kbps (~853 KB/5s)  L=0 R=0  real_samples=0/512  peak=0  ← noise (0/±1 only) — floating DIN or no BT clock
I (171530) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (171530) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=29  DATA PRESENT ✓
I (171540) app_audio: [LINK I2S ] UP ✓ BT Master → P4 Slave (clock + data valid)
I (171540) app_audio: [CHK3 I2S2 RX  ] 1251 kbps (~764 KB/5s)  L=280 R=430  real_samples=511/512  peak=32767  AUDIO ✓
I (176550) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (176550) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=19  DATA PRESENT ✓
I (176560) app_audio: [CHK3 I2S2 RX  ] 1222 kbps (~746 KB/5s)  L=-965 R=-469  real_samples=352/352  peak=29690  AUDIO ✓
I (181570) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (181570) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=35  DATA PRESENT ✓
I (181580) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=-201 R=900  real_samples=509/512  peak=32763  AUDIO ✓
I (186590) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (186590) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (186600) app_audio: [CHK3 I2S2 RX  ] 1200 kbps (~733 KB/5s)  L=12278 R=347  real_samples=509/512  peak=32744  AUDIO ✓
I (191610) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (191610) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (191620) app_audio: [CHK3 I2S2 RX  ] 1196 kbps (~730 KB/5s)  L=16498 R=928  real_samples=510/512  peak=32760  AUDIO ✓
I (196630) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (196630) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=19  DATA PRESENT ✓
I (196640) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=449 R=-491  real_samples=352/352  peak=32556  AUDIO ✓
I (201650) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (201650) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (201660) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=-472 R=-1331  real_samples=510/512  peak=32736  AUDIO ✓
I (206670) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (206670) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (206680) app_audio: [CHK3 I2S2 RX  ] 1223 kbps (~747 KB/5s)  L=-1378 R=87  real_samples=509/512  peak=32600  AUDIO ✓
I (211690) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (211690) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (211700) app_audio: [CHK3 I2S2 RX  ] 1202 kbps (~734 KB/5s)  L=134 R=266  real_samples=509/512  peak=32738  AUDIO ✓
I (216710) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=14  CLOCK PRESENT ✓
I (216710) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (216720) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=28933 R=1496  real_samples=510/512  peak=32748  AUDIO ✓
I (221730) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (221730) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=18  DATA PRESENT ✓
I (221740) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=-1565 R=-356  real_samples=511/512  peak=32702  AUDIO ✓
I (226750) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (226750) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (226760) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=-89 R=-199  real_samples=319/320  peak=32736  AUDIO ✓
I (231770) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (231770) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (231780) app_audio: [CHK3 I2S2 RX  ] 1225 kbps (~748 KB/5s)  L=1 R=-285  real_samples=504/512  peak=32737  AUDIO ✓
I (236790) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (236790) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=30  DATA PRESENT ✓
I (236800) app_audio: [CHK3 I2S2 RX  ] 1204 kbps (~735 KB/5s)  L=-158 R=-199  real_samples=508/512  peak=32685  AUDIO ✓
I (241810) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (241810) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=30  DATA PRESENT ✓
I (241820) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-560 R=-253  real_samples=508/512  peak=32743  AUDIO ✓
I (246830) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (246830) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (246840) app_audio: [CHK3 I2S2 RX  ] 1215 kbps (~742 KB/5s)  L=-478 R=-1009  real_samples=160/160  peak=32678  AUDIO ✓
I (251850) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (251850) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (251860) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=32386 R=-314  real_samples=512/512  peak=32620  AUDIO ✓
I (256870) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (256870) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (256880) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=50 R=187  real_samples=509/512  peak=32740  AUDIO ✓
I (261890) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (261890) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (261900) app_audio: [CHK3 I2S2 RX  ] 1214 kbps (~741 KB/5s)  L=-290 R=-1789  real_samples=506/512  peak=32753  AUDIO ✓
I (266910) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (266910) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (266920) app_audio: [CHK3 I2S2 RX  ] 1202 kbps (~734 KB/5s)  L=-509 R=-866  real_samples=509/512  peak=32713  AUDIO ✓
I (271930) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (271930) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (271940) app_audio: [CHK3 I2S2 RX  ] 1217 kbps (~743 KB/5s)  L=-532 R=-80  real_samples=511/512  peak=29568  AUDIO ✓
I (276950) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (276950) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (276960) app_audio: [CHK3 I2S2 RX  ] 1205 kbps (~736 KB/5s)  L=50 R=830  real_samples=510/512  peak=32754  AUDIO ✓
I (281970) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (281970) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (281980) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-874 R=-275  real_samples=510/512  peak=32545  AUDIO ✓
I (286990) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (286990) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (287000) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=55 R=-194  real_samples=508/512  peak=32714  AUDIO ✓
I (292010) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (292010) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (292020) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-34 R=270  real_samples=352/352  peak=32637  AUDIO ✓
I (297030) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (297030) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (297040) app_audio: [CHK3 I2S2 RX  ] 1214 kbps (~741 KB/5s)  L=527 R=484  real_samples=508/512  peak=31228  AUDIO ✓
I (302050) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (302050) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (302060) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=982 R=468  real_samples=352/352  peak=32756  AUDIO ✓
I (307070) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (307070) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (307080) app_audio: [CHK3 I2S2 RX  ] 1204 kbps (~735 KB/5s)  L=416 R=699  real_samples=511/512  peak=32750  AUDIO ✓
I (312090) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (312090) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=13  DATA PRESENT ✓
I (312100) app_audio: [CHK3 I2S2 RX  ] 1255 kbps (~766 KB/5s)  L=18 R=24  real_samples=479/512  peak=32764  AUDIO ✓
I (317110) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (317110) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=13  DATA PRESENT ✓
I (317120) app_audio: [CHK3 I2S2 RX  ] 1330 kbps (~812 KB/5s)  L=64 R=49  real_samples=472/512  peak=32759  AUDIO ✓
I (322130) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (322130) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=14  DATA PRESENT ✓
I (322140) app_audio: [CHK3 I2S2 RX  ] 1295 kbps (~791 KB/5s)  L=-18 R=-41  real_samples=473/512  peak=32750  AUDIO ✓
I (327150) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=12  WS47 trans/64us=12  CLOCK PRESENT ✓
I (327150) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=17  DATA PRESENT ✓
I (327160) app_audio: [CHK3 I2S2 RX  ] 1286 kbps (~785 KB/5s)  L=-62 R=-58  real_samples=485/512  peak=32766  AUDIO ✓
I (332170) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (332170) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (332180) app_audio: [CHK3 I2S2 RX  ] 1236 kbps (~755 KB/5s)  L=-302 R=-138  real_samples=498/512  peak=32761  AUDIO ✓
I (337190) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (337190) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=15  DATA PRESENT ✓
I (337200) app_audio: [CHK3 I2S2 RX  ] 1238 kbps (~756 KB/5s)  L=-156 R=-223  real_samples=504/512  peak=32735  AUDIO ✓
I (342210) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (342210) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=18  DATA PRESENT ✓
I (342220) app_audio: [CHK3 I2S2 RX  ] 1248 kbps (~762 KB/5s)  L=-128 R=-40  real_samples=496/512  peak=32700  AUDIO ✓
I (347230) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (347230) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (347240) app_audio: [CHK3 I2S2 RX  ] 1223 kbps (~747 KB/5s)  L=377 R=475  real_samples=510/512  peak=32767  AUDIO ✓
I (352250) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (352250) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (352260) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=588 R=334  real_samples=512/512  peak=32752  AUDIO ✓
I (357270) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (357270) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (357280) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=120 R=83  real_samples=511/512  peak=28707  AUDIO ✓
I (362290) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=12  WS47 trans/64us=12  CLOCK PRESENT ✓
I (362290) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (362300) app_audio: [CHK3 I2S2 RX  ] 1223 kbps (~747 KB/5s)  L=304 R=61  real_samples=510/512  peak=32709  AUDIO ✓
I (367310) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (367310) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (367320) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-700 R=-781  real_samples=187/192  peak=30725  AUDIO ✓
I (372330) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (372330) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=36  DATA PRESENT ✓
I (372340) app_audio: [CHK3 I2S2 RX  ] 1214 kbps (~741 KB/5s)  L=2095 R=2179  real_samples=510/512  peak=32743  AUDIO ✓
I (377350) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (377350) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (377360) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=704 R=816  real_samples=512/512  peak=27657  AUDIO ✓
I (382370) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (382370) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=29  DATA PRESENT ✓
I (382380) app_audio: [CHK3 I2S2 RX  ] 1205 kbps (~736 KB/5s)  L=75 R=48  real_samples=511/512  peak=32754  AUDIO ✓
I (387390) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (387390) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=40  DATA PRESENT ✓
I (387400) app_audio: [CHK3 I2S2 RX  ] 1217 kbps (~743 KB/5s)  L=-1095 R=-1330  real_samples=510/512  peak=32741  AUDIO ✓
I (392410) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (392410) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (392420) app_audio: [CHK3 I2S2 RX  ] 1194 kbps (~729 KB/5s)  L=-1414 R=-2003  real_samples=506/512  peak=32721  AUDIO ✓
I (397430) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (397430) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=19  DATA PRESENT ✓
I (397440) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-284 R=771  real_samples=510/512  peak=32267  AUDIO ✓
I (402450) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=14  CLOCK PRESENT ✓
I (402450) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=32  DATA PRESENT ✓
I (402460) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-1118 R=-1349  real_samples=509/512  peak=32766  AUDIO ✓
I (407470) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (407470) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=32  DATA PRESENT ✓
I (407480) app_audio: [CHK3 I2S2 RX  ] 1197 kbps (~731 KB/5s)  L=166 R=296  real_samples=510/512  peak=32747  AUDIO ✓
I (412490) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (412490) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (412500) app_audio: [CHK3 I2S2 RX  ] 1196 kbps (~730 KB/5s)  L=370 R=507  real_samples=352/352  peak=32707  AUDIO ✓
I (417510) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (417510) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (417520) app_audio: [CHK3 I2S2 RX  ] 1243 kbps (~759 KB/5s)  L=-323 R=-350  real_samples=505/512  peak=32759  AUDIO ✓
I (422530) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (422530) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (422540) app_audio: [CHK3 I2S2 RX  ] 1217 kbps (~743 KB/5s)  L=-176 R=-183  real_samples=510/512  peak=32709  AUDIO ✓
I (427550) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (427550) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (427560) app_audio: [CHK3 I2S2 RX  ] 1233 kbps (~753 KB/5s)  L=-1637 R=-1665  real_samples=507/512  peak=32724  AUDIO ✓
I (432570) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (432570) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=32  DATA PRESENT ✓
I (432580) app_audio: [CHK3 I2S2 RX  ] 1217 kbps (~743 KB/5s)  L=-536 R=-642  real_samples=512/512  peak=32759  AUDIO ✓
I (437590) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (437590) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (437600) app_audio: [CHK3 I2S2 RX  ] 1215 kbps (~742 KB/5s)  L=383 R=-2104  real_samples=510/512  peak=32551  AUDIO ✓
I (442610) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (442610) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (442620) app_audio: [CHK3 I2S2 RX  ] 1214 kbps (~741 KB/5s)  L=683 R=1223  real_samples=512/512  peak=32271  AUDIO ✓
I (447630) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (447630) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=13  DATA PRESENT ✓
I (447640) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=215 R=-244  real_samples=511/512  peak=29825  AUDIO ✓
I (452650) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (452650) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (452660) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=-244 R=-389  real_samples=511/512  peak=32619  AUDIO ✓
I (457670) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (457670) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=17  DATA PRESENT ✓
I (457680) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=3 R=-16  real_samples=473/512  peak=32764  AUDIO ✓
I (462690) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (462690) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=15  DATA PRESENT ✓
I (462700) app_audio: [CHK3 I2S2 RX  ] 1299 kbps (~793 KB/5s)  L=31 R=5  real_samples=450/512  peak=32764  AUDIO ✓
I (467710) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (467710) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=13  DATA PRESENT ✓
I (467720) app_audio: [CHK3 I2S2 RX  ] 1286 kbps (~785 KB/5s)  L=-24 R=-46  real_samples=456/512  peak=32761  AUDIO ✓
I (472730) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (472730) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (472740) app_audio: [CHK3 I2S2 RX  ] 1346 kbps (~822 KB/5s)  L=208 R=-307  real_samples=496/512  peak=32759  AUDIO ✓
I (477750) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (477750) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (477760) app_audio: [CHK3 I2S2 RX  ] 1256 kbps (~767 KB/5s)  L=-241 R=-323  real_samples=504/512  peak=32754  AUDIO ✓
I (482770) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (482770) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (482780) app_audio: [CHK3 I2S2 RX  ] 1263 kbps (~771 KB/5s)  L=-15 R=0  real_samples=408/512  peak=32767  AUDIO ✓
I (487790) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (487790) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (487800) app_audio: [CHK3 I2S2 RX  ] 1230 kbps (~751 KB/5s)  L=391 R=199  real_samples=501/512  peak=31746  AUDIO ✓
I (492810) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (492810) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (492820) app_audio: [CHK3 I2S2 RX  ] 1230 kbps (~751 KB/5s)  L=454 R=953  real_samples=124/128  peak=24625  AUDIO ✓
I (497830) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (497830) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (497840) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=317 R=668  real_samples=510/512  peak=32734  AUDIO ✓
I (502850) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (502850) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (502860) app_audio: [CHK3 I2S2 RX  ] 1222 kbps (~746 KB/5s)  L=-700 R=-222  real_samples=508/512  peak=32757  AUDIO ✓
I (507870) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (507870) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=29  DATA PRESENT ✓
I (507880) app_audio: [CHK3 I2S2 RX  ] 1232 kbps (~752 KB/5s)  L=-113 R=-18  real_samples=504/512  peak=32761  AUDIO ✓
I (512890) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (512890) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=29  DATA PRESENT ✓
I (512900) app_audio: [CHK3 I2S2 RX  ] 1228 kbps (~750 KB/5s)  L=-71 R=79  real_samples=510/512  peak=31234  AUDIO ✓
I (517910) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (517910) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (517920) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=-205 R=-326  real_samples=502/512  peak=32731  AUDIO ✓
I (522930) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (522930) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (522940) app_audio: [CHK3 I2S2 RX  ] 1223 kbps (~747 KB/5s)  L=1170 R=1082  real_samples=509/512  peak=32732  AUDIO ✓
I (527950) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (527950) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=34  DATA PRESENT ✓
I (527960) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=-180 R=-253  real_samples=508/512  peak=32734  AUDIO ✓
I (532970) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (532970) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=31  DATA PRESENT ✓
I (532980) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=-1313 R=-1760  real_samples=505/512  peak=32618  AUDIO ✓
I (537990) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (537990) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=29  DATA PRESENT ✓
I (538000) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=-584 R=59  real_samples=505/512  peak=32420  AUDIO ✓
I (543010) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (543010) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (543020) app_audio: [CHK3 I2S2 RX  ] 1228 kbps (~750 KB/5s)  L=16337 R=-1017  real_samples=511/512  peak=32721  AUDIO ✓
I (548030) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (548030) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (548040) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=-947 R=-314  real_samples=511/512  peak=32728  AUDIO ✓
I (553050) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (553050) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (553060) app_audio: [CHK3 I2S2 RX  ] 1236 kbps (~755 KB/5s)  L=321 R=445  real_samples=318/320  peak=23545  AUDIO ✓
I (558070) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (558070) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (558080) app_audio: [CHK3 I2S2 RX  ] 1207 kbps (~737 KB/5s)  L=110 R=453  real_samples=505/512  peak=32683  AUDIO ✓
I (563090) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (563090) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (563100) app_audio: [CHK3 I2S2 RX  ] 1223 kbps (~747 KB/5s)  L=-250 R=84  real_samples=507/512  peak=32760  AUDIO ✓
I (568110) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (568110) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=18  DATA PRESENT ✓
I (568120) app_audio: [CHK3 I2S2 RX  ] 1233 kbps (~753 KB/5s)  L=-250 R=-304  real_samples=506/512  peak=32747  AUDIO ✓
I (573130) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (573130) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (573140) app_audio: [CHK3 I2S2 RX  ] 1225 kbps (~748 KB/5s)  L=964 R=1182  real_samples=507/512  peak=32709  AUDIO ✓
I (578150) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (578150) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (578160) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=2432 R=2122  real_samples=352/352  peak=32735  AUDIO ✓
I (583170) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (583170) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (583180) app_audio: [CHK3 I2S2 RX  ] 1217 kbps (~743 KB/5s)  L=-363 R=-480  real_samples=510/512  peak=32578  AUDIO ✓
I (588190) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (588190) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (588200) app_audio: [CHK3 I2S2 RX  ] 1205 kbps (~736 KB/5s)  L=-855 R=-1756  real_samples=510/512  peak=32709  AUDIO ✓
I (593210) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (593210) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (593220) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=-108 R=-559  real_samples=317/320  peak=32685  AUDIO ✓
I (598230) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (598230) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (598240) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=-812 R=124  real_samples=509/512  peak=28698  AUDIO ✓
I (603250) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (603250) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (603260) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=1072 R=887  real_samples=509/512  peak=32645  AUDIO ✓
I (608270) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (608270) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (608280) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=239 R=659  real_samples=512/512  peak=32739  AUDIO ✓
I (613290) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (613290) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=28  DATA PRESENT ✓
I (613300) app_audio: [CHK3 I2S2 RX  ] 1210 kbps (~739 KB/5s)  L=1398 R=1121  real_samples=510/512  peak=32401  AUDIO ✓
I (618310) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (618310) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=23  DATA PRESENT ✓
I (618320) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=977 R=1090  real_samples=511/512  peak=32703  AUDIO ✓
I (623330) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (623330) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (623340) app_audio: [CHK3 I2S2 RX  ] 1222 kbps (~746 KB/5s)  L=29 R=-331  real_samples=505/512  peak=32757  AUDIO ✓
I (628350) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (628350) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=30  DATA PRESENT ✓
I (628360) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=-152 R=-435  real_samples=507/512  peak=32721  AUDIO ✓
I (633370) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (633370) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (633380) app_audio: [CHK3 I2S2 RX  ] 1236 kbps (~755 KB/5s)  L=-799 R=-853  real_samples=508/512  peak=32722  AUDIO ✓
I (638390) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (638390) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=17  DATA PRESENT ✓
I (638400) app_audio: [CHK3 I2S2 RX  ] 1225 kbps (~748 KB/5s)  L=-223 R=-262  real_samples=504/512  peak=32754  AUDIO ✓
I (643410) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (643410) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=12  DATA PRESENT ✓
I (643420) app_audio: [CHK3 I2S2 RX  ] 1248 kbps (~762 KB/5s)  L=-234 R=-504  real_samples=507/512  peak=32753  AUDIO ✓
I (648430) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (648430) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=32  DATA PRESENT ✓
I (648440) app_audio: [CHK3 I2S2 RX  ] 1256 kbps (~767 KB/5s)  L=380 R=385  real_samples=509/512  peak=30718  AUDIO ✓
I (653450) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (653450) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (653460) app_audio: [CHK3 I2S2 RX  ] 1259 kbps (~769 KB/5s)  L=32573 R=-378  real_samples=509/512  peak=32762  AUDIO ✓
I (658470) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (658470) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=29  DATA PRESENT ✓
I (658480) app_audio: [CHK3 I2S2 RX  ] 1266 kbps (~773 KB/5s)  L=-453 R=-177  real_samples=510/512  peak=32659  AUDIO ✓
I (663490) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (663490) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=24  DATA PRESENT ✓
I (663500) app_audio: [CHK3 I2S2 RX  ] 1256 kbps (~767 KB/5s)  L=-238 R=-238  real_samples=501/512  peak=32715  AUDIO ✓
I (668510) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (668510) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=18  DATA PRESENT ✓
I (668520) app_audio: [CHK3 I2S2 RX  ] 1241 kbps (~758 KB/5s)  L=-387 R=-187  real_samples=511/512  peak=32741  AUDIO ✓
I (673530) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (673530) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=19  DATA PRESENT ✓
I (673540) app_audio: [CHK3 I2S2 RX  ] 1225 kbps (~748 KB/5s)  L=134 R=539  real_samples=508/512  peak=32687  AUDIO ✓
I (678550) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (678550) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (678560) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=803 R=457  real_samples=507/512  peak=32731  AUDIO ✓
I (683570) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (683570) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (683580) app_audio: [CHK3 I2S2 RX  ] 1223 kbps (~747 KB/5s)  L=-504 R=-534  real_samples=507/512  peak=32537  AUDIO ✓
I (688590) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (688590) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (688600) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=42 R=217  real_samples=510/512  peak=32662  AUDIO ✓
I (693610) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=11  CLOCK PRESENT ✓
I (693610) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (693620) app_audio: [CHK3 I2S2 RX  ] 1235 kbps (~754 KB/5s)  L=-164 R=-78  real_samples=509/512  peak=32614  AUDIO ✓
I (698630) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (698630) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (698640) app_audio: [CHK3 I2S2 RX  ] 1269 kbps (~775 KB/5s)  L=168 R=167  real_samples=507/512  peak=32640  AUDIO ✓
I (703650) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (703650) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=19  DATA PRESENT ✓
I (703660) app_audio: [CHK3 I2S2 RX  ] 1263 kbps (~771 KB/5s)  L=4 R=28  real_samples=473/512  peak=32766  AUDIO ✓
I (708670) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=11  CLOCK PRESENT ✓
I (708670) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=2  STUCK — BT GPIO5 not wired to P4 GPIO48?
W (708680) app_audio: [LINK I2S ] DOWN ✗ no valid audio payload from BT Master
I (708680) app_audio: [CHK3 I2S2 RX  ] 1300 kbps (~794 KB/5s)  L=0 R=1  real_samples=0/512  peak=3  ← noise (0/±1 only) — floating DIN or no BT clock
I (713700) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (713700) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=27  DATA PRESENT ✓
I (713710) app_audio: [LINK I2S ] UP ✓ BT Master → P4 Slave (clock + data valid)
I (713710) app_audio: [CHK3 I2S2 RX  ] 1307 kbps (~798 KB/5s)  L=-345 R=-360  real_samples=507/512  peak=32766  AUDIO ✓
I (718720) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (718720) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (718730) app_audio: [CHK3 I2S2 RX  ] 1233 kbps (~753 KB/5s)  L=242 R=291  real_samples=122/128  peak=32759  AUDIO ✓
I (723740) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (723740) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=25  DATA PRESENT ✓
I (723750) app_audio: [CHK3 I2S2 RX  ] 1227 kbps (~749 KB/5s)  L=89 R=115  real_samples=508/512  peak=32740  AUDIO ✓
I (728760) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (728760) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (728770) app_audio: [CHK3 I2S2 RX  ] 1218 kbps (~744 KB/5s)  L=11 R=-185  real_samples=506/512  peak=32760  AUDIO ✓
I (733780) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (733780) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=18  DATA PRESENT ✓
I (733790) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=303 R=302  real_samples=504/512  peak=32766  AUDIO ✓
I (738800) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (738800) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (738810) app_audio: [CHK3 I2S2 RX  ] 1212 kbps (~740 KB/5s)  L=-953 R=-615  real_samples=510/512  peak=32746  AUDIO ✓
I (743820) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (743820) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=26  DATA PRESENT ✓
I (743830) app_audio: [CHK3 I2S2 RX  ] 1220 kbps (~745 KB/5s)  L=-154 R=-170  real_samples=510/512  peak=32753  AUDIO ✓
I (748840) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (748840) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=18  DATA PRESENT ✓
I (748850) app_audio: [CHK3 I2S2 RX  ] 1204 kbps (~735 KB/5s)  L=381 R=323  real_samples=506/512  peak=30719  AUDIO ✓
I (753860) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=12  CLOCK PRESENT ✓
I (753860) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=20  DATA PRESENT ✓
I (753870) app_audio: [CHK3 I2S2 RX  ] 1225 kbps (~748 KB/5s)  L=-228 R=-136  real_samples=497/512  peak=32755  AUDIO ✓
I (758880) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (758880) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=22  DATA PRESENT ✓
I (758890) app_audio: [CHK3 I2S2 RX  ] 1232 kbps (~752 KB/5s)  L=-325 R=-22  real_samples=503/512  peak=32749  AUDIO ✓
I (763900) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=9  WS47 trans/64us=11  CLOCK PRESENT ✓
I (763900) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=19  DATA PRESENT ✓
I (763910) app_audio: [CHK3 I2S2 RX  ] 1215 kbps (~742 KB/5s)  L=-151 R=-187  real_samples=498/512  peak=32763  AUDIO ✓
I (768920) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=11  WS47 trans/64us=12  CLOCK PRESENT ✓
I (768920) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=30  DATA PRESENT ✓
I (768920) app_audio: [CHK3 I2S2 RX  ] 1217 kbps (~743 KB/5s)  L=362 R=477  real_samples=320/320  peak=32755  AUDIO ✓
I (773930) app_audio: [CHK3 CLK probe ] BCK46 trans/64us=10  WS47 trans/64us=12  CLOCK PRESENT ✓
I (773930) app_audio: [CHK3 DIN probe ] GPIO48 transitions/64µs=21  DATA PRESENT ✓
I (773940) app_audio: [CHK3 I2S2 RX  ] 1209 kbps (~738 KB/5s)  L=226 R=457  real_samples=499/512  peak=32685  AUDIO ✓
