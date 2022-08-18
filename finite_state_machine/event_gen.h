
#ifndef _EVENT_GEN_H_
#define _EVENT_GEN_H_

#define MAX_COUNT 5
#include <iostream>

//single_ton class
class EventGen {
  private:
    int m_counter;
    EventGen(){
      m_counter = rand() % MAX_COUNT + 1;
    }
  public:
    ~EventGen();
    static EventGen* getInstance();
    void cleanUp();
    int run(int eventNum);
};

#endif