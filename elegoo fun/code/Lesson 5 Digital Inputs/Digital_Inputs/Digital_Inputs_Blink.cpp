//by Simon Monk
//www.elegoo.com
//2016.06.13

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;
int bright = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonApin) == LOW) {
    bright += 1;
    analogWrite(ledPin, bright);
    delay(10);
  }
  if (digitalRead(buttonBpin) == LOW) {
    bright -= 1;
    analogWrite(ledPin, bright);
    delay(10);
  }

    // digitalWrite(ledPin, HIGH);
    // delay(100);
    // digitalWrite(ledPin, LOW);
    // delay(100);
}
