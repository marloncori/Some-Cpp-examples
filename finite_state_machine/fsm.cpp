
#include "fsm.h"

FSM::FSM(){
  std::cout << "\033[1;35m---> Finite State Machine initialized!\033[0m" << std::endl;
  m_pStartState = new StartState();
  m_pStateOne   = new StateOne();
  m_pStateTwo   = new StateTwo();
  m_pLastState  = new LastState();
  StateMachine<FSM>::init(this, m_pStartState);
  Sleep(1000);
}

FSM::~FSM(){
  delete this;
}

void FSM::isDone(){
   m_done = true;
}

bool FSM::isCompleted(){
  return m_done;
}

void FSM::update(){
  std::cout << "\t >>>>\033[1;35mFSM is being updated...\033[0m" << std::endl;
  Sleep(1000);
  StateMachine<FSM>::update();
}
