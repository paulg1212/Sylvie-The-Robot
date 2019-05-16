int dirPin = 8;
int stepperPin = 9;
int enablePin = 10;

int lastDir = 1;

void setup() {
 pinMode(dirPin, OUTPUT);
 pinMode(enablePin, OUTPUT);
 pinMode(stepperPin, OUTPUT);
}

void step(boolean dir,int steps){
 digitalWrite(dirPin,dir);
 delay(50);
 for(int i=0;i<steps;i++){
   digitalWrite(stepperPin, HIGH);
   delay(1);
   digitalWrite(stepperPin, LOW);
   delay(1);
 }
}

void loop(){
  
 digitalWrite(enablePin, HIGH);
 step(HIGH,1600);
 delay(100);
 
 digitalWrite(enablePin, LOW);
 step(LOW,1600*5);
 delay(100);
 
}
