#include "SignalState.h"

void read() {
    signal_in.createWave();
    if (signal_in.isReady()) {
        signalState = SIGNAL_PROCESS;
    }
}

void process() {
    signal_in.calcFrequency();
}

void toSignalRead() {
    signalState = SIGNAL_READ;
};
