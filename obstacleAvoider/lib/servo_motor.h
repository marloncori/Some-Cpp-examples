#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <chrono>
#include "Servo.h"
#include "timer.h"
#include "turning_time.h"

namespace millenium {
    namespace robotics {
        class ServoMotor {
            private:
                const unsigned char m_controlPin;
                Servo m_arduinoServo;
                std::chrono::steady_clock::time_point m_expectedArrivalTime;
                unsigned char m_lastAngleSet;
                Timer* m_timer;
                enum TurningTime m_arrival;

                unsigned char m_difference( unsigned char& first,  unsigned char& second);
                unsigned char m_withinBounds(unsigned char angle);          
            
            public:
                ServoMotor(unsigned char controlPin);
                void initMotor();
                bool hasArrived();
                void setAngle(unsigned char angle);
        };
    }
}

#endif // servo_motor.h
