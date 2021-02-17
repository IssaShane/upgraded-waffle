#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Fighter.h"

class Enemy : public Fighter {
    public:
        Enemy();
        virtual void notify(State&) override;
};

#endif
