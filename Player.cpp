#include "Player.h"

Player::Player()
{
    //Image Properties
    Img = IMG_Load("data/star-sm2.png");
    Pos.x = 512;
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
    Special = 0;
    Power = 1;
    Health = 100;
    Altitude = 0;
    IsAltChange = false;
}

void Player::draw( SDL_Surface *Screen, bool IsInMenu )
{
    if ( IsInMenu == false )
        SDL_BlitSurface( Img, &Clip, Screen, &Pos );

    if ( Special >= 5 )
    {
        std::cout << "You Have A Special.\n";
    }
}

void Player::getInput()
{
    key = SDL_GetKeyState(NULL);
    //Attacking
    if ( key[SDLK_DOWN] )
    {
        Attacking = true;
        frame = 2;
        Special += 1;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
    }

    //Movement
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

    //Updating frame and direction
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
            Pos.x + Pos.w > POS.x &&
            Pos.y < POS.y + POS.h &&
            Pos.y + Pos.h > POS.y )
        {
            Health -= 1;
        }
    }
}

void Player::setPosY( int newy )
{
    Pos.y = newy;
}

void Player::UpdateY( int CollY, int currentLevel )
{
    if ( currentLevel == 4 && IsAltChange == true )
    {
        CollY = 352;
    }

    if ( Pos.y > CollY - 48 )
    {
        Pos.y -= 1;
    }
    if ( Pos.y < CollY - 48 )
    {
        Pos.y += 1;
    }
}

void Player::updateAlt( int AltChangeStart, int AltChangeEnd, int AltChange )
{
    if ( Pos.x > AltChangeStart && Pos.x < AltChangeEnd )
    {
        IsAltChange = true;
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

int Player::returnSpecial()
{
    return Special;
}

int Player::returnPower()
{
    return Power;
}

Player::~Player()
{
    SDL_FreeSurface( Img );
}
