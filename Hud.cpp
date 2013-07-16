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
    HowToPlay = IMG_Load("data/Splash_Screens/HowToPlay.png");
    Player1_Wins = IMG_Load("data/Splash_Screens/Player1_Win.png");
    Player2_Wins = IMG_Load("data/Splash_Screens/Player2_Win.png");
    bgType = 0;
}

void Hud::Update( int PlayerHealth, int EnemyHealth )
{
    PlayerHealthBarPos.x = 640 - ( PlayerHealth * 3 );
    EnemyHealthBarPos.x = -300 + ( EnemyHealth * 3 );

    key = SDL_GetKeyState(NULL);
    if ( bgType == 1 && key[SDLK_RETURN] )
    {
        bgType = 0;
    }
    if ( PlayerHealth <= 1 )
    {
        bgType = 3;
    }
    if ( EnemyHealth <= 1 )
    {
        bgType = 2;
    }
}

void Hud::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( PlayerHealthBar, NULL, Screen, &PlayerHealthBarPos );
    SDL_BlitSurface( EnemyHealthBar, NULL, Screen, &EnemyHealthBarPos );
    if ( bgType == 1 )
    {
        SDL_BlitSurface( HowToPlay, NULL, Screen, NULL );
    }
    else if ( bgType == 2 )
    {
        SDL_BlitSurface( Player1_Wins, NULL, Screen, NULL );
    }
    else if ( bgType == 3 )
    {
        SDL_BlitSurface( Player2_Wins, NULL, Screen, NULL );
    }
}

Hud::~Hud()
{
    SDL_FreeSurface( PlayerHealthBar );
}
