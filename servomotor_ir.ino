#include<Servo.h>
int ir = 4;
int led1=1;
int sm=2;
int led2=5;
int irV;
int smV;
int servopin = 0;
Servo servoMotor;
void setup(){
  pinMode(ir,INPUT);
  pinMode(sm,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  servoMotor.attach(servopin);
  Serial.begin(9600);
}
void loop(){
  irV=digitalRead(ir);
  Serial.print("ir value");
  Serial.println(irV);
  smV=digitalRead(sm);
  Serial.print("sm value");
  Serial.println(smV);
  if(irV&&smV==1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    delay(1000);
    }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    delay(1000);
  }
  for(int angle=0; angle<=90;angle++)
  {
    servoMotor.write(angle);
    delay(1000);
  }  
}
