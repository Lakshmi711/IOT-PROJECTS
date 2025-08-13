const int trigPin = 2;
const int echoPin = 0;
int triv;
int echov;
long duration; 
int distance; 
int led1=4;
int led2=5;

void setup() { 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600); 
} 

void loop() { 
triv=digitalRead(trigPin);
echov=digitalRead(echoPin);
duration = pulseIn(echov, HIGH); 
distance= duration*0.034/2;
Serial.print("Distance: "); 
Serial.println(distance); 
delay(2000);
if(distance<=30)
{
  digitalWrite(led1,LOW);
  Serial.print("water levl is low");
  delay(1000);
}
else if(distance>50)
{
  digitalWrite(led2,HIGH);
  Serial.print("water lvl is medium");
  delay(1000);
}
else{
  Serial.print("water lvl is high");
  delay(1000);
}
}


