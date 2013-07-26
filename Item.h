#ifndef ITEM_H
#define ITEM_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

class Item
{
    public:
        void init( const char *filename, int x, int y, int clipx, int clipy, int w, int h );
        ~Item();
        void initType( int Type );
        void draw( SDL_Surface *Screen );
        void Activate( int ObjName );
        void deActivate();
        void Update( int CollY );
        void setAffectedObj( int newAffectedObj );
        void Collect();
        int returnAffectedObj();
        int returnType();
        SDL_Rect returnPos();
        int returnTimesCollected();

    private:
        SDL_Surface *Img;
        SDL_Rect Pos;
        SDL_Rect Clip;
        int type;
        int AffectedObj;
        int TimesCollected;
};

#endif
