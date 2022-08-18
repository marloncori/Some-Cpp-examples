#ifndef QUESTION_H
#define QUESTION_H

class Question {
	private:
		std::string query;
		std::string answer;
	
	public:
		Question();
		Question(std::string query, std::string answer);
		~Question();
		std::string getQuery();
		std::string getAnswer();
		
};

#endif // question.h
