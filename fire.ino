int ir=2;
int irv;
int led=3;

void setup(){
  pinMode(pir,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  pirv=digitalRead(pir);
  Serial.print("pir value : ");
  Serial.println(pirv);

  if (pirv==1){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
    delay(1000);
  }
  
}


