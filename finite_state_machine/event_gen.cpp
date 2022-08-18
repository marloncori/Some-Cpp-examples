
#include "event_gen.h"

EventGen::~EventGen(){
  delete this;
}

EventGen* EventGen::getInstance(){
   static EventGen event;
   return &event;
}

void EventGen::cleanUp(){
   std::cout << " [ LOG ] ::: Event Generator has been turned off. :::" << std::endl;
}

int EventGen::run(int eventNum){
   if(m_counter == 0){
      m_counter = rand() % MAX_COUNT + 1;
      if(eventNum > 1){
         std::cout << " [ LOG ] ::: Event Generator has been triggered off. :::" << std::endl;
         return rand() % eventNum + 1;
      }
      return 1;
   }
   else {
      std::cout << " [ LOG ] ::: Waiting for an event. :::" << std::endl;
      m_counter--;
   }
  return 0; 
}
