#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>

class Graphics;
class Controller;
class Hud;
class ItemManager;
class Enemy;
class Player;
class LevelManager;
class Menu;

class System {
    public:
        System();
        ~System();
        void Run();

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
        int frameStart;
        int frameRate;
        int frameDuration;
};

#endif
