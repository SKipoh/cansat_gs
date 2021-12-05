# CANsat Ground Station Arduino

This is the code the Arduino Ground Station Repeater, used as part of the ESA CANsat competition. This repo is designed to be used with my two other CANsat projects: [CANsat Payload Code](https://github.com/SKipoh/pfio_cansat), [CANsat Web App Dashboard](https://github.com/SKipoh/cansat_app)

The code in this repo is only to be used for a ground station "repeater" arduino if you don't have a USB-to-Serial adapter for the APC220

All this code does is read in the data from the APC220 and then write it over the hardware serial port to the host computer

---

## How to use this code

1) Load the project into PlatformIO
2) Check build configuration is correct for your MCU in platform.ini
3) If you are using an Arduino Due as your groundstation comment out lines 2 - 25 and uncomment all the code underneath the comment: ```// IF USING ARDUINO DUE:```
4) Build the code and confirm you are getting no errors. If any do occur and you are using the Arduino Due, ensure that the ```#include <Arduino.h>``` line is UNCOMMENTED and the line ```#include <SoftwareSerial.h>``` IS COMMENTED. If you are using the Arduino Mega or Arduino Nano, leave the code how it is, but ensure that the SoftwareSerial & Arduino Libraries are UNCOMMENTED, and that the github link to SoftwareSerial is still valid
5) If you get no build errors, you can plug your chosen MCU in and upload the code

---

## Communicating with the CANsat & Ground Station Operations

To communicate with this ground station you can use PlatformIO's, or the Arduino IDE's built in Serial Monitor to send the individual commands read back Sensor Data

There are 3 commands you can send to the CANsat:

```c++
a
```

This command tells the CANsat to move the Servo to the "open" or "released" position. This is used when you want to initially setup the CANsat and attach the wire for the release mechanism. You also send this command when you wish to drop the CANsat

```c++
b
```

Send this command to the CANsat when you want to set the release mechanism, this will rotate the servo so the wire for the release is between the two fins and holding the line coming from the ballon

```c++
c
```

When you want to toggle the sensors on and begin receiving data, you send a "c". When the CANsat recieves this byte, on the next loop of code it will toggle a bool that will then tell the CANsat to begin taking measurements, formatting them, and sending them back down to the Ground Station 
