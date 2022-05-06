#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

void doPermutation(std::string&);

int main(){

    std::string word("aba");
    std::string word2("banana");
    std::string word3("amor");
    std::string word4("paralelepipedo");

    std::vector<std::string> words = {
        word, word2, word3, word3
    };

    for(auto wd : words) {
        doPermutation(wd);
    }

    return 0;
}

void doPermutation(std::string& word){
    std::sort(word.begin(), word.end());
    do {
        std::cout << word << std::endl;
    } while(std::next_permutation(word.begin(), word.end()));
}