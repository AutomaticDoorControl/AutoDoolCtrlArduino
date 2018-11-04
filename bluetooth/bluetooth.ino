#include <SoftwareSerial.h>
#include "outgoingCommands.h"

#define LED_PIN 5
#define txPin 11
#define rxPin 10

SoftwareSerial adc(rxPin, txPin);
int isLightOn = 0;


# pragma mark - function prototypes

void processData2();

# pragma mark - main arduino methods

void setup() {
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
    adc.begin(9600);
}

void loop() {
    processData2();
}

# pragma mark - helper methods

void processData2() {
    if (adc.available()) {
        char data = adc.read();
        Serial.println(data);
        if (data == 'a') {
            isLightOn = !isLightOn;
            if (isLightOn == 0) {
                adc.print(offCommand);
                digitalWrite(LED_PIN, LOW);
            } else {
                adc.print(onCommand);
                digitalWrite(LED_PIN, HIGH);
            }
        }
    }
}