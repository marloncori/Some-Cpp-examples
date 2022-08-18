#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <windows.h>

#include "all_states.h"
#include "state_machine.h"
#include "state.h"

class FSM : public StateMachine<FSM> {
  private:
    State<FSM> *m_pStartState;
    State<FSM> *m_pStateOne;
    State<FSM> *m_pStateTwo;
    State<FSM> *m_pLastState;
    bool m_done;

  public:
     FSM();
     ~FSM();
     void isDone();
     bool isCompleted();
     void update();
     friend class StartState;
     friend class StateOne;
     friend class StateTwo;
     friend class LastState;
};

#endif