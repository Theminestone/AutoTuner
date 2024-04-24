#include "AutoTuner.h"

Signal::Signal(uint8_t pin, uint16_t max_cycles, uint8_t sample_rate) {
    _pin = pin;
    _cycle = 0;
    _max_cycles = max_cycles;
    _sample_rate = sample_rate;
    _tolerance = TOLERANZ;
    _tune = TUNE;
    _frequency = 0;
    pinMode(_pin, INPUT);
}

uint32_t Signal::readADC() const {
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

    _pUP = max_value * 0.75;
    _pDOWN = max_value * 0.25;
}

void Signal::calcFrequency() {

    calcPoints();

    for (int i = 0; i < _wave.size(); ++i) {
        if (_points == 0 && _wave[i] >= _pUP) {
            _xP1 = i;
            _points = 1;
        }
        if (_points == 1 && _wave[i] <= _pDOWN) {
            _xP2 = i;
            _points = 2;
        }
        if (_points == 2 && _wave[i] >= _pUP) {
            _xP3 = i;
            _points = 3;
        }
        if (_points == 3 && _wave[i] <= _pDOWN) {
            _xP4 = i;
            _points = 4;
        }
        if (_points == 4 && _wave[i] >= _pUP) {
            _xP5 = i;
            _points = 5;
        }
        if (_points == 5 && _wave[i] <= _pDOWN) {
            _xP6 = i;
            _points = 6;
        }
        if (_points == 6 && _wave[i] >= _pUP) {
            _xP7 = i;
            _points = 7;
        }
        if (_points == 7 && _wave[i] <= _pDOWN) {
            _xP8 = i;
            _points = 8;
        }
        if (_points == 8 && _wave[i] >= _pUP) {
            _xP9 = i;
            _points = 9;
        }
        if (_points == 9 && _wave[i] <= _pDOWN) {
            _xP10 = i;
            _points = 10;
        }
    }

    _points = 0;

    _deltaT1T3 = _xP3 * _sample_rate - _xP1 * _sample_rate;
    _deltaT3T5 = _xP5 * _sample_rate - _xP3 * _sample_rate;
    _deltaT5T7 = _xP7 * _sample_rate - _xP5 * _sample_rate;
    _deltaT7T9 = _xP9 * _sample_rate - _xP7 * _sample_rate;

    _deltaT2T4 = _xP4 * _sample_rate - _xP2 * _sample_rate;
    _deltaT4T6 = _xP6 * _sample_rate - _xP4 * _sample_rate;
    _deltaT6T8 = _xP8 * _sample_rate - _xP6 * _sample_rate;
    _deltaT8T10 = _xP10 * _sample_rate - _xP8 * _sample_rate;

    _sumDelta = _deltaT1T3 + _deltaT3T5 + _deltaT5T7 + _deltaT7T9 + _deltaT2T4 + _deltaT4T6 + _deltaT6T8 + _deltaT8T10;

    if (_sumDelta > 0) {
        _frequency = 1 / (((_sumDelta) / 8) * 0.000001);
    } else { _frequency = 0; }
    clearVector();
}

double Signal::getFrequency() const {
//    return round(_frequency);
    return _frequency;
}

void Signal::clearVector() {
    _wave.clear();
//    _wave.swap(_wave);
}

uint8_t Signal::getTolerance() const {
    return _tolerance;
}

void Signal::setTolerance(uint8_t tolerance) {
    _tolerance = tolerance;
}

uint16_t Signal::getTune() const {
    return _tune;
}

void Signal::setTune(uint16_t tune) {
    _tune = tune;
}
