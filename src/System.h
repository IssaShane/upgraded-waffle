#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>
#include "Observer.h"
#include "State.h"

class Graphics;
class Controller;
class Hud;
class ItemManager;
class Enemy;
class Player;
class LevelManager;
class Menu;
class ComputerPlayer;

class System : public Observer {
    public:
        System();
        ~System();
        void Run();
        virtual void notify(State&);

    private:
        bool quit;
        Graphics *Sprite;
        Controller *contr;
        Hud *Health;
        ItemManager *Item;
        Enemy *Baddy;
        Player *Hero;
        LevelManager *Level;
        Menu *menu;
        ComputerPlayer *comp;
        int frameStart;
        int frameRate;
        int frameDuration;
        View view;
};

#endif
