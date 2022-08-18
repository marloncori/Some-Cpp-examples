#include <iostream>
#include <system_error>
#include <errno.h>

struct Date {
	int day;
	int month;
	int year;
	char delim;
	Date() = default;
	~Date() { delete this; }
};

Date* getUserInput(int& d, int& m, int& y, char delim);
std::string formatDate(Date*& date);
void showResult(const std::string& res);

int main(){

  Date* date = new Date();
  std::string formatted;
  
  int day = 0, month = 0, year = 0;
  char delim = ' ';
  
  date = getUserInput(day, month, year, delim);
  formatted = formatDate(date);
  
  if(!formatted.empty()){
  	showResult(formatted);
  } 
  else {
    throw std::system_error(errno,
	    std::system_category(), " String date is empty. It could not be formatted...");	
  }
  
  return 0;
}

Date* getUserInput(int& d, int& m, int& y, char delim){
  Date* myDate = new Date();
  
  try {
    std::cout << "\n Please enter the information below: \n\t ";
    std::cout << " day = ";
    std::cin >> d;
    if(std::cin.fail()){
       std::cin.ignore();
       fflush(stdin);
  	   std::cout << " Something went wrong... Please try again!\n";
  	   std::cout << "\n Please enter the information below: \n\t ";
       std::cout << " day = ";
       std::cin >> d;
    }
    std::cout << "\n\t month = ";
    std::cin >> m;
    if(std::cin.fail()){
       std::cin.ignore();
       fflush(stdin);
  	   std::cout << " Something went wrong... Please try again!\n";
  	   std::cout << "\n Please enter the information below: \n\t ";
       std::cout << " month = ";
       std::cin >> m;
    }
    std::cout << "\n\t year = ";
    std::cin >> y;
    if(std::cin.fail()){
        std::cin.ignore();
       fflush(stdin);
  	   std::cout << " Something went wrong... Please try again!\n";
  	   std::cout << "\n Please enter the information below: \n\t ";
       std::cout << " year = ";
       std::cin >> y;
    }	
    std::cout << "\n\t delimitter: ";
    std::cin >> delim;
    if(std::cin.fail()){
       std::cin.ignore();
       fflush(stdin);
  	   std::cout << " Something went wrong... Please try again!\n";
  	   std::cout << "\n Please enter the information below: \n\t ";
       std::cout << " delimitter: ";
       std::cin >> delim;
    }
 } catch(const std::runtime_error& exc){
 	std::cerr << " Could not get input data... Error code: -1" 
	  << "\n\t Error msg: " << exc.what() << std::endl;	
 }
 
  try {
  	 myDate->day   = d;
  	 myDate->month = m;
  	 myDate->year  = y;
  	 myDate->delim = delim;
  }catch(const std::runtime_error& err){
  	std::cerr << " Could not assigned values... Error code: -1" 
	  << "\n\t Error msg: " << err.what() << std::endl;	
  }
  
  return myDate;
}

std::string formatDate(Date*& date){
  std::string dateStr;
  if(date->day == 0 || date->month == 0 || date->year == 0){
  	  throw std::system_error(errno,
	    std::system_category(), " DATE object is empty. It could not be formatted...");	
  }
  
  try {  
     dateStr = std::to_string(date->day) + date->delim + std::to_string(date->month)
			   + date->delim + std::to_string(date->year) + "\n";
     return dateStr;
  }catch(const std::runtime_error& err){
  	std::cerr << " Could not assigned values... Error code: -1" 
	  << "\n\t Error msg: " << err.what() << std::endl;
	return dateStr;	
  }	
}

void showResult(const std::string& res){
	std::cout << "\n  This is the formatted date: \n\t [DATE] " << res << std::endl;
}

