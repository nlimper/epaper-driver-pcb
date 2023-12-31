#include "Adafruit_EPD.h"
#include <Fonts/FreeMonoBold9pt7b.h>

#define EPD_DC 17
#define EPD_CS 5
#define EPD_BUSY 4 // can set to -1 to not use a pin (will wait a fixed delay)
#define SRAM_CS -1
#define EPD_RESET 16 // can set to -1 and share with microcontroller Reset!
#define EPD_SPI &SPI // primary SPI

// 1.54" EPD 152x152
Adafruit_SSD1619 display(152, 152, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);

// You will need to install the Adafruit_EPD and Adafruit_GFX library to run this script.

// To draw on the display, you can use all drawing functions from the Adafruit GFX library
// https://learn.adafruit.com/adafruit-gfx-graphics-library/overview

void setup() {
	Serial.begin(115200);

	display.begin();
	display.setRotation(0);

	display.clearBuffer();

	display.setFont(&FreeMonoBold9pt7b);

	const char HelloWorld[] = "Hello World!";

	int16_t tbx, tby;
	uint16_t tbw, tbh;
	display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
	uint16_t x = ((display.width() - tbw) / 2) - tbx;
	uint16_t y = ((display.height() - tbh) / 2) - tby;

	display.fillScreen(EPD_WHITE);

	display.setTextColor(EPD_BLACK);
	display.setCursor(x, y - 10);
	display.print(HelloWorld);

	display.setTextColor(EPD_RED);
	display.setCursor(x, y + 10);
	display.print(HelloWorld);

	display.display();
}

void loop() {
	// don't do anything!
}
