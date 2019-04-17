#include <Servo.h> 

Servo sg90_1;
Servo sg90_2;
Servo sg90_3;
Servo sg90_4;
Servo hx5010_1;
Servo hx5010_2;
Servo hx5010_3;
Servo hx5010_4;

int led_blue = 3;
int led_red = 2;

// Offsets for servos. Use this to tune the mechanism!
int offset_lid_top_right = -30;
int offset_lid_top_left = 30;

int offset_lid_bottom_right = 0;
int offset_lid_bottom_left = 0;

int offset_right_y = -10;
int offset_right_x = 17;

int offset_left_y = 5;
int offset_left_x = -10;

void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);
  
  sg90_1.attach(10);
  sg90_2.attach(11);
  
  sg90_3.attach(6);
  sg90_4.attach(7);
  
  hx5010_1.attach(8);
  hx5010_2.attach(9);

  hx5010_3.attach(4);
  hx5010_4.attach(5);

  sg90_1.write(90 + offset_right_y);
  sg90_2.write(90 + offset_left_y); 
  
  sg90_3.write(90 + offset_right_x);
  sg90_4.write(90 + offset_left_x);
  
  hx5010_1.write(90 + offset_lid_top_right);
  hx5010_2.write(0 + offset_lid_top_left);
  
  hx5010_3.write(0 + offset_lid_bottom_right);
  hx5010_4.write(90 + offset_lid_bottom_left);
  
  Serial.begin(9600);
  Serial.setTimeout(10);
  
  digitalWrite(led_blue, HIGH);  
}

long servoState = 0;

void loop() {
  while (Serial.available() == 0) {}
  servoState = Serial.parseInt();
  
  Serial.print("Received command: ");
  Serial.println(servoState);    

  if(servoState > 0) { 
  
    if(servoState == 2){
      hx5010_1.write(30 + offset_lid_top_right);
      hx5010_2.write(60 + offset_lid_top_left);       
    }
    else if(servoState == 3){
      hx5010_1.write(90 + offset_lid_top_right);
      hx5010_2.write(0 + offset_lid_top_left);  
    }  
    else if(servoState == 4){
      hx5010_3.write(0 + offset_lid_bottom_right);
      hx5010_4.write(90 + offset_lid_bottom_left);    
    } 
    else if (servoState == 5){
      hx5010_3.write(45 + offset_lid_bottom_right);
      hx5010_4.write(45 + offset_lid_bottom_left);   
    }    
    else if (servoState == 6){
      sg90_1.write(130 + offset_right_y);
      sg90_2.write(45 + offset_left_y);    
    }
    else if (servoState == 7){
      sg90_1.write(45 + offset_right_y);
      sg90_2.write(130 + offset_left_y);   
    }
    else if (servoState == 8){
      sg90_3.write(45 + offset_right_x);
      sg90_4.write(45 + offset_left_x);    
    }
    else if (servoState == 9){
      sg90_3.write(130 + offset_right_x);
      sg90_4.write(130 + offset_left_x);      
    }
    else if (servoState == 10){
      hx5010_1.write(90 + offset_lid_top_right);
      hx5010_2.write(0 + offset_lid_top_left);
    
      hx5010_3.write(0 + offset_lid_bottom_right);
      hx5010_4.write(90 + offset_lid_bottom_left);
    
      sg90_1.write(90 + offset_right_y);
      sg90_2.write(90 + offset_left_y);
    
      sg90_3.write(90 + offset_right_x);
      sg90_4.write(90 + offset_left_x); 
    }

    digitalWrite(led_red, HIGH);
    digitalWrite(led_blue, LOW);
    delay(250);
    digitalWrite(led_red, LOW);    
    digitalWrite(led_blue, HIGH); 
  }
}
