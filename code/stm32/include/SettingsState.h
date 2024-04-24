
#ifndef STM32_SETTINGSSTATE_H
#define STM32_SETTINGSSTATE_H

#include "Globals.h"
#include "STATE.h"
#include "MainStates.h"

void mainSettings();

void changeTolerance();

void changeTune();

void changeBuzzer();

void showBattery();

uint8_t calcBattery();

void batteryCheck();

void batteryCritical();

#endif //STM32_SETTINGSSTATE_H
