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
        void Update( int PlayerHealth, int EnemyHealth, double PlayerSpecial, double EnemyBoost );

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
        SDL_Surface *Player1_Wins;
        SDL_Surface *Player2_Wins;
        int bgType;
        Uint8 *key;

        //Player Boost
        SDL_Surface *PlayerBoostBar;
        SDL_Rect PlayerBoostBarPos;

        //Enemy Boost
        SDL_Surface *EnemyBoostBar;
        SDL_Rect EnemyBoostBarPos;


};

#endif
