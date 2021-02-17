#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include <SDL_image.h>
#include "Subject.h"

class Level : public Subject
{
    public:
        void init( const char *filename, int CollY );
        void draw( SDL_Surface *Screen );
        ~Level();

        SDL_Surface *Img;
        int Colly;
};

#endif
