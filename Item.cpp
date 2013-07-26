#include "Item.h"

void Item::init( const char *filename, int x, int y, int clipx, int clipy, int w, int h )
{
    Img = IMG_Load( filename );
    Pos.x = x;
    Pos.y = y;
    Pos.w = w;
    Pos.h = h;
    Clip.x = clipx;
    Clip.y = clipy;
    Clip.w = w;
    Clip.h = h;
    TimesCollected = 0;
}

void Item::initType( int Type )
{
    type = Type;
}

void Item::draw( SDL_Surface *Screen )
{
    if ( TimesCollected <= 1 )
        SDL_BlitSurface( Img, &Clip, Screen, &Pos );
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

int Item::returnAffectedObj()
{
    return AffectedObj;
}

int Item::returnType()
{
    return type;
}

SDL_Rect Item::returnPos()
{
    return Pos;
}

int Item::returnTimesCollected()
{
    return TimesCollected;
}

Item::~Item()
{
    SDL_FreeSurface( Img );
}
