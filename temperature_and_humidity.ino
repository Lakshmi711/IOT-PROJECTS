#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(D1,OUTPUT);
  dht.begin();

}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if(h>75&&t>26)
  {
    digitalWrite(D1,HIGH);
  }
  else
  {
    digitalWrite(D1<LOW);
  }
  if(isnan(h)||isnan(t)||isnan(f)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif=dht.computeHeatindex(f,h);
  float hic=dht.computeHeatindex(f,h,false);
  Serial.print(F("Humidity:"));
  Serial.print(h);
  Serial.print("% Temperature:");
  Serial.print(t);
  Serial.print(F("c"));
  Serial.print(f);
  Serial.print("F Heat index:");
  Serial.print(hic);
  Serial.print(F("c"));
  Serial.print(hif);
  Serial.print("F");

}
