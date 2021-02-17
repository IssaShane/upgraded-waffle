#include "Controller.h"
#include <iostream>
#include <vector>

using namespace std;

Controller::Controller() {
  quit = false;
}

void Controller::update() {
  //cout << "contr::update" << endl;
  SDL_PollEvent(&e);
  if (e.type == SDL_QUIT) quit = true;
  else if (e.type == SDL_KEYDOWN) {
    //cout << "contr::update keydown" << endl;
    
    this->setState(State{StateType::key});
    this->notifyObservers();
  }
  else {
    this->setState(State{StateType::noaction});
    this->notifyObservers();
  }
  this->setState(State{StateType::passiveupdate});
  this->notifyObservers();
}

bool Controller::IsQuit() const { return quit; }