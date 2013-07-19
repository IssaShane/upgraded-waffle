#include "Hud.h"

Hud::Hud()
{
    //Player
    PlayerHealthBar = IMG_Load("data/blood_red_bar.png");
    PlayerHealthBarPos.x = 340;
    PlayerHealthBarPos.y = 0;

    //Enemy
    EnemyHealthBar = IMG_Load("data/blood_red_bar.png");
    EnemyHealthBarPos.x = 0;
    EnemyHealthBarPos.y = 0;

    //Background Screens
    SelectMap = IMG_Load("data/Menu.png");
    Player1_Wins = IMG_Load("data/Splash_Screens/Player1_Win.png");
    Player2_Wins = IMG_Load("data/Splash_Screens/Player2_Win.png");
    bgType = 1;
    IsInMenu = true;

    //Player Special
    PlayerSpecialBar = IMG_Load("data/SpecialBar.png");
    PlayerSpecialBarPos.x = 640;
    PlayerSpecialBarPos.y = 40;
}

void Hud::Update( int PlayerHealth, int EnemyHealth, int PlayerSpecial )
{
    PlayerHealthBarPos.x = 640 - ( PlayerHealth * 3 );
    EnemyHealthBarPos.x = -300 + ( EnemyHealth * 3 );
    PlayerSpecialBarPos.x = 640 - ( PlayerSpecial * 8 );

    key = SDL_GetKeyState(NULL);
    if ( bgType == 1 )
    {
        if ( key[SDLK_1] )
        {
            Level.selectMap( 1 );
            IsInMenu = false;
            bgType = 0;
        }
    }
    if ( PlayerHealth <= 1 )
    {
        bgType = 3;
        IsInMenu = true;
    }
    if ( EnemyHealth <= 1 )
    {
        bgType = 2;
        IsInMenu = true;
    }
    if ( PlayerSpecialBarPos.x < 598 )
    {
        PlayerSpecialBarPos.x = 598;
    }
}

void Hud::draw( SDL_Surface *Screen )
{

    if ( bgType == 0 )
    {
        Level.draw( Screen, IsInMenu );
    }
    else if ( bgType == 1 )
    {
        SDL_BlitSurface( SelectMap, NULL, Screen, NULL );
    }
    else if ( bgType == 2 )
    {
        SDL_BlitSurface( Player1_Wins, NULL, Screen, NULL );
    }
    else if ( bgType == 3 )
    {
        SDL_BlitSurface( Player2_Wins, NULL, Screen, NULL );
    }

    SDL_BlitSurface( PlayerHealthBar, NULL, Screen, &PlayerHealthBarPos );
    SDL_BlitSurface( EnemyHealthBar, NULL, Screen, &EnemyHealthBarPos );
    SDL_BlitSurface( PlayerSpecialBar, NULL, Screen, &PlayerSpecialBarPos );
}

Hud::~Hud()
{
    SDL_FreeSurface( PlayerHealthBar );
}
