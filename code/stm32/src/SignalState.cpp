#include "SignalState.h"

void read() {

//    Serial.printf("%i, ", signal_in.readADC());
    signal_in.createWave();
    if (signal_in.isReady()) { // bis x samples
        signalState = SIGNAL_PROCESS;
    }
}

void process() {
    signal_in.calcFrequency();
//    signalState = SIGNAL_READ;
}

void toSignalRead() {
    signalState = SIGNAL_READ;
};
