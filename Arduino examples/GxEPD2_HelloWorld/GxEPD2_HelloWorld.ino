#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// Demo code for 2.9" epaper display
// libraries needed: GxEPD2, and probably also Adafruit_GFX

// To draw on the display, you can use all drawing functions from the Adafruit GFX library
// https://learn.adafruit.com/adafruit-gfx-graphics-library/overview

GxEPD2_3C<GxEPD2_290_C90c, GxEPD2_290_C90c::HEIGHT> display(GxEPD2_290_C90c(/*CS=5*/ 5, /*DC=*/17, /*RST=*/16, /*BUSY=*/4));

const char HelloWorld[] = "Hello World!";

void helloWorld() {
	display.setRotation(1);
	display.setFont(&FreeMonoBold9pt7b);

	int16_t tbx, tby;
	uint16_t tbw, tbh;
	display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
	uint16_t x = ((display.width() - tbw) / 2) - tbx;
	uint16_t y = ((display.height() - tbh) / 2) - tby;
	
	display.setFullWindow();
	display.fillScreen(GxEPD_WHITE);
	
	display.setTextColor(GxEPD_BLACK);
	display.setCursor(x, y - 10);
	display.print(HelloWorld);
	
	display.setTextColor(GxEPD_RED);
	display.setCursor(x, y + 10);
	display.print(HelloWorld);
	
	display.display(false);
}

void setup() {
	display.init();
	helloWorld();
	display.hibernate();
}

void loop(){};
