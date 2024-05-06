#include "SettingsState.h"

void mainSettings() {
    lcd_text_oben = "Settings        ";
    lcd_text_unten = "<- Back         ";

    writeLCD();

    led_indicator.off();
    led_left.off();
    led_middle.off();
    led_right.off();

    custom1.on();
    custom2.on();
    custom3.on();
    custom4.on();

    motor.standby();
}

void changeTolerance() {

    custom1.on();
    custom2.off();
    custom3.off();
    custom4.off();

    uint8_t tolerance = signal_in.getTolerance();
    if (button_left.get()) {
        if (tolerance != 1) { tolerance--; }
        signal_in.setTolerance(tolerance);
    }
    if (button_right.get()) {
        if (tolerance != 9) { tolerance++; }
        signal_in.setTolerance(tolerance);
    }

    lcd_text_unten = "Tolerance: " + String(signal_in.getTolerance()) + "    ";
    writeLCD();
}

void changeTune() {

    custom1.off();
    custom2.on();
    custom3.off();
    custom4.off();

    uint16_t tune = signal_in.getTune();
    if (button_left.get()) {
        if (tune != 432) { tune = tune - 2; }
        signal_in.setTune(tune);
    }
    if (button_right.get()) {
        if (tune != 446) { tune = tune + 2; }
        signal_in.setTune(tune);
    }

    lcd_text_oben;
    lcd_text_unten = "Tune: " + String(signal_in.getTune()) + "    ";
    writeLCD();
}

void changeBuzzer() {

    custom1.off();
    custom2.off();
    custom3.on();
    custom4.off();

    bool buzzerstate = buzzer.getState();

    if (buzzerstate) {
        lcd_text_oben;
        lcd_text_unten = "Buzzer:  ON     ";
    } else {
        lcd_text_oben;
        lcd_text_unten = "Buzzer:  OFF    ";
    }

    if (button_left.get()) {
        buzzer.setState(!buzzerstate);
    }
    if (button_right.get()) {
        buzzer.setState(!buzzerstate);
    }
    writeLCD();
};

void showBattery() {

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.on();

    lcd_text_oben;
    lcd_text_unten = "Battery: " + String(calcBattery()) + " % ";
    writeLCD();
}

uint8_t calcBattery() {

    analogReadResolution(12); // adc 8 - Bit

    double VBat;
    double Vout;

    Vout = analogRead(BATTERY_LEVEL) * 3.3 / 4096; // analog --> Spannung
    VBat = (Vout * (Rv + RL) / RL); // Spannung Batterie

    uint32_t BatteryProcent = (uint32_t) ((VBat - BATTERY_MIN) * (100 - 0) / (BATTERY_MAX - BATTERY_MIN));

    analogReadResolution(8);

    return BatteryProcent;
};

void batteryCheck() {
    if (calcBattery() < 5) { // 5%
        mainState = STATE_BATTERY_CRITICAL;
        signalState = SIGNAL_WAIT;
        settingsState = SETTINGS_MAIN;
    }
}

void batteryCritical() {

    led_indicator.blink();
    led_left.off();
    led_middle.off();
    led_right.off();

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.off();

    motor.standby();
    lcd_text_oben = "BATTERY CRITICAL";
    lcd_text_unten = "PLEASE RECHARGE ";

    writeLCD();
}