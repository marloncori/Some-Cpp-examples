#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include "timer.h"

namespace millenium {
    namespace robotics {
        class UltrasonicSensor {
            private:
                Timer* m_clock;
                long m_time;
                const unsigned int m_triggerPin;
                const unsigned int m_echoPin;

                void m_ensureTriggerHasSettled();
                void m_sendPingSignal();
                unsigned int m_microsecondsToCm(long duration);
                unsigned int m_measurePongDelay();

            public:
                UltrasonicSensor(unsigned int triggerPin, unsigned int echoPin);
                void initSensor();
                unsigned int getDistance();
        };
    }
}

#endif // ultrasonic_sensor.h