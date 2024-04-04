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

#define DEBOUNCETIME 5 // ms

// Signal
#define SIGNAL_IN PA1
#define MAX_CYCLES 1000
#define SAMPLE_RATE 100 // 100 us

// Battery
#define BATTERY_LEVEL PA6

// Motor
#define MOTOR_FIN PB0
#define MOTOR_RIN PB1

// Buzzer
#define BUZZER

// Notes
#define E2 82.41
#define A2 220 // 110.00
#define D3 146.83
#define G3 196.00
#define H3 246.94
#define E4 329.63
#define TOLERANZ 3 // +-

#endif //STM32_CONSTANTS_H
