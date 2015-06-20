/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include <math.h>
Adafruit_MotorShield AFMSbot(0x61); // Rightmost jumper closed
Adafruit_MotorShield AFMStop(0x60); // Default address, no jumpers

// On the top shield, connect two steppers, each with 200 steps
Adafruit_StepperMotor *myStepper2 = AFMStop.getStepper(768, 1);
Adafruit_StepperMotor *myStepper3 = AFMStop.getStepper(768, 2);

// On the bottom shield connect a stepper to port M3/M4 with 200 steps
//Adafruit_StepperMotor *myStepper1 = AFMStop.getStepper(768, 1);
Adafruit_StepperMotor *myStepper4 = AFMSbot.getStepper(768, 2);

// And a DC Motor to port M1
void setup() {

  while (!Serial);
  Serial.begin(9600);
  //Keyboard.begin();
  // set up Serial library at 9600 bps
  Serial.println("MMMMotor party!");

  AFMStop.begin(); // Start the bottom shield
 AFMSbot.begin(); // Start the top shield
}

int motorRequest = 2000;
int millimeter = 0;
int i;
int steps = 0;
int once = 0;
int y = 0;
int x = 0;
void loop() {

  //RANDOM MOVEMENTS
    if (y==0){
      
     y = random(-100,100);
    }if (x==0){
          x = random(-100,100);
    }
      if (x>0){
        x--;
            myStepper2->onestep(FORWARD, MICROSTEP);
      }else{
        x++;
        myStepper2->onestep(BACKWARD, MICROSTEP);
      }
    
      if (y>0){
        y--;
            myStepper3->onestep(FORWARD, MICROSTEP);
      }else{
        y++;
            myStepper3->onestep(BACKWARD, MICROSTEP);

      }
    
    /*
    //CIRCLE
    //once  = 1;
    Serial.println("RESET");
  int x = 0;
  int y = 0;
  int lastx = 0;
  int lasty = 0;
  for (float angle =0 ;angle<6.28;angle=angle+.008){
    y = round(300*cos(angle));
    x = round(300*sin(angle));
    if (x!=lastx){
      if (x>lastx){
            myStepper2->onestep(FORWARD, MICROSTEP);
      }else{
            myStepper2->onestep(BACKWARD, MICROSTEP);
      }
      lastx = x;
    }
    if (y!=lasty){
      if (y>lasty){
            myStepper3->onestep(FORWARD, MICROSTEP);
      }else{
            myStepper3->onestep(BACKWARD, MICROSTEP);

      }
      lasty = y;
    }
  }
  }
*/
}
