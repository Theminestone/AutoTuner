#include "States.h"

void idle() {
    lcd.clear();
    lcd.flush();
    lcd_text_unten = "";
    lcd_text_oben = "";

    led_indicator.blink();
    led_left.off();
    led_middle.off();
    led_right.off();
}

void tune_e1() {
    lcd_text_oben = "Tuning E1String:";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.off();
    led_left.blink();
    led_middle.blink();
    led_right.blink();
}

void tune_a() {
    lcd_text_oben = "Tuning A-String:";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.on();
    led_left.blink();
    led_middle.blink();
    led_right.blink();
}

void tune_d() {
    lcd_text_oben = "Tuning D-String:";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.on();
    led_left.blink();
    led_middle.blink();
    led_right.blink();
}

void tune_g() {
    lcd_text_oben = "Tuning G-String:";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.on();
    led_left.blink();
    led_middle.blink();
    led_right.blink();
}

void tune_h() {
    lcd_text_oben = "Tuning H-String:";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.on();
    led_left.blink();
    led_middle.blink();
    led_right.blink();
}

void tune_e2() {
    lcd_text_oben = "Tuning E2String:";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.on();
    led_left.blink();
    led_middle.blink();
    led_right.blink();
}

void settings() {
    lcd_text_oben = "Settings";
    lcd_text_unten;
    lcd.setCursor(0, 0);
    lcd.print(lcd_text_oben);
    lcd.setCursor(0, 1);
    lcd.print(lcd_text_unten);
    lcd.write(1);

    led_indicator.blink();
    led_left.on();
    led_middle.on();
    led_right.on();
}

void beep() {}

void readADC() {
    signal_in.createSample();
    if (signal_in.isReady()) {
        sub_state = PROCESS;
    }
}

void process() {
    for (int i = 0; i < 500; ++i) {
        Serial.println(signal_in.getSample(i));
    }
    sub_state = READ;
}

void debug() {
    Serial.printf("Button Left: %i\n", button_left.get());
    Serial.printf("Button Middle: %i\n", button_middle.get());
    Serial.printf("Button Right: %i\n\n", button_right.get());
//
//    Serial.printf("Motor FIN %i\n", motor.getFin());
//    Serial.printf("Motor RIN %i\n\n", motor.getRin());
//
//    Serial.printf("LED Indicator: %i\n", led_indicator.get());
//    Serial.printf("LED Left: %i\n", led_left.get());
//    Serial.printf("LED Right: %i\n", led_right.get());
//    Serial.printf("LED Middle: %i\n\n", led_middle.get());
//

    Serial.printf("LCD_first: %s\n", lcd_text_oben.c_str());
    Serial.printf("LCD_second: %s\n\n", lcd_text_unten.c_str());
    Serial.printf("STATE: %i\n", state);
    Serial.printf("SUB STATE: %i\n\n\n\n", sub_state);
}

