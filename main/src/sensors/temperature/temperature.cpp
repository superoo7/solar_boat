#include "temperature.h"
// Temperature Sensor LM35

temperatureClass::temperatureClass(){
}

void temperatureClass::SETUP(){
  // empty
}

void temperatureClass::TEMPERATURE(){
  // void loop()
  val = analogRead(THERMISTORPIN);
  float mv = ( val / 1024.0 ) * 5000;
  float cel = mv / 10;

}

void temperatureClass::PRINT(){
  Serial.print("Celcius: ");
  Serial.println(temperature.cel);
}

temperatureClass temperature = temperatureClass();
