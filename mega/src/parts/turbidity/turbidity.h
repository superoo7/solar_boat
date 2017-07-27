#ifndef turbidity_h
#define turbidity_h

#include "Arduino.h"
// CONSTANT
// which analog pin to connect
#define TURBIDITYPIN A0

// Declared turbidity class (initiate)
class turbidityClass{
  public:

  	// class
    float TURBIDITY();


    // variable
    int turbidityValue;

};

extern turbidityClass turbidity;



#endif
