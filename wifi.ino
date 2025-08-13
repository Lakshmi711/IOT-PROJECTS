#include <ESP8266WiFi.h>
WiFiClient client;
const char* MY_SSID = "test";
const char* MY_PWD = "12345678";
const char* TS_SERVER = "api.thingspeak.com";
String TS_API_KEY ="LC2F8J835P3XI0XE";
int mql=26;
int mqlv;
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
 pinMode(mql,INPUT);
 delay(1000);
 connectWifi();
 
}
void loop()
{
  mqlv=analogRead(mql);
  Serial.println(mqlv);
  
   if (client.connect(TS_SERVER, 80)) 
   { 
     String postStr = TS_API_KEY;
     postStr += "&field1=";
     postStr += String(mqlv);
     postStr += "\r\n";
   
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