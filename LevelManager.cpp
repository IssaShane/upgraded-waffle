#include "LevelManager.h"

LevelManager::LevelManager()
{
    Level1.init( "data/Map1.png", 386 );
    Level2.init( "data/Map2.png", 386 );
    Level3.init( "data/Map3.png", 224 );
    Level4.init( "data/Map4.png", 224 );
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
    if ( activeMap == 3 && IsInMenu == false )
    {
        Level3.draw( Screen );
    }
    if ( activeMap == 4 && IsInMenu == false )
    {
        Level4.draw( Screen );
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
    if ( activeMap == 4 )
    {
        return Level4.Colly;
    }
}

int LevelManager::returnAltChange()
{
    if ( activeMap == 4 )
    {
        return 96;
    }
}

int LevelManager::returnAltStart()
{
    if ( activeMap == 4 )
    {
        return 128;
    }
}

int LevelManager::returnAltEnd()
{
    if ( activeMap == 4 )
    {
        return 480;
    }
}

int LevelManager::returnCurrentLevel()
{
    return activeMap;
}
