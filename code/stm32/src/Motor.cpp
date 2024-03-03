#include "AutoTuner.h"

Motor::Motor(uint8_t pin_fin, uint8_t pin_rin) {
    _fin = 0;
    _rin = 0;

    _pin_fin = pin_fin;
    _pin_rin = pin_rin;
    pinMode(_pin_fin, OUTPUT);
    pinMode(_pin_rin, OUTPUT);
}

void Motor::write() const {
    digitalWrite(_pin_fin, _fin);
    digitalWrite(_pin_rin, _rin);
}

void Motor::standby() {
    _fin = 0;
    _rin = 0;
    write();
}

void Motor::forward() {
    _fin = 1;
    _rin = 0;
    write();
}

void Motor::reverse() {
    _fin = 0;
    _rin = 1;
    write();
}

void Motor::breake() {
    _fin = 1;
    _rin = 1;
    write();
}

uint8_t Motor::getFin() const {
    return _fin;
}

uint8_t Motor::getRin() const {
    return _rin;
}
