#ifndef turbidity_h
#define turbidity_h

#include "Arduino.h"

#define TURBIDITYPIN A0


class turbidityClass{
  public:
    turbidityClass();
    void SETUP();
    void TURBIDITY();

    // variable
    int turbidityAnalogPin;
    float turbidityVoltageOutput;

};

extern turbidityClass turbidity;

#endif
