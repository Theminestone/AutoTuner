#include "AutoTuner.h"

Buzzer::Buzzer(uint8_t pin, uint8_t state) {
    _pin = pin;
    _state = state;
    _note = 0;
}

uint8_t Buzzer::getState() const {
    return _state;
}

void Buzzer::setState(uint8_t state) {
    _state = state;
}

void Buzzer::setNote(uint16_t note) {
    _note = note;
}

void Buzzer::play() const {
    if (_state) {
        tone(_pin, _note);
        Serial.println("Tone");
    }
    else {
        noTone(_pin);
        Serial.println("no Tone");
    }
}

