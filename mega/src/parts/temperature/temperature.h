#ifndef temperature_h
#define temperature_h

#include "Arduino.h"
// CONSTANT
// which analog pin to connect
#define THERMISTORPIN A1

class temperatureClass{
  public:


    float TEMPERATURE();


    // variable
    int temperatureValue;
    float mv;
};

extern temperatureClass temperature;



#endif
