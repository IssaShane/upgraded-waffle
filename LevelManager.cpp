#include "LevelManager.h"

LevelManager::LevelManager()
{
    Level1.init( "data/Map1.png", 386 );
    Level2.init( "data/Map2.png", 386 );
    Level3.init( "data/Map3.png", 224 );
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
        Hero.UpdateY( 336 );
    }
    if ( activeMap == 2 && IsInMenu == false )
    {
        Level2.draw( Screen );
        Hero.UpdateY( 336 );
    }
    if ( activeMap == 3 && IsInMenu == false )
    {
        Level3.draw( Screen );
        Hero.UpdateY( 224 );
    }
}

int LevelManager::returnCollY()
{
    if ( activeMap == 1 )
        return Level1.Colly;
    if ( activeMap == 2 )
        return Level2.Colly;
    if ( activeMap == 3 )
        return Level3.Colly;
}
