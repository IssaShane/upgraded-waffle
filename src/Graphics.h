#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include "Hud.h"
#include "ItemManager.h"
#include "Subject.h"
#include "Observer.h"

class State;

enum View {
    MenuInterface, Game
};

class Graphics : public Subject, public Observer {
    public:
        Graphics();
        ~Graphics();
        //void draw(SDL_Event&);
        void update();

        virtual void notify(State&) override;

    private:
        SDL_Surface *Screen;
        SDL_Window *win;
        View view;
        /*Player Hero;
        Enemy Baddy;
        Hud Health;
        ItemManager Item;*/
};

#endif
