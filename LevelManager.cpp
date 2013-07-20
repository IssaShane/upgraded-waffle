#include "LevelManager.h"

LevelManager::LevelManager()
{
    Level1.init( "data/Map1.png", 386 );
    Level2.init( "data/Map2.png", 256 );
}

void LevelManager::selectMap( int SelectedMap )
{
    activeMap = SelectedMap;
}

void LevelManager::draw( SDL_Surface *Screen, bool IsInMenu )
{
    if ( activeMap == 1 && IsInMenu == false )
    {
        Level1.draw( Screen );
    }
    if ( activeMap == 2 && IsInMenu == false )
    {
        Level2.draw( Screen );
    }
}

int LevelManager::returnCollY()
{
    if ( activeMap == 1 )
        return Level1.Colly;
}
