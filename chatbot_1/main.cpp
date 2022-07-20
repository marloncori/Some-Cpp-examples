#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "string_functions.h"
#include "record.h"

#define DEBUG

std::vector<std::string> readLinesIntoVec(std::ifstream& file);
std::vector<Record> getRecords(std::string fileName);
std::string getResponse(std::string input, std::vector<Record> records);

int main(){
  std::string input(" ");
  	std::string response(" ");
	std::string fileName("records.txt")
	
	std::ifstream data(fileName);
	std::vector<Record> records;
	records = getRecords(fileName);

	std::cout << "\n>>>\033[1;32m The conversation is about to start!\033[0m\n" << std::endl;	
	while(1){
		std::cout << " [USER] > \033[1;35m";
		std::getline(std::cin, input);
		std::cout << "\033[0m" << std::endl;
		
		if(input == "q"){
			std::cout << "\n>>>\033[1;33m The conversation has ended.\033[0m" << std::endl;
			break;
		}
		response = getResponse(input, records);
		std::cout << "   [CHATBOT] > \033[1;34m" << response << "\033[0m" << std::endl;
	}
	
  return 0;
}

std::vector<std::string> readLinesIntoVec(std::ifstream& file){
	std::string line;
	std::vector<std::string> fileLines;
	
	while(std::getline(file, line)){
		fileLines.push_back(line);
	}
	return fileLines;
}

std::vector<Record> getRecords(std::string fileName){
	const std::string phraseTag = "<phrase>";
	const std::string responseTag = "<response>";
	std::string line;
	char delim = '>';
	
	std::vector<Record> records;
	std::vector<std::string> rawFile;
	std::vector<std::string> splitString;
	std::ifstream file("records.txt");
	
	rawFile = readLinesIntoVec(file);
	Record* currentRecord;
	for(int i {0}; i < rawFile.size(); i++){
		line = rawFile[i];
		if(line.find(phraseTag) != std::string::npos){
			Record tempRec;
			splitString = split(line, delim);
			#ifdef DEBUG
				std::cout << " -----------------------------------" << std::endl;
				std::cout << " if(line.find(phraseTag) != std::string::npos)" << std::endl;
				std::cout << " -----------------------------------" << std::endl;
				std::cout << " splitString: " << splitString << std::endl;
			#endif
			tempRec.phrase = splitString[1];
			#ifdef DEBUG
				std::cout << " tempRec.phrase: " << tempRec.phrase << std::endl;
			#endif
			trim(tempRec.phrase);
			#ifdef DEBUG
				std::cout << " trimmed tempRec.phrase: " << tempRec.phrase << std::endl;
			#endif
			records.push_back(tempRec);
			#ifdef DEBUG
				std::cout << " tempRec = " << tempRec << std::endl;
			#endif
			currentRecord = &records[records.size()-1];
			#ifdef DEBUG
				std::cout << " current Record = " << *currentRecord << std::endl;
			#endif
		}
		else if(line.find(responseTag) != std::string::npos){
			splitString = split(line, delim);
			#ifdef DEBUG
				std::cout << " -----------------------------------" << std::endl;
				std::cout << " if(line.find(phraseTag) != std::string::npos)" << std::endl;
				std::cout << " -----------------------------------" << std::endl;
				std::cout << " splitString: " << splitString << std::endl;
			#endif
			trim(splitString);
			#ifdef DEBUG
				std::cout << " trimmed splitString: " << splitString << std::endl;
				std::cout << " splitString[1] = " << splitString << std::endl;
			#endif
			currentRecord->responses.push_back(splitString[1]);
		}
	}
	return records;
}

std::string getResponse(std::string input, std::vector<Record> records){
	std::string response;
	std::vector<std::string> words = split(input, ' ');
	int total = LevensteinDistance(input, records[0].phrase);
	int index = 0;
	
	// go through each response and each word in the smallest levenstein distance
	for(int i {1}; i < records.size(); i++){
		int tempTotal = LevensteinDistance(input, records[i].phrase);
		if(tempTotal <= total){
			total = tempTotal;
			index = i;
		}
	}
	
	int randomIndex = rand() % records[index].responses.size();
	response = records[index].responses[randomIndex];
	
	return response;
}

