#ifndef STM32_AUTOTUNER_H
#define STM32_AUTOTUNER_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

#include <vector>
#include <cmath>
#include <algorithm>

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
    uint16_t _debounce;
    bool _toggle;
    bool _on;
    uint8_t _status;
    uint8_t _last_value;
    uint32_t _last_millis;

    bool _debounce_update(byte value);

public:

    explicit Button(uint8_t pin, bool toggle = true, uint16_t debounce_milliseconds = 10, bool high_side = true);

    bool update();

    [[nodiscard]] uint8_t get() const;
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
    bool _ready{};

    uint8_t _sample_rate; // in us

    double _Pup;
    double _Pdown;

    uint16_t _xP1;
    uint16_t _xP2;
    uint16_t _xP3;
    uint16_t _xP4;
    uint16_t _xP5;
    uint16_t _xP6;
    uint16_t _xP7;
    uint16_t _xP8;
    uint16_t _xP9;
    uint16_t _xP10;

    double _deltaT1T3;
    double   _deltaT3T5;
    double   _deltaT5T7;
    double   _deltaT7T9;

    double   _deltaT2T4;
    double   _deltaT4T6;
    double   _deltaT6T8;
    double   _deltaT8T10;

    uint8_t _points; // for P calc

    uint16_t _frequency;

public:
    explicit Signal(uint8_t pin, uint16_t max_cycles, uint8_t sample_rate);

    uint8_t getWave(uint8_t i);

    uint16_t getFrequency();

    void createWave();

    bool isReady();

    void clearVector();

    uint32_t readADC();

    void calcFrequency();

    void calcPoints();

};

enum STATE {
    IDLE = 0,
    TUNE_E1,
    TUNE_A,
    TUNE_D,
    TUNE_G,
    TUNE_H,
    TUNE_E2,
    SETTINGS,
    BEEP
};

enum SUB_STATE {
    READ = 0,
    PROCESS,
    WAIT,
};
#endif //STM32_AUTOTUNER_H
