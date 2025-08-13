#include <DHT.h>

#define DHTPIN 4        
#define DHTTYPE DHT22  
#define SOIL_MOISTURE_PIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();
}

void loop() {
    float temp = dht.readTemperature(); 
    float humidity = dht.readHumidity(); 
    int soilMoisture = analogRead(SOIL_MOISTURE_PIN); 
    int waterLevel = map(soilMoisture, 0, 4095, 0, 100);

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

    if (temp < 15) {
        Serial.println("Temperature Status: Low");
    } else if (temp >= 15 && temp <= 30) {
        Serial.println("Temperature Status: Medium");
    } else {
        Serial.println("Temperature Status: High");
    }

    if (humidity < 30) {
        Serial.println("Humidity Status: Low");
    } else if (humidity >= 30 && humidity <= 70) {
        Serial.println("Humidity Status: Medium");
    } else {
        Serial.println("Humidity Status: High");
    }

    Serial.print("Soil Moisture Level: ");
    Serial.println(waterLevel);

    if (waterLevel == 0) {
        Serial.println("Soil Status: Dry");
    } else if (waterLevel > 0 && waterLevel <= 100) {
        Serial.println("Soil Status: Wet");
    }

    Serial.println("----------------------------");
    delay(2000);
}
