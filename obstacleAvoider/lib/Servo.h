#ifndef SERVO_H
#define SERVO_H

#include <inttypes.h>

#define SERVO_VERSION           2

#define MIN_PULSE_WIDTH       544
#define MAX_PULSE_WIDTH      2400
#define DEFAULT_PULSE_WIDTH  1500 // when servo is attached
#define REFRESH_INTERVAL     20000  // in microseconds

#define _Nbr_16timers         4
#define SERVOS_PER_TIMER     12
#define MAX_SERVOS          (_Nbr_16timers * SERVOS_PER_TIMER)
#define INVALID_SERVO        255

/*typedef struct {
    ServoPin_t Pin;
    volatile unsigned int ticks;
} servo_t; */

class Servo {
    private:
        unsigned char servoIndex;
        signed char min;
        signed char max;
        int m_lastValue;
        bool m_isActive;
        
    public:
        Servo();
        unsigned char attach(int pin);
        unsigned char attach(int pin, int min, int max);
        void detach();
        void write(int value);
        void writeMicroseconds(int value);
        int read();
        unsigned int readMicroseconds();
        bool isAttached();
};

#endif
