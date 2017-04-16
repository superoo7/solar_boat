// analog output
#include "Arduino.h"
#include "turbidity.h"

turbidityClass::turbidityClass(){
}

// no setup required
void turbidityClass::SETUP(){
}

void turbidityClass::TURBIDITY(){
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
}

turbidityClass turbidity = turbidityClass();
