#include "internet.h"

// WiFi
char ssid[] = "";     //  your network SSID (name)
char pass[] = "";   // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
WiFiClient  client;

// ThingSpeak
unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "";

wifiShieldClass::wifiShieldClass(){

}

void wifiShieldClass::SETUP(){
  // attempt to connect using WPA2 encryption:
    Serial.println("Attempting to connect to WPA network...");
    status = WiFi.begin(ssid, pass);

    // if you're not connected, stop here:
    if ( status != WL_CONNECTED) {
      Serial.println("Couldn't get a wifi connection");
      while(true);
    }
    // if you are connected, print out info about the connection:
    else {
      Serial.println("Connected to network");
    }
}

// ThingSpeak
thingspeakClass::thingspeakClass(){

}

void thingspeakClass::SETUP(){
  ThingSpeak.begin(client);
}

// a->temp, b->turb, c->o2, d->compassX, e->compassY, f->compassZ, g->GPSLong, h->GPSLat

void thingspeakClass::UPDATE(float a, float b, float c, float d, float e, float f, float g, float h){
    float arr[] = {a,b,c,d,e,f,g,h};

    for(int cter = 1; cter <= 8; cter++) {
      // convert to long since thingspeak API does not take in float data type
      ThingSpeak.setField(cter, (long)arr[cter-1]);
      Serial.println((long)arr[cter-1]);
    }
  // Write the fields that you've set all at once.
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);



}

wifiShieldClass wifishield = wifiShieldClass();
thingspeakClass thingspeak = thingspeakClass();
