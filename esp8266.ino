#include <ESP8266WiFi.h>
WiFiClient client;
const char* MY_SSID = "ACTFIBERNET";
const char* MY_PWD = "act12345";
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY ="YJ5JBEUL1NO12BD5";
int ir = 0;
int irvalue;
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
 pinMode(ir,INPUT);
 delay(700);
 connectWifi();
}
void loop()
{
  irvalue = digitalRead(ir);
  Serial.println(irvalue);
   if (client.connect(TS_SERVER, 80)) 
   { 
     String postStr = TS_API_KEY;
     postStr += "&field1=";
     postStr += String(irvalue);
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