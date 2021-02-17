#include "Menu.h"
#include "State.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Menu::~Menu() {
  SDL_FreeSurface(SelectMap);
  SDL_FreeSurface(SelectPlayer);
  SelectMap = nullptr;
  SelectPlayer = nullptr;
}

Menu::Menu() {
  currentScreen = 0;
  SelectMap = IMG_Load("data/SelectMap.png");
  SelectPlayer = IMG_Load("data/SelectPlayer.png");
}

void Menu::notify(State &st) {
  if (st.type == StateType::draw) {
    if (currentScreen == 0) 
      SDL_BlitSurface(SelectPlayer,NULL,st.Screen,NULL);
    else if (currentScreen == 1)
      SDL_BlitSurface(SelectMap,NULL,st.Screen,NULL);
  }
  else if (st.type == StateType::key) {
    //cout << "Menu::Key" << endl;
    const Uint8 *keys = SDL_GetKeyboardState(nullptr);
    if (currentScreen == 0) {
      if (keys[SDL_SCANCODE_1]) {
        cout << "one player" << endl;
        currentScreen = 1;
      }
    }
    else if (currentScreen == 1) {
      int activeMap = 0;
      if (keys[SDL_SCANCODE_1]) {
        cout << "map 1" << endl;
        activeMap = 1;
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      else if (keys[SDL_SCANCODE_2]) {
        cout << "map 2" << endl;
        activeMap = 2;
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      else if (keys[SDL_SCANCODE_3]) {
        cout << "map 3" << endl;
        activeMap = 3;
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      else if (keys[SDL_SCANCODE_4]) {
        cout << "map 4" << endl;
        activeMap = 4;
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      State newst = this->getState();
      newst.type = StateType::setlevel;
      newst.stat = activeMap;
      this->setState(newst);
      this->notifyObservers();
    }
  }
}