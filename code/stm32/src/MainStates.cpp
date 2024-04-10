#include "MainStates.h"

void idle() {
    lcd_text_oben = "                ";
    lcd_text_unten = "                ";

    led_indicator.blink();
    led_left.off();
    led_middle.off();
    led_right.off();

    lcd.clear();

    motor.standby();
}

void tune_e2() {
    lcd_text_oben = "Tuning E2: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + E2 + "Hz";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > E2 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < E2 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    }
}

void tune_a2() {
    lcd_text_oben = "Tuning A2: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + A2 + "Hz";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > A2 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < A2 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inTune(); }
}

void tune_d3() {
    lcd_text_oben = "Tuning D3: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + D3 + "Hz";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > D3 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < D3 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    }
}

void tune_g3() {
    lcd_text_oben = "Tuning G3: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + G3 + "Hz";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > G3 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < G3 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    }
}

void tune_h3() {
    lcd_text_oben = "Tuning H3: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + H3 + "Hz";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > H3 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < H3 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    }
}

void tune_e4() {
    lcd_text_oben = "Tuning E4: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + E4 + "Hz";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > E4 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < E4 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    }
}

void toHigh() {

    led_indicator.off();
    led_left.off();
    led_middle.off();
    led_right.on();

    motor.reverse();
}

void toLow() {

    led_indicator.off();
    led_left.on();
    led_middle.off();
    led_right.off();

    motor.forward();
}

void inTune() {

    led_indicator.off();
    led_left.off();
    led_middle.on();
    led_right.off();

    motor.breakk();
}

void writeLCD() {

//    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
}

void debug() {
    Serial.printf("Button Left: %i\n", button_left.get());
    Serial.printf("Button Middle: %i\n", button_middle.get());
    Serial.printf("Button Right: %i\n", button_right.get());
//
//    Serial.printf("Motor FIN %i\n", motor.getFin());
//    Serial.printf("Motor RIN %i\n\n", motor.getRin());
//
//    Serial.printf("LED Indicator: %i\n", led_indicator.get());
//    Serial.printf("LED Left: %i\n", led_left.get());
//    Serial.printf("LED Right: %i\n", led_right.get());
//    Serial.printf("LED Middle: %i\n\n", led_middle.get());
//

//    Serial.printf("LCD_first: %s\n", lcd_text_oben.c_str());
//    Serial.printf("LCD_second: %s\n\n", lcd_text_unten.c_str());
    Serial.printf("MAIN_STATE: %i\n", mainState);
    Serial.printf("SIGNAL_STATE: %i\n", signalState);
    Serial.printf("STATE_SETTINGS: %i\n\n", settingsState);
}
