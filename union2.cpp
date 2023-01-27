#include<iostream>

using namespace std;

union abc {
    int x;
	char ch;
} var;

void show(abc var){
  cout<< var.x << endl;
}

int main() {	
	
    var.ch = 'A';
    show(var);

   return 0;
}