#include "header.h"

void setup()
{
  // from sensors/ultrasonic
  pinMode(US_TRIG, OUTPUT); 
  pinMode(US_ECHO, INPUT);
  Serial.begin(9600);

}

void loop()
{
  // from sensors/ultrasonic
  ultraSonic();
  delay(1000);

}
