#ifndef motors_h
#define motors_h

#include "Arduino.h"


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
