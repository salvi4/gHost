#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_AUTH "your key"
#define FIREBASE_HOST "your db URL"
#define WIFI_SSID "your ssid"
#define WIFI_PASSWORD "your pass"

String values,sensor_data;

void setup()
{
  //Initializes the serial connection at 9600 get sensor data from arduino.
   Serial.begin(9600);
   
  delay(1000);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
  }
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}

void loop() 
{
  bool Sr=false;
 
  while(Serial.available())
  {
    //get sensor data from serial put in sensor_data
    sensor_data=Serial.readString(); 
    Sr=true;    
  }
  
  delay(1000);

  if(Sr==true)
  {  
    values=sensor_data;
  
    //get comma indexes from values variable
    int fristCommaIndex = values.indexOf(',');
    int secondCommaIndex = values.indexOf(',', fristCommaIndex+1);
    int thirdCommaIndex = values.indexOf(',', secondCommaIndex + 1);
  
    //get sensors data from values variable by  spliting by commas and put in to variables  
    String ultrasonic_value = values.substring(0, fristCommaIndex);
    String IR_sensor1_value = values.substring(fristCommaIndex+1, secondCommaIndex);
    String IR_sensor2_value = values.substring(secondCommaIndex+1);

    //store ultrasonic sensor data as string in firebase 
    Firebase.setString("ultrasonic_value",ultrasonic_value);
    delay(10);
    //store IR sensor 1 data as string in firebase 
    Firebase.setString("IR_sensor1_value",IR_sensor1_value);
    delay(10);
    //store IR sensor 2 data as string in firebase 
    Firebase.setString("IR_sensor2_value",IR_sensor2_value);

  /*
  delay(10);
  
  //store previous sensors data as string in firebase
  
  Firebase.pushString("previous_ultrasonic_value",ultrasonic_value);
   delay(10);
  Firebase.pushString("previous_IR_sensor1_value",IR_sensor1_value);
   delay(10);
  Firebase.pushString("previous_IR_sensor2_value",IR_sensor2_value);
  */
  
    delay(1000);
  
    if (Firebase.failed()) 
    {  
      return;
    }
  }   
}
