#include "Menu.h"
#include "State.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Menu::~Menu() {
  SDL_FreeSurface(SelectMap);
  SDL_FreeSurface(SelectPlayer);
  SDL_FreeSurface(Player1_Wins);
  SDL_FreeSurface(Player2_Wins);
  SelectMap = nullptr;
  SelectPlayer = nullptr;
  Player1_Wins = nullptr;
  Player2_Wins = nullptr;
}

Menu::Menu() {
  currentScreen = 0;
  SelectMap = IMG_Load("data/SelectMap.png");
  SelectPlayer = IMG_Load("data/SelectPlayer.png");
  Player1_Wins = IMG_Load("data/Splash_Screens/Player1_Win.png");
  Player2_Wins = IMG_Load("data/Splash_Screens/Player2_Win.png");
}

void Menu::notify(State &st) {
  if (st.type == StateType::draw) {
    if (currentScreen == 0) 
      SDL_BlitSurface(SelectPlayer,NULL,st.Screen,NULL);
    else if (currentScreen == 1)
      SDL_BlitSurface(SelectMap,NULL,st.Screen,NULL);
    else if (currentScreen == 3)
      SDL_BlitSurface(Player1_Wins,NULL,st.Screen,NULL);
    else if (currentScreen == 4)
      SDL_BlitSurface(Player2_Wins,NULL,st.Screen,NULL);
  }
  else if (st.type == StateType::key) {
    //cout << "Menu::Key" << endl;
    const Uint8 *keys = SDL_GetKeyboardState(nullptr);
    if (currentScreen == 0) {
      if (keys[SDL_SCANCODE_1]) {
        cout << "one player" << endl;
        State newst = this->getState();
        newst.type = StateType::setaitrue;
        newst.view = View::Game; // So that the player receives it
        newst.user = User::p2;
        this->setState(newst);
        this->notifyObservers();
        currentScreen = 1;
      }
      else if (keys[SDL_SCANCODE_2]) {
        cout << "two player" << endl;
        currentScreen = 1;
      }
    }
    // we add currentScreen = 2 so that further keyboard input is ignored after
    //   the menu is exited
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
    else if (currentScreen == 2) {
      if (keys[SDL_SCANCODE_ESCAPE]) {
        State newst;
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
    }
  }
  else if (st.type == StateType::death) {
    if (st.user == User::p1) currentScreen = 3;
    else if (st.user == User::p2) currentScreen = 4;
    State newst = this->getState();
    newst.type = StateType::toggleview;
    this->setState(newst);
    this->notifyObservers();
  }
}