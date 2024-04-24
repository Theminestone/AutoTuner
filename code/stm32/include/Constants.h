#ifndef STM32_CONSTANTS_H
#define STM32_CONSTANTS_H

// LEDS
#define LED_INDICATOR PC13
#define LED_LEFT PA8
#define LED_MIDDLE PA9
#define LED_RIGHT PA10

#define CUSTOM3 PA15
#define CUSTOM4 PB3
#define CUSTOM2 PB4
#define CUSTOM1 PB5

// Buttons
#define BUTTON_LEFT PB13
#define BUTTON_RIGHT PB15
#define BUTTON_MIDDLE PB14

#define DEBOUNCETIME 5 // ms

// Signal
#define SIGNAL_IN PA2
#define MAX_CYCLES 1000 // 1000
#define SAMPLE_RATE 100 // 100 us

// Battery
#define BATTERY_LEVEL PA6
#define Rv 1820000 // 1MEG + 820k
#define RL 1180000 // 1MEG + 118k
#define BATTERY_MAX 8.4 // V
#define BATTERY_MIN 6.4 // V

// Motor
#define MOTOR_FIN PB0
#define MOTOR_RIN PB1

// Buzzer
#define BUZZER_PIN PB8
#define BUZZER_STATE false

// Notes https://www.profdong.com/elc4351/notefreqs.html

#define TUNE 440;
#define TOLERANZ 6 // +-

//#define E2_440 164.81
//#define A2_440 220.00
//#define D3_440 293.66
//#define G3_440 392.00
//#define H3_440 493.88
//#define E4_440 659.25
//
//#define E2_442 165.56
//#define A2_442 221.00
//#define D3_442 295.00
//#define G3_442 393.78
//#define H3_442 496.13
//#define E4_442 662.25

//#define E2 164.81
//#define A2 220.00
//#define D3 293.66
//#define G3 392.00
//#define H3 493.88
//#define E4 659.25

#define E2 82.41
#define A2 110.00
#define D3 146.83
#define G3 196.00
#define H3 246.94
#define E4 329.63

#endif //STM32_CONSTANTS_H
