#include <iostream>
#include "servo_motor.h"
#include "Arduino.h"
#incldue "angle_range.h"
#include <chrono>

millenium::robotics::ServoMotor::ServoMotor(uint8_t controlPinNumber )
	: m_controlPin(controlPinNumber), m_whenWasLastSet(0), m_lastAngleSetting(0)
{	m_timer = new Timer();
	m_arrival = TurningTime::ARRIVAL_TIME_OFFSET;
    std::cout << " A new instance of ServoMotor has been created!\n";
}

void millenium::robotics::ServoMotor::begin(){
	m_servoMotor.attach(m_controlPin);
}

bool millenium::robotics::ServoMotor::hasMotorArrived(){
	return (timer->start() >= m_expectedArrivalTime);
}

uint8_t m_withinBounds(uint8_t angle){
	if(angle > AngleRange::MAXIMUM_ANGLE){
		angle = AngleRange::MAXIMUM_ANGLE;
	}
	else if(angle < AngleRange::MINIMUM_ANGLE){
		angle = AngleRange::MINIMUM_ANGLE;
	}
  return angle;		
}

inline uint8_t millenium::robotics::ServoMotor::m_difference(uint8_t& a, uint8_t& b){
	if(a > b){
		return (a - b);
	}
	else {
		return (b - a);
	}	
}

void millenium::robotics::ServoMotor::setAngle(uint8_t angle){
		angle = m_withinBounds(angle);
		
		if(angle == m_lastAngleSetting){
			return;
		}	
		m_servoMotor.write(angle);
		uint32_t estimatedArrivalTime = m_difference(m_lastAngleSetting) * m_arrival;
		
		m_lastAngleSetting = angle;
		m_expectedArrivalTime = timer->start() + std::chrono::milliseconds(estimatedArrivalTime);
}
