#ifndef STM32_AUTOTUNER_H
#define STM32_AUTOTUNER_H

#include <Arduino.h>
#include "Constants.h"
#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

class LED {
private:
    uint8_t _pin;
    uint8_t _value;
    uint32_t _interval;
    uint32_t _lastToggle;

    void write() const;

public:
    explicit LED(uint8_t pin, ulong _interval = 100);

    void on();

    void off();

    void set(uint8_t value);

    void toggle();

    void blink();

    void pwm(uint8_t pwm_value) const;

    [[nodiscard]] uint8_t get() const;
};

class Button {
private:
    uint8_t _pin;
    uint8_t _state;
    uint8_t _currentState;
    uint8_t _lastState;
    uint16_t _debounceTime;
    uint32_t _lastMillis;

    bool read();

public:
    explicit Button(uint8_t pin, uint16_t debounceTime);

    bool get();
};

class Motor {
private:
    uint8_t _pin_fin;
    uint8_t _pin_rin;
    uint8_t _fin;
    uint8_t _rin;

public:
    Motor(uint8_t pin_fin, uint8_t pin_rin);

    void write() const;

    void standby();

    void forward();

    void reverse();

    void breakk();

    [[nodiscard]] uint8_t getFin() const;

    [[nodiscard]] uint8_t getRin() const;

};

class Signal {
private:
    uint8_t _pin;
    std::vector<uint8_t> _wave;
    uint16_t _cycle;
    uint16_t _max_cycles;
    bool _ready = false;

    uint8_t _sample_rate; // in us

    double _pUP{};
    double _pDOWN{};

    uint16_t _xP1{};
    uint16_t _xP2{};
    uint16_t _xP3{};
    uint16_t _xP4{};
    uint16_t _xP5{};
    uint16_t _xP6{};
    uint16_t _xP7{};
    uint16_t _xP8{};
    uint16_t _xP9{};
    uint16_t _xP10{};

    double _deltaT1T3{};
    double _deltaT3T5{};
    double _deltaT5T7 = 0;
    double _deltaT7T9 = 0;

    double _deltaT2T4{};
    double _deltaT4T6{};
    double _deltaT6T8 = 0;
    double _deltaT8T10 = 0;

    double _sumDelta{};

    uint8_t _points{}; // for P calc

    uint8_t _tolerance;

    uint16_t _tune;

    double _frequency;

    void calcPoints();

    void clearVector();

public:
    explicit Signal(uint8_t pin, uint16_t max_cycles, uint8_t sample_rate);

    uint8_t getWave(uint8_t i);

    [[nodiscard]] double getFrequency() const;

    void createWave();

    bool isReady();

    void calcFrequency();

    [[nodiscard]] uint32_t readADC() const;

    [[nodiscard]] uint8_t getTolerance() const;

    void setTolerance(uint8_t tolerance);

    [[nodiscard]] uint16_t getTune() const;

    void setTune(uint16_t tune);
};

#endif //STM32_AUTOTUNER_H
