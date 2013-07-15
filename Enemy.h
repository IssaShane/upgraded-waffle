#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Enemy
{
    public:
        Enemy();
        ~Enemy();
        void draw( SDL_Surface *Screen );
        void getInput();
        void checkHealth( SDL_Rect POS, bool IsAttacking );
        SDL_Rect returnPos();
        int returnHealth();
        bool returnAttacking();

    private:
        SDL_Surface *Img;
        SDL_Rect Clip;
        SDL_Rect Pos;
        int Health;
        Uint8 *key;
        bool Attacking;
        int Direction;
        Uint32 colorKey;
};

#endif
