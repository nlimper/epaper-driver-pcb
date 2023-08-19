# epaper driver pcb
 e-paper driver PCB, schematic and example scripts for esp32


## What is it?
This is a ready-to-go PCB to connect a bare epaper display (salvaged from a used Electronic Shelf Label) to a microcontroller (like ESP32) via SPI.

## What makes it special?
The driver board is compatible with at least the Solum 2.9" and 1.54" displays. These Electronic Shelf Label displays have the copper contacts of the FPC Connector at the bottom of the cable (in contrast with Waveshare epaper displays, who have the exposed copper contacts at the top). I didn't test any other displays or brands.

The pcb is designed so you can almost make a straight connection to a ESP32 Lolin board. No other components are needed to make it work. On ESP32, you can use the GxEPD2 library to use the display. Examples are in this repository.

But the ready make driver pcb on Tindie: https://www.tindie.com/products/electronics-by-nic/display-driver-board-for-epaper-shelf-label/
There, I also sell the compatible displays: [2.9" displays](https://www.tindie.com/products/electronics-by-nic/5-pcs-29-epaper-tags-for-openepaperlink/) and [1.54" displays](https://www.tindie.com/products/electronics-by-nic/5-pcs-154-epaper-tags-for-openepaperlink/).

| Driver | ESP32 |
| ------ | ----- |
| MOSI   | 23    |
| CLK    | 18    |
| CS     | 5     |
| DC     | 17    |
| RST    | 16    |
| BUSY   | 4     |
| 3.3V   | 3.3V  |
| GND    | GND   |

