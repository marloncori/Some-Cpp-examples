/*Best C++ beginner tutorial arduino robot by Rawze, pt1 - pt10*/

#ifndef BIDIRECTIONAL_MOTOR_H_
#define BIDIRECTIONAL_MOTOR_H_

#include "speed_value.h"
#include "speed_direction.h"

namespace millenium {
	namespace robotics {
		class DC_Motor {
			private: 
				const unsigned int m_directionPin;
				const unsigned int m_speedPin;
				      long m_speed;
				enum SpeedValue m_value;
				enum SpeedDirection m_direction;
				long clipSpeedRange(long speed);
			public:
				DC_Motor(unsigned int directionPinNumber, unsigned int speedPinNumber);
				~DC_Motor();
				void init();
				void setSpeed(long speed);
		};
				
	}
}


#endif // bidirectional_motor.h

