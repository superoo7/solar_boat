#include "ultrasonic.h"

long sonarSensorDistance(int trigPin,int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration/2) / 29.1;

  return distance;
}

ultrasonicClass::ultrasonicClass(){

}

void ultrasonicClass::SETUP(){

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  Serial.println("Done setup for ultrasonic");

}

long ultrasonicClass::rightSensorDistance() {

  rightSensor = sonarSensorDistance(trigPin1, echoPin1);
  return rightSensor;
}

long ultrasonicClass::leftSensorDistance() {

  leftSensor = sonarSensorDistance(trigPin2, echoPin2);
  return leftSensor;
}

long ultrasonicClass::frontSensorDistance() {

  frontSensor = sonarSensorDistance(trigPin3, echoPin3);
  return frontSensor;
}




ultrasonicClass ultrasonic = ultrasonicClass();
