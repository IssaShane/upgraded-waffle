#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include <SDL_image.h>
#include <fstream>
#include <vector>
#include "Subject.h"

class Level : public Subject
{
    public:
        Level( const char *filename, int CollY );
        Level(const Level&);
        void draw( SDL_Surface *Screen );
        bool IsColliding(const SDL_Rect&) const;
        int findFloor(const SDL_Rect&) const;
        ~Level();

        SDL_Surface *Img;
        int Colly;
        std::vector<SDL_Rect> floor;
};

#endif
