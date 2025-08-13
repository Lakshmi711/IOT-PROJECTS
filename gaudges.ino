#include <ESP8266WiFi.h>
WiFiClient client;
const char* MY_SSID = "ACTFIBERNET";
const char* MY_PWD = "act12345";
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY ="TRURQZR7KIXGFIPN";
int tri=2;
int echo=0;
long dur;
int distance;
int ldr=1;
int ldrv;
int ir=4;
int irv;

void connectWifi()
{
  Serial.print("Connecting to "+ *MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("");  
}
void setup() 
{

 Serial.begin(9600);
 pinMode(tri,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(ldr,INPUT);
 pinMode(ir,INPUT);
 delay(700);
 connectWifi();
}
void loop()
{
  digitalWrite(tri,LOW);
  delayMicroseconds(2);
  digitalWrite(tri,HIGH);
  delayMicroseconds(2);
  digitalWrite(tri,LOW);
  delayMicroseconds(2);
  dur=pulseIn(echo,HIGH);
  distance=dur*0.034/2;
  Serial.print("distance is");
  Serial.println(distance);

  ldrv=digitalRead(ldr);
  Serial.print("ldr value");
  Serial.println(ldrv);

  irv=digitalRead(ir);
  Serial.print("ir value");
  Serial.println(irv);

  delay(1000);
  
   if (client.connect(TS_SERVER, 80)) 
   { 
     String postStr = TS_API_KEY;
     postStr += "&field1=";
     postStr += String(distance);
     postStr += "&field2=";
     postStr += String(ldrv);
     postStr += "&field3=";
     postStr += String(irv);
     postStr += "\r\n\r\n";
   
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: " + TS_API_KEY + "\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(postStr.length());
     client.print("\n\n");
     client.print(postStr);
     delay(1000); 
   }
   client.stop();
}