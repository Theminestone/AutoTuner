#ifndef STM32_AUTOTUNER_H
#define STM32_AUTOTUNER_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <ezBuzzer.h>

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

    void breake();

    [[nodiscard]] uint8_t getFin() const;

    [[nodiscard]] uint8_t getRin() const;


};

class Signal {
private:
    uint8_t _pin;
    uint16_t _sample[500]{};
    uint16_t _sample_size;
    uint16_t _frequency;
    bool _ready{};

    uint16_t readADC() const;

    uint16_t processFrequency();

public:
    explicit Signal(uint8_t pin);

    uint16_t getSample(uint8_t i);

    uint16_t getFrequency();

    void createSample();

    bool isReady();
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
