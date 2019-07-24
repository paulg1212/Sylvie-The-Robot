// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>

long stepperState = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);  

  // Start the I2C Bus as Master
  Wire.begin(); 
}

void loop() {
  while (Serial.available() == 0) {}
  stepperState = Serial.parseInt();

  Serial.print("Received command: ");
  Serial.println(stepperState); 
  
  if(stepperState > 0) {

    if(stepperState == 2){
      Wire.beginTransmission(3); // transmit to device #9
      Wire.write(4);              // sends i2c message
      Wire.endTransmission();    // stop transmitting      
    }
    else if(stepperState == 3){
      Wire.beginTransmission(3); // transmit to device #9
      Wire.write(5);              // sends i2c message
      Wire.endTransmission();    // stop transmitting        
    }
    else if(stepperState == 4){
      Wire.beginTransmission(2); // transmit to device #9
      Wire.write(4);              // sends i2c message
      Wire.endTransmission();    // stop transmitting    
    }
    else if(stepperState == 5){
      Wire.beginTransmission(2); // transmit to device #9
      Wire.write(5);              // sends i2c message
      Wire.endTransmission();    // stop transmitting         
    }
    else if(stepperState == 6){
      Wire.beginTransmission(1); // transmit to device #9
      Wire.write(4);              // sends i2c message
      Wire.endTransmission();    // stop transmitting       
    }
    else if(stepperState == 7){
      Wire.beginTransmission(1); // transmit to device #9
      Wire.write(5);              // sends i2c message
      Wire.endTransmission();    // stop transmitting       
    }
    else if(stepperState == 8){
      Wire.beginTransmission(3); // transmit to device #9
      Wire.write(5);              // sends i2c message
      Wire.endTransmission();    // stop transmitting

      Wire.beginTransmission(2); // transmit to device #9
      Wire.write(5);              // sends i2c message
      Wire.endTransmission();    // stop transmission

      Wire.beginTransmission(1); // transmit to device #9
      Wire.write(5);              // sends i2c message
      Wire.endTransmission();    // stop transmission
    } 
    else if(stepperState = 9){
      Wire.beginTransmission(3); // transmit to device #9
      Wire.write(4);              // sends i2c message
      Wire.endTransmission();    // stop transmitting

      Wire.beginTransmission(2); // transmit to device #9
      Wire.write(4);              // sends i2c message
      Wire.endTransmission();    // stop transmission

      Wire.beginTransmission(1); // transmit to device #9
      Wire.write(4);              // sends i2c message
      Wire.endTransmission();    // stop transmission
    }
  }
}
