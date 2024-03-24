#include "AutoTuner.h"

bool Button::_debounce_update(uint8_t value) {
    if (_toggle) {
        if (_last_value == !_on && value == _on) {
            _status = !_status;
            return true;
        }
        return false;
    } else {
        if (_on) _status = value;
        else _status = !value;
        return true;
    }
}

Button::Button(uint8_t pin, bool toggle, uint16_t debounce_milliseconds, bool high_side) {
    _status = 0;
    _last_value = 0;
    _last_millis = 0;
    _pin = pin;
    _debounce = debounce_milliseconds;
    _toggle = toggle;
    _on = high_side;
    _status = !_on;
    pinMode(_pin, INPUT);
}

bool Button::update() {
    bool triggered = false;
    uint8_t value = digitalRead(_pin);
    if (value != _last_value) { // change since last update, but may be contact bounce
        if (millis() > _last_millis + _debounce) { // debounce_milliseconds have passed, it's not contact bounce
            _last_millis = millis();
            triggered = _debounce_update(value);
        } else
//            Serial.println("unwanted");
        _last_value = value;
    }
    return triggered;
}

uint8_t Button::get() const { return _status; }