//for collecting GPS data and transfering longtitude and lattitude to thingspeak 
//arduino 2 

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ThingSpeak.h>
#define USE_WIFI101_SHIELD
#include <SPI.h>
#include <WiFi.h>
char ssid[] = "melvin";    //  your network SSID (name) 
    char pass[] = "29052012";   // your network password
    int status = WL_IDLE_STATUS;
    
    WiFiClient  client;
    
unsigned long myChannelNumber = 179216;
const char * myWriteAPIKey = "OOIHZJXIQJZE1G4J";

static const int RXPin = 2, TXPin = 3;
float lattitude,longtitude; 
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  Serial.println("Arduino starting...");
WiFi.begin(ssid, pass);
Serial.println("Connected.");
ThingSpeak.begin(client);
Serial.println("Connected to ThingSpeak.");
  ss.begin(GPSBaud);

  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    longtitude=gps.location.lng();
    lattitude=gps.location.lat();
    ThingSpeak.setField(2,longtitude);
    ThingSpeak.setField(3,lattitude);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); 
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(F("."));
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
