#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Level.h"
#include "Player.h"

class LevelManager
{
    public:
        LevelManager();
        void selectMap( int SelectedMap );
        void draw( SDL_Surface *Screen, bool IsInMenu );
        int returnCollY();
        int returnAltChange();
        int returnAltStart();
        int returnAltEnd();
        int returnCurrentLevel();

    private:
        int activeMap;
        Player Hero;
        Level Level1;
        Level Level2;
        Level Level3;
        Level Level4;
};

#endif
