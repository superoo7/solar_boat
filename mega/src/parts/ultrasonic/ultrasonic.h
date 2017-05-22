#ifndef ultrasonic_h
#define ultrasonic_h

#include "Arduino.h"
#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8



class ultrasonicClass{
public:

    long rightSensor,frontSensor,leftSensor;

    ultrasonicClass();
    void SETUP();
    long frontSensorDistance();
    long leftSensorDistance();
    long rightSensorDistance();
};

extern ultrasonicClass ultrasonic;




#endif
