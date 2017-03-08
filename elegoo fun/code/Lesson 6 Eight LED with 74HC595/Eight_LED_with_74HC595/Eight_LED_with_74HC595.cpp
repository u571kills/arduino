//by Simon Monk
//www.elegoo.com
//2016.06.13
// Modfied by Martin

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    buzzerBeepTime(i);
    delay(500);
  }
  for (int i = 8; i >= 0; i--)
  {
    bitClear(leds, i);
    updateShiftRegister();
    buzzerBeepTime(i);
    delay(500);
  }
}


void updateShiftRegister()
{
 digitalWrite(latchPin, LOW);
 shiftOut(dataPin, clockPin, LSBFIRST, leds);
 digitalWrite(latchPin, HIGH);
}

void buzzerBeepTime(int count)
{
  for (int i = 0; i <= count; i++) {
  bitSet(leds, 7);
  updateShiftRegister();
  delay(40);
  bitClear(leds, 7);
  updateShiftRegister();
  delay(40);
  }
}
