# Smart_car_parking-Project

##Description:
Smart car parking is a project where real-time information regarding parking space is updated immediately on entrance of parking lot. LCD display before car enters to 
parking space. The available or unavailable parking spaces are displayed simply using LCD display and LED's.These processes together with sensor and update the status 
on each parking slot, its data is managed on the cloud.

##Hardware:
1. Sensors              : Ultrasonic sensors
2. Controller/Modules   : ATmega16A, Xbee s2c wireless module with Antenna, XBee USB Adapter based on CP2102 IC
3. Display              : LCD display, LED's

##Software: 
1. IDE                      : Microchip studio, Digi XCTU
2. Communication protocols  : MQTT, Zigbee 
3. IOT                      : AWS, Node-Red
4. Programming language     : Embedded-C, Micro-python

## Folder details:
1. LCD_DISPLAY : This folder contains lcd driver code and lcd application code for display. It also have .hex file which you can directly dump into microcontroller and
it will display information.
