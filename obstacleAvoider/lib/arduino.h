#ifndef ARDUINO_H
#define ARDUINO_H

#include <iostream>
#include <unistd.h>

#define F_CPU  16000000

#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define clockCyclesPerMicrosecond()  ( F_CPU / 1000000L )

static std::string line(" -----------------------------------------------------");

enum mode {
    OUTPUT,
    INPUT_M,
};

enum state {
    LOW,
    HIGH,
};

namespace arduino {

    void pinMode(unsigned int GPIO, unsigned int direction);

    void digitalWrite(unsigned int GPIO, unsigned int logic);

    void analogWrite(unsigned int GPIO, long bits);

    void delayMicroseconds(long time);
    
    unsigned long pulseIn(unsigned int GPIO, unsigned int state, unsigned long timeout);

    int mapRange(int minA, int maxA, int minB, int maxB, int inputA);

}

#endif
