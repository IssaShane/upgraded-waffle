#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Subject.h"
#include "Observer.h"
#include <SDL.h>

/*
A Note:

Is this convoluted? Yes; entirely. It's here so that if I decide to conjure
something more useful or advanced, I have the infrastructure to do that.
*/

class ComputerPlayer : public Observer, public Subject {
  public:
    ComputerPlayer();
    virtual void notify(State&);
  private:
    SDL_Rect pos;
    User user;
};

#endif