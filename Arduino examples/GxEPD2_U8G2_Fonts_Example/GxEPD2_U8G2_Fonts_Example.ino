#include <GxEPD2_3C.h>

// convert Truetype font to Adafruit GFX: https://rop.nl/truetype2gfx/
#include "calibrib25pt7b.h"

// More info about the GxEPD library: https://github.com/ZinggJM/GxEPD2

GxEPD2_3C<GxEPD2_290_C90c, GxEPD2_290_C90c::HEIGHT> display(GxEPD2_290_C90c(/*CS=5*/ 5, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4));

void drawCentreString(const String &buf, int x, int y) {
	int16_t x1, y1;
	uint16_t w, h;
	display.getTextBounds(buf, 0, 0, &x1, &y1, &w, &h);
	display.setCursor(x - (w / 2), y);
	display.print(buf);
}

void setup() {

	display.init();
	display.setFullWindow();
	display.setRotation(1);
	display.fillScreen(GxEPD_WHITE);

	display.setFont(&calibrib25pt7b);
	display.setTextSize(1);
	display.setTextColor(GxEPD_BLACK);
	drawCentreString("epaper demo", 148, 50);

	display.setFont(&calibrib25pt7b);
	display.setTextColor(GxEPD_RED);
	drawCentreString("Also in red!", 150, 110);
	display.display(false);
	
}

void loop() {
}
