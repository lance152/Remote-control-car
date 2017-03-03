
#include "Ultrasonic.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

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
Ultrasonic ultrasonic(12,13);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
//  myMotor->setSpeed(150);
//  myMotor->run(FORWARD);
//  // turn on motor
//  myMotor->run(RELEASE);
  RR->setSpeed(150);
  RF->setSpeed(150);
  LR->setSpeed(150);
  LF->setSpeed(150);
}

void loop() {

  Serial.print(ultrasonic.Ranging(CM));
  Serial.println("cm");
  
  RR->run(FORWARD);
  RF->run(FORWARD);
  LR->run(FORWARD);
  LF->run(FORWARD);

}

//void forward()
