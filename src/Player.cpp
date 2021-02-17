#include "Player.h"
#include "State.h"
#include <iostream>

using namespace std;

Player::Player() : Fighter{"data/star-sm2.png",SDL_Rect{512,336,32,48},SDL_Rect{0,0,32,48}} {
    //Stats
    frame = 0;
    Boost = 5;
    Power = 1;
    Health = 100;
    Altitude = 0;
    IsAltChange = false;
    Speed = 5;
    Special = 5;
}

void Player::notify(State &st) {
    Fighter::notify(st);
    
    if (st.type == StateType::key) {
        const Uint8 *keys = SDL_GetKeyboardState(nullptr);
        if (keys[SDL_SCANCODE_DOWN]) {
            Power = 1;
            Attacking = true;
            Clip.x = 64;
            frame = 2;
            // alert the opponent of an attack
            this->attack();
        }
        else if (keys[SDL_SCANCODE_RCTRL]) {
            Power = 5;
            Attacking = true;
            Clip.x = 64;
            frame = 2;
            Special -= 1.5;
            // alert the opponent of an attack
            this->attack();
        }
        else if (keys[SDL_SCANCODE_RIGHT]) {
            Pos.x += Speed;
            dir = 3;
            Clip.y = 48;
            frame += 1;
        }
        else if (keys[SDL_SCANCODE_LEFT]) {
            Pos.x -= Speed;
            dir = 2;
            Clip.y = 0;
            frame += 1;
        }
        else if (keys[SDL_SCANCODE_UP]) {
            Speed = 10;
            Boost -= 0.05;
        }
        else if (keys[SDL_SCANCODE_RSHIFT]) {
            IsEnabledShield = true;
        }
    }
  else if (st.type == StateType::attack) {
    this->checkHealth(st.pos,st.power,true);
    //cout << "health: " << this->getHealth() << endl;
    // alert HUD
    State newst = this->getState();
    newst.type = StateType::health;
    newst.user = User::p1;
    newst.stat = this->getHealth();
    this->setState(newst);
    this->notifyObservers();
  }
  else if (st.type == StateType::passiveupdate) {
      if (this->getHealth() <= 0) {
          State newst = this->getState();
          newst.type = StateType::death;
          newst.user = User::p1;
          this->setState(newst);
          this->notifyObservers();
      }
  }

    
}



