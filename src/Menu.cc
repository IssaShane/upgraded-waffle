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
  SDL_FreeSurface(ControlScreen);
  delete cursor;
  SelectMap = NULL;
  SelectPlayer = NULL;
  Player1_Wins = NULL;
  Player2_Wins = NULL;
  cursor = NULL;
  ControlScreen = NULL;
}

Menu::Menu() {
  currentScreen = -1;
  SelectMap = IMG_Load("data/SelectMap.png");
  SelectPlayer = IMG_Load("data/SelectPlayer.png");
  Player1_Wins = IMG_Load("data/Splash_Screens/Player1_Win.png");
  Player2_Wins = IMG_Load("data/Splash_Screens/Player2_Win.png");
  ControlScreen = IMG_Load("data/Splash_Screens/controls.png");
  cursor = new GameObject{"data/cursor.png", SDL_Rect{64,64,23,26}};
  keydepressed = false;
}


void Menu::notify(State &st) {
  if (st.type == StateType::draw) {
    if (currentScreen == -1) {
      SDL_BlitSurface(ControlScreen,NULL,st.Screen,NULL);
    }
    else if (currentScreen == 0) {
      SDL_BlitSurface(SelectPlayer,NULL,st.Screen,NULL);
      cursor->draw(st.Screen);
    }
    else if (currentScreen == 1) {
      SDL_BlitSurface(SelectMap,NULL,st.Screen,NULL);
      cursor->draw(st.Screen);
    }
    else if (currentScreen == 3)
      SDL_BlitSurface(Player1_Wins,NULL,st.Screen,NULL);
    else if (currentScreen == 4)
      SDL_BlitSurface(Player2_Wins,NULL,st.Screen,NULL);
  }
  else if (st.type == StateType::key) {
    //cout << "Menu::Key" << endl;
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    if (keydepressed == false) { 
      if (st.keycode == SDLK_DOWN) {
        cursor->moveVertical(64);
        keydepressed = true;
      }
      else if (st.keycode == SDLK_UP) {
        cursor->moveVertical(-64);
        keydepressed = true;
      }
    }
    if (currentScreen == -1) {
      if (keys[SDL_SCANCODE_RETURN] && keydepressed == false) {
        currentScreen = 0;
        keydepressed = true;
      } 
    }
    else if (currentScreen == 0) {
      if (keys[SDL_SCANCODE_1] || 
        (cursor->getPos().y == 64 && keys[SDL_SCANCODE_RETURN] && keydepressed == false)) {
        keydepressed = true;
        cout << "one player" << endl;
        State newst = this->getState();
        newst.type = StateType::setaitrue;
        newst.view = View::Game; // So that the player receives it
        newst.user = User::p2;
        this->setState(newst);
        this->notifyObservers();
        currentScreen = 1;
      }
      else if (keys[SDL_SCANCODE_2] || 
        (cursor->getPos().y == 128 && keys[SDL_SCANCODE_RETURN] && keydepressed == false)) {
        keydepressed = true;
        cout << "two player" << endl;
        currentScreen = 1;
      }
    }
    // we add currentScreen = 2 so that further keyboard input is ignored after
    //   the menu is exited
    else if (currentScreen == 1) {
      int activeMap = 0;
      if (keys[SDL_SCANCODE_1] ||
        (cursor->getPos().y == 64 && keys[SDL_SCANCODE_RETURN] && keydepressed == false)) {
        keydepressed = true;
        cout << "map 1" << endl;
        activeMap = 1;
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      else if (keys[SDL_SCANCODE_2] ||
        (cursor->getPos().y == 128 && keys[SDL_SCANCODE_RETURN] && keydepressed == false)) {
        keydepressed = true;
        cout << "map 2" << endl;
        activeMap = 2;
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      else if (keys[SDL_SCANCODE_3] ||
        (cursor->getPos().y == 196 && keys[SDL_SCANCODE_RETURN] && keydepressed == false)) {
        keydepressed = true;
        cout << "map 3" << endl;
        activeMap = 3; 
        currentScreen = 2;
        State newst = this->getState();
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
      else if (keys[SDL_SCANCODE_4] ||
        (cursor->getPos().y == 256 && keys[SDL_SCANCODE_RETURN] && keydepressed == false)) {
        keydepressed = true;
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
      if (keys[SDL_SCANCODE_ESCAPE] && keydepressed == false) {
        keydepressed = true;
        State newst;
        newst.type = StateType::toggleview;
        this->setState(newst);
        this->notifyObservers();
      }
    }
  }
  else if (st.type == StateType::death) {
    if (st.user == User::p1) currentScreen = 4;
    else if (st.user == User::p2) currentScreen = 3;
    State newst = this->getState();
    newst.type = StateType::toggleview;
    this->setState(newst);
    this->notifyObservers();
  }
  else if (st.type == StateType::keyup) keydepressed = false;
}