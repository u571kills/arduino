#include <Arduino.h>

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

int linePosition = 0;
int colPosition = 0;

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte sad[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
};

byte left[8] = {
  B00000,
  B11110,
  B01111,
  B00111,
  B01111,
  B11110,
  B00000,
};

byte right[8] = {
  B00000,
  B01111,
  B11110,
  B11100,
  B11110,
  B01111,
  B00000,
};

byte down[8] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11011,
  B10001,
  B00000,
};

byte up[8] = {
  B00000,
  B00000,
  B10001,
  B11011,
  B11111,
  B11111,
  B01110,
  B00000,
};

int read_LCD_buttons() {
  adc_key_in = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;
  return btnNONE;  // when all others fail, return this...
}

void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, up);
  lcd.createChar(1, down);
  lcd.createChar(3, left);
  lcd.createChar(4, right);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Full Chub");
  int my_size = 10;
  lcd.setCursor(0, 1);
  lcd.print("8");
  for (int i=1; i <= my_size; i++) {
    lcd.setCursor(i, 1);
    lcd.print("=D   ");
    if (i == my_size)
        {
          lcd.setCursor(i, 1);
          lcd.print("=D*   ");
        }
    delay(500);
  }
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("               ");
  lcd.setCursor(0, 1);
  lcd.print("               ");
  lcd.setCursor(0, 0);
  lcd.print(".");
}

void loop() {
  // put your main code here, to run repeatedly:


  lcd_key = read_LCD_buttons();

  switch (lcd_key)               // depending on which button was pushed, we perform an action
  {

    //RIGHT BUTTON
    case btnRIGHT:
      {

        lcd.setCursor(colPosition, linePosition);
        lcd.print(" ");
        colPosition++;

        if (colPosition > 15)
        {
          colPosition = 15;

        }

        lcd.setCursor(colPosition, linePosition);
        lcd.write(byte(4));
        delay(300);
        break;
      }

    //LEFT BUTTON
    case btnLEFT:
      {
        lcd.setCursor(colPosition, linePosition);
        lcd.print(" ");
        colPosition = colPosition - 1;
        if (colPosition < 0)
        {
          colPosition = 0;
        }

        lcd.setCursor(colPosition, linePosition);
        lcd.write(byte(3));
        delay(300);
        break;
      }

    //UP BUTTON
    case btnUP:
      {

        lcd.setCursor(colPosition, linePosition);
        lcd.print(" ");
        linePosition = linePosition -1;


        if (linePosition < 0)
        {
          linePosition = 0;

        }

        lcd.setCursor(colPosition, linePosition);
        lcd.write(byte(0));
        delay(300);
        break;
      }

    // DOWN BUTTON
    case btnDOWN:
      {
        lcd.setCursor(colPosition, linePosition);
        lcd.print(" ");
        linePosition = linePosition + 1;

        if (linePosition > 1)
        {
          linePosition = 1;

        }
        lcd.setCursor(colPosition, linePosition);
        lcd.write(byte(1));
        delay(300);
        break;
      }


    case btnSELECT:
      {
       lcd.print(".");
       break;
     }
        // case btnNONE:
        // {
        // lcd.print(".");
        // break;
        // }
  }




}
