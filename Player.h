#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>

class Player
{
    public:
        Player();
        ~Player();
        void draw( SDL_Surface *Screen );
        void getInput();
        void checkHealth( SDL_Rect POS, bool IsAttacking );
        int returnHealth();
        SDL_Rect returnPos();
        bool returnAttacking();

    private:
        SDL_Surface *Img;
        SDL_Rect Clip;
        SDL_Rect Pos;
        bool Attacking;
        Uint8 *key;
        int Health;
        int Direction;
};

#endif
