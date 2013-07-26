#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Player.h"
#include "Enemy.h"
#include "Hud.h"
#include "ItemManager.h"

class Graphics
{
    public:
        Graphics();
        ~Graphics();
        void draw();

    private:
        SDL_Surface *Screen;
        Player Hero;
        Enemy Baddy;
        Hud Health;
        ItemManager Item;
};

#endif
