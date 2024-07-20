int ir = 0;
int a = 4;
int irV
void setup()
{
  pinMode(ir,INPUT);
  pinMode(a,OUTPUT)
  Serial.begin(9600)
}
void loop()
{
  irV = digitalread(ir);
  Serial.println("IR Value:");
  Serial.println(irV);
  delay(500);
  if(irV==0)
  {
    digitalWrite(a,HIGH);
  }
  else{
    digitalWrite(a,LOW);
  }
}
