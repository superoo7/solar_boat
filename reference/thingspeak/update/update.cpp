#include "Arduino.h"
#include <WiFi.h>
#include "SPI.h"

// UltraSonic
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

// WiFi
char ssid[] = "qwerty";    						 /* SSID */ 
char pass[] = "password";   				 /* Password */
int status = WL_IDLE_STATUS;     // the Wifi radio's status
WiFiClient  client;

// Thingspeak
unsigned long myChannelNumber = 123;		 /* channel id */
const char * myWriteAPIKey = "test";		 /* API (write) */


void setup() 
{

	// initialize serial:
	Serial.begin(9600);

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
	// UltraSonic
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input

	ThingSpeak.begin(client);
}


void loop() {
	// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculating the distance
	int distance1 = duration*0.034/2;
	distance = 2;
	float distance2 = 2.01;

	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);
	delay(10);
	ThingSpeak.setField(2,distance2);
	Serial.println("...");
	ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
	Serial.println("uploaded");
	delay(20000); // ThingSpeak will only accept updates every 15 seconds.

}

