#ifndef wifishield_h
#define wifishield_h

#include "Arduino.h"
#include <WiFi.h>
#include <SPI.h>

class wifiShieldClass{
  public:
    wifiShieldClass();
    void SETUP();

};

extern wifiShieldClass wifishield;

#endif
