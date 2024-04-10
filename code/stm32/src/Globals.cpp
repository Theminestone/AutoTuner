#include "Globals.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

Button button_left(BUTTON_LEFT, DEBOUNCETIME);
Button button_right(BUTTON_RIGHT, DEBOUNCETIME);
Button button_middle(BUTTON_MIDDLE, DEBOUNCETIME);

LED led_indicator(LED_INDICATOR);
LED led_left(LED_LEFT);
LED led_right(LED_RIGHT);
LED led_middle(LED_MIDDLE);

Motor motor(MOTOR_FIN, MOTOR_RIN);

Signal signal_in(SIGNAL_IN, MAX_CYCLES, SAMPLE_RATE);

String lcd_text_oben = "                ";
String lcd_text_unten = "                ";

MAIN_STATE mainState = STATE_IDLE;
SIGNAL_STATE signalState = SIGNAL_WAIT;
SETTINGS_STATE settingsState = SETTINGS_MAIN;