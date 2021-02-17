#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class State;

class Observer {
  public:
    virtual void notify(State&) = 0;
    std::string category;
};

#endif