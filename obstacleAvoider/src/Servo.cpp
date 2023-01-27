#include "Servo.h"
#include "arduino.h"

#include <iostream>

#define usToTicks(_us)  (( clockCyclesPerMicrosecond() * _us) / 8)
#define ticksToUs(_ticks)  (( (unsigned)_ticks * 8) / clockCyclesPerMicrosecond() )

#define TRIM_DURATION   2

#define NBR_TIMERS     (MAX_SERVOS / SERVOS_PER_TIMER)

//static servo_t servos[MAX_SERVOS];
static volatile unsigned char Channel[_Nbr_16timers];

unsigned char servoCount = 0;

#define SERVO_INDEX_TO_TIMER(_servo_nbr) ( (timer16_Sequence_t) (_servo_nbr / SERVOS_PER_TIMER))
#define SERVO_INDEX_TO_CHANNEL(_servo_nbr) (_servo_nbr % SERVOS_PER_TIMER)
#define SERVO_INDEX(_timer, _channel) ((_timer*SERVOS_PER_TIMER) + _channel)
//#define SERVO(_timer, _channel)  (servos[SERVO_INDEX(_timer, _channel)])

#define SERVO_MIN()  (MIN_PULSE_WIDTH - this->min * 4)
#define SERVO_MAX()  (MAX_PULSE_WIDTH - this->max * 4)

#define MIN_ANGLE   0
#define MAX_ANGLE   180

Servo::Servo(){
    if(servoCount < MAX_SERVOS){
        this->servoIndex = servoCount++;
        //servos[this->servoIndex].ticks usToTicks(DEFAULT_PULSE_WIDTH);
    }
    else {
        this->servoIndex = INVALID_SERVO;
    }
}

unsigned char Servo::attach(int pin){
    m_isActive = true;
    return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

unsigned char Servo::attach(int pin, int min, int max){
    if(this->servoIndex < MAX_SERVOS){
        arduino::pinMode(pin, mode::OUTPUT);
        //servos[this->servoIndex].Pin.nbr = pin;

        this->min = (MIN_PULSE_WIDTH - min)/4;
        this->max = (MAX_PULSE_WIDTH - max)/4;
        std::cout << "   Servo motor has been attached!\n";
        /*timer16_Sequence_t timer = SERVO_INDEX_TO_TIMER(servoIndex);
        if(isTimerActive(timer) == false){
            initISR(timer);
        }
        servos[this->servoIndex].Pin.isActive = true;*/
    }
    return this->servoIndex;
}

void Servo::detach(){
    /*servos[this->servoIndex].Pin.isActive = false;
    timer16_Sequence_t timer = SERVO_INDEX_TO_TIMER(servoIndex);
    if(isTimerActive(timer) == false){
        finISR(timer);
    }*/
    std::cout << " Servo motor has been detached!\n";
    m_isActive = false;
}

void Servo::write(int value){
    if(value < MIN_PULSE_WIDTH){
        if(value < 0) value = 0;
        if(value > 180) value = 180;
        value = arduino::mapRange(MIN_ANGLE, MAX_ANGLE, SERVO_MIN(), SERVO_MAX(), value);
    }
    std::cout << "  Servo angle has been set to: " << value << "!\n";
    this->writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value){
    short channel = this->servoIndex;
    if(channel < MAX_SERVOS){
        if(value < SERVO_MIN()){
            value = SERVO_MIN();
        }
        else if(value > SERVO_MAX()){
            value = SERVO_MAX();
        }

        value = value - TRIM_DURATION;
        value = usToTicks(value);
        m_lastValue = value;
        /*unsigned char oldSREG = SREG;
        cli();
        servos[channel].ticks = value;
        SREG = oldSREG;*/
    }
}

int Servo::read(){
    return arduino::mapRange(SERVO_MIN(), SERVO_MAX(), MIN_ANGLE, MAX_ANGLE, m_lastValue);
}


unsigned int Servo::readMicroseconds(){
    unsigned int pulseWidth;
    if(this->servoIndex != INVALID_SERVO){
        //pulseWidth = ticksToUs(servos[this->servoIndex].ticks) + TRIM_DURATION;
	pulseWidth = MAX_PULSE_WIDTH - MIN_PULSE_WIDTH;
    }
    else {
        pulseWidth = 0;
    }
    return pulseWidth;
}

bool Servo::isAttached(){
    //return servos[this->servoIndex].Pin.isActive;
    return m_isActive;
}
