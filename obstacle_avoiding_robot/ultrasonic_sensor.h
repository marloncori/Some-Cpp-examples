#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "timer.h"

namespace millenium {
	namespace robotics {
		class UltrasonicSensor {
			private:
				Timer* clock;
				long time;
				const unsigned int m_triggerPin;
				const unsigned int m_echoPin;
				
				void m_ensureTriggerHasSettled();
				void m_sendPingSignal();
				unsigned int m_microsecondsToCm(long duration);
				unsigned int m_measurePongDelay();
				
			public:
				UltrasonicSensor(unsigned int triggerPinNumber, unsigned int echoPinNumber);
				~UltrasonicSensor();
				void begin();
				unsigned int getCollisionDistance();
		};
	}
}

#endif // ultrasonic_sensor.h
