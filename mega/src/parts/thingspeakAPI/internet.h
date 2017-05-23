#ifndef thingspeakAPI_h
#define thingspeakAPI_h

#include "Arduino.h"
#include <ThingSpeak.h>
#include <WiFi.h>

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
    void UPDATE(long a, long b, long c);
};

extern thingspeakClass thingspeak;

#endif
