#include <DHT.h>

#define DHTPIN 4        // Pin where the DHT22 is connected
#define DHTTYPE DHT22   // Define the sensor type
#define SOIL_MOISTURE_PIN 34 // Pin where the soil moisture sensor is connected

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();
}

void loop() {
    float temp = dht.readTemperature(); // Read temperature in Celsius
    float humidity = dht.readHumidity(); // Read humidity
    int soilMoisture = analogRead(SOIL_MOISTURE_PIN); // Read soil moisture sensor value

    // Map soil moisture reading to a range of 0 to 50
    int waterLevel = map(soilMoisture, 0, 4095, 0, 100);

    // Check if readings are valid
    if (isnan(temp) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Temperature status
    if (temp < 15) {
        Serial.println("Temperature Status: Low");
    } else if (temp >= 15 && temp <= 30) {
        Serial.println("Temperature Status: Medium");
    } else {
        Serial.println("Temperature Status: High");
    }

    // Humidity status
    if (humidity < 30) {
        Serial.println("Humidity Status: Low");
    } else if (humidity >= 30 && humidity <= 70) {
        Serial.println("Humidity Status: Medium");
    } else {
        Serial.println("Humidity Status: High");
    }

    // Soil moisture status
    Serial.print("Soil Moisture Level: ");
    Serial.println(waterLevel);

    if (waterLevel == 0) {
        Serial.println("Soil Status: Dry");
    } else if (waterLevel > 0 && waterLevel <= 100) {
        Serial.println("Soil Status: Wet");
    }

    Serial.println("----------------------------");
    delay(2000); // Wait for 2 seconds before next reading
}
