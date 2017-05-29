#ifndef temperature_h
#define temperature_h

#include "Arduino.h"

// CONSTANT
// which analog pin to connect
#define THERMISTORPIN A1

class temperatureClass{
  public:
    temperatureClass();
    void SETUP();
    void TEMPERATURE();

    // constant

    // variable
    int val;
    float mv, cel, farh;
};

extern temperatureClass temperature;

#endif
