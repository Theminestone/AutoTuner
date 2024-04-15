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
//        Serial.println("Tolerance up");
    }
    if (button_right.get()) {
        if (tolerance != 9) { tolerance++; }
        signal_in.setTolerance(tolerance);
//        Serial.println("Tolerance down");
    }

    lcd_text_unten = "Tolerance: " + String(signal_in.getTolerance()) + "    ";
    writeLCD();
}

void changeTune() {

    uint16_t tune = signal_in.getTune();
    if (button_left.get()) {
        if (tune != 432) { tune = tune - 2; }
        signal_in.setTune(tune);
//        Serial.println("Tune down");
    }
    if (button_right.get()) {
        if (tune != 446) { tune = tune + 2; }
        signal_in.setTune(tune);
//        Serial.println("Tune up");

    }

    lcd_text_oben;
    lcd_text_unten = "Tune: " + String(signal_in.getTune()) + "    ";
    writeLCD();
}

void showBattery() {

    lcd_text_oben;
    lcd_text_unten = "Battery: " + String(calcBattery()) + "%";
    writeLCD();
}

uint8_t calcBattery() {
    double VBat;
    double Vout;
    uint8_t BatteryProcent;

//    uint32_t a = analogRead(BATTERY_LEVEL);
    double a = 255;

    Vout = a * 3.3 / 255; // analog --> Spannung
    VBat = (Vout * (Rv + RL) / RL); // Spannung Batterie

    BatteryProcent = (uint8_t) ((VBat - BATTERY_MIN) * (100 - 0) / (BATTERY_MAX - BATTERY_MIN));

    return BatteryProcent;

    /*
     * Bei 3V3 (255) --> Batterie: 8V4 100%
     * Bei 2V6 (200) --> Batterie: 6V6 0%
     * */
};