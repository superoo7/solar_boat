#ifndef GPS_h
#define GPS_h

#include <Arduino.h>
#include "TinyGPS++.h"
#include <SoftwareSerial.h>

// Change this! (need pwm)
// static const int RXPin = 4, TXPin = 3;
static const int RXPin = 44, TXPin = 45;
static const uint32_t GPSBaud = 9600;

class GPSClass{
public:

    void SETUP();
    void LOCATION();
    int lng, lat;
};

extern GPSClass GPS;


#endif
