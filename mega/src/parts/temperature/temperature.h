#ifndef temperature_h
#define temperature_h

#include "Arduino.h"

// CONSTANT
// which analog pin to connect
#define THERMISTORPIN A1

// Declared temperature class (initiate)
class temperatureClass{
  public:

  	// function
    float TEMPERATURE();


    // variable
    int temperatureValue;
    float mv;
};

extern temperatureClass temperature;



#endif
