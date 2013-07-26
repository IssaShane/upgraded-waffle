#include "Graphics.h"

Graphics::Graphics()
{
    Screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
}

void Graphics::draw()
{
    Hero.getInput();
    Hero.checkHealth( Baddy.returnPos(), Baddy.returnAttacking(), Baddy.returnPower() );
    Hero.UpdateY( Health.Level.returnCollY(), Health.Level.returnCurrentLevel() );
    Hero.updateAlt( Health.Level.returnAltStart(), Health.Level.returnAltEnd(), Health.Level.returnAltChange() );
    Hero.UpdateItems( Item.returnType(), Item.returnTimesCollected() );
    Health.Update( Hero.returnHealth(), Baddy.returnHealth(), Hero.returnBoost(), Baddy.returnBoost(), Hero.returnSpecial(), Baddy.returnSpecial() );
    Baddy.checkHealth( Hero.returnPos(), Hero.returnAttacking(), Hero.returnPower() );
    Baddy.UpdateY( Health.Level.returnCollY(), Health.Level.returnCurrentLevel() );
    Baddy.updateAltChange( Health.Level.returnAltStart(), Health.Level.returnAltEnd() );
    Baddy.UpdateItems( Item.returnType(), Item.returnTimesCollected() );
    Baddy.getInput();
    Item.Update( Hero.returnPos(), Baddy.returnPos(), Health.Level.returnCollY() );

    Health.draw( Screen );
    Item.draw( Screen, Health.IsInMenu );
    Baddy.draw( Screen, Health.IsInMenu );
    Hero.draw( Screen, Health.IsInMenu );
    SDL_Flip( Screen );
}

Graphics::~Graphics()
{
    SDL_FreeSurface( Screen );
}
