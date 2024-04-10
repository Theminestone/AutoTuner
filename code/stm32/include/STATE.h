#ifndef STM32_STATE_H
#define STM32_STATE_H

enum MAIN_STATE {
    STATE_IDLE = 0,
    STATE_TUNE_E2,
    STATE_TUNE_A2,
    STATE_TUNE_D3,
    STATE_TUNE_G3,
    STATE_TUNE_H3,
    STATE_TUNE_E4,
    STATE_SETTINGS,
};

enum SIGNAL_STATE {
    SIGNAL_WAIT = 0,
    SIGNAL_READ,
    SIGNAL_PROCESS,
};

enum SETTINGS_STATE {
    SETTINGS_MAIN = 0,
    SETTINGS_CHANGE_TOLERANCE,
    SETTINGS_CHANGE_TUNE,
    SETTINGS_BATTERY,
};

#endif //STM32_STATE_H
