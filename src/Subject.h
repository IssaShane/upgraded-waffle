#ifndef SUBJECT_H
#define SUBJECT_H

#include "State.h"
#include <vector>
#include <string>

class Observer;

class Subject {
  public:
    void addObserver(Observer*);
    void notifyObservers();
    void notifyObserversOfCategory(std::string);

    State getState() const;
    void setState(State);

  private:
    std::vector<Observer*> observers;
    State state;
};

#endif