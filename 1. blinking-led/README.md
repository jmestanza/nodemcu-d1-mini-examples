# Blinking LED example

In this first project we'll see what needs to be configured in order to run the basic led blinking example of Arduino.

Arduino IDE can be downloaded here: https://www.arduino.cc/en/software.

All the code examples were run in Microsoft Windows 10 Home, but Arduino can be downloaded to both Linux and Mac.

## Cheking that the device is connected

First of all let's check that Arduino IDE recognizes our device.

- Plug in the Nodemcu D1 Mini with a micro USB cable.
- In Arduino IDE go to `Tools->Port ` and check that you can select a port (in which the module is connected).

If you're having trouble with this part the problem might be that the USB cable is not the right one (e.g. it has the power lines but does not have the communication/data lines) or it may be some driver issue.

## Installing Arduino on ESP8266 with Boards Manager

For the installation process of the ESP8266 in Arduino, please check the following tutorial
https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/

**\[Optional\]** if you want to get the Board Manager URL directly from the source you can check the instructions given in [**Installing with Boards Manager**] section of the following link: https://github.com/esp8266/Arduino/

## Run the example!

Go to `File->Examples->0.1 Basics->Blink` to get the example code.

In order to run our programs we should always click on **Verify** to check that everything we have written compiles.

If compilation step goes well, we then have to click on **Upload** and the code will be updated in the flash memory of the board, meaning that the program that we just modified will be the one that is running.

If all the steps went well you should see the blue LED turned on! 🥳🎉.
