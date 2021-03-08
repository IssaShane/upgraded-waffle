#ifndef HUD_H
#define HUD_H

#include <SDL.h>
#include <SDL_image.h>
#include "LevelManager.h"
#include "Observer.h"

class Hud : public Observer
{
    public:
        Hud();
        ~Hud();
        void draw( SDL_Surface *Screen );
        virtual void notify(State&) override;

        //return funcitons
        bool returnAIEngaged();

        bool IsInMenu;

        //Level Select
        //LevelManager Level;

    private:
        //Player
        SDL_Surface *PlayerHealthBar;
        SDL_Rect PlayerHealthBarPos;

        //Enemy
        SDL_Surface *EnemyHealthBar;
        SDL_Rect EnemyHealthBarPos;

        bool AIEngaged;

        //Player Boost
        SDL_Surface *PlayerBoostBar;
        SDL_Rect PlayerBoostBarPos;

        //Enemy Boost
        SDL_Surface *EnemyBoostBar;
        SDL_Rect EnemyBoostBarPos;

        //Player Special
        SDL_Surface *PlayerSpecialBar;
        SDL_Rect PlayerSpecialBarPos;

        //Enemy Special
        SDL_Surface *EnemySpecialBar;
        SDL_Rect EnemySpecialBarPos;

        void setLevel(int);
};

#endif
