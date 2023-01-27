#include<iostream>
#include<array>
#include<chrono>
#include<algorithm>
#include<random>

void random_element(std::array<std::string, 5> names){

    std::string line("\n\t:::::::::::::::::::::::::::::::::::::::::\n");
    

    std::random_device rd;
    std::mt19937 gen(rd());
    int lowerBound = 0;
    int upperBound = 5-1;

    std::uniform_int_distribution<> distr(lowerBound, upperBound);
    size_t index = (size_t)distr(gen); 

    std::cout << line << std::endl;
    std::cout << "\t >>>> Randomly selected name: " << names.at(index) << std::endl;
    std::cout << line << std::endl;
 
}

int main (){
   std::string name("Marlon"), name1("Geysa"), name2("Beniamin"), name3("Laura"), name4("Ana");
   std::array<std::string, 5> names = {name, name1, name2, name3};

   int counter = 0;
   while(counter < 5){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(names.begin(), names.end(), 
            std::default_random_engine(seed));
        random_element(names);
        counter++;
   }

  return 0;   
}

