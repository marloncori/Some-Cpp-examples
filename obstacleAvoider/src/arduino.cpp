
#include "arduino.h"

    void arduino::pinMode(unsigned int GPIO, unsigned int direction){
        std::cout << "\n " << line << "\n";
        std::cout << "  An electronic component has been connected to \n  Arduino\'s GPIO "
          << GPIO << " and it is configured as " << (direction == mode::OUTPUT ? "OUTPUT" : "INPUT") << ".\n";
        std::cout << "\n " << line << "\n";
    }

    void arduino::digitalWrite(unsigned int GPIO, unsigned int logic){
        std::cout << "\n\t" << line << "\n";
        std::cout << "\t  [DIGITAL_INFO] Arduino\'s GPIO " << GPIO << " is set to " << 
          (logic == state::LOW ? "LOW" : "HIGH") << ".\n";
        std::cout << "\n\t" << line << "\n";
    }

    void arduino::analogWrite(unsigned int GPIO, long bits){
        std::cout << "\n" << line << "\n";
        std::cout << "  [ANALOG_INFO] A value of " << bits << " has been sent to GPIO " << GPIO << ".\n";
        std::cout << "\n" << line << "\n";
    }

    void arduino::delayMicroseconds(long time){
        std::cout << " [ARDUINO] Atmega368 has been told to wait for: " << time << " microseconds!\n";
        sleep(time/1000);
    }
    
    unsigned long arduino::pulseIn(unsigned int GPIO, unsigned int state, unsigned long timeout){
        unsigned long pulseWidth = 0; /* keep initialization out of time
        critical area, convert the timeout from microseconds to a
        number of times through the initial loop; it takes 16 clock
        cycles per iteration */
        unsigned int cyclesPerIteration = 16;
        unsigned long numLoops = 0;
        unsigned long maxLoops = microsecondsToClockCycles(timeout) / cyclesPerIteration;

        do{
            ++numLoops;
            if(numLoops++ == maxLoops){
                return 0;
            }
            pulseWidth++;
        } while(numLoops++ != maxLoops);
        std::cout << "  [ARDUINO SENSOR] PulseIn function has returned a measurement value!\n";
      return pulseWidth;  
    }

    int arduino::mapRange(int minA, int maxA, int minB, int maxB, int inputA){
       int outputB = minB + (inputA - minA) * (maxB - minB) / (maxA - minA); 
      return outputB;
    }

