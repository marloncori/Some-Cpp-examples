#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <iostream>

void doPermutation(std::string);

int main(){

    std::string word("aba");
    std::string word2("banana");
    std::string word3("amor");
    std::string word4("para");

    std::vector<std::string> words = {
        word, word2, word3, word4
    };

    for(auto wd : words) {
        doPermutation(wd);
    }

    return 0;
}

void doPermutation(std::string word){
    int counter {0};
    std::vector<std::string> perm;

    std::sort(word.begin(), word.end(), std::greater<char>());
    do {
        std::cout << word << std::endl;
        perm.push_back(word);
        counter++; 
    } while(std::prev_permutation(word.begin(), word.end()));   
        
    std::random_device rd;
    std::mt19937 generate(rd());
    int lowerBound = 0;
    int upperBound = perm.size()-1;

    std::uniform_int_distribution<> distr(lowerBound, upperBound);
    size_t index = (size_t)distr(generate); 

    std::vector<std::string> words;
    std::string c = "";
    for(auto wd : perm) {
       for(auto w : wd) {
           c += (char) w >> 2;
       }
       words.push_back(c);
    }

    std::cout << " >>>> Randomly selected permutation: " << perm[index] << std::endl;
        std::cout << " >>>> Randomly selected encrypted word: " << words[index] << std::endl;
    std::cout << " --> Total permutations: " << counter << "\n" << std::endl;
 
}