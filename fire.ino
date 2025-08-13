int fire=2;
int firev;
int led=3;

void setup(){
  pinMode(fire,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  pirv=digitalRead(firev);
  Serial.println(pirv);

  if (firev==1){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
    delay(1000);
  }
  
}


