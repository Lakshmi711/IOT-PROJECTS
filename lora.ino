
#include <SPI.h>

#define SCK 5
#define MISO 19
#define MOSI 23
#define SS 15
#define RST 4

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  Serial.println("Testing SPI Communication with LoRa Ra-02...");

  // Reset LoRa module
  pinMode(RST, OUTPUT);
  digitalWrite(RST, LOW);
  delay(100);
  digitalWrite(RST, HIGH);
  delay(100);
  Serial.println("LoRa module reset.");

  // Manually initialize SPI
  SPI.begin(SCK, MISO, MOSI, SS);
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);  // Disable LoRa before testing

  Serial.println("Reading LoRa module version...");

  digitalWrite(SS, LOW);
  SPI.transfer(0x42);  // Send register read command
  byte response = SPI.transfer(0x00);  // Read response
  digitalWrite(SS, HIGH);

  Serial.print("SPI Response: 0x");
  Serial.println(response, HEX);

  if (response == 0x12) {
    Serial.println("✅ LoRa Ra-02 detected (SX1278)!");
  } else {
    Serial.println("❌ LoRa module NOT detected! Check wiring and power.");
  }
}

void loop() {}
