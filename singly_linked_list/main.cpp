#include <iostream>
#include <array>
#include <vector>

#include "SLList.h"

int main(){
  SLList* linkedList = new SLList();
  
  std::array<int, 7> values = {12, 34, 56, 78, 91, 7, 40};
  std::vector<int> nums = {13, 25, 37, 53, 60, 79, 85, 100};
  
  if(linkedList->isEmpty()){
  	for(auto& val : values){
  	   linkedList->pushToHead(val);
	}
  }    
  
  if(!linkedList->isEmpty()){
  	for(auto& num : nums){
  	   linkedList->pushToTail(num);
	}
  }
  
  int number = 100;
  if(linkedList->isPresent(number)){
      linkedList->deleteNode(number); 
  }
 
  int n = linkedList->delFromHead();
  std::cout << " The value " << n << " is not needed anymore.\n";
  
  n = linkedList->delFromTail();
  std::cout << " And the value " << n << " is not needed anymore either.\n";
  
 return 0;
}

