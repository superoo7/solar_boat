#ifndef thingspeakAPI_h
#define thingspeakAPI_h

#include "Arduino.h"
#include <ThingSpeak.h>				// using thingspeak library
#include <WiFi.h>

// WiFiShield
// Declared WiFiShield class (initiate)
class wifiShieldClass{
public:
	// function
    wifiShieldClass();
    void SETUP();
};

extern wifiShieldClass wifishield;


// ThingSpeak
class thingspeakClass{
  public:
  	// function
    thingspeakClass();
    void SETUP();
    void UPDATE(float a, float b, float c, float d, float e, float f, float g, float h);
};

extern thingspeakClass thingspeak;

#endif
