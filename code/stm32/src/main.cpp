#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    pinMode(PC13, OUTPUT);
}

void loop() {
    delay(50);
    digitalWrite(PC13, HIGH);
    delay(50);
    digitalWrite(PC13, LOW);

    Serial.println("test");
}