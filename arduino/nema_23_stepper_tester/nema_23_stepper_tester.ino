int dirPin = 8;
int stepperPin = 9;
int mode2 = 10;
int mode1 = 11;
int mode0 = 12;
int enablePin = 13;

int stepperSpeed = 1;

void setup() {
 pinMode(dirPin, OUTPUT);
 pinMode(enablePin, OUTPUT);
 pinMode(stepperPin, OUTPUT);

 digitalWrite(mode2, LOW);
 digitalWrite(mode1, LOW);
 digitalWrite(mode0, LOW);  
}

void step(boolean dir,int steps){
 digitalWrite(dirPin,dir);
 delay(50);
 for(int i=0;i<steps;i++){
   digitalWrite(stepperPin, HIGH);
   delay(stepperSpeed);
   digitalWrite(stepperPin, LOW);
   delay(stepperSpeed);
 }
}

void loop(){
  
 digitalWrite(enablePin, HIGH);
 delay(250);
 
 digitalWrite(enablePin, LOW);
 step(HIGH,200*10);
 
 digitalWrite(enablePin, HIGH);
 delay(250);

 digitalWrite(enablePin, LOW);
 step(LOW,200*10); 
 
}
