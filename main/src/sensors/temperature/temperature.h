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
    void PRINT();
    // constant

    // variable
    int val;

    // make it integer
    float mv, cel, farh;
};

extern temperatureClass temperature;

#endif
