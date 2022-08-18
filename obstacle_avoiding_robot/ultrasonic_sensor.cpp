
#include "Arduino.h"
#include "ultrasonic_sensor.h"

#include <iostream>
#include <windows.h>

#define NO_RETRY_LEFT 0
#define MAX_NUM_OF_RETRIES 10

millenium::robotics::UltrasonicSensor::UltrasonicSensor(
		unsigned int triggerPinNumber,
		unsigned int echoPinNumber
	):
		m_triggerPin(triggerPinNumber),
		m_echoPin(echoPinNumber) {  
		
	clock = new Timer();
	std::cout << " [HC-SR04] An instance of an ultrasonic sensor has been created!" << std::endl;
}

void millenium::robotics::UltrasonicSensor::begin(){
	std::cout << " [HC-SR04] Initializing sensor to start getting distance readings..." << std::endl;
	Sleep(500);
	pinMode(m_triggerPin, OUTPUT);
	pinMode(m_echoPin, INPUT);
}

void millenium::robotics::UltrasonicSensor::m_ensureTriggerHasSettled(){
	clock->start();
	digitalWrite(m_triggerPin, LOW);
	delayMicroseconds(2);
	std::cout << "   [HC-SR04] Trigger pin successfully settled!" << std::endl;
	time = clock->elapsedTime();	
}

void millenium::robotics::UltrasonicSensor::m_sendPingSignal(){
	clock->start();
	digitalWrite(m_triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_triggerPin, LOW);
	std::cout << "  [HC-SR04] A ping signal has been sent." << std::endl;
	time += clock->elapsedTime();	
}

unsigned int millenium::robotics::UltrasonicSensor::m_microsecondsToCm(long duration){
	return (unsigned int)duration * 0.034 / 2;
	//or return (duration/5.8)/10
	//or return (duration/2)/29.1
}

unsigned int millenium::robotics::UltrasonicSensor::m_measurePongDelay(){
	clock->start();
	pinMode(m_echoPin, INPUT);
	long measurement = pulseIn(m_echoPin, HIGH, time);
	std::cout << " [HC-SR04] Measuring the Pong delay..." << std::endl;
	time += clock->elapsedTime();
	measurement += (long)time;
  return m_microsecondsToCm(measurement);
}
	
unsigned int millenium::robotics::UltrasonicSensor::getCollisionDistance(){
	
	unsigned int feedback = 0;
	unsigned int lastMeasuredFeedback = 0;
	unsigned int retries = MAX_NUM_OF_RETRIES;
	
	do{
		lastMeasuredFeedback = feedback;
		m_ensureTriggerHasSettled();
		m_sendPingSignal();
		feedback = m_measurePongDelay();
		--retries;
	}while((feedback != lastMeasuredFeedback) && (retries > NO_RETRY_LEFT));
	if(retries == NO_RETRY_LEFT){
		std::cout << " [HC-SR04] No retries are left while getting the feedback." << std::endl;
	}
	else {
		std::cout << "  FEEDBACK EQUALS LAST MEASURED FEEDBACK!" << std::endl;
		
	}
	std::cout << " [HC-SR04] A distance reading has been obtained..." << std::endl;
	return feedback;
}
