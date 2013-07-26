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
    Boost = 5;
    Power = 1;
    Health = 100;
    Altitude = 0;
    IsAltChange = false;
    Speed = 5;
    Special = 5;
}

void Player::draw( SDL_Surface *Screen, bool IsInMenu )
{
    if ( IsInMenu == false )
        SDL_BlitSurface( Img, &Clip, Screen, &Pos );
}

void Player::getInput()
{
    key = SDL_GetKeyState(NULL);
    //Primary Attack
    if ( key[SDLK_DOWN] )
    {
        Power = 1;
        Attacking = true;
        Clip.x = 64;
        frame = 2;
    }
    //Special Attack
    else if ( key[SDLK_RCTRL] )
    {
        Power = 5;
        Attacking = true;
        Clip.x = 64;
        frame = 2;
        Special -= 1.5;
    }
    else
    {
        Attacking = false;
        Clip.x = 0;
    }

    if ( Special <= 0 )
    {
        Power = 1;
    }

    //Movement
    if ( key[SDLK_RIGHT] )
    {
        Pos.x += Speed;
        Direction = 3;
        Clip.y = 48;
        frame += 1;
    }
    if ( key[SDLK_LEFT] )
    {
        Pos.x -= Speed;
        Direction = 2;
        Clip.y = 0;
        frame += 1;
    }

    //Boost
    if ( key[SDLK_UP] )
    {
        Speed = 10;
        Boost -= 0.05;
    }
    else
    {
        Speed = 5;
    }

    if ( Boost <= 0 )
    {
        Speed = 5;
    }

    //Sheild
    if ( key[SDLK_RSHIFT] )
    {
        IsEnabledShield = true;
    }
    else
    {
        IsEnabledShield = false;
    }

    //Updating frame and direction
    if ( frame > 1 && Attacking == false )
    {
        frame = 0;
    }
    Clip.x = frame * 32;

    //Wrap player to other side of screen
    if ( Pos.x < 0 )
        Pos.x = 640;
    if ( Pos.x > 640 )
        Pos.x = 0;
}

void Player::checkHealth( SDL_Rect POS, bool IsAttacking, int power )
{
    if ( IsAttacking == true && IsEnabledShield == false )
    {
        if ( Pos.x < POS.x + POS.w &&
            Pos.x + Pos.w > POS.x &&
            Pos.y < POS.y + POS.h &&
            Pos.y + Pos.h > POS.y )
        {
            Health -= power;
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
    else if ( currentLevel == 4 && IsAltChange == false )
    {
        CollY = 224;
    }

    if ( Pos.y > CollY - 48 )
    {
        Pos.y -= 15;
    }
    if ( Pos.y < CollY - 48 )
    {
        Pos.y += 15;
    }
}

void Player::updateAlt( int AltChangeStart, int AltChangeEnd, int AltChange )
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

void Player::UpdateItems( int Type, int TimesCollected )
{
    bool IsCollected = false;
    //If the power up is a BoostUp
    if ( Type == 1 && TimesCollected == 1 )
    {
        Boost = 5;
        IsCollected = true;
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

int Player::returnPower()
{
    return Power;
}

double Player::returnBoost()
{
    return Boost;
}

double Player::returnSpecial()
{
    return Special;
}

Player::~Player()
{
    SDL_FreeSurface( Img );
}
