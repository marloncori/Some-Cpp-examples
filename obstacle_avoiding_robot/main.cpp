#include <iostream>
#include <windows.h>

//#include "Arduino.h"
//#include "bidirectional_motor.h"
#include "ultrasonic_sensor.h"

using namespace millenium::robotics;

constexpr unsigned int trigPin = 8;
constexpr unsigned int echoPin = 9;

//constexpr unsigned int motorPin = 12;
//constexpr unsigned int speedPin = 10;

std::string start("\n\t >>>> PROGRAM IS ABOUT TO START <<<< ");
std::string pause("\n\t ====== PROGRAM HAS STOPPED FOR A WHILE ===== ");
std::string cleanUp("\n\t ::: PROGRAM HAS ENDED ::: ");
std::string line2("................................................................");

//DC_Motor* motor = new DC_Motor(motorPin, speedPin);
UltrasonicSensor* hc_sr04 = new UltrasonicSensor(trigPin, echoPin);
unsigned int distance = 0;

void setup();
void loop();

int main(){
   
   std::cout << start << std::endl;
   Sleep(400);
   
   setup();
   loop();
   
   std::cout << cleanUp << std::endl;
   
   return 0;
}

void setup(){
	/*enum SpeedValue value = SpeedValue::INITIAL;
	enum SpeedValue value2 = SpeedValue::MAX_FORWARD;
	enum SpeedValue value3 = SpeedValue::MAX_BACKWARD;
	
	std::cout << "\n\n\t  SpeedValue is set to ---> " << 
	  (value == 0 ? "STOPPED" : value == 255 ? "MAX_FORWARD" : "MAX_BACKWARD") << std::endl;
	Sleep(1000);
	std::cout << "\t  New SpeedValue is set to ---> " << 
	  (value2 == 0 ? "STOPPED" : value2 == 255 ? "MAX_FORWARD" : "MAX_BACKWARD") << std::endl;
	Sleep(1000);		
	std::cout << "\t  New SpeedValue 2 is set to ---> " <<
	  (value3 == 0 ? "STOPPED" : value3 == 255 ? "MAX_FORWARD" : "MAX_BACKWARD") << "\n\n " << line2 << std::endl;
	Sleep(1000);

	SpeedDirection dir1 = SpeedDirection::CLOCKWISE;
	SpeedDirection dir2 = SpeedDirection::COUNTERCLOCKWISE;
	
	std::cout << "\n\n\t  SpeedDirection is preset as --> " 
	     << (dir1 == 1 ? "COUNTERCLOCKWISE" : "CLOCKWISE") << std::endl;
	Sleep(1000);
	std::cout << "\t   Now speedDirection is preset as --> " 
	    << (dir2 == 1 ? "COUNTERCLOCKWISE" : "CLOCKWISE") <<"\n\n " << line2 << std::endl;
	Sleep(1000);*/

//	motor->init();		
//	Sleep(2000);
	hc_sr04->begin();
	Sleep(400);
}

void loop(){
	distance = hc_sr04->getCollisionDistance();
	std::cout << "\n ::::::::::::::::::::::::::::::::::::::::::::::::::::::\n HC-SR04 Ultrasonic sensor has read this distance: " << distance << " cm.\n ::::::::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	Sleep(500);	

	/*for(long PWM {255}; PWM > 100; PWM -= 45){
		motor->setSpeed(-PWM);
		Sleep(1000);	
    }*/
	distance = hc_sr04->getCollisionDistance();
	std::cout << "\n ::::::::::::::::::::::::::::::::::\n HC-SR04 Ultrasonic sensor has read this distance: " << distance << " cm.\n ::::::::::::::::::::::::::::::::::" << std::endl;
	
	std::cout << pause << std::endl;
	Sleep(500);
	/*long highSpeed = 260;
	motor->setSpeed(highSpeed);*/
	Sleep(200);
	
	distance = hc_sr04->getCollisionDistance();
	std::cout << "\n ::::::::::::::::::::::::::::::::::\n HC-SR04 Ultrasonic sensor has read this distance: " << distance << " cm.\n ::::::::::::::::::::::::::::::::::" << std::endl;
	
	/*long lowSpeed = -270;	
	motor->setSpeed(lowSpeed);*/
	Sleep(500);
	std::cout << line2 << std::endl;
	distance = hc_sr04->getCollisionDistance();
	std::cout << "\n ::::::::::::::::::::::::::::::::::\n HC-SR04 Ultrasonic sensor has read this distance: " << distance << " cm.\n ::::::::::::::::::::::::::::::::::" << std::endl;
}

