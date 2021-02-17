#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL.h>
#include "Subject.h"

class Controller : public Subject {
  public:
    Controller();
    void update();
    bool IsQuit() const;

  private:
    bool quit;
    SDL_Event e;
};

#endif