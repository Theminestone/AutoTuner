#include "AutoTuner.h"
#include "Globals.h"
#include "States.h"

HardwareTimer *timer = new HardwareTimer(TIM3);

void setup() {

    Serial.begin(9600);

    state = IDLE;
    sub_state = WAIT;

    lcd.init();
    lcd.backlight();
    lcd.clear();

    analogReadResolution(8); // adc 8bit?

    timer->setOverflow(SAMPLE_RATE, MICROSEC_FORMAT); // µs
}


void loop() {
    switch (state) {
        case IDLE:
            sub_state = WAIT;
            idle();
            if (button_middle.update()) { state = TUNE_E1; }
            break;
        case TUNE_E1:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_e1();
//            if (button_right.update() && !button_left.update()) { state = TUNE_A; }
//            if (button_right.update()) { state = SETTINGS; }

            break;
        case TUNE_A:
            tune_a();
//            if (button_right.update() && !button_left.update()) { state = TUNE_D; }
//            if (!button_right.update() && button_left.update()) { state = TUNE_E1; }
            break;
        case TUNE_D:
            tune_d();
//            if (button_right.update() && !button_left.update()) { state = TUNE_G; }
//            if (!button_right.update() && button_left.update()) { state = TUNE_A; }
            break;
        case TUNE_G:
            tune_g();
//            if (button_right.update() && !button_left.update()) { state = TUNE_H; }
//            if (!button_right.update() && button_left.update()) { state = TUNE_D; }
            break;
        case TUNE_H:
            tune_h();
//            if (button_right.update() && !button_left.update()) { state = TUNE_E2; }
//            if (!button_right.update() && button_left.update()) { state = TUNE_G; }
            break;
        case TUNE_E2:
            tune_e2();
//            if (button_right.update() && !button_left.update()) { state = SETTINGS; }
//            if (!button_right.update() && button_left.update()) { state = TUNE_H; }
            break;
        case SETTINGS:
            sub_state = WAIT;
            settings();
            if (button_middle.update()) { state = IDLE; }
            break;
        case BEEP:
            beep();
            break;
    }

    // State in Substate (Interupt)
    if (state == TUNE_E1 || state == TUNE_A || state == TUNE_D || state == TUNE_G || state == TUNE_H || state == TUNE_E2) {
        switch (sub_state) {
            case READ:
                timer->resume();
                timer->attachInterrupt(read);
                break;
            case PROCESS:
                timer->pause();
                process();
                break;
            case WAIT:
                break;
        }
    }
//    debug();
}
