#include "dissolvedO2.h"
// Dissolved Oxygen sensor



void dissolvedO2Class::SETUP(){
  // void setup()

  sensorstring.reserve(30);
}


float dissolvedO2Class::DISSOLVEDO2(){
  // void loop()
  // reset
  sensorstring = "";                                  //clear the string:
  sensor_string_complete = false;                     //reset the flag used to tell if we have received a completed string from the Atlas Scientific product

  if (sensor_string_complete == true) {               //if a string from the Atlas Scientific product has been received in its entirety
    Serial.println(sensorstring);                     //send that string to the PC's serial monitor
    if (isdigit(sensorstring[0])) {                   //if the first character in the string is a digit
      DO = sensorstring.toFloat();                    //convert the string to a floating point number so it can be evaluated by the Arduino
      return DO;

    } else {
      return 0;
    }
  }

}


dissolvedO2Class dissolvedO2 = dissolvedO2Class();
