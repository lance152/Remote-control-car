
//#include "Ultrasonic.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <SoftwareSerial.h>

#define WIFI_TX       9
#define WIFI_RX       8
SoftwareSerial wifi(WIFI_RX, WIFI_TX);   //RX, TX

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *RR = AFMS.getMotor(1);
Adafruit_DCMotor *RF = AFMS.getMotor(2);
Adafruit_DCMotor *LF = AFMS.getMotor(3);
Adafruit_DCMotor *LR = AFMS.getMotor(4);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);
//Ultrasonic ultrasonic(12,13);

char val;  // variable to recerive data from serial port

void setup() {
  Serial.begin(115200);           // set up Serial library at 9600 bps
  

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  Serial.println("DC Motor Ready!!");

  wifi.begin(115200); 
  Serial.println("Wifi is ready!");
}

void loop() {

//  Serial.print(ultrasonic.Ranging(CM));
//  Serial.println("cm");
//  
//  if(Serial.available())
//  {
//    val=Serial.read();
//    }
    while(wifi.available()>0){
    char c= wifi.read();
    Serial.println(c);
    if(c=='W'){
      Serial.println("Connected");
    }

    switch(c){
      case 'F':
        forward();
        break;
      case 'B':
        reverse();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'S':
        st();
        break;
    }
  }
}

void forward( ){
  RR->setSpeed(150);
  RF->setSpeed(150);
  LR->setSpeed(150);
  LF->setSpeed(150);
  
  RR->run(FORWARD);
  RF->run(FORWARD);
  LR->run(FORWARD);
  LF->run(FORWARD);
  }

void reverse(){
  RR->setSpeed(150);
  RF->setSpeed(150);
  LR->setSpeed(150);
  LF->setSpeed(150);
  
  RR->run(BACKWARD);
  RF->run(BACKWARD);
  LR->run(BACKWARD);
  LF->run(BACKWARD);
  }
  
void left(){
  RR->setSpeed(160);
  RF->setSpeed(130);
  LR->setSpeed(150);
  LF->setSpeed(0);
  
  RR->run(FORWARD);
  RF->run(FORWARD);
  LR->run(FORWARD);
  LF->run(FORWARD);
  }
  
void right(){
  RR->setSpeed(150);
  RF->setSpeed(0);
  LR->setSpeed(160);
  LF->setSpeed(130);
  
  RR->run(FORWARD);
  RF->run(FORWARD);
  LR->run(FORWARD);
  LF->run(FORWARD);
  }  

 void st()
 {
    RR->setSpeed(0);
    RF->setSpeed(0);
    LR->setSpeed(0);
    LF->setSpeed(0);
  }
