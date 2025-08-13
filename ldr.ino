#include "DHT.h"

// Define the GPIO pin where the DHT11 is connected
#define DHTPIN 34     // Use GPIO34 for the DHT sensor

// Define the type of DHT sensor
#define DHTTYPE DHT11 // DHT11 sensor type

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test on ESP32!"));

  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // Wait 2 seconds between readings
  delay(2000);

  // Read humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check if any reads failed
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute the heat index in Fahrenheit
  float hif = dht.computeHeatIndex(f, h);
  // Compute the heat index in Celsius
  float hic = dht.computeHeatIndex(t, h, false);

  // Print the results to the Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
