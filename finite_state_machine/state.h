#ifndef STATE_H
#define STATE_H

//abstract class
template<class T>
class State {
   public:
      ~State(){};
      virtual void enter(T *ptr);
      virtual void execute(T *ptr);
      virtual void exit(T *ptr);
};

#endif