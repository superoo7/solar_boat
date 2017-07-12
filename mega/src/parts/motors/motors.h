#ifndef motors_h
#define motors_h

#include "Arduino.h"

const int leftMotorDirection = 22, leftMotor1 = 23, leftMotor2 = 24;
const int rightMotorDirection = 25, rightMotor1 = 26, rightMotor2 = 27;

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
