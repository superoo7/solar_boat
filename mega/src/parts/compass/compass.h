#ifndef compass_h
#define compass_h

#include "Arduino.h"
#include <Wire.h> //I2C Arduino Library
#define addr 0x1E //I2C Address for The HMC5883

class compassClass{
public:
  compassClass();
  void SETUP();
  void COMPASS();

  // variable
  int x,y,z; //triple axis data
};

extern compassClass compass;




#endif
