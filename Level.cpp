#include "Level.h"

void Level::init( const char *filename, int CollY )
{
    Img = IMG_Load(filename);
    Colly = CollY;
}

void Level::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( Img, NULL, Screen, NULL );
}

Level::~Level()
{
    SDL_FreeSurface( Img );
}
