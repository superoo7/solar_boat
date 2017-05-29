#include "turbidity.h"

// analog output

turbidityClass::turbidityClass(){
}

// no setup required
void turbidityClass::SETUP(){
}

void turbidityClass::TURBIDITY(){
  turbidityAnalogPin = analogRead(TURBIDITYPIN);// read the input on analog pin 0:
  turbidityVoltageOutput = turbidityAnalogPin * ( 5.0 / 1024.0 ); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

}

turbidityClass turbidity = turbidityClass();
