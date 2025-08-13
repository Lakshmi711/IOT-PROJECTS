#include<Wire.h>
#include<Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
void setup(){
  Serial.begin(9600);
  if(!bmp.begin()){
    Serial.println("Could not find bmp180 or bmp085 sensor!");
    while(1){}
  }
}                                       
void loop(){
  Serial.print("temperature=");
  Serial.print(bmp.readTemperature());
  Serial.println("*C");
  Serial.print("Pressure =");
  Serial.print(bmp.readPressure());
  Serial.print("Pa");
  Serial.print("altitude=");
  Serial.print(bmp.readAltitude());
  Serial.print("meters");
  Serial.println();
  delay(1000);

 }