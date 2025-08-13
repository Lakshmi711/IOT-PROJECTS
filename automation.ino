#include <SoftwareSerial.h>

#define RXD2 16 
#define TXD2 17

#define LEFT_INDICATOR  25
#define RIGHT_INDICATOR 26
#define WIPER           27
#define HEADLIGHTS      14

SoftwareSerial mySerial(RXD2, TXD2);

void setup() {
    Serial.begin(115200);
    mySerial.begin(9600); 

    pinMode(LEFT_INDICATOR, OUTPUT);
    pinMode(RIGHT_INDICATOR, OUTPUT);
    pinMode(WIPER, OUTPUT);
    pinMode(HEADLIGHTS, OUTPUT);

    digitalWrite(LEFT_INDICATOR, LOW);
    digitalWrite(RIGHT_INDICATOR, LOW);
    digitalWrite(WIPER, LOW);
    digitalWrite(HEADLIGHTS, LOW);

    Serial.println("குரல் கட்டளை அமைப்பு தயாராக உள்ளது...");
}

void loop() {
    if (mySerial.available()) {
        int voiceCommand = mySerial.read();  // Read command from Elechouse V3
        Serial.print("பெறப்பட்ட கட்டளை: ");
        Serial.println(voiceCommand);
        
        switch (voiceCommand) {
            case 1:
                Serial.println("car, இடது சிக்னல் இயக்கப்படுகிறது");
                digitalWrite(LEFT_INDICATOR, HIGH);
                break;
            case 2:
                Serial.println("car,இடது சிக்னல் அணைக்கப்படுகிறது");
                digitalWrite(LEFT_INDICATOR, LOW);
                break;
            case 3:
                Serial.println("car,வலது சிக்னல் இயக்கப்படுகிறது");
                digitalWrite(RIGHT_INDICATOR, HIGH);
                break;
            case 4:
                Serial.println("car,வலது சிக்னல் அணைக்கப்படுகிறது");
                digitalWrite(RIGHT_INDICATOR, LOW);
                break;
            case 5:
                Serial.println("car,வைப்பர் இயக்கப்படுகிறது");
                digitalWrite(WIPER, HIGH);
                break;
            case 6:
                Serial.println("car,வைப்பர் அணைக்கப்படுகிறது");
                digitalWrite(WIPER, LOW);
                break;
            case 7:
                Serial.println("car,முன்னணி விளக்குகள் இயக்கப்படுகிறது");
                digitalWrite(HEADLIGHTS, HIGH);
                break; 
            case 8:
                Serial.println("car,முன்னணி விளக்குகள் அணைக்கப்படுகிறது"); 
                digitalWrite(HEADLIGHTS, LOW);
                break;
            default:
                Serial.println("தெரியாத கட்டளை");
                break;
        }
    }
}