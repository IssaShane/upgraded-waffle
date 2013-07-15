#include "Graphics.h"

Graphics::Graphics()
{
    Screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
    bg = IMG_Load("data/Map1.png");
}

void Graphics::draw()
{
    Hero.getInput();
    Hero.checkHealth( Baddy.returnPos(), Baddy.returnAttacking() );
    Health.Update( Hero.returnHealth(), Baddy.returnHealth() );
    Baddy.checkHealth( Hero.returnPos(), Hero.returnAttacking() );
    Baddy.getInput();

    SDL_BlitSurface( bg, NULL, Screen, NULL );
    Baddy.draw( Screen );
    Hero.draw( Screen );
    Health.draw( Screen );
    SDL_Flip( Screen );
}

Graphics::~Graphics()
{
    SDL_FreeSurface( Screen );
}
