#ifndef internet_h
#define internet_h

#include "Arduino.h"
#include <WiFi.h>
#include <SPI.h>
#include "ThingSpeak/ThingSpeak.h"          // Library from ThingSpeak

// WiFiShield
class wifiShieldClass{
  public:
    wifiShieldClass();
    void SETUP();

};

extern wifiShieldClass wifishield;


// ThingSpeak 
class thingspeakClass{
  public:
    thingspeakClass();
    void SETUP();
    void update();
};

extern thingspeakClass thingspeak;


#endif
