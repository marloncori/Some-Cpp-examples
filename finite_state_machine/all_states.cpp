
#include <windows.h>
#include "fsm.h"
#include "state_machine.h"
#include "all_states.h"
#include "event_gen.h"

#define FIRST_EVENT  1
#define SECOND_EVENT 2

//-------------------------------------------------------
StartState::StartState(){
  std::cout << "\033[1;32m[MSG]\033[0m \033[1;33mStart State\033[0m \033[1;32mhas been created!\033[0m" << std::endl;
  Sleep(1000);
}

StartState::~StartState(){

}

void StartState::enter(FSM *fsm){
 std::cout << "\n\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   [MSG]\033[1;37mEntering\033[0m \033[1;33mStart State\033[0m..." << std::endl;
 std::cout << "\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}

void StartState::execute(FSM *fsm){
   //initial state
   if(EventGen::getInstance()->run(FIRST_EVENT)){
     std::cout << "\n\033[1;32m   =====================================================\033[0m" << std::endl;
     std::cout << "   [MSG]\033[1;35mExecuting\033[0m \033[1;33mStart State\033[0m..." << std::endl;
     std::cout << "\033[1;32m    =====================================================\033[0m" << std::endl;
     Sleep(1000);
     fsm->changeState(fsm->m_pStateOne);
     std::cout << "   ------>>>>> Jumping to \033[1;33m State One!\033[0m" << std::endl; 
     Sleep(1000);
   }
}

void StartState::exit(FSM *fsm){
 std::cout << "\n\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   \033[1;32m[WARNING]\033[0m\033[1;34m >>> Exit\033[0m \033[1;33mStart State\033[0m..." << std::endl;
 std::cout << "\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);

}
      
//-------------------------------------------------------
StateOne::StateOne(){
  std::cout << "\033[1;32m[MSG]\033[0m \033[1;33mState One\033[0m \033[1;32mhas been created!\033[0m" << std::endl;
  Sleep(1000);
}

StateOne::~StateOne(){
  
}

void StateOne::enter(FSM *fsm){
 std::cout << "\n\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   [MSG]\033[1;36mEntering\033[0m \033[1;33mState One\033[0m..." << std::endl;
 std::cout << "\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}

void StateOne::execute(FSM *fsm){
 if(EventGen::getInstance()->run(SECOND_EVENT)){
     std::cout << "\n\033[1;32m   =====================================================\033[0m" << std::endl;
     std::cout << "   [MSG]\033[1;37mExecuting\033[0m \033[1;33mState One\033[0m..." << std::endl;
     std::cout << "\033[1;32m    =====================================================\033[0m" << std::endl;
     Sleep(1000);
     fsm->changeState(fsm->m_pStateTwo);
     std::cout << "   ------>>>>> Jumping to \033[1;33m State Two!\033[0m" << std::endl; 
     Sleep(1000);
 }
 else if(EventGen::getInstance()->run(FIRST_EVENT)){
     std::cout << "\n\033[1;31m   =====================================================\033[0m" << std::endl;
     std::cout << "   [MSG]\033[1;37mExecuting\033[0m \033[1;33mState One\033[0m..." << std::endl;
     std::cout << "\033[1;31m    =====================================================\033[0m" << std::endl;
     Sleep(1000);
     fsm->changeState(fsm->m_pLastState);
     std::cout << "   ------>>>>> Jumping to \033[1;36m Last State!\033[0m" << std::endl; 
     Sleep(1000);
 }

}

void StateOne::exit(FSM *fsm){
 std::cout << "\n\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   \033[1;32m[WARNING]\033[0m\033[1;35m >>> Exit\033[0m \033[1;33mState One\033[0m..." << std::endl;
 std::cout << "\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}

//-------------------------------------------------------
StateTwo::StateTwo(){
 std::cout << "\033[1;32m[MSG]\033[0m \033[1;33mState Two\033[0m \033[1;32mhas been created!\033[0m" << std::endl;
 Sleep(1000);
}

StateTwo::~StateTwo(){
 
}

void StateTwo::enter(FSM *fsm){
 std::cout << "\n\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   [MSG]\033[1;35mEntering\033[0m \033[1;33mState Two\033[0m..." << std::endl;
 std::cout << "\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}

void StateTwo::execute(FSM *fsm){
 if(EventGen::getInstance()->run(FIRST_EVENT)){
     std::cout << "\n\033[1;32m   =====================================================\033[0m" << std::endl;
     std::cout << "   [MSG]\033[1;36mExecuting\033[0m \033[1;33mState One\033[0m..." << std::endl;
     std::cout << "\033[1;32m    =====================================================\033[0m" << std::endl;
     Sleep(1000);
     fsm->changeState(fsm->m_pStateOne);
     std::cout << "   ------>>>>> Jumping back to \033[1;33m State One!\033[0m" << std::endl; 
     Sleep(1000);
  }
}

void StateTwo::exit(FSM *fsm){
 std::cout << "\n\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   \033[1;32m[WARNING]\033[0m\033[1;36m >>> Exit\033[0m \033[1;33mState Two\033[0m..." << std::endl;
 std::cout << "\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}

//-------------------------------------------------------
LastState::LastState(){
 std::cout << "\033[1;32m[MSG]\033[0m \033[1;33mLAST State\033[0m \033[1;32mhas been created!\033[0m" << std::endl;
 Sleep(1000);
}

LastState::~LastState(){
  
}
void LastState::enter(FSM *fsm){
 std::cout << "\n\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   [MSG]\033[1;34mEntering\033[0m \033[1;33mLast State\033[0m..." << std::endl;
 std::cout << "\033[1;32m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}

void LastState::execute(FSM *fsm){
   fsm->isDone();
   std::cout << "\n\t [LOGOUT]\033[1;34mLast state has been reached\033[0m\n\t   \033[1;33mProgram has ended.\033[0m" << std::endl;
}

void LastState::exit(FSM *fsm){
 std::cout << "\n\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 std::cout << "   \033[1;32m[WARNING]\033[0m\033[1;37m >>> Exit\033[0m \033[1;33mLast State\033[0m..." << std::endl;
 std::cout << "\033[1;33m   --------------------------------------------------------\033[0m" << std::endl;
 Sleep(1000);
}
//--------------------------------------------------------
