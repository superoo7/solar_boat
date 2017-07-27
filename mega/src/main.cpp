#include "header.h"
int thingspeakCounter = 20;           
long rightSensor, leftSensor, frontSensor;                // declare front, left and right distance

void avoidanceSystem(long right, long left, long front);  // a function that do avoidance based on distance

void setup()
{
  Serial.begin(9600);       // hardware
  Serial3.begin(9600);      // software
  dissolvedO2.SETUP();      // setup dissolved oxygen probe (Refer to dissolvedO2 class)
  wifishield.SETUP();       // setup wifishield (Refer to wifishield class)
  thingspeak.SETUP();       // setup thingspeak API (Refer to thingspeak class)
  ultrasonic.SETUP();       // setup ultrasonic (Refer to ultrasonic class)
  compass.SETUP();          // setup compass (Refer to compass Class)
  GPS.SETUP();              // setup GPS (Refer to GPS)
  motors.SETUP();           // setup motor (Refer to motor class)
  motors.stop();

  Serial.println("Done setup");
}



void loop()
{

  // ultraSonic

  // from ultrasonic class call the func rightSensorDistance and get right distance
  rightSensor = ultrasonic.rightSensorDistance();    
  // from ultrasonic class call the func leftSensorDistance and get left distance
  leftSensor = ultrasonic.leftSensorDistance();
  // from ultrasonic class call the func frontSensorDistance and get front distance
  frontSensor = ultrasonic.frontSensorDistance();

  // print out result for debugging
  Serial.println("Ultrasonic:");
  Serial.print(rightSensor);
  Serial.print(",");
  Serial.print(leftSensor);
  Serial.print(",");
  Serial.println(frontSensor);

  // pass in 3 params of the surrounding distance and make the motor avoid the obstacles (Refer to the func)
  avoidanceSystem(rightSensor, leftSensor, frontSensor);

  // delay for 800ms 
  delay(800);

  // every 20 times, update to thingspeak
  if (thingspeakCounter > 20) {
    // everything is off (motor)
    // motor off
    motors.stop();

    // compass
    compass.COMPASS();                    // from compass class call COMPASS() func
    float compassX = (float) compass.x;   // using compass class get the val of x
    float compassY = (float) compass.y;   // using compass class get the val of y
    float compassZ = (float) compass.z;   // using compass class get the val of z

    // dissolved oxygen
    dissolvedO2.serialEvent();            // from dissolvedO2 class call serialEvent func
    dissolvedO2.serialEvent3();           // from dissolvedO2 class call serialEvent3 func
    // after 2 serial event is setup, value of dissolved O2 can be taken
    // using the func DISSOLVEDO2() the value of the probe can be taken
    float o2 = (float) dissolvedO2.DISSOLVEDO2(); 
    
    // temperature
    // the value of temperature can be taken from class temperature func TEMPERATURE()
    float temp = (float) temperature.TEMPERATURE();
    
    // turbidity
    // the value of turbidity can be taken from class turbidity func TURBIDITY()
    float turb = (float) turbidity.TURBIDITY();

    // GPS
    // the function LOCATION() is called from the class GPS
    GPS.LOCATION();
    float GPSLong = GPS.lng; // from the GPS class, get val of lng
    float GPSLat = GPS.lat;  // from the GPS class, get val of lat

    // ThingSpeak will only accept updates every 15 seconds.
    // pass in all the value that got from sensors to Thingspeak
    // using the function UPDATE() in thingspeak class, it will sent a HTTP UPDATE request to thingspeak API
    thingspeak.UPDATE(temp, turb, o2, compassX, compassY, compassZ, GPSLong, GPSLat);
    thingspeakCounter = 0;
    Serial.println("submitted to thingspeak!");
    delay(100);
  } else {
    // if not yet 20 times
    thingspeakCounter++;
  }
}

// the avoidance system is based on surrounding distance and avoid it with forward or reverse motor
// this is just basic avoidance
void avoidanceSystem(long right, long left, long front){
  long tresholdDistance = 30;  // threshold distance is the min distance between the boat and obstacles

  if (front <= tresholdDistance) {          // if there is obstacles at front, reverse the motor
    motors.reverse();
    Serial.println("MOTOR IS REVERSING");
  } else if (left <= tresholdDistance) {    // if there is obstacles at right, turn left 
    motors.right();
    Serial.println("MOTOR IS TURNING LEFT");
  } else if (right <= tresholdDistance) {   // if there is obstacles at left, turn right
    motors.left();
    Serial.println("MOTOR IS TURNING RIGHT");
  } else {                                  // else go forward
    motors.forward();
    Serial.println("FORWARDING");
  }
}
