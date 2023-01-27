#include <iostream>
#include <numeric>
#include <vector>

unsigned int editDistance(const std::string& word1, const std::string& word2){
    const size_t len1 = word1.size();
    const size_t len2 = word2.size();
    std::vector<unsigned int> column(len2 + 1);
    std::vector<unsigned int> prevColumn(len2 + 1);

    std::iota(prevColumn.begin(), prevColumn.end(), 0);
    for(unsigned int i = 0; i< len1; i++){
        column[0] = i + 1;
        for(unsigned int j = 0; j < len2; j++){
            column[j+1] = std::min(1 + column[j],
                    std::min(1 + prevColumn[j],
                    prevColumn[j] 
                       + (word1[i] == word2[j] ? 0 : 1)));
            column.swap(prevColumn);
        }
    }
    return prevColumn[len2];
}

int main() {
    auto name{"paralelepipedo"};
    auto word{"fe"};

    auto dist = editDistance(name, word);
    std::cout << "\n\t distance = " << dist << std::endl;

   return 0;
}