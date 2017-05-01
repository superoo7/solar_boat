#ifndef ultrasonic_h
#define ultrasonic_h

#include "Arduino.h"

class ultrasonicClass{
  public:
    ultrasonicClass();
    void SETUP();
    void DISTANCE();

    // defines pins numbers
    const int ultraSonicTrigPin = 9;
    const int ultraSonicEchoPin = 10;

    // defines variables
    long timeTakenToTravel;
    int distanceTravelled;
};

extern ultrasonicClass ultrasonic;

#endif
