// Header file is used to include all the other sensors file

#ifndef header_h
#define header_h

#include "Arduino.h"

// internet
#include "parts/thingspeakAPI/internet.h"		// WiFi Shield and Thingspeak API

// sensors
#include "parts/temperature/temperature.h"      // LM35 temperature sensor
#include "parts/ultrasonic/ultrasonic.h"        // 3 ultrasonic sensor
#include "parts/turbidity/turbidity.h"          // turbidity sensor
#include "parts/dissolvedO2/dissolvedO2.h"      // dissolvedO2 sensor
#include "parts/compass/compass.h"              // compass
#include "parts/GPS/GPS.h"                      // GPS

// motor
#include "parts/motors/motors.h" 				// motor shield

#endif
