#ifndef turbidity_h
#define turbidity_h

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
