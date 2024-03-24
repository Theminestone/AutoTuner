#ifndef STM32_CONSTANTS_H
#define STM32_CONSTANTS_H

// LEDS
#define LED_INDICATOR PC13
#define LED_LEFT PA8
#define LED_MIDDLE PA9
#define LED_RIGHT PA10

// Buttons
#define BUTTON_LEFT PB13
#define BUTTON_RIGHT PB15
#define BUTTON_MIDDLE PB14

// Signal
#define SIGNAL_IN PA1
#define MAX_CYCLES 1000
#define SAMPLE_RATE 100 // us


// Battery
#define BATTERY_LEVEL PA6

// Motor
#define MOTOR_FIN PB0
#define MOTOR_RIN PB1

// Buzzer
#define BUZZER

// Notes
#define E4 329.63
#define A4 440.00
#define D5 587.33
#define G5 783.99
#define H5 987.77
#define E6 1318.51


#endif //STM32_CONSTANTS_H
