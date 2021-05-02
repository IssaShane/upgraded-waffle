#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Level.h"
//#include "Player.h"
#include "Observer.h"
#include "Subject.h"

class LevelManager : public Observer, public Subject {
    public:
        LevelManager();
        ~LevelManager();
        void draw( SDL_Surface *Screen, bool IsInMenu );

        virtual void notify(State&);

        int returnCollY();
        int returnAltChange();
        int returnAltStart();
        int returnAltEnd();
        int returnCurrentLevel();

    private:
        int activeMap;
        //Player Hero;
        /*Level Level1;
        Level Level2;
        Level Level3;
        Level Level4;*/
        std::vector<Level*> levels;
};

#endif
