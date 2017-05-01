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
  float farh = ( cel * 9 ) / 5 + 32;
  
}

temperatureClass temperature = temperatureClass();
