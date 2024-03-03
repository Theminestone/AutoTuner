#include "AutoTuner.h"

void LED::write() const {
    digitalWrite(_pin, _value);
}

LED::LED(uint8_t pin, uint32_t interval) {
    _value = 0;
    _lastToggle = 0;

    _pin = pin;
    _interval = interval;
    pinMode(_pin, OUTPUT);
}

void LED::on() {
    _value = 1;
    write();
}

void LED::off() {
    _value = 0;
    write();
}

void LED::set(uint8_t value) {
    _value = value;
    write();
}

void LED::toggle() {
    _value = !_value;
    write();
}

void LED::blink() {
    if (_interval < millis() - _lastToggle) {
        _value = !_value;
        _lastToggle = millis();
        write();
    }
}

void LED::pwm(uint8_t pwm_value) const {
    analogWrite(_pin, pwm_value);
}

uint8_t LED::get() const { return _value; }