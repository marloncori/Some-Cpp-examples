#include <iostream>
#include <forward_list>
#include <vector>

constexpr int MAX = 13;
//constexpr std::string myStrings[MAX];

int len(const std::string&);
//std::forward_list<std::string> split(const std::string&, const char);
std::vector<std::string> split(const std::string&, const char);


int main(){
    std::string title("\n Welcome : to : program : to : split : functions : \n using : a : custom : split : function");
    const char delim = ':'; 
    auto result = split(title, delim);

    std::cout << "\n Here you are the splitted string: " << std::endl;
    for(int i=0; i<MAX; i++){
          std::cout << "\n\t word : " << (i+1) << " --> " << result.back() << std::endl; 
          result.pop_back();

    }
    
    return 0;
}

int len(const std::string& word){
    int length = 0;
    for(int i=0; word[i] != '\0'; i++){
        length++;
    }
    return length;
}

std::vector<std::string>split(const std::string& word, const char separator){
//std::forward_list<std::string> split(const std::string& word, const char separator){
    std::vector<std::string> words;
    int currentId = 0, iter = 0;
    int startId = 0, endId = 0;
    while(iter <= len(word)){
        if(word[iter] == separator || iter ==  len(word)){
            endId = iter;
            std::string subStr = "";
            subStr.append(word, startId, (endId - startId));
            words.push_back(subStr);
            //myStrings[currentId] = subStr;  
            currentId += 1;  
            startId = endId + 1;  
        }
        iter++;
    }
  return words;
}

