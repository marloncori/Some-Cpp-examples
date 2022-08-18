#ifndef CHATBOT_H
#define CHATBOT_H

#include <list>
#include <fstream>
#include <iotream>

#include "question.h"

class Chatbot {
	private:
		std::list<Question> questions;
	
	public:
		Chatbot();
		~Chatbot();
		void greet(std::string name);
		bool isQuestion(std::string input);
		bool check(std::string input);
		void reply(std::string input);
		void storeQuestion(std::string input);	
};

#endif // chatbot.h
