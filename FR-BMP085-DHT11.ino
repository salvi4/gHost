//Libreries
#include <Adafruit_BMP085.h>
#include "DHT.h"

// Constants
#define DELAY 1000 // Delay between two measurements in ms
#define VIN 5 // V power voltage
#define R 10000 // Ohm resistance value
#define DHT11_PIN 6 // Pin connected to DHT11
#define DHTTYPE DHT11 // Type of sensor
const int sensorPin = A0; // Pin connected to photoresistor

//Variables
int16_t sensorVal; // Analog value from the sensor
int16_t lux; //Lux value
String values;

//Objects
Adafruit_BMP085 bmp;
DHT dht(DHT11_PIN, DHTTYPE);
  
void setup() {
  Serial.begin(9600);
  bmp.begin();
  dht.begin();
}
  
void loop() 
{
  /*
    //Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(F("*C"));
    
    //Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(F("Pa"));

    //Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(F("m"));

    //Serial.print("Humidity = ");
    Serial.print(dht.readHumidity());
    Serial.println(F("%"));

    lux=sensorRawToPhys(analogRead(sensorPin));
    //Serial.print(F("Physical value from sensor = "));
    Serial.print(lux); // the analog reading
    Serial.println(F(" lumen")); // the analog reading
    
    Serial.println();
    delay(DELAY);*/

    values= ((String)bmp.readTemperature()+','+(String)bmp.readPressure()+','+(String)dht.readHumidity());
    delay(1000);
    // removed any buffered previous serial data.
    Serial.flush();
    delay(1000);
    // sent sensors data to serial (sent sensors data to ESP8266)
    Serial.print(values);
    delay(2000);
}

int sensorRawToPhys(int raw)
{
  // Conversion rule
  float Vout = float(raw) * (VIN / float(1023));// Conversion analog to voltage
  float RLDR = (R * (VIN - Vout))/Vout; // Conversion voltage to resistance
  int phys=500/(RLDR/1000); // Conversion resitance to lumen
  return phys;
}
