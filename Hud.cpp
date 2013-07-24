#include "Hud.h"

Hud::Hud()
{
    //Player
    PlayerHealthBar = IMG_Load("data/PlayerHealthBar.png");
    PlayerHealthBarPos.x = 340;
    PlayerHealthBarPos.y = 0;

    //Enemy
    EnemyHealthBar = IMG_Load("data/EnemyHealthBar.png");
    EnemyHealthBarPos.x = 0;
    EnemyHealthBarPos.y = 0;

    //Background Screens
    SelectMap = IMG_Load("data/Menu.png");
    Player1_Wins = IMG_Load("data/Splash_Screens/Player1_Win.png");
    Player2_Wins = IMG_Load("data/Splash_Screens/Player2_Win.png");
    bgType = 1;
    IsInMenu = true;

    //Player Boost
    PlayerBoostBar = IMG_Load("data/SpecialBar.png");
    PlayerBoostBarPos.x = 640;
    PlayerBoostBarPos.y = 40;

    //Enemy Boost
    EnemyBoostBar = IMG_Load("data/SpecialBar.png");
    EnemyBoostBarPos.x = 0;
    EnemyBoostBarPos.y = 40;

    //Player Special Bar
    PlayerSpecialBar = IMG_Load("data/SpecialBar2.png");
    PlayerSpecialBarPos.x = 640;
    PlayerSpecialBarPos.y = 56;

    //Enemy Special Bar
    EnemySpecialBar = IMG_Load("data/SpecialBar2.png");
    EnemySpecialBarPos.x = 0;
    EnemySpecialBarPos.y = 56;
}

void Hud::Update( int PlayerHealth, int EnemyHealth, double PlayerBoost, double EnemyBoost, double PlayerSpecial, double EnemySpecial )
{
    PlayerHealthBarPos.x = 640 - ( PlayerHealth * 3 );
    EnemyHealthBarPos.x = -300 + ( EnemyHealth * 3 );
    PlayerBoostBarPos.x = 640 - ( PlayerBoost * 8 );
    EnemyBoostBarPos.x = -16 + ( EnemyBoost * 8 );
    PlayerSpecialBarPos.x = 640 - ( PlayerSpecial * 8 );
    EnemySpecialBarPos.x = -16 + ( EnemySpecial * 8 );

    key = SDL_GetKeyState(NULL);
    if ( bgType == 1.0 )
    {
        if ( key[SDLK_1] )
        {
            Level.selectMap( 1 );
            IsInMenu = false;
            bgType = 0;
        }
        if ( key[SDLK_2] )
        {
            Level.selectMap( 2 );
            IsInMenu = false;
            bgType = 0;
        }
        if ( key[SDLK_3] )
        {
            Level.selectMap( 3 );
            IsInMenu = false;
            bgType = 0;
        }
        if ( key[SDLK_4] )
        {
            Level.selectMap( 4 );
            IsInMenu = false;
            bgType = 0;
        }
    }
    if ( bgType == 1.2 )
    {
        if ( key[SDLK_1] )
        {
            bgType = 1.0;
            AIEngaged = true;
        }
        if ( key[SDLK_2] )
        {
            bgType = 1.0;
            AIEngaged = false;
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
    if ( PlayerBoostBarPos.x < 598 )
    {
        PlayerBoostBarPos.x = 598;
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
    else if ( bgType == 1.2 )
    {
        SDL_BlitSurface( SelectPlayer, NULL, Screen, NULL );
    }
    else if ( bgType == 2 )
    {
        SDL_BlitSurface( Player1_Wins, NULL, Screen, NULL );
    }
    else if ( bgType == 3 )
    {
        SDL_BlitSurface( Player2_Wins, NULL, Screen, NULL );
    }

    if ( IsInMenu == false )
    {
        SDL_BlitSurface( PlayerHealthBar, NULL, Screen, &PlayerHealthBarPos );
        SDL_BlitSurface( EnemyHealthBar, NULL, Screen, &EnemyHealthBarPos );
        SDL_BlitSurface( PlayerBoostBar, NULL, Screen, &PlayerBoostBarPos );
        SDL_BlitSurface( EnemyBoostBar, NULL, Screen, &EnemyBoostBarPos );
        SDL_BlitSurface( PlayerSpecialBar, NULL, Screen, &PlayerSpecialBarPos );
        SDL_BlitSurface( EnemySpecialBar, NULL, Screen, &EnemySpecialBarPos );
    }
}

bool Hud::returnAIEngaged()
{
    return AIEngaged;
}

Hud::~Hud()
{
    SDL_FreeSurface( PlayerHealthBar );
    SDL_FreeSurface( PlayerBoostBar );
    SDL_FreeSurface( EnemyHealthBar );
    SDL_FreeSurface( EnemyBoostBar );
}
