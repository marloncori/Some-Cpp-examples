#include "record.h"

void Record::showRecord(){
	std::cout << "\033[1;33m Phrase:\033[0m\n\t\033[1;34m" << phrase << "\033[0m" << std::endl;
	std::cout << "\033[1;32m Responses:\033[0m\n\t\033[1;34m";
	
	for(int i {0}; i < responses.size(); i++){
		 std::cout << responses.at(i) << "\033[0m" << std::endl;
	}
}
