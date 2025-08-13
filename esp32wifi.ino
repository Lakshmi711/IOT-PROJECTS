#include<WiFi.h>
#include<ESPWiFi.h>
WiFiClient client;
const char* MY_SSID="ACTFIBERNET";
const char* MY_PWD="act12345";
const char* TS_SERVER="api.thingspeak.com";
String TS_API_KEY = "G1IU8NXD2NZRUVHX";
int ir = 4;
int gas = 27;
int irvalue;
int gasvalue;

void connectWiFi()
{
  Serial.print("connecting to"+ *MY_SSID);
  WiFi.begin(MY_SSID,MY_PWD);
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("");
}
void setup()
{
  Serial.begin(9600);
  pinMode(ir,INPUT);
  pinMode(gas,INPUT);
  delay(700);
  connectWiFi();
}
void loop()
{
  irvalue=digitalRead(ir);
  Serial.println(irvalue);
  gasvalue=analogRead(gas);
  Serial.println(gasvalue);
  if(client.connect(TS_SERVER,80))
  {
    String postStr = TS_API_KEY;
    postStr +="&field1=";
    postStr += String(irvalue);
    postStr +="&field2=";
    postStr += String(gasvalue);
    postStr +="\r\n\r\n";

    client.print("POST/update HTTP/1.1\n");
    client.print("  Host:api.thingspeak.com\n");
    client.print("Connection:close\n");
    client.print("X-THINGSPEAKAPIKEY:"+TS_API_KEY+"\n");
    client.print("content-Type:application/x-www-form-urlencoded\n");
    client.print("content-Length:");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    delay(1000);
  }
  client.stop();
}
