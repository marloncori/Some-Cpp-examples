
#include "timer.h"
#include <iostream>

Timer::Timer(){
    std::cout << " *---->> A timer has been initialized!\n";
}

void Timer::start(){
    startTime = std::chrono::steady_clock::now();
}

std::chrono::time_point<std::chrono::steady_clock> Timer::getStart(){
  return startTime;
}

long Timer::elapsedTime(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - startTime).count();
}

