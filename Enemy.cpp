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
}

void Enemy::checkHealth( SDL_Rect POS, bool IsAttacking, int Power )
{

    if ( IsAttacking == true )
    {
        if ( Pos.x         < POS.x + POS.w &&
             Pos.x + Pos.w > POS.w         &&
             Pos.y         < POS.y + POS.h &&
             Pos.y + Pos.h > POS.y )
        {
            Health -= Power;
        }
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
