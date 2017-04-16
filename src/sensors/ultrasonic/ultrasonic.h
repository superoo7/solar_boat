#ifndef ultrasonic_h
#define ultrasonic_h


class ultrasonicClass{
  public:
    ultrasonicClass();
    void SETUP();
    void DISTANCE();
    // defines pins numbers
    // const uint8_t trigPin =  9;
    // const uint8_t echoPin = 10;
    const int trigPin {9};
    const int echoPin {10};

    // defines variables
    long duration;
    int distance;
};

extern ultrasonicClass ultrasonic;

#endif
