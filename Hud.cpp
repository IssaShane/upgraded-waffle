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
}

void Hud::Update( int PlayerHealth, int EnemyHealth )
{
    PlayerHealthBarPos.x = 640 - ( PlayerHealth * 3 );
    EnemyHealthBarPos.x = -300 + ( EnemyHealth * 3 );
}

void Hud::draw( SDL_Surface *Screen )
{
    SDL_BlitSurface( PlayerHealthBar, NULL, Screen, &PlayerHealthBarPos );
    SDL_BlitSurface( EnemyHealthBar, NULL, Screen, &EnemyHealthBarPos );
}

Hud::~Hud()
{
    SDL_FreeSurface( PlayerHealthBar );
}
