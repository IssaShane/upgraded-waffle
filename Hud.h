#ifndef HUD_H
#define HUD_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "LevelManager.h"

class Hud
{
    public:
        Hud();
        ~Hud();
        void draw( SDL_Surface *Screen );
        void Update( int PlayerHealth, int EnemyHealth, double PlayerBoost, double EnemyBoost, double PlayerSpecial, double EnemySpecial );

        //return funcitons
        bool returnAIEngaged();

        bool IsInMenu;

        //Level Select
        LevelManager Level;

    private:
        //Player
        SDL_Surface *PlayerHealthBar;
        SDL_Rect PlayerHealthBarPos;

        //Enemy
        SDL_Surface *EnemyHealthBar;
        SDL_Rect EnemyHealthBarPos;

        //Background Screens
        SDL_Surface *SelectMap;
        SDL_Surface *SelectPlayer;
        SDL_Surface *Player1_Wins;
        SDL_Surface *Player2_Wins;
        double bgType;
        Uint8 *key;
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
};

#endif
