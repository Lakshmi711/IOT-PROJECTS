
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup() {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // Wait for serial monitor

  if (!accel.begin()) {
    Serial.println("Failed to initialize ADXL345 sensor!");
    while (1);
  }
  Serial.println("ADXL345 sensor initialized");
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);
  
  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;
  
  Serial.print("X: "); Serial.print(x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(y); Serial.print("  ");
  Serial.print("Z: "); Serial.println(z);
  
  delay(1000); // Wait for 1 second before reading again
}