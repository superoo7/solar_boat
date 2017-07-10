#include "TinyGPS++.h"
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);

  Serial.println(F("GPS"));
  Serial.println(F("Latitude   Longitude"));
}

void loop() {

  float lng, lat;
  
  // print lat and long

  lat = printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  lng = printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  Serial.println("Latitude | Longitude");
  Serial.print(lat);
  Serial.print(" | ");
  Serial.print(lng);
  Serial.println("");
  smartDelay(1000);

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));


}

// This custom version of delay() ensures that the gps object
// is being "fed".
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static float printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    return val;
  }
  else
  {
    Serial.print(val, prec);
    val = val*1000000;
    return val;
  }
  smartDelay(0);
}

