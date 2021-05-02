#include "Subject.h"
#include "Observer.h"

void Subject::addObserver(Observer *ob) {
  observers.emplace_back(ob);
}

void Subject::notifyObservers() {
  for (int i = 0; i < observers.size(); i++) observers[i]->notify(state);
}

void Subject::notifyObserversOfCategory(std::string type) {
  for (int i = 0; i < observers.size(); i++) 
    if (observers[i]->category == type) observers[i]->notify(state);
}

void Subject::setState(State st) {
  state = st;
}

State Subject::getState() const { return state; }