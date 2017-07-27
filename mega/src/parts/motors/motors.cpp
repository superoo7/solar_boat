#include "motors.h"

// declare motor pin
const int right1 =9 , right2=10, left1=11, left2=12;
int pins[4] = { right1, right2, left1, left2}; // make them in array for ease of setup


void motorsClass::SETUP() {
  // void setup()
  for (int i=0; i<4; i++) {
   pinMode(pins[i], OUTPUT);
 }
}

// motor stop
void motorsClass::stop(){
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], LOW);
}

// motor go forward
void motorsClass::forward(){
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], HIGH);
}

// motor go reverse
void motorsClass::reverse(){
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[3], LOW);
}

// motor go left
void motorsClass::left(){
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[3], LOW);
}

// motor go right
void motorsClass::right(){
  digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], HIGH);
}

motorsClass motors = motorsClass();
