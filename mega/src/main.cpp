#include "header.h"


void setup()
{
  Serial.begin(9600);
  wifishield.SETUP();
  thingspeak.SETUP();
  ultrasonic.SETUP();
}

void loop()
{
  // dissolved oxygen
  // temperature
  // turbidity
  long rightSensor = ultrasonic.rightSensorDistance();
  long leftSensor = ultrasonic.leftSensorDistance();
  long frontSensor = ultrasonic.frontSensorDistance();
  thingspeak.UPDATE(leftSensor, rightSensor, frontSensor);

  delay(20000); // ThingSpeak will only accept updates every 15 seconds.
}
