#include "header.h"
int thingspeakCounter = 20;
long rightSensor, leftSensor, frontSensor;
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
  rightSensor = ultrasonic.rightSensorDistance();
  Serial.println(rightSensor);
  leftSensor = ultrasonic.leftSensorDistance();
  Serial.println(leftSensor);
  frontSensor = ultrasonic.frontSensorDistance();
  Serial.println(frontSensor);

  // ultrasonic.avoidanceSystem(rightSensor, leftSensor, frontSensor);

  delay(1000);


  if (thingspeakCounter > 20) {
  // ThingSpeak will only accept updates every 15 seconds.
  thingspeak.UPDATE(leftSensor, rightSensor, frontSensor);
  thingspeakCounter = 0;
  Serial.println("submitted to thingspeak!");
  delay(100);
  } else {
    thingspeakCounter++;
  }




}
