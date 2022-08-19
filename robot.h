#ifndef ROBOT_H
#define ROBOT_H

class Robot {
  public:
     virtual void forward() = 0;
     virtual void backward() = 0;
     virtual void right() = 0;
     virtual void left() = 0;
     virtual void coordinates(std::string x_y) = 0;
     virtual void go(char instruction) = 0;
};

#endif