#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>

class Player
{
    public:
        //Action Functions
        Player();
        ~Player();
        void draw( SDL_Surface *Screen );
        void getInput();
        void checkHealth( SDL_Rect POS, bool IsAttacking );

        //Return Functions
        int returnHealth();
        SDL_Rect returnPos();
        bool returnAttacking();
        int returnSpecial();
        int returnPower();

    private:
        //Image Properties
        SDL_Surface *Img;
        SDL_Rect Clip;
        SDL_Rect Pos;
        int frame;
        int Direction;
        Uint8 *key;
        Uint32 colorKey;

        //Stats
        bool Attacking;
        int Health;
        int Special;
        int Power;
};

#endif
