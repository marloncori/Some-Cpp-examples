#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

class Timer {
	private:
    	std::chrono::time_point<std::chrono::steady_clock> start_time;

	public:
		Timer();
		~Timer();
    	void start();
  	    long elapsedTime();
};

#endif
