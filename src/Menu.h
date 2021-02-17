#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include "Observer.h"
#include "Subject.h"

class Menu : public Observer, public Subject {
  public:
    Menu();
    ~Menu();
    virtual void notify(State&) override;

  private:
    // Background Screens
    SDL_Surface *SelectMap;
    SDL_Surface *SelectPlayer;
    SDL_Surface *Player1_Wins;
    SDL_Surface *Player2_Wins;
    int currentScreen; // Menu Screens & Gameplay
};

#endif