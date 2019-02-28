#include <Servo.h> 

Servo sg90_1;
Servo sg90_2;
Servo hx5010_1;
Servo hx5010_2;

void setup() {
  sg90_1.attach(10);
  sg90_2.attach(11);
  hx5010_1.attach(8);
  hx5010_2.attach(9);  

  hx5010_1.write(0);
  hx5010_2.write(0);
  sg90_1.write(0);
  sg90_2.write(0); 
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    
    char servoState = Serial.read();
    
    if(servoState == '2') {
      hx5010_1.write(0);      
    }
    if(servoState == '3') {
      hx5010_1.write(90);    
    }
    if(servoState == '4') {
      hx5010_2.write(0);    
    }
    if(servoState == '5') {
      hx5010_2.write(90);    
    }    
  }
}

