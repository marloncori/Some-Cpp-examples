#include <iostream>
#include <vector>

void startDecryption(int step, std::vector<std::string>& names){
    std::vector<std::string> words;
    std::string word("");
    int lt = 0;
    
    for(auto wd : names) {
      for(auto w : wd) {
         lt = (int)w << step;
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

void decrypt(std::vector<std::string> names, int option){
 switch(option){
    case 1:
        startDecryption(option, names);
        break;
    case 2:
        startDecryption(option, names);
        break;
    case 3:
        startDecryption(option, names);
        break;
    case 4:
        startDecryption(option, names);
        break;
    case 5:
        startDecryption(option, names);
        break;
    default:
        std::cout << " Invalid option!" << std::endl;
        break;
  }
}

int main(){
    std::vector<std::string> symbols = {
        "¶↓∟←¶↑∟↑↑←↕↑∟→↓←←◄∟←↑←↓►",
        "¶↓∟←¶↑∟↑↑←↕↑∟→↓←←◄∟←↑←↓►¶↔↑▲",
        "¶↓∟←¶↑∟↑↑←↕↑∟→↓←←◄∟←↑←↓►¶↔↑▲►↑∟→",
        "¶↓∟←¶↑∟↑↑←↕↑∟→↓←←◄∟←↑←↓►¶↔↑▲►↑∟→¶▲↔→←←"
    };
    decrypt(symbols, 2);
    
    std::vector<std::string> symbols2 = {
        "(296",
            "(296(09106",
                "(296(09106$095266",
                    "(296(09106$095266\"96073",
                        "(296(09106$095266\"96073!§§"
    };
    decrypt(symbols2, 1);

   return 0;
}