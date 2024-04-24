#include "AutoTuner.h"
#include "Globals.h"
#include "MainStates.h"
#include "SignalState.h"
#include "SettingsState.h"

HardwareTimer *timer = new HardwareTimer(TIM3);
HardwareTimer *timer_wait = new HardwareTimer(TIM4);
HardwareTimer *batteryLevel = new HardwareTimer(TIM2);

void setup() {
    Serial.begin(9600);

    motor.standby();
    lcd.init();
    lcd.backlight();
    lcd.clear();

    analogReadResolution(8); // adc 8 - Bit

    timer->setOverflow(SAMPLE_RATE, MICROSEC_FORMAT); // µs
    timer_wait->setOverflow(250000, MICROSEC_FORMAT);
    batteryLevel->setOverflow(5 * 1000000, MICROSEC_FORMAT);

    batteryLevel->resume();
    batteryLevel->attachInterrupt(batteryCheck);
}

void loop() {
    switch (mainState) {
        case STATE_IDLE:
            signalState = SIGNAL_WAIT;
            idle();
            if (button_middle.get()) { mainState = STATE_TUNE_E2; }
            break;
        case STATE_TUNE_E2:
            if (signalState == SIGNAL_WAIT) { signalState = SIGNAL_READ; }
            tune_e2();
            if (button_left.get()) { mainState = STATE_TUNE_E4; }
            if (button_right.get()) { mainState = STATE_TUNE_A2; }
            if (button_middle.get()) { mainState = STATE_SETTINGS; }
            break;
        case STATE_TUNE_A2:
            if (signalState == SIGNAL_WAIT) { signalState = SIGNAL_READ; }
            tune_a2();
            if (button_left.get()) { mainState = STATE_TUNE_E2; }
            if (button_right.get()) { mainState = STATE_TUNE_D3; }
            if (button_middle.get()) { mainState = STATE_SETTINGS; }
            break;
        case STATE_TUNE_D3:
            if (signalState == SIGNAL_WAIT) { signalState = SIGNAL_READ; }
            tune_d3();
            if (button_left.get()) { mainState = STATE_TUNE_A2; }
            if (button_right.get()) { mainState = STATE_TUNE_G3; }
            if (button_middle.get()) { mainState = STATE_SETTINGS; }
            break;
        case STATE_TUNE_G3:
            if (signalState == SIGNAL_WAIT) { signalState = SIGNAL_READ; }
            tune_g3();
            if (button_left.get()) { mainState = STATE_TUNE_D3; }
            if (button_right.get()) { mainState = STATE_TUNE_H3; }
            if (button_middle.get()) { mainState = STATE_SETTINGS; }
            break;
        case STATE_TUNE_H3:
            if (signalState == SIGNAL_WAIT) { signalState = SIGNAL_READ; }
            tune_h3();
            if (button_left.get()) { mainState = STATE_TUNE_G3; }
            if (button_right.get()) { mainState = STATE_TUNE_E4; }
            if (button_middle.get()) { mainState = STATE_SETTINGS; }
            break;
        case STATE_TUNE_E4:
            if (signalState == SIGNAL_WAIT) { signalState = SIGNAL_READ; }
            tune_e4();
            if (button_left.get()) { mainState = STATE_TUNE_H3; }
            if (button_right.get()) { mainState = STATE_TUNE_E2; }
            if (button_middle.get()) { mainState = STATE_SETTINGS; }
            break;
        case STATE_SETTINGS:
            signalState = SIGNAL_WAIT;
            switch (settingsState) {
                case SETTINGS_MAIN:
                    mainSettings();
                    if (button_middle.get()) { settingsState = SETTINGS_CHANGE_TOLERANCE; }
                    if (button_left.get()) { mainState = STATE_TUNE_E2; }
                    break;
                case SETTINGS_CHANGE_TOLERANCE:
                    changeTolerance();
                    if (button_middle.get()) { settingsState = SETTINGS_CHANGE_TUNE; }
                    break;
                case SETTINGS_CHANGE_TUNE:
                    changeTune();
                    if (button_middle.get()) { settingsState = SETTINGS_BATTERY; }
                    break;
                case SETTINGS_BATTERY:
                    showBattery();
                    if (button_middle.get()) { settingsState = SETTINGS_BUZZER; }
                    break;
                case SETTINGS_BUZZER:
                    changeBuzzer();
                    if (button_middle.get()) { settingsState = SETTINGS_MAIN; }
                    break;
            }
            break;
        case STATE_BATTERY_CRITICAL:
            timer->pause();
            timer_wait->pause();
            batteryLevel->pause();
            batteryCritical();
            break;
    }

    switch (signalState) {
        case SIGNAL_READ:
            timer_wait->pause();
            timer->resume();
            timer->attachInterrupt(read);
            break;
        case SIGNAL_PROCESS:
            timer->pause();
            timer_wait->resume();
            timer_wait->attachInterrupt(toSignalRead);
            process();
            break;
        case SIGNAL_WAIT:
            timer->pause();
            timer_wait->pause();
            break;
    }
    debug();
}