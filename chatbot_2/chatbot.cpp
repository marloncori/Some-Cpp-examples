
#include "chatbot.h"

Chatbot::Chatbot(){
	std::ifstream inputFile;
	inputFile.open("../data/knowledge.txt");
	std::string tempQuery;
	std::string tempAnswer;
	char delim = ';';
	
	while(!inputFile.eof()){
		std::getline(inputFile, tempQuery, delim);
		std::getline(inputFile, tempAnswer);
		Question information(tempQuery, tempAnswer);
		questions.push_back(information);
	}
}

Chatbot::~Chatbot(){
	delete this;
}

void Chatbot::greet(std::string name){
	std::cout 	<< "  [CHATBOT] \033[1;33m Hello, master " << name << "! Ask me a question :)\033[0m" << std::endl;	
}

bool Chatbot::isQuestion(std::string input){
	char delim = '?';
	if(input.empty()){
		return false;
	}
	
	if(input.back() == delim){
		return true;			
	}
	else {
		return false;
	}
}

bool Chatbot::check(std::string input){
	std::list<Question>::iterator it;
	it = questions.begin();
	for(it; it != questions.end(); it++){
		if(input == it->getQuery()){
			return true;
		}
	}
	return false;
}

void Chatbot::reply(std::string input){
	std::list<Question>::iterator it;
	it = questions.begin();
	for(it; it != questions.end(); it++){
		if(input == it->getQuery()){
			std::cout << "  [CHATBOT] \033[1;33m" << it->getAnswer() << "\033[0m" << std::endl;
		}
	}
}

void Chatbot::storeQuestion(std::string input){
	std::string tmp;
	std::cout 	<< "  [CHATBOT] \033[1;33m Hmmm... That\'s a good question. Maybe you could help me out?\033[0m" << std::endl;
	std::cout << << "  -----> \033[1;34m" << input << "\033[0m" << std::endl;
	std::cout 	<< "  [CHATBOT] \033[1;33m Please tell me below what can be a proper answer to it:\033[0m" << std::endl;
	  std::cout << << "   (ANSWER) \033[1;35m"; 
	  std::getline(std::cin, tmp;);
	  std::cout << "\033[0m" << std::endl;

	Question new_data(input, tmp);
	questions.push_back(new_data); //store a new question-answer pair

	std::ofstream outputFile;
	outputFile.open("../data/knowledge.txt");

		if(outputFile.is_open()){
			outputFile << std::endl << input << ";" << tmp;
			std::cout 	<< "  [CHATBOT] \033[1;33m Okay. I\'ve successfully stored the new information in my knowledge database.\033[0m" << std::endl;
		}
		else {
			std::cerr << " [CHATBOT]\033[1;31mWARNING: Database is not opened. I cannot store the new question-answer pair!\033[0m" << std::endl;
		}
		outputFile.close();
}
