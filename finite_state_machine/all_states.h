#ifndef _ALL_STATES_H_
#define _ALL_STATES_H_

#include "state.h"

class StartState : public State<class FSM> {
   public:
      StartState();
      ~StartState();
      void enter(FSM *fsm);
      void execute(FSM *fsm);
      void exit(FSM *fsm);
};

class StateOne : public State<class FSM> {
   public:
      StateOne();
      ~StateOne();
      void enter(FSM *fsm);
      void execute(FSM *fsm);
      void exit(FSM *fsm);
};

class StateTwo : public State<class FSM> {
   public:
       StateTwo();
      ~StateTwo();
      void enter(FSM *fsm);
      void execute(FSM *fsm);
      void exit(FSM *fsm);
};

class LastState : public State<class FSM> {
   public:
      LastState();
      ~LastState();
      void enter(FSM *fsm);
      void execute(FSM *fsm);
      void exit(FSM *fsm);
};

#endif