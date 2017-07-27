#ifndef motors_h
#define motors_h

#include "Arduino.h"

// Declared motor class (initiate)
class motorsClass{
  public:
  	// function
    void SETUP();
    void stop();
    void forward();
    void reverse();
    void left();
    void right();

};


extern motorsClass motors;

#endif
