#ifndef STM32_GLOBALS_H
#define STM32_GLOBALS_H

#include "AutoTuner.h"
#include "Constants.h"

extern LiquidCrystal_I2C lcd;

extern Button button_left;
extern Button button_right;
extern Button button_middle;

extern LED led_indicator;
extern LED led_left;
extern LED led_right;
extern LED led_middle;

extern Motor motor;

extern Signal signal_in;

extern String lcd_text_oben;
extern String lcd_text_unten;

extern STATE state;
extern SUB_STATE sub_state;
#endif //STM32_GLOBALS_H
