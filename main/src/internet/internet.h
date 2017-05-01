#ifndef internet_h
#define internet_h

#include "Arduino.h"
#include <WiFi.h>
#include <SPI.h>
#include "ThingSpeak/ThingSpeak.h"

class wifiShieldClass{
  public:
    wifiShieldClass();
    void SETUP();

};

extern wifiShieldClass wifishield;



class thingspeakClass{
  public:
    thingspeakClass();
    void SETUP();
    void update();
};

extern thingspeakClass thingspeak;


#endif
