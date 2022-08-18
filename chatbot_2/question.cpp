#include "question.h"

Question::Question(){
	query = "";
	answer = "";	
}

Question::Question(std::string query, std::string answer){
	this->query = query;
	this->answer = answer;
}

Question::~Question(){
	delete this;
}

std::string Question::getQuery(){
	return query;
}

std::string Question::getAnswer(){
	return answer;
}
