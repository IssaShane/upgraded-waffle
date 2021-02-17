#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Fighter.h"

class Player : public Fighter
{
    public:
        //Action Functions
        Player();
        virtual void notify(State&) override;
};

#endif
