#ifndef SYSTEM_H
#define SYSTEM_H

#include "SDL/SDL.h"
#include "Graphics.h"

class System
{
    public:
        System();
        ~System();
        void Run();

    private:
        bool quit;
        SDL_Event event;
        Graphics Sprite;
        int frameStart;
        int frameRate;
        int frameDuration;
};

#endif
