#include <iostream>

#include "servo_motor.h"
#include "arduino.h"
#include "angle_range.h"

millenium::robotics::ServoMotor::ServoMotor(unsigned char controlPin)
        : m_controlPin(controlPin), m_lastAngleSet(0), m_expectedArrivalTime(std::chrono::milliseconds(0)) {
     m_timer = new Timer();
     m_timer->start();
     m_arrival = TurningTime::ARRIVAL_TIME_OFFSET;
     std::cout << "  A new instance of a ServoMotor has been created!\n";           
}

void millenium::robotics::ServoMotor::initMotor(){
    m_arduinoServo.attach(m_controlPin);
}

bool millenium::robotics::ServoMotor::hasArrived(){
    return (m_timer->getStart() >= m_expectedArrivalTime);
}

unsigned char millenium::robotics::ServoMotor::m_withinBounds(unsigned char angle){
    if(angle > AngleRange::MAXIMUM){
        angle = AngleRange::MAXIMUM;
    }
    else if(angle < AngleRange::MINIMUM){
        angle = AngleRange::MINIMUM;
    }
    return angle;
}

inline unsigned char millenium::robotics::ServoMotor::m_difference(unsigned char& first, unsigned char& second){
    if(first > second){
        return (first - second);
    }
    else {
        return (second - first);
    }
}

void millenium::robotics::ServoMotor::setAngle(unsigned char angle){
    //m_timer->start();

    angle = m_withinBounds(angle);
    if(angle == m_lastAngleSet){
        return ;
    }
    m_arduinoServo.write(angle);
    unsigned long estimatedArrivalTime = m_difference(angle, m_lastAngleSet) * m_arrival;

    m_lastAngleSet = angle;
    std::chrono::seconds secs(estimatedArrivalTime/1000);
    std::chrono::steady_clock::time_point now = m_timer->getStart();

    m_expectedArrivalTime = now + secs;
}
