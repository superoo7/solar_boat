//Turbidity sensor - a1 pin

#include "Arduino.h"

void setup()
{
  Serial.begin(9600);
  delay(5000);

} // end setup()

void loop()
{
  int sensorValue = analogRead(A1);// read the input on analog pin 0:
  float voltage1 = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.print(voltage1); // print out the value you read:
}

