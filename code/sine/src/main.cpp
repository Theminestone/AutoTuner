#include <Arduino.h>
#include <SineWave.h>

void setup() {

    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(9, OUTPUT);
    sw.setInterval(50);
    sw.setPin(10);
}

void loop() {

    digitalWrite(9, HIGH);
    Serial.println(analogRead(A0));

    for (int i = 0; i < 10; i++) {
        sw.playTone(500 + i * 10, 50);
    }
    sw.stopTone();
}