#include "AutoTuner.h"

Button::Button(uint8_t pin, uint16_t debounceTime) {

    _pin = pin;
    _state = 0;
    _currentState = 0;
    _lastState = 0;
    _debounceTime = debounceTime;
    _lastMillis = 0;

    pinMode(_pin, INPUT);
}

bool Button::read() {
    _currentState = digitalRead(_pin);
    if (_currentState != _lastState) _lastMillis = millis();
    if ((millis() - _lastMillis) > _debounceTime) {
        if (_currentState != _state) {
            _state = _currentState;
            return true;
        }
    }
    _lastState = _currentState;
    return false;
}

bool Button::get() {
    if (read() && _state == HIGH) {
        return true;
    }
    return false;
}
