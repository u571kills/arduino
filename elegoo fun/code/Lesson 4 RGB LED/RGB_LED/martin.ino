//by Simon Monk
//www.elegoo.com
//2016.06.13

// Define Pins
#define RED 9

#define delayTime 10 // fading time between colors


void setup()
{
pinMode(RED, OUTPUT);
digitalWrite(RED, HIGH);
}

// define variables
int redValue;


// main loop
void loop()
{
  redValue = 0; // choose a value between 1 and 255 to change the color.

  analogWrite(RED, 0);
  delay(1000);

   for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    redValue += 1;
    analogWrite(RED, redValue);
    delay(delayTime);
  }

  for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
 {
   redValue -= 1;
   analogWrite(RED, redValue);
   delay(delayTime);
 }
}
