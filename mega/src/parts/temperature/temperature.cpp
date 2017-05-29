#include "temperature.h"
// Temperature Sensor LM35

temperatureClass::temperatureClass(){
}

void temperatureClass::SETUP(){
  // empty
}

float temperatureClass::TEMPERATURE(){
  // void loop()
  val = analogRead(THERMISTORPIN);
  mv = ( val / 1024.0 ) * 5000;
  cel = mv / 10;
  return cel;
}


temperatureClass temperature = temperatureClass();
