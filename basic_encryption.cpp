#include <iostream>
#include <vector>
#include <array>

void startEncryption(int step, std::vector<std::string>& names){
    std::vector<std::string&> words;
    std::string word("");
    int lt = 0;
    
    for(auto wd : names) {
      for(auto w : wd) {
         lt = (int)w >> step;
         word += (char)lt;
         lt = 0;
       }
      words.push_back(word);
      word = "";
    }

    for(size_t id {0}; id<names.size(); ++id){
      std::cout << " >>>> Vector name: " << names[id] << std::endl;
      std::cout << " >>>> Encrypted word: " << words[id] << std::endl;
    }
}

void encrypt(std::vector<std::string> names, int option){
 switch(option){
    case 1:
        startEncryption(option, names);
        break;
    case 2:
        startEncryption(option, names);
        break;
    case 3:
        startEncryption(option, names);
        break;
    case 4:
        startEncryption(option, names);
        break;
    case 5:
        startEncryption(option, names);
        break;
    default:
        std::cout << " Invalid option!" << std::endl;
        break;
  }
}

int main(){
    std::vector<std::string> words = {"Perl", "Pascal", 
       "Haskell", "Erlang", "C++", "Ruby", "Bash", "Python"};

    std::array<int, 6> nums = {0, 1, 2, 3, 4, 5};

    for(auto num : nums){
       encrypt(words, num);
    }
    
   return 0;
}