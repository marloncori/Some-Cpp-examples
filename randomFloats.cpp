#include <iostream> 
#include <random>
#include <ctime>   
#include <vector>  
#include <condition_variable>  
#include <mutex>  
#include <thread>  
#include <windows.h>  

constexpr int FLOAT_MIN = 10; 
constexpr int FLOAT_MAX = 50;  

std::string line("\033[1;33m------------------------------------\033[0m"); 
std::vector<float> dists{};
std::condition_variable cond_var;
bool data_available;
std::mutex mtx;

float calcDistance(){
    //std::random_device rd;     
    std::default_random_engine eng{static_cast<long unsigned int>(time(0))};     
    std::uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);
  return distr(eng);     
}        

void getSensorReading(){
 while(1){
  std::lock_guard<std::mutex> lk(mtx);
   dists.push_back(calcDistance());
   data_available = true;
  cond_var.notify_all();
 }
}

void showRobotData(){
  std::unique_lock<std::mutex> guard(mtx);
    std::cout << "\n Waiting for incoming data..." << std::endl;
  cond_var.wait(guard, 
      [](){return !dists.empty();});
 
    float dist = dists.front();
    std::cout << "\n"<< line << std::endl;
    std::cout << "\033[1;32m  The distance is: " << dist
     << "cm. \033[0m" << std::endl;
    std::cout << line << std::endl;
     dists.pop_back();
     data_available = false;
     Sleep(1000);
    //cond_var.notify_all();
}

int main() {  
   
  std::vector<std::thread> threads;
     threads.push_back(std::thread(getSensorReading));
      threads.push_back(std::thread(showRobotData));

  for(auto& thread : threads){
     if(thread.joinable())
         thread.join();
  }

  std::cout << line << std::endl;
  std::cout << "\n:::  END OF PROGRAM ::: \n";
   
 return EXIT_SUCCESS; 
} 