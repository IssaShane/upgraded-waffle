#include "Subject.h"
#include "Observer.h"

void Subject::addObserver(Observer *ob) {
  observers.emplace_back(ob);
}

void Subject::notifyObservers() {
  for (Observer *ob : observers) ob->notify(state);
}

void Subject::notifyObserversOfCategory(std::string type) {
  for (Observer *ob : observers) 
    if (ob->category == type) ob->notify(state);
}

void Subject::setState(State st) {
  state = st;
}

State Subject::getState() const { return state; }