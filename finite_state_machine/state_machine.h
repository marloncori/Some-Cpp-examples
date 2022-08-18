#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include <iostream>
#include <windows.h>
#include "state.h"

template<class T>
class StateMachine {
   private:
      T *m_pOwner;
      State<T> *m_pCurrentState;
      bool m_firstRun;
   public:
      //StateMachine();
      ~StateMachine(){delete this;};
      void init(T* pOwner, State<T> *initialState);  
      void update();
      void changeState(State<T> *newState);
};

/*StateMachine::StateMachine(){
   std::cout << "\n \033[1;32mA NEW STATE MACHINE HAS BEEN CREATED.\033[0m" << std::endl;   
   Sleep(1000);
}*/

template<class T>
inline void StateMachine<T>::init(T *p_Owner, State<T> *initialState ){
   m_pCurrentState = initialState;
   m_pOwner = p_Owner;
   m_firstRun = true;
   std::cout << "\n \033[1;32m[INFO]\033[0m \033[1;33mState Machine is ready.\033[0m" << std::endl; 
   Sleep(1000);
}

template<class T>
inline void StateMachine<T>::update(){
   if(m_firstRun){ 
      m_firstRun = !m_firstRun;
      m_pCurrentState->enter(m_pOwner);
      std::cout << "\t\033[1;32m[INFO]\033[0m \033[1;34mSTATE MACHINE is updating state for the\033[0m \033[1;33mfirst time\033[0m\033[1;34m!\033[0m" << std::endl;   
      Sleep(1000);
   }
   m_pCurrentState->execute(m_pOwner);
   std::cout << "\n  \033[1;32m[LOG]\033[0m \033[1;34mA new state is being executed\033[1;33mright now\033[0m\033[1;34m.\033[0m" << std::endl;   
   Sleep(1000);
}

template<class T>
inline void StateMachine<T>::changeState(State<T> *newState){
   m_pCurrentState->exit(m_pOwner);
   std::cout << "\n  \033[1;32m[LOG]\033[0m \033[1;31mState Machine has left behing the \033[1;33mprevious state\033[0m\033[1;31m.\033[0m" << std::endl;   
   Sleep(1000);
   m_pCurrentState = newState;
   m_pCurrentState->enter(m_pOwner);   
}

#endif