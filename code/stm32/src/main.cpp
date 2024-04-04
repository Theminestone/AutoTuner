#include "AutoTuner.h"
#include "Globals.h"
#include "States.h"

HardwareTimer *timer = new HardwareTimer(TIM3);

void setup() {
    Serial.begin(9600);

    motor.standby();
    lcd.init();
    lcd.backlight();
    lcd.clear();

    analogReadResolution(8); // adc 8 - Bit

    timer->setOverflow(SAMPLE_RATE, MICROSEC_FORMAT); // µs
}

void loop() {
    switch (state) {
        case IDLE:
            sub_state = WAIT;
            idle();
            if (button_middle.get()) { state = TUNE_E2; }
            break;
        case TUNE_E2:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_e2();
            if (button_middle.get()) { state = TUNE_A2; }
            break;
        case TUNE_A2:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_a2();
            if (button_middle.get()) { state = TUNE_D3; }
            break;
        case TUNE_D3:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_d3();
            if (button_middle.get()) { state = TUNE_G3; }
            break;
        case TUNE_G3:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_g3();
            if (button_middle.get()) { state = TUNE_H3; }
            break;
        case TUNE_H3:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_h3();
            if (button_middle.get()) { state = TUNE_E4; }
            break;
        case TUNE_E4:
            if (sub_state == WAIT) { sub_state = READ; }
            tune_e4();
            if (button_middle.get()) { state = SETTINGS; }
            break;
        case SETTINGS:
            sub_state = WAIT;
            settings();
            if (button_middle.get()) { state = TUNE_E2; }
            break;
    }

    // State in Substate (Interupt)
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
            timer->pause();
            break;
    }
    debug();
}