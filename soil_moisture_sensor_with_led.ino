int mh = 7;
int led = 2;
int mhV;
void setup()
{
  pinMode(mh,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  mhV = digitalRead(mh);
  Serial.print("mh value");
  Serial.println(mhV);
  if(mhV==0){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
    delay(1000);
  }
  
}
