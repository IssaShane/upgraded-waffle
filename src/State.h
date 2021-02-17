#ifndef STATE_H
#define STATE_H

#include <SDL.h>
#include <vector>

enum StateType {
  key, draw, noaction, passiveupdate, 
  attack, health, boost, special, death,
  setlevel, setplayer, toggleview
};

enum User {
  p1,p2
};

class State {
  public:
    // key
    StateType type;
    std::vector<bool> keycode;
    // draw
    SDL_Surface *Screen;
    // attack
    SDL_Rect pos;
    int power;
    // stat (i.e. health, energy)
    User user;
    int stat;
};

#endif