#ifndef ultrasonic_h
#define ultrasonic_h

#include "Arduino.h"

class ultrasonicClass{
  public:
    ultrasonicClass();
    void SETUP();
    void DISTANCE();
    // defines pins numbers
    // const uint8_t trigPin =  9;
    // const uint8_t echoPin = 10;
    const int ultraSonicTrigPin {9};
    const int ultraSonicEchoPin {10};

    // defines variables
    long timeTakenToTravel;
    int distanceTravelled;
};

extern ultrasonicClass ultrasonic;

#endif
