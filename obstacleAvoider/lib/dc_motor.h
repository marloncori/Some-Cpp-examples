#ifndef DC_MOTOR_H
#define D_MOTOR_H

#include "speed_value.h"
#include "speed_direction.h"

namespace millenium {
    namespace robotics {
        class DCMotor {
            private:
                const unsigned int m_directionPin;
                const unsigned int m_speedPin;
                long m_speed;
                enum SpeedValue m_value;
                enum SpeedDirection m_direction;

                long m_clipRange(long speed);

            public:
                DCMotor(unsigned int directionPin, unsigned int speedPin);
                void initMotor();
                void setSpeed(long speed);
        };
    }
}

#endif // dc_motor.h