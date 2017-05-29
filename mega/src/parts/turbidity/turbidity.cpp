#include "turbidity.h"
// Turbidity Sensor SKU: SEN0189


float turbidityClass::TURBIDITY(){
  // void loop()
  turbidityValue = analogRead(TURBIDITYPIN);
  return turbidityValue * ( 5.0 / 1024.0 );
}


turbidityClass turbidity = turbidityClass();
