#include "header.h"

void serialPrintResult();

void setup()
{
  turbidity.SETUP();
  ultrasonic.SETUP();
  Serial.begin(9600);
  temperature.SETUP();
  // wifishield.SETUP();
  // thingspeak.SETUP();
}

void loop()
{
  turbidity.TURBIDITY();
  ultrasonic.DISTANCE();
  temperature.TEMPERATURE();
  delay(10);
  // insert error handling
  serialPrintResult();

  delay(1000);

}


void serialPrintResult()
{
  turbidity.PRINT();
  Serial.print("Distance: ");
  Serial.println(ultrasonic.distanceTravelled);
  temperature.PRINT();
  Serial.println(" ");


}
