#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
    private:
        std::chrono::time_point<std::chrono::steady_clock> startTime;

    public:
        Timer();
        void start();
        std::chrono::time_point<std::chrono::steady_clock> getStart();
        long elapsedTime();
};

#endif // timer.h
