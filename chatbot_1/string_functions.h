#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

std::vector<std::string> split(std::string text, char delim);
size_t LevensteinDistance(const std::string& first, const std::string& second);

void trimLeading(const std::string& word);
void trimTrailing(const std::string& word);
void trim(std::string& word);

#endif // string_fuctions.h
 
