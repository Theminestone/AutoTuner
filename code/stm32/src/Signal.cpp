#include "AutoTuner.h"

Signal::Signal(uint8_t pin, uint16_t max_cycles, uint8_t sample_rate) {
    _pin = pin;
    _cycle = 0;
    _max_cycles = max_cycles;
    _sample_rate = sample_rate;
    _frequency = 0;
    pinMode(_pin, INPUT);
}

uint32_t Signal::readADC() {
    return analogRead(_pin);
}

void Signal::createWave() {
    _wave.push_back(static_cast<uint8_t>(readADC()));
    _cycle++;
    if (_cycle == _max_cycles) {
        _cycle = 0;
        _ready = true;
    }
}

uint8_t Signal::getWave(uint8_t i) {
    return _wave[i];
}

bool Signal::isReady() {
    if (_ready) {
        _ready = false;
        return true;
    }
    return false;
}

void Signal::calcPoints() {
//    auto min_value = *min_element(_wave.begin(), _wave.end());
    auto max_value = *max_element(_wave.begin(), _wave.end());

    _Pup = max_value * 0.75;
    _Pdown = max_value * 0.25;
}

void Signal::calcFrequency() {

    calcPoints();

    for (int i = 0; i < _wave.size(); ++i) {
        if (_points == 0 && _wave[i] >= _Pup) {
            _xP1 = i;
            _points = 1;
        }
        if (_points == 1 && _wave[i] <= _Pdown) {
            _xP2 = i;
            _points = 2;
        }
        if (_points == 2 && _wave[i] >= _Pup) {
            _xP3 = i;
            _points = 3;
        }
        if (_points == 3 && _wave[i] <= _Pdown) {
            _xP4 = i;
            _points = 4;
        }
        if (_points == 4 && _wave[i] >= _Pup) {
            _xP5 = i;
            _points = 5;
        }
        if (_points == 5 && _wave[i] <= _Pdown) {
            _xP6 = i;
            _points = 6;
        }
        if (_points == 6 && _wave[i] >= _Pup) {
            _xP7 = i;
            _points = 7;
        }
        if (_points == 7 && _wave[i] <= _Pdown) {
            _xP8 = i;
            _points = 8;
        }
        if (_points == 8 && _wave[i] >= _Pup) {
            _xP9 = i;
            _points = 9;
        }
        if (_points == 9 && _wave[i] <= _Pdown) {
            _xP10 = i;
            _points = 10;
        }
    }
    _deltaT1T3 = _xP3 * _sample_rate - _xP1 * _sample_rate;
    _deltaT3T5 = _xP5 * _sample_rate - _xP3 * _sample_rate;
    _deltaT5T7 = _xP7 * _sample_rate - _xP5 * _sample_rate;
    _deltaT7T9 = _xP9 * _sample_rate - _xP7 * _sample_rate;

    _deltaT2T4 = _xP4 * _sample_rate - _xP2 * _sample_rate;
    _deltaT4T6 = _xP6 * _sample_rate - _xP4 * _sample_rate;
    _deltaT6T8 = _xP8 * _sample_rate - _xP6 * _sample_rate;
    _deltaT8T10 = _xP10 * _sample_rate - _xP8 * _sample_rate;

    _frequency = (int) round(
            (1 / (((_deltaT1T3 + _deltaT3T5 + _deltaT5T7 + _deltaT7T9 + _deltaT2T4 + _deltaT4T6 + _deltaT6T8 + _deltaT8T10) / 8) * 0.000001)));
}

uint16_t Signal::getFrequency() {

    calcFrequency();


//    Serial.printf("Pup: %d\n", _Pup);
//    Serial.printf("Pdown: %d\n", _Pdown);
//
//    Serial.printf("xP1: %i\n", _xP1);
//    Serial.printf("xP2: %i\n", _xP2);
//    Serial.printf("xP3: %i\n", _xP3);
//    Serial.printf("xP4: %i\n", _xP4);
//    Serial.printf("xP5: %i\n", _xP5);
//    Serial.printf("xP6: %i\n", _xP6);
//    Serial.printf("xP7: %i\n", _xP7);
//    Serial.printf("xP8: %i\n", _xP8);
//    Serial.printf("xP9: %i\n", _xP9);
//    Serial.printf("xP10: %i\n", _xP10);
//
//    Serial.printf("_deltaT1T3: %i\n", _deltaT1T3);
//    Serial.printf("_deltaT3T5: %i\n", _deltaT3T5);
//    Serial.printf("_deltaT5T7: %i\n", _deltaT5T7);
//    Serial.printf("_deltaT7T9: %i\n", _deltaT7T9);
//
//    Serial.printf("_deltaT2T4: %i\n", _deltaT2T4);
//    Serial.printf("_deltaT4T6: %i\n", _deltaT4T6);
//    Serial.printf("_deltaT6T8: %i\n", _deltaT6T8);
//    Serial.printf("_deltaT8T10: %i\n", _deltaT8T10);
//
//    Serial.printf("points: %i\n", _points);

    Serial.print("Frequenz: ");
    Serial.print(_frequency);
    Serial.println("Hz");

    clearVector();

    return _frequency;
}

void Signal::clearVector() {
    _wave.clear();
//    _wave.swap(_wave);
}
