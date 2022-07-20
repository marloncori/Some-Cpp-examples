#include "string_functions.h"

std::vector<std::string> split(std::string text, char delim){
   std::stringstream input(text);
   std::string item;
   std::vector<std::string> output;
   
   while(std::getline(input, item, delim)){
   		output.push_back(item);
   }
   return output;
}

size_t LevensteinDistance(const std::string& first, const std::string& second){
	const size_t firstSize(first.size());
	const size_t secondSize(second.size());
	
	if(firstSize == 0){
		return secondSize;
	}
	if(secondSize == 0){
		return firstSize;
	}
	
	size_t* costs = new size_t[secondSize + 1];
	for(size_t k {0}; k<=secondSize; k++){
		costs[k] {k};
	}
	size_t i {0};
	for(std::string::const_iterator firstIter {first.begin()}; firstIter != first.end(); ++firstIter, ++i){
		costs[0] {i + 1};
		size_t corner {i};
		    
		size_t j {0};
		for(std::string::const_iterator secondIter {second.begin()}; secondIter != second.end(); ++secondIter, ++j){
			size_t upper {costs[j+1]};
			if(*firsIter == *secondIter){
				costs[j+1] = corner;
			}
			else {
				size_t t(upper<corner?upper:corner);
				costs[j+1] = (costs[j]<t?costs[j]:t)+1;
			}
			corner = upper;
	    }
	}
	size_t result = costs[secondSize];
	delete [] costs;
	
	return result;
}

void trimLeading(const std::string& word){
	if(word.empty()){
		return;
	}
	while(word.find(" ") == 0){
		word.erase(0, 1);
	}
}

void trimTrailing(const std::string& word){
	if(word.empty()){
		return;
	}
	size_t len = word.size();
	while(word.find(" ") == --len){
		word.erase(len, (len + 1));
	}
}

void trim(std::string& word){
	trimLeading(word);
	trimTrailing(word);
}

