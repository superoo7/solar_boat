#include "ultrasonic.h"

ultrasonicClass::ultrasonicClass() {

}

void ultrasonicClass::SETUP() {
  pinMode(ultraSonicTrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(ultraSonicEchoPin, INPUT); // Sets the echoPin as an Input
}

void ultrasonicClass::DISTANCE() {

  // Clears the trigPin
  digitalWrite(ultraSonicTrigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(ultraSonicTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicTrigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  timeTakenToTravel = pulseIn(ultraSonicEchoPin, HIGH);
  // Calculating the distance
  distanceTravelled = timeTakenToTravel * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distanceTravelled);

}

ultrasonicClass ultrasonic = ultrasonicClass();
