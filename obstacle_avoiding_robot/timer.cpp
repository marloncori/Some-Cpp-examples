
#include "timer.h"
#include <iostream>

Timer::Timer(){
	std::cout << " ----->>>> A TIMER HAS BEEN CREATED!" << std::endl;
}

Timer::~Timer(){
	delete this;
}

void Timer::start() {
    start_time = std::chrono::steady_clock::now();
}

long Timer::elapsedTime() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            	    std::chrono::steady_clock::now() - start_time).count();
}
    	
