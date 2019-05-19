//Taken from arduino forum
//This is an example of how you would control 1 stepper

// This 2 pin code is configured for use with a Nema 23 Bipolar 1.8deg 1.16Nm (164.3oz.in) 1.5A 5.4V 57x57x56mm 4 Wires

#include <AccelStepper.h> // This can be installed by going to 
// Sketch > Include Library > Manage Libraries > Search for "AccelStepper" 

int motorSpeed = 1400; //maximum steps per second
int motorAccel = 2500; //steps/second/second to accelerate

int motorDirPin = 8; //digital pin 8
int motorStepPin = 9; //digital pin 9

int gearReduction = 38.4;

int stepsPerRev = 50; // e.g. one full revolution is 200 at 1.8deg. 100 for half. 50 for quarter.. etc.

int enablePin = 10; // Turn motor driver on/off (can save power when motor is idle)

//set up the accelStepper intance
//the "1" tells it we are using a driver (DRV8825 or other)
AccelStepper stepper(1, motorStepPin, motorDirPin);

void setup(){
 stepper.setMaxSpeed(motorSpeed);
 stepper.setSpeed(motorSpeed);
 stepper.setAcceleration(motorAccel);
 
 stepper.moveTo((stepsPerRev * 38.4) / 2); //Move X times revolutions, according to configuration
}

void loop(){
 
 //if stepper is at desired location
 if (stepper.distanceToGo() == 0){
   //go the other way the same amount of steps  <= "go the other way" sounds like a direction change to me.
   //so if current position is 400 steps out, go position -400
   stepper.moveTo(-stepper.currentPosition()); 
 }
 
 //these must be called as often as possible to ensure smooth operation
 //any delay will cause jerky motion
 stepper.run();
}  
