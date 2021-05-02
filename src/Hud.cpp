#include "Hud.h"
#include "State.h"
#include <iostream>

using namespace std;

Hud::Hud() {
    //Player
    PlayerHealthBar = IMG_Load("data/PlayerHealthBar.png");
    PlayerHealthBarPos.x = 340;
    PlayerHealthBarPos.y = 0;

    //Enemy
    EnemyHealthBar = IMG_Load("data/EnemyHealthBar.png");
    EnemyHealthBarPos.x = 0;
    EnemyHealthBarPos.y = 0;

    //Player Boost
    PlayerBoostBar = IMG_Load("data/SpecialBar.png");
    PlayerBoostBarPos.x = 640;
    PlayerBoostBarPos.y = 40;

    //Enemy Boost
    EnemyBoostBar = IMG_Load("data/SpecialBar.png");
    EnemyBoostBarPos.x = 0;
    EnemyBoostBarPos.y = 40;

    //Player Special Bar
    PlayerSpecialBar = IMG_Load("data/SpecialBar2.png");
    PlayerSpecialBarPos.x = 640;
    PlayerSpecialBarPos.y = 56;

    //Enemy Special Bar
    EnemySpecialBar = IMG_Load("data/SpecialBar2.png");
    EnemySpecialBarPos.x = 0;
    EnemySpecialBarPos.y = 56;
}

void Hud::notify(State &st) {
    //cout << "enemy bar x: " << EnemyHealthBarPos.x << endl;
    if (st.type == StateType::draw) this->draw(st.Screen);
    else if (st.type == StateType::health) {
        //cout << "HUD::HEALTH" << endl;
        if (st.user == User::p1) 
            PlayerHealthBarPos.x = 640 - ( st.stat * 3 );
        else if (st.user == User::p2) {
            cout << "enemy health: " << st.stat << endl;
            EnemyHealthBarPos.x = -300 + ( st.stat * 3 );
            //cout << "enemy  bar x: " << EnemyHealthBarPos.x << endl;
        }
    }
    else if (st.type == StateType::boost) {
        if (st.user == User::p1)
            PlayerBoostBarPos.x = 640 - ( st.stat * 8 );
        else if (st.user == User::p2)
            EnemyBoostBarPos.x = -16 + ( st.stat * 8 );
    }
    else if (st.type == StateType::special) {
        if (st.user == User::p1)
            PlayerSpecialBarPos.x = 640 - ( st.stat * 8 );
        else if (st.user == User::p2)
            EnemySpecialBarPos.x = -16 + ( st.stat * 8 );
    }
}

void Hud::draw( SDL_Surface *Screen ) {
    //cout << "Enemy bar pos.x : " << EnemyHealthBarPos.x << endl;
    //cout << "Player bar pos.x :" << PlayerHealthBarPos.x << endl;
    SDL_BlitSurface( PlayerHealthBar, NULL, Screen, &PlayerHealthBarPos );
    SDL_BlitSurface( EnemyHealthBar, NULL, Screen, &EnemyHealthBarPos );
    SDL_BlitSurface( PlayerBoostBar, NULL, Screen, &PlayerBoostBarPos );
    SDL_BlitSurface( EnemyBoostBar, NULL, Screen, &EnemyBoostBarPos );
    SDL_BlitSurface( PlayerSpecialBar, NULL, Screen, &PlayerSpecialBarPos );
    SDL_BlitSurface( EnemySpecialBar, NULL, Screen, &EnemySpecialBarPos );
    
}

bool Hud::returnAIEngaged()
{
    return AIEngaged;
}

Hud::~Hud()
{
    SDL_FreeSurface( PlayerHealthBar );
    SDL_FreeSurface( PlayerBoostBar );
    SDL_FreeSurface( PlayerSpecialBar );
    SDL_FreeSurface( EnemyHealthBar );
    SDL_FreeSurface( EnemyBoostBar );
    SDL_FreeSurface( EnemySpecialBar );
}
