
#include <iostream>
#include <windows.h>

#include "Arduino.h"
#include "bidirectional_motor.h"
 
millenium::robotics::DC_Motor::DC_Motor(unsigned int directionPinNumber, unsigned int speedPinNumber)
       : m_directionPin(directionPinNumber), m_speedPin(speedPinNumber) {
   std::cout << " [CONTROLLER] An instace of a DC Motor has been created!" << std::endl;
}

millenium::robotics::DC_Motor::~DC_Motor(){
	delete this;	
}

long millenium::robotics::DC_Motor::clipSpeedRange(long speed){
	if(speed < 0){
		m_value = SpeedValue::MAX_BACKWARD;
		if(speed < m_value){
			speed = SpeedValue::MAX_BACKWARD;
			std::cout << "  --> Robot motor speed range has been clipped. \n  Now it equals SpeedValue::MAX_BACKWARD (-255)." << std::endl;
		}
	} 
	else {
		m_value = SpeedValue::MAX_FORWARD;
		if(speed > m_value){
			speed = SpeedValue::MAX_FORWARD;
			std::cout << "  --> Robot motor speed range has been clipped. \n  Now it equals SpeedValue::MAX_FORWARD (255)." << std::endl;
		}
	}
  return speed;
}

void millenium::robotics::DC_Motor::init(){
	std::cout << " [CONTROLLER] Initializing DC Motor..." << std::endl;
	Sleep(3000);
	pinMode(m_directionPin, OUTPUT);
	pinMode(m_speedPin, INPUT);	
}

void millenium::robotics::DC_Motor::setSpeed(long speed){
	if(speed < 0){
		m_speed = clipSpeedRange(speed);
		m_direction = SpeedDirection::COUNTERCLOCKWISE;
		digitalWrite(m_directionPin, m_direction);
	    analogWrite(m_speedPin, m_speed);
	    std::cout << "   [DC_MOTOR] Robot wheel is moving BACKWARD!" << std::endl;
	}
	else {
		m_speed = clipSpeedRange(speed);
		m_direction = SpeedDirection::CLOCKWISE;
		digitalWrite(m_directionPin, m_direction);
	    analogWrite(m_speedPin, m_speed);
	    std::cout << "   [DC_MOTOR] Robot wheel is moving FORWARD!" << std::endl;
	}
}

