#ifndef ENTITY_H
#define ENTITY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Entity
{
    public:
        void init( const char *filename, int x, int y, int clipx, int clipy, int w, int h )
        {
            Img = IMG_Load(filename);
            Pos.x = x;
            Pos.y = y;
            Pos.w = w;
            Pos.h = h;
            Clip.x = clipx;
            Clip.y = clipy;
            Clip.w = w;
            Clip.h = h;
        }

        void draw( SDL_Surface *Screen )
        {
            SDL_BlitSurface( Img, &Clip, Screen, &Pos );
        }

        ~Entity()
        {
            SDL_FreeSurface( Img );
        }

    private:
        SDL_Surface *Img;
        SDL_Rect Clip;
        SDL_Rect Pos;
};

#endif
