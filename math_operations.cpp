#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <cmath>
#include <utility>
#include <windows.h>

class Operation {
  private:
     int x;
     int y;

  public:
     Operation(int x, int y);
     ~Operation();
     void reset(int new_x, int new_y);
     void add();
     void subt();
     void div();
     void mult();
     void pow();
};

Operation::Operation(int x, int y): x(x), y(y){
   std::cout << "  Program is starting......\n" << std::endl;
   Sleep(2000);
}

Operation::~Operation(){ 
   delete this;
}

void Operation::reset(int new_x, int new_y){
   x = new_x;
   y = new_y;
}

void Operation::add(){
  std::cout << "\t" << x << " + " 
       << y << " = " << (x+y) << std::endl;
}

void Operation::subt(){
  std::cout << "\t" << x << " - " 
       << y << " = " << (x-y) << std::endl;
}

void Operation::div(){
  std::cout << "\t" << x << " / " 
       << y << " = " << (x/y) << std::endl;
}

void Operation::mult(){
  std::cout << "\t" << x << " * " 
       << y << " = " << (x*y) << std::endl;
}

void Operation::pow(){
  std::cout << "\t" << x << " ^ " 
       << y << " = " << std::pow(x,y) << std::endl;
}

void calculate(const std::vector<char>& operators, const Operation* op, const std::map<char, std::function<void()>>& cmds);

int main(){
  
  int x = 21, y = 3;
  Operation* op = new Operation(x, y);

  std::vector<char> operators;
      operators.push_back('+');
        operators.push_back('-');
          operators.push_back('*');
           operators.push_back('/');
             operators.push_back('^'); 

  std::map<char, std::function<void()>> cmds;
       cmds.emplace('+', [&op](){op->add();});
         cmds.emplace('-', [&op](){op->subt();});       
           cmds.emplace('*', [&op](){op->mult();});
             cmds.emplace('/', [&op](){op->div();});
                cmds.emplace('^', [&op](){op->pow();});
             

  calculate(operators, op, cmds);
      
  std::vector<std::pair<int, int>> vals;
  vals.emplace_back(std::make_pair(48, 2));
  vals.emplace_back(std::make_pair(35, 5));

  for(auto& val : vals){
    op->reset(val.first, val.second);
     calculate(operators, op, cmds); 
  }

 return 0;
}

void calculate(const std::vector<char>& operators, const Operation* op, const std::map<char, std::function<void()>>& cmds)
{
 for(auto it = operators.begin(); it != operators.end(); it++){
     auto itr = cmds.find(*it);
     std::cout << "\n Requested mathematics operation: \n\t";
     if(itr != cmds.end()){
         itr->second();
         std::cout << " ..............................." << std::endl;
         Sleep(1000);
     }
  }
}