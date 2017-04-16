#include "header.h"


void setup()
{
  turbidity.SETUP();
  ultrasonic.SETUP();
  Serial.begin(9600);

}

void loop()
{
  turbidity.TURBIDITY();
  ultrasonic.DISTANCE();
  delay(500);

}
