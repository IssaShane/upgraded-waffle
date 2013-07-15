#include "Player.h"

Player::Player()
{
    Img = IMG_Load("data/star-sm.png");
    Pos.x = 512;
    Pos.y = 336;
    Pos.w = 32;
    Pos.h = 48;
    Clip.x = 4;
    Clip.y = 8;
    Clip.w = 32;
    Clip.h = 48;
    Health = 100;
    colorKey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
    SDL_SetColorKey( Img, SDL_SRCCOLORKEY, colorKey );
}

void Player::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( Img, &Clip, Screen, &Pos );
    std::cout << Health << std::endl;
}

void Player::getInput()
{
    key = SDL_GetKeyState(NULL);
    if ( key[SDLK_SPACE] )
    {
        Attacking = true;
        Clip.x = 88;
        Clip.y = 8;
    }
    else
    {
        Attacking = false;
        Clip.x = 4;
        Clip.y = 8;
    }
    if ( key[SDLK_RIGHT] )
    {
        Pos.x += 5;
        Direction = 3;
    }
    if ( key[SDLK_LEFT] )
    {
        Pos.x -= 5;
        Direction = 2;
    }

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
            if ( Direction == 3 )
            {
                Pos.x -= 10;
            }
            else if ( Direction == 2 )
            {
                Pos.x += 10;
            }
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
