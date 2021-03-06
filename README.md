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
- Flash the ESP01's firmware in order to serial communicate with Arduino with a baud rate of 9600. (You can use this tutorial: https://www.youtube.com/watch?v=Ag_Yk_0AFxs)
- Create the database.

Using:
- Card manager:
  - esp8266 card manager by ESP8266 community. Version: 3.0.1 (File > Preferences > Additional Boards Manager URLs: https://arduino.esp8266.com/stable/package_esp8266com_index.json)
- Libraries:
  - Adafruit BMP085 Library. Version 1.1.0 (https://github.com/adafruit/Adafruit-BMP085-Library)
  - Arduino JSON Library. Version 5.13.5 (https://arduinojson.org/v6/doc/installation/)
  - DHT sensor Library. Version 1.4.3 (https://github.com/adafruit/DHT-sensor-library)
  - Firebase Arduino Client Library for ESP8266 and ESP32. Version 2.3.7 (https://github.com/mobizt/Firebase-ESP-Client)
    - Commented all the libraries except for the real-time one in the FirebaseFS.h file.
  - ESP8266WiFi Library 
- Database:
  - Realtime database with rules settled: only auth user can read/write on the db




