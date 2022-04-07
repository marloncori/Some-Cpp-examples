#include <iostream>
#include <string>
#include <iomanip>
#include <system_error>
#include <windows.h>
#include <utility>

std::string line("============================================");

void heading(const std::string& ln){
   std::cout << "\n" << ln << std::endl;
   std::cout << "   R O B O T  C O N T R O L " << std::endl;
   std::cout << ln << std::endl;
}

std::pair<std::string, int> getInfo(){
  std::string cmd;
  int delay{0};
  heading(line);
    
    std::cout << std::setw(5) << " Enter a command \n" 
      << std::setw(6) << "for the robot to move:\n" <<
      std::setw(8) << " Forward" <<
      std::setw(8) << " Backward" <<
      std::setw(8) << " Right" <<
      std::setw(8) << " Left" <<
      std::setw(8) << " Stop" << std::endl;

    std::cout << "\n" << std::setw(10) << " cmd: ";
    std::getline(std::cin, cmd);

    std::cout << "Okay, you have chosen \n the following command: \'" << cmd << "\'" << std::endl;
    std::cout << std::setw(5) << " For how long should the robot move?\n" <<
    std::setw(6) << "[Enter a value in milliseconds] Time: ";
    
    std::cin >> delay; 
    std::cout << line << std::endl;
    flush(std::cout);

   return std::make_pair(cmd, delay);

}

void showInfo(std::pair<std::string, int> cmdAndDelay){
   int counter{0};
   int n {1}; 
   std::string msg("");

   if((cmdAndDelay.first.compare("") == 0) || (cmdAndDelay.second == 0)){
	throw std::system_error(errno, std::system_category(), 
               "[WARNING] Arguments CMD and DELAY should not be null!");
   }

      if(!cmdAndDelay.first.compare("forward")) msg = "The robot is moving forward!";
      if(!cmdAndDelay.first.compare("backward")) msg = "The robot is moving backward!";
      if(!cmdAndDelay.first.compare("right")) msg = "The robot is turning right!";
      if(!cmdAndDelay.first.compare("left")) msg = "The robot is turning left";
      if(!cmdAndDelay.first.compare("stop")) msg = "The robot has stopped.";

   do{
      counter++; 
      std::cout << std::setw(n) << line << "\n"
		<< std::setw(n) << msg << "\n"
		<< std::setw(n) << line 
     				<< std::endl;
      n += 2;
      Sleep(cmdAndDelay.second);
   } while(counter < 4);
   std::cout.flush();
}

int main(int argc, char* argv[]) {
  
   std::string name(argv[1]);
   std::string adios(argv[2]);

   std::cout << " >>> Program will start in 2 seconds, master " << name << "!" << std::endl;
   Sleep(2000);

   try{

      std::pair<std::string, int> cmd_delay = getInfo();
      showInfo(cmd_delay);
      Sleep(1000);

   }catch(const std::runtime_error& err){
      std::cerr << " Exception has been caught:\n "
                << err.what() << std::endl;
   }

   std::cout << "\n >>> Program has ended. " << adios << ", master " << name << "!" << std::endl;
   Sleep(500);

   return 0;
}