#include "MainStates.h"

void idle() {
    lcd_text_oben = "                ";
    lcd_text_unten = "                ";

    led_indicator.on();
    led_left.off();
    led_middle.off();
    led_right.off();

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.off();

    lcd.clear();

    motor.standby();
}

void tune_e2() {
    lcd_text_oben = "Tuning E2: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + E2 + "Hz  ";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > E2 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < E2 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inIdle(); }

    buzzer.setNote((uint16_t) E2);
    buzzer.play();
}

void tune_a2() {
    lcd_text_oben = "Tuning A2: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + A2 + "Hz  ";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > A2 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < A2 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inIdle(); }

    buzzer.setNote((uint16_t) A2);
    buzzer.play();
}

void tune_d3() {
    lcd_text_oben = "Tuning D3: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + D3 + "Hz  ";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > D3 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < D3 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inIdle(); }

    buzzer.setNote((uint16_t) D3);
    buzzer.play();
}

void tune_g3() {
    lcd_text_oben = "Tuning G3: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + G3 + "Hz  ";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > G3 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < G3 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inIdle(); }

    buzzer.setNote((uint16_t) G3);
    buzzer.play();
}

void tune_h3() {
    lcd_text_oben = "Tuning H3: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + H3 + "Hz  ";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > H3 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < H3 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inIdle(); }

    buzzer.setNote((uint16_t) H3);
    buzzer.play();
}

void tune_e4() {
    lcd_text_oben = "Tuning E4: ...";
    lcd_text_unten = String(signal_in.getFrequency()) + "Hz->" + E4 + "Hz  ";

    writeLCD();

    if (signal_in.getFrequency() > 0) {
        if (signal_in.getFrequency() > E4 + signal_in.getTolerance()) {
            toHigh();
        } else if (signal_in.getFrequency() < E4 - signal_in.getTolerance()) {
            toLow();
        } else {
            inTune();
        }
    } else { inIdle(); }

    buzzer.setNote((uint16_t) E4);
    buzzer.play();
}

void toHigh() {

    led_indicator.off();
    led_left.off();
    led_middle.off();
    led_right.on();

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.off();

    motor.reverse();
}

void toLow() {

    led_indicator.off();
    led_left.on();
    led_middle.off();
    led_right.off();

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.off();

    motor.forward();
}

void inTune() {

    led_indicator.off();
    led_left.off();
    led_middle.on();
    led_right.off();

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.off();

    motor.standby();
}

void inIdle() {

    custom1.off();
    custom2.off();
    custom3.off();
    custom4.off();

    led_left.off();
    led_middle.off();
    led_right.off();

    led_indicator.off();
    led_left.blink();
    led_middle.blink();
    led_right.blink();

    motor.standby();
}

void writeLCD() {

    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
}

void debug() {
    Serial.printf("Button Left: %i\n", button_left.get());
    Serial.printf("Button Middle: %i\n", button_middle.get());
    Serial.printf("Button Right: %i\n", button_right.get());

    Serial.printf("LED Indicator: %i\n", led_indicator.get());
    Serial.printf("LED Left: %i\n", led_left.get());
    Serial.printf("LED Right: %i\n", led_right.get());
    Serial.printf("LED Middle: %i\n", led_middle.get());

    Serial.printf("Custom1: %i\n", custom1.get());
    Serial.printf("Custom2: %i\n", custom2.get());
    Serial.printf("Custom3: %i\n", custom3.get());
    Serial.printf("Custom4: %i\n", custom4.get());

    Serial.printf("Motor FIN %i\n", motor.getFin());
    Serial.printf("Motor RIN %i\n\n", motor.getRin());

    Serial.printf("Frequency %i\n", signal_in.getFrequency());
    Serial.printf("Tolerance %i\n", signal_in.getTolerance());
    Serial.printf("Tune %i\n", signal_in.getTune());
    Serial.printf("Battery %s\n", calcBattery());

    Serial.printf("LCD_first: %s\n", lcd_text_oben.c_str());
    Serial.printf("LCD_second: %s\n\n", lcd_text_unten.c_str());

    Serial.printf("MAIN_STATE: %i\n", mainState);
    Serial.printf("SIGNAL_STATE: %i\n", signalState);
    Serial.printf("STATE_SETTINGS: %i\n\n", settingsState);
}
