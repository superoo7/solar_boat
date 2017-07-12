#ifndef motors_h
#define motors_h

#include "Arduino.h"

//leftMotorDirection = 0, rightMotorDirection = 0,
const int leftMotor1 = 7, leftMotor2 = 8;
const int rightMotor1 = 9, rightMotor2 = 10;

class motorsClass{
  public:
    void SETUP();
    void stop();
    void forward();
    void reverse();
    void left();
    void right();

};


extern motorsClass motors;

#endif
