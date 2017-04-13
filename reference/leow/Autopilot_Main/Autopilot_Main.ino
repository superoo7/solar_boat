#include <Wire.h>
#include "compass.h"
#include <SoftwareSerial.h>
#include <SoftEasyTransfer.h>
#include <Average.h>
#include "LowPower.h"
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

//Motor Control
int maxspeed;
//maxspeed - motgain * 30 > 0
//MOTGAIN 4
int motgain = 4;
int anglerange = 30;
int rightpin = 10;
int leftpin = 9;
int led = 13;
int overavg = 10;
int steerarray[10];
int throttlearray[10];
int enablePin1=11;
int enablePin2=12;
//GPS
static int r = 6371;
const float Pi = 3.14159;
int accuracy = 5;
unsigned long lasttime = 0;
//for motor
#define E1 11  // Enable Pin for motor 1
#define E2 12  // Enable Pin for motor 2
 
#define I1 9  // Control pin 1 for motor 1
#define I2 2  // Control pin 2 for motor 1
#define I3 10  // Control pin 1 for motor 2
#define I4 3  // Control pin 2 for motor 2
 
//for detecting distance using 5 different ultrasonic sensors 
//left sensor
const int TRIG_PIN1= 4; //green wire
const int ECHO_PIN1= 5; //blue wire

// mid sensor
const int TRIG_PIN2= 8; //green wire
const int ECHO_PIN2= 13; //blue wire

//right sensor
const int TRIG_PIN3= 6; //green wire
const int ECHO_PIN3= 7; //blue wire


  unsigned long t1a;
  unsigned long t1b;

  unsigned long t2a;
  unsigned long t2b;

  unsigned long t3a;
  unsigned long t3b;



  unsigned long p_w1;
  unsigned long p_w2;
  unsigned long p_w3;
  
  float cm1;
  float inches1;
  float cm2;
  float inches2;
  float cm3;
  float inches3;

const unsigned int MAX_DIST = 23200;



SoftEasyTransfer rx;

SoftwareSerial link(0, 1);

struct RECEIVE_DATA_STRUCTURE{
  float latitude;
  float longitude;
};

RECEIVE_DATA_STRUCTURE gpsin;

void setup() {
  //Serial.begin(115200);
  Wire.begin();
  pinMode(rightpin, OUTPUT);
  pinMode(leftpin, OUTPUT);
  pinMode(led, OUTPUT);
  compass_init(2);
  compass_debug = 1;
  compass_offset_calibration(3);
  link.begin(38400);
  rx.begin(details(gpsin), &link);
  digitalWrite(led, HIGH);
  digitalWrite(enablePin1, HIGH);
  digitalWrite(enablePin2, HIGH);
   // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN1, OUTPUT);
  digitalWrite(TRIG_PIN1, LOW);

  pinMode(TRIG_PIN2, OUTPUT);
  digitalWrite(TRIG_PIN2, LOW);

  pinMode(TRIG_PIN3, OUTPUT);
  digitalWrite(TRIG_PIN3, LOW);

pinMode(I1,OUTPUT);
pinMode(I2,OUTPUT);
pinMode(E1,OUTPUT);

pinMode(I3,OUTPUT);
pinMode(I4,OUTPUT);
pinMode(E2,OUTPUT);
   
  Serial.begin(9600);
}

void loop() {
//  Navigate(49.231623, -122.695656, 200);
//  Navigate(49.231600, -122.695745, 200);
//  Navigate(49.231545, -122.695796, 200);
//  Navigate(49.231474, -122.695756, 200);
//  Navigate(49.231450, -122.695659, 200);
//  Navigate(49.231472, -122.695568, 200);
//  Navigate(49.231535, -122.695523, 200);
//  Navigate(49.231600, -122.695572, 200);
 Control();
}

void Control() {
//  while (pulseIn(5, HIGH, 100000) > 0){
//    int throttle = pulseIn(4, HIGH, 20000);
//    int steer = pulseIn(5, HIGH, 20000);
//    if (throttle > 1000 && steer > 1000) {
//      Override(throttle, steer);


void loop () {
  

 READ();
Action();

}

 void READ() {



  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);

  while ( digitalRead(ECHO_PIN1) == 0 );
  t1a = micros();
  while ( digitalRead(ECHO_PIN1) == 1);
  t1b = micros();
  p_w1 = t1b - t1a;

  cm1 = p_w1 / 58.0;
  inches1 = p_w1 / 148.0;

  
  Serial.print("u1 \t");
  if ( p_w1 > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(cm1);
    Serial.print(" cm \t");
    Serial.print(inches1);
    Serial.println(" in");
  }

  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  while ( digitalRead(ECHO_PIN2) == 0 );
  t2a = micros();
  while ( digitalRead(ECHO_PIN2) == 1);
  t2b = micros();
  p_w2 = t2b - t2a;

  cm2 = p_w2 / 58.0;
  inches2 = p_w2 / 148.0;

  Serial.print("u2 \t");
  if ( p_w2 > MAX_DIST ) {
    Serial.println("Out of range");
  } 
  else {
    Serial.print(cm2);
    Serial.print(" cm \t");
    Serial.print(inches2);
    Serial.println(" in");
  }

  digitalWrite(TRIG_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);

  while ( digitalRead(ECHO_PIN3) == 0 );
  t3a = micros();
  while ( digitalRead(ECHO_PIN3) == 1);
  t3b = micros();
  p_w3 = t3b - t3a;


  cm3 = p_w3 / 58.0;
  inches3 = p_w3 / 148.0;

  Serial.print("u3 \t");
  if ( p_w3 > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(cm3);
    Serial.print(" cm \t");
    Serial.print(inches3);
    Serial.println(" in");
  }

   Serial.println(" ");
delay(600);
}

void Action() {
  
  if (cm1<50) //turn right
  {
  analogWrite(E1, 0); // Run in half speed
  analogWrite(E2, 255); // Run in full speed
  
  digitalWrite(I1,LOW);

  digitalWrite(I2,HIGH);

  digitalWrite(I3, HIGH);

  digitalWrite(I4,LOW);
  delay (2000);
  }
 
  else  if (cm2<50) //turn right
  {
  analogWrite(E1,0); // Run in half speed
  analogWrite(E2,225); // Run in full speed
  
  digitalWrite(I1,LOW);

  digitalWrite(I2,HIGH);

  digitalWrite(I3,HIGH);

  digitalWrite(I4,LOW);
  }

  else  if (cm3<50) //turn left
  {
  analogWrite(E1,225); // Run in half speed
  analogWrite(E2, 0); // Run in full speed
  
  digitalWrite(I1,HIGH);

  digitalWrite(I2,LOW);

  digitalWrite(I3,LOW);

  digitalWrite(I4,HIGH);
  }

  else if (cm1&&cm3&&cm2 > 50){
  analogWrite(E1, 100); // not moving
  analogWrite(E2, 100); // not moving
  digitalWrite(I1,HIGH);

  digitalWrite(I2,LOW);

  digitalWrite(I3,HIGH);

  digitalWrite(I4,LOW);
    }
    delay(50);
  }
}


void Navigate(float lat2, float long2, int velocity) {
  maxspeed = velocity;
  while (GetDistanceInM(gpsin.latitude, gpsin.longitude, lat2, long2) > accuracy) {
    if (rx.receiveData()){
      lasttime = millis();
    }
    while (pulseIn(5, HIGH, 100000) > 0){
      int throttle = pulseIn(4, HIGH, 20000);
      int steer = pulseIn(5, HIGH, 20000);
      if (throttle > 1000 && steer > 1000) {
        Override(throttle, steer);
      }
      delay(50);
    }
    if ((millis() - lasttime) < 2000) {
      int bearing = GetBearing();
      int heading = GetHeading(gpsin.latitude, gpsin.longitude, lat2, long2);
      int leftmot = MotorSpeed(bearing, heading, 1);
      int rightmot = MotorSpeed(bearing, heading, 0);
      if (leftmot < 0) {
        leftmot = 0;
      }
      if (rightmot < 0) {
        rightmot = 0;
      }
      RunMotor(leftmot, 1);
      RunMotor(rightmot, 0);
      Serial.print(bearing);
      Serial.print("  ");
      Serial.print(heading);
      Serial.print("  ");
      Serial.print(GetDistanceInM(gpsin.latitude, gpsin.longitude, lat2, long2));
      Serial.print("  ");
      Serial.print(leftmot);
      Serial.print("  ");
      Serial.println(rightmot);
    }
    else {
      RunMotor(0, 1);
      RunMotor(0, 0);
      Serial.println("No GPS Signal");
    }
  }
  Serial.println("NavLoop Return");
  RunMotor(0, 1);
  RunMotor(0, 0);
}

void Override(int throttle, int steering) {
  int left;
  int right;
  if (throttle > 1600)
  {
    throttle = (int)(0.51 * (throttle - 1500));
    if (steering > 1500) {
      right = (int)(throttle - 0.51* (steering - 1500));
      if (right < 0)
      {
        right = 0;
      }
      left = throttle;
    }
    else {
      left = (int)(throttle + 0.51 * (steering - 1500));
      if (left < 0)
      {
        left = 0;
      }
      right = throttle;
    }
  }
  else {
    left = 1;
    right = 1;
  }
  RunMotor(right, 0);
  RunMotor(left, 1);
  Serial.print(left);
  Serial.print("  ");
  Serial.println(right);
}

void RunMotor(int val, int option){
  if (option == 0) {
    //Right Motor
    analogWrite(rightpin, val);
  }
  else {
    //Left Motor
    analogWrite(leftpin, val);
  }
}

int GetBearing() {
  compass_heading();
  float headingradians = bearing / (180 / M_PI);
  float declinationAngle = 0.289724656;
  headingradians += declinationAngle;
  bearing = (int)((headingradians * 180 / M_PI)+270) % 360;
  return bearing;
}

int MotorSpeed(int bearing, int heading, int option) {
  heading = heading % 360;
  bearing = bearing % 360;
  if (heading == bearing)
  {
    return (maxspeed);
  }
  int o1 = (int)heading - (int)bearing;
  int o2 = (int)bearing - (int)heading;
  int direction = ((360 - ((int)heading - (int)bearing)) % 360);
  if (direction < 180) {
    if (direction > anglerange)
    {
      //Right Motor
      if (option == 0) {
        return maxspeed;
      }
      //Left Motor
      else {
        return 0;
      }
    }
    else
    {
      //Right Motor
      if (option == 0) {
        return maxspeed;
      }
      //Left Motor
      else {
        return maxspeed - (direction * motgain);
      }
    }
  }
  else if (direction >= 180)
  {
    if ((360 - direction) > anglerange)
    {
      //Right Motor
      if (option == 0) {
        return 0;
      }
      //Left Motor
      else {
        return maxspeed;
      }
    }
    else
    {
      //Right Motor
      if (option == 0) {
        return maxspeed - ((360 - direction) * motgain);
      }
      //Left Motor
      else {
        return maxspeed;
      }
    }
  }
  return 0;
}

static float GetHeading(float lat1, float long1, float lat2, float long2)
{
  //Current Latitude, Current Longitude
  //Projected Latitude, Projected Longitude
  //To get reverse heading, add 180
  lat1 = ConvertToRadians(lat1);
  lat2 = ConvertToRadians(lat2);
  long1 = ConvertToRadians(long1);
  long2 = ConvertToRadians(long2);
  float dLon = long2 - long1;
  float y = sin(dLon) * cos(lat2);
  float x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dLon);
  return ConvertToStaticDegrees(atan2(y, x));
}
static float GetDistanceInM(float lat1, float long1, float lat2, float long2)
{
  //Current Latitude, Current Longitude
  //Projected Latitude, Projected Longitude
  lat1 = ConvertToRadians(lat1);
  lat2 = ConvertToRadians(lat2);
  long1 = ConvertToRadians(long1);
  long2 = ConvertToRadians(long2);
  float dLat = lat2 - lat1;
  float dLon = long2 - long1;
  float a = haversin(dLat) + cos(lat1) * cos(lat2) * haversin(dLon);
  float c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return r * c * 1000; // Distance in M
}
static float ConvertToDegrees(float rad)
{
  float degrees = rad / (Pi / 180);
  if (degrees <= -180) {
    return degrees + 360;
  }
  else {
    return degrees;
  }
}
static float ConvertToStaticDegrees(float rad)
{
  float degrees = rad / (Pi / 180);
  if (degrees <= 0) {
    return degrees + 360;
  }
  else {
    return degrees;
  }
}
static float ConvertToRadians(float angle)
{
  return (Pi / 180) * angle;
}
static float haversin(float input)
{
  return (sin(input / 2)) * (sin(input / 2));
}















