#include "GPS.h"

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

// declare func
static float printFloat(float val, bool valid, int len, int prec);
static void smartDelay(unsigned long ms);

void GPSClass::SETUP() {
  // void setup()
  ss.begin(GPSBaud);
  Serial.println("Done setup for GPS");
}

void GPSClass::LOCATION() {
  lat = printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);  // get value of latitude
  lng = printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);  // get value of longitude
  smartDelay(1000);

  if (millis() > 5000 && gps.charsProcessed() < 10)                     // if did not reveive GPS signal
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
    // since thingspeak only accept whole number (int/long), so by making 10^6, ensure to keep the precision of the location
    return val;
  }
  smartDelay(0);
}


GPSClass GPS = GPSClass();
