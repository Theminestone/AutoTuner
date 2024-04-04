#ifndef STM32_STATES_H
#define STM32_STATES_H

#include "Globals.h"

void read();

void process();

void idle();

void tune_e2();

void tune_a2();

void tune_d3();

void tune_g3();

void tune_h3();

void tune_e4();

void settings();

void toHigh();

void toLow();

void inTune();

void writeLCD();

void debug();

#endif //STM32_STATES_H
