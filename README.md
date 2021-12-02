# CANsat Ground Station Arduino

This is the code the Arduino Ground Station Repeater, used as part of the ESA CANsat competition. This repo is designed to be used with my two other CANsat projects: [CANsat Payload Code](https://github.com/SKipoh/pfio_cansat), [CANsat Web App Dashboard](https://github.com/SKipoh/cansat_app)

The code in this repo is only to be used for a ground station "repeater" arduino if you don't have a USB-to-Serial adapter for the APC220

All this code does is read in the data from the APC220 and then write it over the hardware serial port to the host computer

## How to use this code

- Load the project into PlatformIO
- Check build configuration is correct for your MCU
- Check it builds correctly
- Upload to arduino
