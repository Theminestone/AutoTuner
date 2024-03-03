#include "AutoTuner.h"

Signal::Signal(uint8_t pin) {
    _pin = pin;
    _sample_size = 0;
    _frequency = 0;
    pinMode(_pin, INPUT);
}

uint16_t Signal::readADC() const {
    return analogRead(_pin);
}

void Signal::createSample() {
    _sample[_sample_size] = readADC();
    _sample_size++;
    if (_sample_size == 500) {
        _sample_size = 0;
        _ready = true;
    }
}

uint16_t Signal::getSample(uint8_t i) {
    return _sample[i];
}

uint16_t Signal::processFrequency() {

// crazy shit
    return 0;
}

uint16_t Signal::getFrequency() {
    return _frequency;
}

bool Signal::isReady() {
    if (_ready) {
        _ready = false;
        return true;
    }
    return false;
}
