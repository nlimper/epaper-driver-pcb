#include <Arduino.h>

#include "Adafruit_EPD.h"
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>

#define EPD_DC 17
#define EPD_CS 5
#define EPD_BUSY 4 // can set to -1 to not use a pin (will wait a fixed delay)
#define SRAM_CS -1
#define EPD_RESET 16 // can set to -1 and share with microcontroller Reset!
#define EPD_SPI &SPI // primary SPI
#define POWERPIN 22 // testjig has 3V3 of the driver pcb connected to pin 22 to be able to turn it on and off

// 1.54" EPD 152x152
// Adafruit_IL0373 display(152, 152, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);
Adafruit_SSD1619 display(152, 152, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY, EPD_SPI);

// or when you use custom SPI pins:
// Adafruit_SSD1619 display(int width, int height, int16_t SID, int16_t SCLK, int16_t DC, int16_t RST, int16_t CS, int16_t SRCS, int16_t MISO,	int16_t BUSY);

// You will need to install the Adafruit_EPD and Adafruit_GFX library to run this script.

// To draw on the display, you can use all drawing functions from the Adafruit GFX library
// https://learn.adafruit.com/adafruit-gfx-graphics-library/overview
// other examples: https://github.com/adafruit/Adafruit_EPD/tree/master/examples

void updateDisplay() {
	Serial.println("Start updating display");
	display.begin();

	display.setRotation(2);
	display.clearBuffer();
	display.fillScreen(EPD_WHITE);

	display.fillRect(10, 10, 40, 40, EPD_BLACK);
	display.fillRect(55, 10, 40, 40, EPD_RED);
	display.drawRect(100, 10, 40, 40, EPD_BLACK);

	display.setFont(&FreeSansBold12pt7b);
	display.setTextColor(EPD_BLACK);
	display.setCursor(10, 90);
	display.print("Display test");

	display.setFont(&FreeSans9pt7b);
	display.setTextColor(EPD_RED);
	display.setCursor(10, 130);
	display.print("Check passed!");

	display.display();
	Serial.println("Finished updating display");
}

void powerOn() {
	pinMode(POWERPIN, OUTPUT);
	digitalWrite(POWERPIN, HIGH);
	delay(100);
}

void powerOff() {
	pinMode(MISO, INPUT);
	pinMode(MOSI, INPUT);
	pinMode(EPD_DC,INPUT);
	pinMode(EPD_CS, INPUT);
	pinMode(EPD_BUSY, INPUT);
	pinMode(EPD_RESET, INPUT);
	pinMode(SCK, INPUT);
	digitalWrite(POWERPIN, LOW);
}

void setup() {
	Serial.begin(115200);
	powerOn();
	updateDisplay();
	powerOff();
}

void loop() {
	
}
