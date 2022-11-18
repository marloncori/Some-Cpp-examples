#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "Servo.h"
#include "timer.h"
#include "turning_time.h"

namespace millenium {
	namespace robotics {
		class ServoMotor {
			private:
				const uint8_t controlPin;
				Servo m_servoMotor;
				uint32_t m_expectedArrivalTime;
				uint8_t m_lastAngleSetting;
				Timer* m_timer;
				enum TurningTime m_arrival;
				
				uint8_t m_difference(uint8_t& a, uint8_t& b);
				uint8_t m_withinBounds(uint8_t angle);
				
			public:
				ServoMotor(uint8_t controlPinNumber);
				void begin();
				bool hasMotorArrived();
				void setAngle(uint8_t angle);
		};
	}
}

#endif // servo_motor.h
