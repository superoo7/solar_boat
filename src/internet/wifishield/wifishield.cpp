#include "wifishield.h"

char ssid[] = "SSID";     //  your network SSID (name)
char pass[] = "PassWord";   // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status


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
