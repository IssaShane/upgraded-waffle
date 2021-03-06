#include "Enemy.h"
#include "State.h"
#include <iostream>

using namespace std;

Enemy::Enemy() : Fighter{"data/trev-ftr2.png",SDL_Rect{64,0,32,48},SDL_Rect{0,0,32,48}} {
    //Stats
    frame = 0;
    Health = 100;
    Attacking = false;
    IsAltChange = false;
    Speed = 5;
    Boost = 5;
    Power = 1;
    Special = 5;
    IsEnabledShield = false;
    user = User::p2;
}

void Enemy::notify(State &st) {
    if (st.view == View::Game) {
        //cout << "Player health: " << this->getHealth() << endl;
        Fighter::notify(st);
        if (st.type == StateType::key && IsComputer == false) {
            const Uint8 *keys = SDL_GetKeyboardState(NULL);
            if (keys[SDL_SCANCODE_D]) {
                Pos.x += Speed;
                dir = 3;
                Clip.y = 0;
                frame += 1;
            }
            else if (keys[SDL_SCANCODE_A]) {
                Pos.x -= Speed;
                dir = 2;
                Clip.y = 48;
                frame += 1;
            }
            else if (keys[SDL_SCANCODE_S]) {
                Power = 1;
                Clip.x = 64;
                frame = 2;
                // alert the opponent of an attack
                this->attack();
                //cout << "enemy is attacking: " << Attacking << endl;
            }
            else if (keys[SDL_SCANCODE_Q]) {
                Power = 5;
                Clip.x = 64;
                frame = 2;
                Special -= 1.5;
                // alert the opponent of an attack
                this->attack();
            }
            else if (keys[SDL_SCANCODE_W]) {
                Speed = 10;
                Boost -= 0.05;
            }
            else if (keys[SDL_SCANCODE_E]) {
                IsEnabledShield = true;
            }
        } 
        else if (st.type == StateType::attack) {
            this->checkHealth(st.pos,st.power,true);
            //cout << "health: " << this->getHealth() << endl;
            // alert HUD
            State newst = this->getState();
            newst.type = StateType::health;
            newst.user = User::p2;
            newst.stat = this->getHealth();
            this->setState(newst);
            this->notifyObservers();
        } 
        else if (st.type == StateType::passiveupdate) {
            if (this->getHealth() <= 0) {
                this->Health = 100;
                State newst = this->getState();
                newst.type = StateType::death;
                newst.user = User::p2;
                this->setState(newst);
                this->notifyObservers();
            }
        }
    }
}
