#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Servo.h>


char auth[] = "YJMldNasQhI0TDIJhZ8ltIwYC60E9vxV";


char ssid[] = "Piratu'";
char pass[] = "rapadungaidunga";

int angle = 0;
bool servoRunning = false;
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX


#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

Servo servo;

BLYNK_WRITE(V3)
{
  if(param.asInt() == 1) {     // if Button sends 1
    servoRunning = true;
    servoRun();             // start the function
  }
}

BLYNK_WRITE(V4)
{
  if(param.asInt() == 1) {
    servoRunning = false; // if Button sends 1
    servoWalk();             // start the function
  }
}

void servoWalk(){
  while(servoRunning == false){
    for(angle = 0; angle <= 90; angle += 5)    // command to move from 0 degrees to 90 degrees 
  {                                  
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(300);
  
  for(angle = 90; angle>= 0; angle-= 5)     // command to move from 90 degrees to 0 degrees 
  {                                
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(300);
  }
  
}

void servoRun(){
   while (servoRunning == true)
   {
    for(angle = 0; angle <= 120; angle += 5)    // command to move from 0 degrees to 120 degrees 
  {                                  
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(200);
  
  for(angle = 120; angle>=0; angle-= 5)     // command to move from 120 degrees to 0 degrees 
  {                                
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(200);
   }
   
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);

  servo.attach(9);
}

void loop()
{
  Blynk.run();
}
