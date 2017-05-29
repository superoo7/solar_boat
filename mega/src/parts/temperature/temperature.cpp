#include "temperature.h"
// Temperature Sensor LM35

// function will return celcius value
float temperatureClass::TEMPERATURE(){
  // void loop()
  temperatureValue = analogRead(THERMISTORPIN);
  mv = ( temperatureValue / 1024.0 ) * 5000;
  return mv / 10;
}


temperatureClass temperature = temperatureClass();
