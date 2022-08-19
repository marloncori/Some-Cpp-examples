#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>
#include <string>
#include <windows.h>
#include "robot.h"

class Rover : public Robot {
  protected:
     int* position;
     std::string facing;
     std::map<char, std::function<void()>> cmds;

  public:
     Rover(std::string facing, int x_coord, int y_coord){
         this->facing = facing;
         this->position = new int[2]{x_coord, y_coord};
         cmds.emplace('R', [this](){ this->right(); });
         cmds.emplace('L', [this](){ this->left(); });
	 cmds.emplace('F', [this](){ this->forward(); });
     	 cmds.emplace('B', [this](){ this->backward(); });        
     }

     ~Rover(){ delete this; }

     std::string getPosition(){
       return "\n\tX coordinate: " + std::to_string(position[0]) +
               + "\n\tY coordinate: " + std::to_string(position[1]);
      }

      std::string getFacing(){
         return facing;
      }

      void setFacing(std::string direction){
         facing = direction;
      }

      std::map<char, std::function<void()>> getCmds(){
         return cmds;
      }

      void motion(std::string direction){
        std::cout << "The robot is moving: \n\tdirection --> "
         << direction << std::endl;
      }
      
      void coordinates(std::string x_y){
        std::cout << "   New coordinates: " 
            << x_y << std::endl;
      }
        
       void right(){

               if(getFacing() == "N") {
                   setFacing("E");
		   motion(getFacing());
                   return;
               }

               if(getFacing() == "E") {
                   setFacing("S");
		   motion(getFacing());
                   return;
               }

               if(getFacing() == "S") {
                   setFacing("W");
		   motion(getFacing());
                   return;
               }
           setFacing(getFacing()); 
         }

         void left(){
               if(getFacing() == "N") {
                   setFacing("W");
		   motion(getFacing());
                   return;
               }

               if(getFacing() == "W") {
                   setFacing("S");
		   motion(getFacing());
                   return;
               }

               if(getFacing() == "S") {
                   setFacing("E");
		   motion(getFacing());
                   return;
               }
           setFacing(getFacing());
         }

         void forward(){
               if(getFacing() == "N") {
                  position[1] = position[1] + 1;
                  coordinates(getPosition());
               }

   	       if(getFacing() == "E") {
                  position[0] = position[0] + 1;
                  coordinates(getPosition());
               }
               
               if(getFacing() == "S") {
                  position[1] = position[1] - 1;
                  coordinates(getPosition());
               } 

   	       if(getFacing() == "W") {
                  position[0] = position[0] - 1;
                  coordinates(getPosition()); 
               }

         }

         void backward(){
              if(getFacing() == "N") {
                   position[1] = position[1] - 1;
                   coordinates(getPosition());
               }

   	       if(getFacing() == "E") {
                   position[0] = position[0] - 1;
                   coordinates(getPosition());
               }
               
               if(getFacing() == "S") {
                   position[1] = position[1] + 1;
                   coordinates(getPosition()); 
               } 

   	       if(getFacing() == "W") {
                   position[0] = position[0] + 1;
                   coordinates(getPosition());
               }         
         
         }

       void go(char instruction){
          std::map<char, std::function<void()>>::const_iterator itr;
          
          itr = getCmds().find(instruction);
          if(itr != getCmds().end()){
               itr->second();
               std::cout << "   [ROS] Battery level is still high." << std::endl;
          }
        }
};

int main(){
  int count {0};
  std::string dir("N");
  std::vector<char> cmds = {'R','L','F','F','R','B','R','L','F','B','R','F','L'};

  Rover* bot = new Rover(dir, 0, 0);
 
  std::cout << " The rover is facing "<< bot->getFacing() << std::endl;
  std::cout << bot->getPosition() << std::endl; 

  for(auto& cmd : cmds){ 
     bot->go(cmd);
     Sleep(1000);
     std::cout << " --------------------------\n " << std::endl;
  }

  bot->setFacing("E");
  std::cout << " ================================== \n\n " << std::endl;

  for(auto& cmd : cmds){ 
     bot->go(cmd);
     Sleep(1000);
     std::cout << " --------------------------\n " << std::endl;
  }

 return 0;
}