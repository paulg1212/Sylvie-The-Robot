#include <Servo.h> 

Servo sg90_1;
Servo sg90_2;
Servo sg90_3;
Servo sg90_4;
Servo hx5010_1;
Servo hx5010_2;
Servo hx5010_3;
Servo hx5010_4;

void setup() {
  sg90_1.attach(10);
  sg90_2.attach(11);
  
  sg90_3.attach(6);
  sg90_4.attach(7);
  
  hx5010_1.attach(8);
  hx5010_2.attach(9);

  hx5010_3.attach(4);
  hx5010_4.attach(5);

  sg90_1.write(45);
  sg90_2.write(45); 
  
  sg90_3.write(45);
  sg90_4.write(45);
  
  hx5010_1.write(0);
  hx5010_2.write(0);
  
  hx5010_3.write(90);
  hx5010_4.write(90);
  
  Serial.begin(9600);
  Serial.setTimeout(10);
}

long servoState = 0;

void loop() {
  while (Serial.available() == 0) {}
  servoState = Serial.parseInt();
  
  Serial.print("Received command: ");
  Serial.println(servoState);  
  
  if(servoState == 2){
    hx5010_1.write(0);
    hx5010_3.write(90);    
  }
  else if(servoState == 3){
    hx5010_1.write(90);
    hx5010_3.write(0);
  }  
  else if(servoState == 4){
    hx5010_2.write(0);
    hx5010_4.write(90);
  } 
  else if (servoState == 5){
    hx5010_2.write(90);
    hx5010_4.write(0);
  }
  else if (servoState == 6){
    sg90_1.write(0);
    sg90_3.write(0); 
  }
  else if (servoState == 7){
    sg90_1.write(90);
    sg90_3.write(90);  
  }
  else if (servoState == 8){
    sg90_2.write(0);
    sg90_4.write(0);  
  }
  else if (servoState == 9){
    sg90_2.write(90);
    sg90_4.write(90);  
  }
  else if (servoState == 10){
    hx5010_1.write(0);
    hx5010_2.write(0);
    
    hx5010_3.write(90);
    hx5010_4.write(90);
    
    sg90_1.write(45);
    sg90_2.write(45);
    
    sg90_3.write(45);
    sg90_4.write(45); 
  }  
}
