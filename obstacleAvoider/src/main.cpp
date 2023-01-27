#include <iostream>

#include "arduino.h"
#include "dc_motor.h"
#include "ultrasonic_sensor.h"
#include "servo_motor.h"

constexpr unsigned int triggerPin = 8;
constexpr unsigned int echoPin    = 9;

constexpr unsigned int motorPin   = 12;
constexpr unsigned int speedPin   = 10;

constexpr unsigned int controlPin   = 14;

std::string start("\n\t >>>> PROGRAM IS ABOUT TO START... <<<<< ");
std::string takePause("\n\t ====== PROGRAM HAS STOPPED FOR A WHILE =======");
std::string cleanUp("\n\t  ::: PROGRAM HAS FINALLY ENDED ::: ");
std::string line2("..................................................");
std::string line3(" ::::::::::::::::::::::::::::::::::::::::::::::::::");


millenium::robotics::DCMotor* motor = 
  new millenium::robotics::DCMotor(motorPin, speedPin); 
millenium::robotics::UltrasonicSensor* hc_sr04 = 
  new millenium::robotics::UltrasonicSensor(triggerPin, echoPin);
millenium::robotics::ServoMotor* servo = 
    new millenium::robotics::ServoMotor(controlPin);

void setup();
void loop();

int main(int argc, char** argv) {
    std::cout << start << "\n";
    arduino::delayMicroseconds(1000);

    setup();
    arduino::delayMicroseconds(1000);

    loop();

    std::cout << cleanUp << "\n";

  return 0;
}

void setup(){
    enum SpeedValue initVal = SpeedValue::INITIAL;
    enum SpeedValue fwdVal = SpeedValue::MAX_FORWARD;
    enum SpeedValue bkdVal = SpeedValue::MAX_BACKWARD;

    std::cout << "\n\n\t Speed value is set to --> " << 
        (initVal == 0 ? "STOPPED" : initVal == 255 ? "MAX_FORWARD" : "MAX_BACKWARD") << "!\n";
    arduino::delayMicroseconds(1000);

    std::cout << "\n\n\t New speed value is set to --> " << 
        (fwdVal == 0 ? "STOPPED" : fwdVal == 255 ? "MAX_FORWARD" : "MAX_BACKWARD") << "!\n";    
    arduino::delayMicroseconds(1000);

    std::cout << "\n\n\t Yet another speed value is set to --> " << 
        (bkdVal == 0 ? "STOPPED" : bkdVal == 255 ? "MAX_FORWARD" : "MAX_BACKWARD") << "!\n";    
    arduino::delayMicroseconds(1000);

    enum SpeedDirection dir1 = SpeedDirection::CLOCKWISE;
    enum SpeedDirection dir2 = SpeedDirection::COUNTERCLOCKWISE;

    std::cout << "\n\n\t Speed direction is preset to ==> " << 
        (dir1 == 1 ? "COUNTERCLOCKWISE" : "CLOCKWISE") << "!\n";    
    arduino::delayMicroseconds(1000);
   
    std::cout << "\n\n\t New speed direction is preset to ==> " << 
        (dir2 == 1 ? "COUNTERCLOCKWISE" : "CLOCKWISE") << "!\n";    
    arduino::delayMicroseconds(1000);

    motor->initMotor();
    arduino::delayMicroseconds(2000);
    hc_sr04->initSensor();
    arduino::delayMicroseconds(4000);
    servo->initMotor();
    arduino::delayMicroseconds(1500);
}

void loop(){
    int distance = hc_sr04->getDistance();
    std::cout << "\n" << line3 << " HC-SR04 Ultrasonic sensor has read this distance: \n\t --> " << distance << " cm!\n"; 

    for(long PWM {255}; PWM > 100; PWM -= 40){
        motor->setSpeed(-PWM);
        arduino::delayMicroseconds(3000);
    }

    servo->setAngle(150);
    while(!servo->hasArrived()){}
    arduino::delayMicroseconds(500);

    distance = hc_sr04->getDistance();
    std::cout << "\n" << line3 << " HC-SR04 Ultrasonic sensor has read a new distance: \n\t --> " << distance << " cm!\n"; 

    std::cout << takePause << "\n";
    arduino::delayMicroseconds(1000);

    long highSpeed = 260;
    motor->setSpeed(highSpeed);
    arduino::delayMicroseconds(2000);

    servo->setAngle(79);
    while(!servo->hasArrived()){}
    arduino::delayMicroseconds(500);

    distance = hc_sr04->getDistance();
    std::cout << "\n" << line3 << " HC-SR04 Ultrasonic sensor has read a new distance: \n\t --> " << distance << " cm!\n"; 

    long lowSpeed = -270;
    motor->setSpeed(lowSpeed);
    arduino::delayMicroseconds(2000);

    servo->setAngle(-120);
    while(!servo->hasArrived()){}
    arduino::delayMicroseconds(500);
    
    std::cout << line2 << "\n";

    distance = hc_sr04->getDistance();
    std::cout << "\n" << line3 << " HC-SR04 Ultrasonic sensor has read a new distance: \n\t --> " << distance << " cm!\n"; 

   return;
}
