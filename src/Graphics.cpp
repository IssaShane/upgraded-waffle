#include "Graphics.h"
#include <iostream>
#include "State.h"

using namespace std;


Graphics::Graphics()
{
    win = SDL_CreateWindow("XFighter",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    Screen = SDL_GetWindowSurface(win);
    if (win == nullptr) cout << "could not load window" << endl;
    if (Screen == nullptr) cout << "Screen could not be initialized" << endl;
    cout << "window initialized" << endl;
    view = View::MenuInterface;
}

/*
void Graphics::draw(SDL_Event &e) {
    
    Hero.getInput(e);
    Hero.checkHealth( Baddy.getPos(), Baddy.IsAttacking(), Baddy.getPower() );
    Hero.UpdateY( Health.Level.returnCollY(), Health.Level.returnCurrentLevel() );
    Hero.updateAlt( Health.Level.returnAltStart(), Health.Level.returnAltEnd(), Health.Level.returnAltChange() );
    Hero.UpdateItems( Item.returnType(), Item.returnTimesCollected() );
    Health.Update( Hero.getHealth(), Baddy.getHealth(), Hero.getBoost(), Baddy.getBoost(), Hero.getSpecial(), Baddy.getSpecial(), e );
    Baddy.checkHealth( Hero.getPos(), Hero.IsAttacking(), Hero.getPower() );
    Baddy.UpdateY( Health.Level.returnCollY(), Health.Level.returnCurrentLevel() );
    Baddy.updateAlt( Health.Level.returnAltStart(), Health.Level.returnAltEnd(), Health.Level.returnAltChange() );
    Baddy.UpdateItems( Item.returnType(), Item.returnTimesCollected() );
    Baddy.getInput(e);
    Item.Update( Hero.getPos(), Baddy.getPos(), Health.Level.returnCollY(), Health.Level.returnCurrentLevel());
    Item.UpdateAlt( Health.Level.returnAltStart(), Health.Level.returnAltEnd(), Health.Level.returnAltChange() );
    
    Health.draw( Screen );
    Item.draw( Screen, true );
    Baddy.draw( Screen );
    Hero.draw( Screen );
    SDL_UpdateWindowSurface(win);
}*/

void Graphics::notify(State& st) {
    if (st.type == StateType::death) view = View::MenuInterface;
    /*else if (st.type == StateType::toggleview) {
        if (view == View::MenuInterface) view = View::Game;
        else if (view == View::Game) view = View::MenuInterface;
    }*/
}

void Graphics::update(View view) {
    State newst = this->getState();
    newst.type = StateType::draw;
    newst.Screen = Screen;
    newst.view = view;
    this->setState(newst);
    if (view == View::MenuInterface) this->notifyObserversOfCategory("Menu");
    else if (view == View::Game) this->notifyObserversOfCategory("Game");
    SDL_UpdateWindowSurface(win);
}

Graphics::~Graphics() {
    SDL_FreeSurface( Screen );
    SDL_DestroyWindow(win);
}
