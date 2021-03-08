#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL.h>
#include "Subject.h"

enum View;

class Controller : public Subject {
  public:
    Controller();
    void update(View);
    bool IsQuit() const;

  private:
    bool quit;
    SDL_Event e;
};

#endif