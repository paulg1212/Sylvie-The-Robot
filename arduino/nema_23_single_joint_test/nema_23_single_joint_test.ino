// This 2 pin code is configured for use with a Nema 23 Bipolar 1.8deg 1.16Nm (164.3oz.in) 1.5A 5.4V 57x57x56mm 4 Wires

#include <AccelStepper.h> // This can be installed by going to 
#include <Wire.h>
// Sketch > Include Library > Manage Libraries > Search for "AccelStepper" 

int microstepRes = 2;

int stepperSpeed = 800 * microstepRes; //maximum steps per second
int motorAccel = 4000 * microstepRes * 2; //steps/second/second to accelerate

int gearReduction = 38.4;
int stepsPerRev = 100; // e.g. one full revolution is 200 at 1.8deg. 100 for half. 50 for quarter.. etc.

int resetPin = 5;
int m2Pin = 6;
int m1Pin = 7;
int m0Pin = 8; 
int enablePin = 4; // Turn motor driver on/off (can save power when motor is idle)

//set up the accelStepper intance
//the "1" tells it we are using a driver (DRV8825 or other)
AccelStepper stepper_one(1, 3, 2);//Step, Dir

void setup(){
  Serial.begin(9600);
  Serial.setTimeout(10);
  
  stepper_one.setMaxSpeed(stepperSpeed);
  stepper_one.setSpeed(stepperSpeed);
  stepper_one.setAcceleration(motorAccel);

  digitalWrite(m2Pin, LOW);
  digitalWrite(m1Pin, LOW);
  digitalWrite(m0Pin, HIGH); 

  digitalWrite(resetPin, HIGH);
}

long stepperState = 0;

void loop(){
  while (Serial.available() == 0) {}
  stepperState = Serial.parseInt();

  Serial.print("Received command: ");
  Serial.println(stepperState); 

  if(stepperState > 0) {
    
    if(stepperState == 2){
        stepper_one.move((7 * 38.4 * microstepRes) / 2); //Move X times revolutions, according to gear reduction ratio.
    }
    else if(stepperState == 3){    
        stepper_one.move((-7 * 38.4 * microstepRes) / 2);                
    }
    else if(stepperState == 4){
        stepper_one.move((12 * 38.4 * microstepRes) / 2);
    }
    else if(stepperState == 5){
        stepper_one.move((-12 * 38.4 * microstepRes) / 2);
    }
    else if(stepperState == 6){
        stepper_one.move((25 * 38.4 * microstepRes) / 2);
    }
    else if(stepperState == 7){
        stepper_one.move((-25 * 38.4 * microstepRes) / 2);
    }

  //these must be called as often as possible to ensure smooth operation
  //any delay will cause jerky motion
  }
  
  while (stepper_one.distanceToGo() != 0) {
      stepper_one.run();
  }
}  
