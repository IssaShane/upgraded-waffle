#include "LevelManager.h"
#include "State.h"
#include <iostream>

using namespace std;

LevelManager::LevelManager() {
    Level1.init( "data/Map1.png", 386 );
    Level2.init( "data/Map2.png", 386 );
    Level3.init( "data/Map3.png", 224 );
    Level4.init( "data/Map4.png", 224 );
    activeMap = 1;
}

void LevelManager::draw( SDL_Surface *Screen, bool IsInMenu ) {
    cout << "activeMap: " << activeMap << endl;
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

void LevelManager::notify(State &st) {
    if (st.type == StateType::setlevel) activeMap = st.stat;
    else if (st.type == StateType::draw) draw(st.Screen,false);
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
    else
    {
        return 0;
    }
}

int LevelManager::returnAltChange()
{
    if ( activeMap == 4 )
    {
        return 96;
    }
    else
    {
        return 0;
    }
}

int LevelManager::returnAltStart()
{
    if ( activeMap == 4 )
    {
        return 128;
    }
    else
    {
        return 0;
    }
}

int LevelManager::returnAltEnd()
{
    if ( activeMap == 4 )
    {
        return 480;
    }
    else
    {
        return 0;
    }
}

int LevelManager::returnCurrentLevel()
{
    return activeMap;
}
