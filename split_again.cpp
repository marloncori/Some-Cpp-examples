#include <iostream>
#include <istream>
#include <vector>

std::vector<std::string> split(const std::string&, char);

int main(){

  std::string phrase("Another, test, program, for, splitting, string");
  char delim = ',';
  auto result = split(phrase, delim); 
  std::cout << " Result: " << std::endl;

 return 0;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}