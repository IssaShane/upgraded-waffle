#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

class Player
{
    public:
        //Action Functions
        Player();
        ~Player();
        void draw( SDL_Surface *Screen, bool IsInMenu );
        void getInput();
        void checkHealth( SDL_Rect POS, bool IsAttacking, int power );
        void setPosY( int newy );
        void UpdateY( int CollY, int currentLevel );
        void updateAlt( int AltChangeStart, int AltChangeEnd, int AltChange );

        //Return Functions
        int returnHealth();
        SDL_Rect returnPos();
        bool returnAttacking();
        int returnPower();
        double returnBoost();

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
        double Boost;
        int Power;
        int Altitude;
        bool IsAltChange;
        int Speed;
};

#endif
