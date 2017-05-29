#ifndef dissolvedO2_h
#define dissolvedO2_h
// Dissolved Oxygen sensor
#include "Arduino.h"
                  //define how the soft serial port is going to work

class dissolvedO2Class{
  public:

    void SETUP();
    float DISSOLVEDO2();

    // variables
    float DO;                                             //used to hold a floating point number that is the DO                                            //used to hold a floating point number that is the DO
    String sensorstring = "";
    boolean sensor_string_complete = false;

    //function
    void serialEvent3() {                                 //if the hardware serial port_3 receives a char
        sensorstring = Serial3.readStringUntil(13);         //read the string until we see a <CR>
        sensor_string_complete = true;                      //set the flag used to tell if we have received a completed string from the PC
    }


};

extern dissolvedO2Class dissolvedO2;



#endif
