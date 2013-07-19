#ifndef LEVEL_H
#define LEVEL_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Level
{
    public:
        void init( const char *filename, int CollY );
        void draw( SDL_Surface *Screen );
        ~Level();

        SDL_Surface *Img;
        int Colly;
};

#endif
