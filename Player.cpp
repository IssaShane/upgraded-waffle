#include "Player.h"

Player::Player()
{
    Img = IMG_Load("data/star-sm2.png");
    Pos.x = 512;
    Pos.y = 336;
    Pos.w = 32;
    Pos.h = 48;
    Clip.x = 0;
    Clip.y = 0;
    Clip.w = 32;
    Clip.h = 48;
    Health = 100;
    colorKey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
    SDL_SetColorKey( Img, SDL_SRCCOLORKEY, colorKey );
    frame = 0;
}

void Player::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( Img, &Clip, Screen, &Pos );
}

void Player::getInput()
{
    key = SDL_GetKeyState(NULL);
    if ( key[SDLK_SPACE] )
    {
        Attacking = true;
        frame = 2;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
    }
    if ( key[SDLK_RIGHT] )
    {
        Pos.x += 5;
        Direction = 3;
        Clip.y = 48;
        frame += 1;
    }
    if ( key[SDLK_LEFT] )
    {
        Pos.x -= 5;
        Direction = 2;
        Clip.y = 0;
        frame += 1;
    }
    if ( frame > 1 && Attacking == false )
    {
        frame = 0;
    }
    Clip.x = frame * 32;
}

void Player::checkHealth( SDL_Rect POS, bool IsAttacking )
{
    if ( IsAttacking == true )
    {
        if ( Pos.x < POS.x + POS.w &&
            Pos.x + Pos.w > POS.w &&
            Pos.y < Pos.y + Pos.h &&
            Pos.y + Pos.h > Pos.y )
        {
            Health -= 1;
        }
    }
}

int Player::returnHealth()
{
    return Health;
}

SDL_Rect Player::returnPos()
{
    return Pos;
}

bool Player::returnAttacking()
{
    return Attacking;
}

Player::~Player()
{
    SDL_FreeSurface( Img );
}
