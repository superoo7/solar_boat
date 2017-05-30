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

  // ultraSonic
  rightSensor = ultrasonic.rightSensorDistance();
  // Serial.println(rightSensor);
  leftSensor = ultrasonic.leftSensorDistance();
  // Serial.println(leftSensor);
  frontSensor = ultrasonic.frontSensorDistance();
  // Serial.println(frontSensor);


  // avoidanceSystem(rightSensor, leftSensor, frontSensor);

  delay(1000);

  // every 20 sevonds, update to thingspeak
  if (thingspeakCounter > 20) {
    // everything is off (motor)
    // motor off


    // compass
    compass.COMPASS();
    float compassX = (float) compass.x;
    float compassY = (float) compass.y;
    float compassZ = (float) compass.z;

    // dissolved oxygen
    dissolvedO2.serialEvent();
    dissolvedO2.serialEvent3();
    float o2 = (float) dissolvedO2.DISSOLVEDO2();
    // temperature
    float temp = (float) temperature.TEMPERATURE();
    // turbidity
    float turb = (float) turbidity.TURBIDITY();

    // GPS
    float GPSLong = 0;
    float GPSLat = 0;

    // ThingSpeak will only accept updates every 15 seconds.
    thingspeak.UPDATE(temp, turb, o2, compassX, compassY, compassZ, GPSLong, GPSLat);
    thingspeakCounter = 0;
    Serial.println("submitted to thingspeak!");
    delay(100);
  } else {
    thingspeakCounter++;
  }




}
