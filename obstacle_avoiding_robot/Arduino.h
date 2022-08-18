#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <iostream>
#include <windows.h>

#define OUTPUT 0
#define INPUT  1

#define LOW  0
#define HIGH 1

#define F_CPU 16000000

#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )

std::string line(" ----------------------------------------------------");

template<class T, class U>
void pinMode(T GPIO, U direction){
  std::cout << "\n" << line << std::endl;
  std::cout << "  An electronic component has been connected to \n   Arduino\'s GPIO "
   << GPIO << " and it is configured as " << (direction == OUTPUT ? "OUTPUT" : "INPUT") << "!" << std::endl;	
  std::cout << line << "\n" << std::endl;
}

template<class T, class U>
void digitalWrite(T GPIO, U logic){
  std::cout << "\n\t" << line << std::endl;
  std::cout << "\t   [DIGITAL INFO] Arduino\'s GPIO " << GPIO << " is set to " << 
   (logic == LOW ? "LOW" : "HIGH") << "!" << std::endl;	
  std::cout << "\t" << line << "\n" << std::endl;
}

template<class T, class U>
void analogWrite(T GPIO, U bits){
  std::cout << "\n" << line << std::endl;
  std::cout << "  [ANALOG INFO] A value of " << bits << " bits has been written \n           to Arduino\'s GPIO number " << GPIO << "!" << std::endl;	
  std::cout << line << "\n" << std::endl;	
}

template<class T>
void delayMicroseconds(T time){
    std::cout << "  [ARDUINO] Board has been told to wait for " << time << " microseconds." << std::endl;	
	Sleep(time);
}

template<class T, class L, class U>
U pulseIn(T GPIO, L state, U timeout){
	U width = 0; // keep initialization out of time critical area
	// convert the timeout from microseconds to a number of times through
	// the initial loop; it takes 16 clock cycles per iteration.
	U numloops = 0;
	U maxloops = microsecondsToClockCycles(timeout) / 16;
	
	do{
		++numloops;
		if (numloops++ == maxloops){
			return 0;
		}
		width++;
	} while(numloops++ != maxloops);
	std::cout << " [SENSOR] PulseIn function has returned a measurement value!" << std::endl;
  return width;
}

#endif // Arduino.h
