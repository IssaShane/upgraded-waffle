#include "Enemy.h"

Enemy::Enemy()
{
    //Image Properties
    Img = IMG_Load("data/trev-ftr2.png");
    Pos.x = 64;
    Pos.y = 336;
    Pos.w = 32;
    Pos.h = 48;
    Clip.x = 0;
    Clip.y = 0;
    Clip.w = 32;
    Clip.h = 48;
    colorKey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
    SDL_SetColorKey( Img, SDL_SRCCOLORKEY, colorKey );

    //Stats
    frame = 0;
    Health = 100;
    Attacking = false;
    IsAltChange = false;
}

void Enemy::draw( SDL_Surface *Screen, bool IsInMenu )
{
    if ( IsInMenu == false )
        SDL_BlitSurface( Img, &Clip, Screen, &Pos );
}

void Enemy::getInput()
{
    key = SDL_GetKeyState( NULL );
    //Movement
    if ( key[SDLK_d] )
    {
        Pos.x += 5;
        Direction = 3;
        Clip.y = 0;
        frame += 1;
    }
    if ( key[SDLK_a] )
    {
        Pos.x -= 5;
        Direction = 2;
        Clip.y = 48;
        frame += 1;
    }

    //Attacking
    if ( key[SDLK_s] )
    {
        Attacking = true;
        Clip.x = 64;
        frame = 2;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
    }

    //Updating Frame and Direction
    if ( frame > 1 && Attacking == false )
    {
        frame = 0;
    }
    Clip.x = frame * 32;

    //Wrap to other side of screen
    if ( Pos.x < 0 )
        Pos.x = 640;
    if ( Pos.x > 640 )
        Pos.x = 0;
}

void Enemy::checkHealth( SDL_Rect POS, bool IsAttacking, int Power )
{

    if ( IsAttacking == true )
    {
        if ( Pos.x         < POS.x + POS.w &&
             Pos.x + Pos.w > POS.x )
        {
            Health -= Power;
        }
    }
}

void Enemy::UpdateY( int CollY, int currentLevel )
{
    if ( currentLevel == 4 && IsAltChange == true )
    {
        CollY = 352;
    }
    else if ( currentLevel == 4 && IsAltChange == false )
    {
        CollY = 224;
    }

    if ( Pos.y > CollY - 48 )
    {
        Pos.y -= 5;
    }
    if ( Pos.y < CollY - 48 )
    {
        Pos.y += 5;
    }
}

void Enemy::updateAltChange( int AltChangeStart, int AltChangeEnd )
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

SDL_Rect Enemy::returnPos()
{
    return Pos;
}

int Enemy::returnHealth()
{
    return Health;
}

bool Enemy::returnAttacking()
{
    return Attacking;
}

Enemy::~Enemy()
{
    SDL_FreeSurface( Img );
}
