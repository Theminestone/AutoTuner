#include "SettingsState.h"

void mainSettings() {
    lcd_text_oben = "Settings        ";
    lcd_text_unten = "<- Back         ";

    writeLCD();

    motor.standby();
}

void changeTolerance() {

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

void showBattery() {

    Serial.println(analogRead(BATTERY_LEVEL));



    lcd_text_oben;
    lcd_text_unten = "Battery: " + String(analogRead(BATTERY_LEVEL)) + "";
    writeLCD();
}