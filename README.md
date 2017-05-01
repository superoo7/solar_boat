# Solar Boat
## Description
An autonomous boat powered by solar that used Arduino Mega to collect data.

## Choices of IDE: Arduino IDE, Atom(with platformIO)
For making OOP work, if Arduino IDE is used, we need to make all the files into libraries.
Atom (platformIO) is a preferred method for developing large projects like this.

## For testing:
we are using arduino UNO for testing and arduino MEGA for real use

in platformio.ini change:
uno -> megaatmega2560

`board = uno           ;megaatmega2560`


## ToDo List
- Jason: LM35 Temperature Sensor
- Improve the OOP part of the code (maybe use of a template in C++)
- Check the code for Ultrasonic Avoidance system done by Leo
- Added ThingSpeak Code into main file
- Make Serial.println of the data sent to ThingSpeak and put it as an Obj Function

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
* Basic setup of ThingSpeak (update and read) in reference

### reference/leo
Original file by leo
Arduino 1 has the GPS module, if you want to test it, test it on the TinyGPS++ "Full example" first, once it is okay, run the Final Arduino 2 file, that file is to upload the GPS to ThingSpeak

Arduino 2 attaches the compass for the bearing, which is supposedly to be run on Autopilot Main file

### reference/ThingSpeak
#### Thingspeak for testing:

##### UPDATE
`https://api.thingspeak.com/update?api_key=APIKEYS&field1=1&field2=2&field3=3`
The thingspeak will return a number that indicates the location/sequence of the number

##### READ from public
`https://thingspeak.com/channels/123456`


### Problem
* error handling when sensors failed to display data
* wifi code has something wrong (resolved)

### Contributors
* Leo
* [Lai](superoo7.com)
* Jason
* Anis
* Puteri

### License
read [LICENSE.txt](https://github.com/superoo7/solar-boat/blob/master/LICENSE.txt) (MIT License)

### Reference

#### Libraries
* [OneWire.h](https://github.com/PaulStoffregen/OneWire)
* [DallasTemperature.h](https://github.com/milesburton/Arduino-Temperature-Control-Library)

#### Referred Website
* [UltraSonic HC-SR04 setup](http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
* [ThingSpeak Arduino setup](http://community.thingspeak.com/tutorials/arduino/send-data-to-thingspeak-with-arduino/)
* [ThingSpeak GitHub (check example)](https://github.com/mathworks/thingspeak-arduino)


