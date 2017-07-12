#ifndef ultrasonic_h
#define ultrasonic_h

#include "Arduino.h"
// right
#define trigPin1 3
#define echoPin1 2
// left
#define trigPin2 4
#define echoPin2 5
// front
#define trigPin3 46
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
