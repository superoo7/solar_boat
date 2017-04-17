#include "header.h"

void serialPrintResult();

void setup()
{
  turbidity.SETUP();
  // ultrasonic.SETUP();
  Serial.begin(9600);
  // temperature.SETUP();

}

void loop()
{
  turbidity.TURBIDITY();
  // ultrasonic.DISTANCE();
  // temperature.TEMPERATURE();
  delay(10);
  // insert error handling
  serialPrintResult();

  delay(1000);

}

void serialPrintResult()
{
  Serial.print("Turbidity: ");
  Serial.println(turbidity.turbidityVoltageOutput);
  // Serial.print("Distance: ");
  // Serial.println(ultrasonic.distanceTravelled);
  // Serial.print("Celcius: ");
  // Serial.println(temperature.cel);
  // Serial.println("Farenheit: ");
  // Serial.println(temperature.farh);
  // Serial.println(" ");


}
