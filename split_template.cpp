#include <iostream>
#include <vector>

template<char delimiter>
class WordDelimitedBy : public std::string
{};

std::vector<std::string> splitWords(const std::string& text, char delim){
	std::istringstream iss(text);
	std::vector<std::string> results((std::istream_iterator<WordDelimitedByComma<delim>>(iss)),
                                 std::istream_iterator<WordDelimitedByComma<delim>>());
   return results;
}

int main(){
	std::string text("Let,me,split,this,into,words");
        char delimitter = ',';

	auto splitted = splitWords(text, delimitter);

        for(auto& word : splitted){
            std::cout << " Splitted word: " << word << std::endl;
        }
   return 0;
}