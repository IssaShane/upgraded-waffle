#include "Item.h"

Item::Item(const char* filename, SDL_Rect pos, SDL_Rect clip) : GameObject{filename,pos,clip} {}
Item::~Item() {}

void Item::initType( int Type )
{
    type = Type;
}

void Item::Activate( int ObjName )
{
    AffectedObj = ObjName;
}

void Item::deActivate()
{
    AffectedObj = 0;
}

void Item::Update( int CollY, int currentLevel )
{
    if ( currentLevel == 4 && IsAltChange == true )
    {
        CollY = 352;
    }
    else if ( currentLevel == 4 && IsAltChange == false )
    {
        CollY = 224;
    }

    Pos.y += 5;
    if ( Pos.y > CollY - Clip.h )
    {
        Pos.y -= 5;
    }
    else if ( Pos.y < CollY - Clip.h )
    {
        Pos.y += 5;
    }
}

void Item::UpdateAlt( int AltChangeStart, int AltChangeEnd, int AltChange )
{
    if ( Pos.x > AltChangeStart && Pos.x < AltChangeEnd )
    {
        IsAltChange = true;
    }
    else
    {
        IsAltChange = false;
    }
}

void Item::setAffectedObj( int newAffectedObj )
{
    AffectedObj = newAffectedObj;
}

void Item::Collect()
{
    TimesCollected += 1;
}

int Item::getAffectedObj()
{
    return AffectedObj;
}

int Item::getType()
{
    return type;
}

int Item::getTimesCollected()
{
    return TimesCollected;
}

