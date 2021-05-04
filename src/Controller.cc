#include "Controller.h"
#include <iostream>
#include <vector>

using namespace std;

Controller::Controller() {
  quit = false;
}

void Controller::update(View view) {
  //cout << "contr::update" << endl;
  SDL_PollEvent(&e);
  if (e.type == SDL_QUIT) quit = true;
  else if (e.type == SDL_KEYDOWN) {
    //cout << "contr::update keydown" << endl;
    State newst;
    newst.type = StateType::key;
    newst.keycode = e.key.keysym.sym;
    newst.view = view;
    this->setState(newst);
    this->notifyObservers();
  }
  else if (e.type == SDL_KEYUP) {
    State newst;
    newst.type = StateType::keyup;
    newst.view = view;
    this->setState(newst);
    this->notifyObservers();
    //cout << "keyup notified" << endl;
  }
  else {
    State newst;
    newst.type = StateType::noaction;
    newst.view = view;
    this->setState(newst);
    this->notifyObservers();
  }
  State newst;
  newst.type = StateType::passiveupdate;
  newst.view = view;
  this->setState(newst);
  this->notifyObservers();
}

bool Controller::IsQuit() const { return quit; }