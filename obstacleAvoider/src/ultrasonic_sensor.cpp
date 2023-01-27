
#include "arduino.h"
#include "ultrasonic_sensor.h"

#include <iostream>

#define  NO_RETRY_LEFT   0
#define  NUM_OF_RETRIES  1

millenium::robotics::UltrasonicSensor::UltrasonicSensor(
    unsigned int triggerPin, unsigned int echoPin
) : m_triggerPin(triggerPin), m_echoPin(echoPin){
    m_clock = new Timer();
    std::cout << "  [HC-SR04] An instance of an ultrasonic sensor has been created!\n";
}

void millenium::robotics::UltrasonicSensor::initSensor(){
    std::cout << " [HC-SR04] Initializing sensor to start getting distance readings...\n";
    arduino::pinMode(m_triggerPin, mode::OUTPUT);
    arduino::pinMode(m_echoPin, mode::INPUT_M);
}

void millenium::robotics::UltrasonicSensor::m_ensureTriggerHasSettled(){
    m_clock->start();
    arduino::digitalWrite(m_triggerPin, state::LOW);
    arduino::delayMicroseconds(2);
    std::cout << " [HC-SR04] Trigger pin settled!\n";
    m_time = m_clock->elapsedTime();
}

void millenium::robotics::UltrasonicSensor::m_sendPingSignal(){
    m_clock->start();
    arduino::digitalWrite(m_triggerPin, state::HIGH);
    arduino::delayMicroseconds(10);
    arduino::digitalWrite(m_triggerPin, state::LOW);
    std::cout << " [HC-SR04] A ping signal has been sent...\n";
    m_time += m_clock->elapsedTime();
}

unsigned int millenium::robotics::UltrasonicSensor::m_microsecondsToCm(long duration){
    return static_cast<unsigned int>(duration * 0.034 / 2);
    //or return (duration/5.8) / 10;
    //or return (duration/2) /29.1;
}

unsigned int millenium::robotics::UltrasonicSensor::m_measurePongDelay(){
    m_clock->start();
    arduino::pinMode(m_echoPin, mode::INPUT_M);
    long measurement = arduino::pulseIn(m_echoPin, state::HIGH, m_time);
    std::cout << "  [HC-SR04] Measuring the pong delay from data received by echo pin...\n";
    m_time += m_clock->elapsedTime();
    measurement += static_cast<long>(m_time);
  return m_microsecondsToCm(measurement);   
}

unsigned int millenium::robotics::UltrasonicSensor::getDistance(){
    unsigned int distance = 0;
    unsigned int lastMeasuredDist = 0;
    unsigned int retries = NUM_OF_RETRIES;

    do{
        lastMeasuredDist = distance;
        m_ensureTriggerHasSettled();
        m_sendPingSignal();
        distance = m_measurePongDelay();
        --retries;
    } while((distance != lastMeasuredDist) || (retries > NO_RETRY_LEFT));

    if(retries == NO_RETRY_LEFT){
        std::cout << " [HC-SR04]  No retries are left to get distance.\n";
    }
    std::cout << " [HC-SR04]  A distance reading has been obtained...\n";
   return distance;
}
