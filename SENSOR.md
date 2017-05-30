# SETUP OF THE MICROCONTROLLER
## THINGSPEAK
Go to [ThingSpeak.com](http://thingspeak.com), sign up an account.

After log in, Click on __New Channel__

ThingSpeak allows up to 8 fields for free account.

For this project, we used all 8 fields. (follow the pictures)

![ThingSpeak Setup](/images/ThingSpeak.png)

Copy __CHANNEL ID__ and __Write API Key__ (in API Keys) and paste it in [mega/src/parts/thingspeakAPI/internet.cpp](https://github.com/superoo7/solar_boat/blob/master/mega/src/parts/thingspeakAPI/internet.cpp) (shown in picture below)

![internet part](/images/Internet.png)

you can update the WiFi part with SSID and Password. (__ONLY WPA/WPA2 only__)

## WiFi Shield
**Name**: Arduino WiFi Shield
**Pin Used**: a shield that attach onto Arduino UNO / MEGA

![Arduino WiFi Shield](https://www.arduino.cc/en/uploads/Main/ArduinoWifiShield.jpg)

source: [arduino.cc about Arduino WiFi Shield](https://www.arduino.cc/en/Main/ArduinoWiFiShield)

## Dissolved Oxygen
**Name**: Part # KIT-103D

**Pin Used**: 

RX(Green): 14

TX(Yellow): 15

Only work on Arduino Mega

source: [dissolved oxygen](https://www.atlas-scientific.com/_files/code/Arduino-Mega-DO-Sample-Code.pdf)

## Temperature

**Name**: LM35 Temperature Sensor

**Pin Used**: Analog A1 (UNO)

We are going to make our own temperature sensor using LM35 which is available in Lab.
circuit and codes:

![LM35](/reference/temperatureLM35/LM35.jpg)

source: [instructables](http://www.instructables.com/id/ARDUINO-TEMPERATURE-SENSOR-LM35/)


## Turbidity

**Name**: Turbidity Sensor SEN0189

**Mode**: Analog

**Pin Used**: Analog A0 (UNO)

![Turbidity Sensor](https://www.dfrobot.com/wiki/images/5/59/SEN0189.jpg)

source:
[reference](https://www.dfrobot.com/wiki/index.php/Turbidity_sensor_SKU:_SEN0189)

## UltraSonic sensors

**Name**: HC-SR04

**Pin Used**: 3 sensors is used

| Sonar         | echoPin| trigPin  |
| ------------- |:------:| --------:|
| Sonar1        | 2      | 3        |
| Sonar2        | 6      | 7        |
| Sonar3        | 8      | 9        |



![HC-SR04](https://www.microcontrollerelectronics.com/wp-content/uploads/2014/10/HCSR04.jpg)

source:

[HC-SR04](https://www.amazon.com/SainSmart-HC-SR04-Ranging-Detector-Distance/dp/B004U8TOE6)

[Deployment of multiple UltraSonic](https://www.youtube.com/watch?v=dSIEuxMHVSI)

## Compass
![Compass GY-271](https://i2.wp.com/henrysbench.capnfatz.com/wp-content/uploads/2015/09/GY-273-Magnetometer-Pin-Outs.png)

**Name**: Compass GY-271

**Pin Used**: 

* GY-273 Compass Module -> Arduino
* VCC -> VCC (See Note Below)
GND -> GND
* SCL -> A5/SCL, (Use Pin 21 on the Arduino Mega)
* SDA -> A4/SDA, (Use Pin 20 on the Arduino Mega)
* DRDY -> Not Connected

reference:

[HMC5883L_Simple](https://github.com/sleemanj/HMC5883L_Simple)

[Source Code](http://henrysbench.capnfatz.com/henrys-bench/arduino-sensors-and-input/arduino-gy-273-hmc5883l-magnetometer-compass-tutorial/)
