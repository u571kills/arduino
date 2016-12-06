#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(2,0);
 lcd.print("Hi Dan, "); // print a simple message
 lcd.setCursor(0,1);
 lcd.print("This is sweet!"); // print a simple message
}

void loop() {}
