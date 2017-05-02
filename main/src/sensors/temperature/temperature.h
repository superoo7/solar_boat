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

    // variable 
    int val;
    float mv, cel;
};

extern temperatureClass temperature;

#endif
