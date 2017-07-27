#ifndef GPS_h
#define GPS_h

#include <Arduino.h>
#include "TinyGPS++.h"				// GPS Library
#include <SoftwareSerial.h>


// declare pin to use and the baud rate
static const int RXPin = 44, TXPin = 45;
static const uint32_t GPSBaud = 9600;

// Declared GPS class (initiate)
class GPSClass{
public:
	// function
    void SETUP();
    void LOCATION();

    // variable
    int lng, lat;
};

extern GPSClass GPS;


#endif
