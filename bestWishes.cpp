#include <iostream>
#include <vector>

constexpr int YOUR_ENDURANCE_SIZE = 34;

auto mayGodBlessYouAll(const std::vector<std::string>& vec) -> bool {
     if(vec.size() == 0){
        return false;
     }   
     for(auto word : vec){
          std::cout << word << " ";
     }
  return true;
}

auto main() -> int {
    std::string insightfulWords[YOUR_ENDURANCE_SIZE] = {"\nNever", "stop", "believing", "even", "though", "times", "may", "be", "difficult.", "\nActually", "those", "hardships", "are", "needed", "for us", "to be polished", "like a brute", "stone.", "in the", "end", "you will", "shine", "like", "a", "beautiful", "diamond", "if", "you only", "keep", "focused", "and", "moving ahead!\n"};
    std::vector<std::string> bestWishes(YOUR_ENDURANCE_SIZE);
    
    for(int i=0; i<32; i++){
        bestWishes.push_back(insightfulWords[i]);
    }

   bool result = mayGodBlessYouAll(bestWishes);
   if(result){
      std::cout << "\nCongrats! You\'ve successfully passed all the exams!" << std::endl;
   }
   else {
      std::cout << " Have you fallen down? Stand up and try it again. That test is meant to be defeated by someone just like you!" << std::endl;
   }

  return 0;
}