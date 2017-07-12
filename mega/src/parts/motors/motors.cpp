#include "motors.h"
void motorsClass::SETUP() {
  // const int leftMotorDirection = 22, leftMotor1 = 23, leftMotor2 = 24;
  // const int rightMotorDirection = 25, rightMotor1 = 26, rightMotor = 27;

  // pinMode(leftMotorDirection, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  // pinMode(rightMotorDirection, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);


}

// 1-High 2-Low : forward
// 1-Low 2-High : reverse

void motorsClass::stop(){
  // digitalWrite(leftMotorDirection, LOW);
  // digitalWrite(rightMotorDirection, LOW);
  // left
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  //right
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
}

void motorsClass::forward(){
  // left
  // digitalWrite(leftMotorDirection, HIGH);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  //right
  // digitalWrite(rightMotorDirection, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

void motorsClass::reverse(){
  // left
  // digitalWrite(leftMotorDirection, HIGH);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  //right
  // digitalWrite(rightMotorDirection, HIGH);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void motorsClass::left(){
  // left forward, right reverse
  // left
  // digitalWrite(leftMotorDirection, HIGH);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  //right
  // digitalWrite(rightMotorDirection, HIGH);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}

void motorsClass::right(){
  // right forward, left reverse
  // left
  // digitalWrite(leftMotorDirection, HIGH);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  //right
  // digitalWrite(rightMotorDirection, HIGH);
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
}

motorsClass motors = motorsClass();
