# Using Arduino 
## Choices of IDE: Arduino IDE, Atom(with platformIO), Eclipse

## ToDo List
- Jason: LM35 Temperature Sensor
- Improve the OOP part of the code (maybe use of a template in C++)
- Check the code for Ultrasonic Avoidance system done by Leo
- Connect to Thingspeak with WiFi Module

### Done
* OOP part done for: _UltraSonic_, _Turbidity_
* Detect UltraSonic Distance using [HC-SR04](https://www.amazon.com/SainSmart-HC-SR04-Ranging-Detector-Distance/dp/B004U8TOE6)
* Temperature sensor uses _OneWire.h_ and _DallasTemperature.h_ 
* Use of temperature sensor LM35. circuit and codes:
![LM35](/reference/temperatureLM35/LM35.jpg)
source: [instructables](http://www.instructables.com/id/ARDUINO-TEMPERATURE-SENSOR-LM35/)
* Turbidity sensor done [reference](https://www.dfrobot.com/wiki/index.php/Turbidity_sensor_SKU:_SEN0189)
* pH Sensor done
* added library
* Done OOP Object setup

### reference/leow
Original file by leow
Arduino 1 has the GPS module, if you want to test it, test it on the TinyGPS++ "Full example" first, once it is okay, run the Final Arduino 2 file, that file is to upload the GPS to ThingSpeak

Arduino 2 attaches the compass for the bearing, which is supposedly to be run on Autopilot Main file

### Problem
* error handling when sensors failed to display data
* wifi code has something wrong

### Reference

#### Libraries
* [OneWire.h](https://github.com/PaulStoffregen/OneWire)
* [DallasTemperature.h](https://github.com/milesburton/Arduino-Temperature-Control-Library)

#### Referred Website
* [UltraSonic HC-SR04 setup](http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)



