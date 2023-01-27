
#include <iostream>
#include <unistd.h>

#include "dc_motor.h"
#include "arduino.h"

millenium::robotics::DCMotor::DCMotor(unsigned int directionPin, unsigned int speedPin)
        : m_directionPin(directionPin), m_speedPin(speedPin) {
    std::cout << "  An instance of a DC motor has been called.\n";
};

long millenium::robotics::DCMotor::m_clipRange(long speed){
    if(speed < 0){
        m_value = SpeedValue::MAX_BACKWARD;
        if(speed < m_value){
            speed = m_value;
        }
    }
    else {
        m_value = SpeedValue::MAX_FORWARD;
        if(speed > m_value){
            speed = m_value;
        }
    }
    std::cout << "  --> Robot motor speed range has been clipped. \n   Now it equals: " << speed << "\n";
    return speed;
}

void millenium::robotics::DCMotor::initMotor(){
    std::cout << " [DC_MOTOR] Initializing DC Motor...\n";
    sleep(2);
    arduino::pinMode(m_directionPin, mode::OUTPUT);
    arduino::pinMode(m_speedPin, mode::INPUT_M);
}

void millenium::robotics::DCMotor::setSpeed(long speed){
    std::string dirName;
    if(speed < 0){
        m_direction = SpeedDirection::COUNTERCLOCKWISE;
        dirName = "BACKWARD";
    }
    else {
        m_direction = SpeedDirection::CLOCKWISE;
        dirName = "FORWARD";
    }
    m_speed = m_clipRange(speed);
    arduino::digitalWrite(m_directionPin, m_direction);
    arduino::analogWrite(m_speedPin, m_speed);
    std::cout << "  [DC_MOTOR] Robot wheel is moving" << dirName << "\n";
}
