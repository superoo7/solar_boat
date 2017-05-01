#include "Arduino.h"
#include "ThingSpeak.h"
#include <WiFi.h>
#include "SPI.h"

// setup wifi (WPA)
// using Arduino WiFi Shield
char ssid[] = "SSID"; 												/* SSID */
char pass [] = "PASSWORD";										/* Password */
int status = WL_IDLE_STATUS;
WiFiClient client;

// Thingspeak API
// channel need to be public
unsigned long myChannelNumber = 123456; 			/* Channel number */

void setup() {
  // initialize serial:
	 Serial.begin(9600);
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
	
	// Start ThingSpeak after connected to wifi
	ThingSpeak.begin(client);


}

void loop() {
	String sentence = ThingSpeak.readStringField(myChannelNumber, 1);
	Serial.println("");
	Serial.println("");
	Serial.println("");
	Serial.println(sentence);
	Serial.println("done");

	delay(10000);
										  
}
