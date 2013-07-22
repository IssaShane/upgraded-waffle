#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Enemy
{
    public:
        Enemy();
        ~Enemy();
        void draw( SDL_Surface *Screen, bool IsInMenu );
        void getInput();
        void checkHealth( SDL_Rect POS, bool IsAttacking, int Power );
        void UpdateY( int CollY, int currentLevel );
        void updateAltChange( int AltChangeStart, int AltChangeEnd );

        //Return Functions
        SDL_Rect returnPos();
        int returnHealth();
        bool returnAttacking();

    private:
        //Image Properties
        SDL_Surface *Img;
        SDL_Rect Clip;
        SDL_Rect Pos;
        Uint32 colorKey;
        Uint8 *key;

        //Stats
        int Health;
        bool Attacking;
        int Direction;
        int frame;
        bool IsAltChange;
};

#endif
