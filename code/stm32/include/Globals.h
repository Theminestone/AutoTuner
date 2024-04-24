#ifndef STM32_GLOBALS_H
#define STM32_GLOBALS_H

#include "AutoTuner.h"
#include "Constants.h"
#include "STATE.h"

extern LiquidCrystal_I2C lcd;

extern Buzzer buzzer;

extern Button button_left;
extern Button button_right;
extern Button button_middle;

extern LED led_indicator;
extern LED led_left;
extern LED led_right;
extern LED led_middle;

extern LED custom1;
extern LED custom2;
extern LED custom3;
extern LED custom4;

extern Motor motor;

extern Signal signal_in;

extern String lcd_text_oben;
extern String lcd_text_unten;

extern MAIN_STATE mainState;
extern SIGNAL_STATE signalState;
extern SETTINGS_STATE settingsState;

#endif //STM32_GLOBALS_H
