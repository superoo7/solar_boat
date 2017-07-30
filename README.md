# Solar Boat
## Instruction
[link](https://www.instructables.com/id/Sensors-and-MicroController-Used/)

## Description
An autonomous boat powered by solar that used Arduino Mega to collect data.
Setup of microcontroller please check [SENSOR.md](https://github.com/superoo7/solar-boat/blob/master/SENSOR.md)


Video is below

[![vid](https://img.youtube.com/vi/F-L40Tb0cZ8/0.jpg)](https://www.youtube.com/watch?v=F-L40Tb0cZ8)

## C++ short notes
[Notes.pdf](https://github.com/superoo7/solar-boat/blob/master/Notes.pdf)

## Choices of IDE: Arduino IDE, Atom(with platformIO)
For making OOP work, if Arduino IDE is used, we need to make all the files into libraries.
Atom (platformIO) is a preferred method for developing large projects like this.

## For testing:
we are using arduino UNO for testing and arduino MEGA for real use

in platformio.ini change:
uno -> megaatmega2560

`board = uno           ;megaatmega2560`

### Done
* Done ThingSpeak API Setup
* OOP part done for: _UltraSonic_, _Turbidity_, _Dissolved O2_, _Temperature_
* Detect UltraSonic Distance using [HC-SR04](https://www.amazon.com/SainSmart-HC-SR04-Ranging-Detector-Distance/dp/B004U8TOE6)
* **Tested** Use of temperature sensor LM35. circuit and codes:
![LM35](/reference/temperatureLM35/LM35.jpg)

source: [instructables](http://www.instructables.com/id/ARDUINO-TEMPERATURE-SENSOR-LM35/)
* Turbidity sensor done [reference](https://www.dfrobot.com/wiki/index.php/Turbidity_sensor_SKU:_SEN0189)
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


### Contributors
* Leo
* [Lai](http://www.github.com/superoo7)
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
* [GPS Setup visualisation](https://www.youtube.com/watch?v=D20uSl_JHrk)

