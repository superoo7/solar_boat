#include "header.h"
int thingspeakCounter = 20;
long rightSensor, leftSensor, frontSensor;
void setup()
{
  Serial.begin(9600);       //hardware
  Serial3.begin(9600);     //software
  dissolvedO2.SETUP();
  wifishield.SETUP();
  thingspeak.SETUP();
  ultrasonic.SETUP();
  compass.SETUP();
}



void loop()
{
  // compass
  compass.COMPASS();
  int compassX = compass.x;
  int compassY = compass.y;
  int compassZ = compass.z;
  // Show Values
  Serial.print("X Value: ");
  Serial.println(compassX);
  Serial.print("Y Value: ");
  Serial.println(compassY);
  Serial.print("Z Value: ");
  Serial.println(compassZ);
  Serial.println();


  // dissolved oxygen
  dissolvedO2.serialEvent();
  dissolvedO2.serialEvent3();
  float o2 = dissolvedO2.DISSOLVEDO2();
  // temperature
  float temp = temperature.TEMPERATURE();
  // turbidity
  float turb = turbidity.TURBIDITY();
  // ultraSonic
  rightSensor = ultrasonic.rightSensorDistance();
  // Serial.println(rightSensor);
  leftSensor = ultrasonic.leftSensorDistance();
  // Serial.println(leftSensor);
  frontSensor = ultrasonic.frontSensorDistance();
  // Serial.println(frontSensor);

  // ultrasonic.avoidanceSystem(rightSensor, leftSensor, frontSensor);
  Serial.println(o2);
  delay(1000);


  if (thingspeakCounter > 20) {
  // ThingSpeak will only accept updates every 15 seconds.
  thingspeak.UPDATE(temp, turb, o2);
  thingspeakCounter = 0;
  Serial.println("submitted to thingspeak!");
  delay(100);
  } else {
    thingspeakCounter++;
  }




}
