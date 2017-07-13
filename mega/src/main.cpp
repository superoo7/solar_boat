#include "header.h"
int thingspeakCounter = 20;
long rightSensor, leftSensor, frontSensor;

void avoidanceSystem(long right, long left, long front);

void setup()
{
  Serial.begin(9600);       //hardware
  Serial3.begin(9600);      //software
  dissolvedO2.SETUP();
  wifishield.SETUP();
  thingspeak.SETUP();
  ultrasonic.SETUP();
  // compass.SETUP();
  GPS.SETUP();
  motors.SETUP();
  motors.stop();

  Serial.println("Done setup");
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
  Serial.println("Ultrasonic:");
  Serial.print(rightSensor);
  Serial.print(",");
  Serial.print(leftSensor);
  Serial.print(",");
  Serial.println(frontSensor);

  avoidanceSystem(rightSensor, leftSensor, frontSensor);

  delay(800);

  // every 20 sevonds, update to thingspeak
  if (thingspeakCounter > 20) {
    // everything is off (motor)
    // motor off


    // compass
    // compass.COMPASS();
    float compassX = 0;
    float compassY = 0;
    float compassZ = 0;
    // float compassX = (float) compass.x;
    // float compassY = (float) compass.y;
    // float compassZ = (float) compass.z;

    // dissolved oxygen
    dissolvedO2.serialEvent();
    dissolvedO2.serialEvent3();
    float o2 = (float) dissolvedO2.DISSOLVEDO2();
    // temperature
    float temp = (float) temperature.TEMPERATURE();
    // turbidity
    float turb = (float) turbidity.TURBIDITY();

    // GPS
    GPS.LOCATION();
    float GPSLong = GPS.lng;
    float GPSLat = GPS.lat;

    // ThingSpeak will only accept updates every 15 seconds.
    thingspeak.UPDATE(temp, turb, o2, compassX, compassY, compassZ, GPSLong, GPSLat);
    thingspeakCounter = 0;
    Serial.println("submitted to thingspeak!");
    delay(100);
  } else {
    thingspeakCounter++;
  }
}


void avoidanceSystem(long right, long left, long front){
  long tresholdDistance = 30;  // 10cm threshold

  if (front <= tresholdDistance) {
    motors.reverse();
    Serial.println("MOTOR IS REVERSING");
  } else if (left <= tresholdDistance) {
    motors.right();
    Serial.println("MOTOR IS TURNING LEFT");
  } else if (right <= tresholdDistance) {
    motors.left();
    Serial.println("MOTOR IS TURNING RIGHT");
  } else {
    motors.forward();
    Serial.println("FORWARDING");
  }
}
