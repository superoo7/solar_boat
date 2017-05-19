#include "header.h"


void setup()
{
  Serial.begin(9600);
  wifishield.SETUP();
  thingspeak.SETUP();

}

void loop()
{
  // dissolved oxygen
  // temperature
  // turbidity

  for(int cnt = 0; cnt <= 40; cnt++) {
    thingspeak.UPDATE(1.1*cnt , 2.2*cnt , 3.3*cnt);

    delay(20000); // ThingSpeak will only accept updates every 15 seconds.
  }
}
