# gHost
gHost is a project to interface Arduino with Firebase using an ESP8266-01 module.

In this project I'll use:
- Arduino UNO REV3
- ESP8266-01 WiFi module
- BMP085 module
- DHT11 module
- Photoresistor

The main goal of this project is to communicate the data fetched from Arduino to Firebase realtime database, serial communicating this data to the ESP01 module.

Mandatory passage:
I flashed the ESP01's firmware in order to serial communicate with Arduino with a baud rate of 9600.
Create the database.

Using:
- Card manager:
  esp8266 card manager by ESP8266 community. Version: 2.5.0 (File > Preferences > Additional Boards Manager URLs: https://arduino.esp8266.com/stable/package_esp8266com_index.json)
- Libraries:
  Adafruit BMP085 Library. Version 1.1.0 (https://github.com/adafruit/Adafruit-BMP085-Library)
  Arduino JSON Library. Version 5.13.5 (https://arduinojson.org/v6/doc/installation/)
  DHT sensor Library. Version 1.4.3 (https://github.com/adafruit/DHT-sensor-library)
  Firebase-Arduino Library. Version 0.3 (https://github.com/FirebaseExtended/firebase-arduino)
  ESP8266WiFi Library 
- Database:
  Realtime database in test-mode



