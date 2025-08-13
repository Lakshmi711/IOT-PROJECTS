#include <WiFi.h>
#include <HTTPClient.h>

#define RE 12
#define RXD2 13
#define TXD2 14

const byte nitro[] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x01, 0xC5, 0xCB};      
const byte phos[] = {0x01, 0x03, 0x00, 0x05, 0x00, 0x01, 0x94, 0x0B};  
const byte pota[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};  

byte values[7];

void setup() {
    Serial.begin(115200);
    Serial1.begin(4800, SERIAL_8N1, RXD2, TXD2);
    
    pinMode(RE, OUTPUT);
    digitalWrite(RE, LOW);
}

void loop() {
    float nitrogen = readModbus(nitro);
    float phosphorus = readModbus(phos);
    float potassium = readModbus(pota);

    Serial.println("Soil Nutrients:");
    Serial.print("Nitrogen: "); Serial.print(nitrogen); Serial.println("%");
    Serial.print("Phosphorous: "); Serial.print(phosphorus); Serial.println("%");
    Serial.print("Potassium: "); Serial.print(potassium); Serial.println("%");
    Serial.println("--------------------------");

    delay(5000); 
}

int readModbus(const byte request[]) {
    digitalWrite(RE, HIGH);
    delay(100);
    Serial1.write(request, 8);
    Serial1.flush();
    digitalWrite(RE, LOW);
    delay(1000); 

    for (byte i = 0; i < 7; i++) {
        values[i] = Serial1.read();
    }

    return (int(values[3] << 8 | values[4]));
}
