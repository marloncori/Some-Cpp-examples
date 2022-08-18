#include <iostream>
#include <unistd.h>

#include "question.h"
#include "chatbot.h"

class Dialogue {
	private:
		Chatbot* bot;
	public:
		Dialogue();
		void init(const std::string& name);
		void run(std::string& input);
		void stop();
};

Dialogue::Dialogue(){
	std::cout << "\n >>> \033[1;36m Chatbot has entered the room. \033[0m]" << std::endl;	
	sleep(2);
}

void Dialogue::init(const std::string& name){
	bot->greet(name);
}	

void Dialogue::run(std::string& input){
	std::cout 	<< "[USER] \033[1;32m";
	std::getline(std::cin, input);
	std::cout << "\033[0m" << std::endl;
	
	for(int i {0}; i != input.length(); i++){
		input.at(i) = std::tolower(input.at(i));
	}
	if(bot->isQuestion(input)){
		if(bot->check(input)){
			bot->reply(input);
		}
		else {
			bot->storeQuestion(input);
		}
	}
	else {
		sleep(1);
			std::cout 	<< "  [CHATBOT] \033[1;33m You didn\'t asked your question in the right way. \n   Make sure to end it with a \033[1;31m\'?\'\033[0m \033[1;33m.\033[0m" << std::endl; 
	}
}

void Dialogue::stop(){
	delete bot;
	sleep(1);
	std::cout << "\n >>> \033[1;37m Chatbot has left the room. Program has ended, goodbye!\033[0m]" << std::endl;	
}
	
int main(){

	Dialoge chat;
	std::string master("Marlon");
	std::string userInput;
	chat.init(master);
	
	while(1){
		chat.run(userInput);
		sleep(1);
	}
	
	chat.stop();
	
  return 0;
}
