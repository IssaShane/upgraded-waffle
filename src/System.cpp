#include "System.h"
#include "Graphics.h"
#include "Controller.h"
#include "Menu.h"
#include "ComputerPlayer.h"
#include <iostream>

using namespace std;

System::System() {
    quit = false;
    SDL_Init( SDL_INIT_EVERYTHING );
    int imgflags = IMG_INIT_PNG;
    if (!(IMG_Init(IMG_INIT_PNG) & imgflags)) cout << "cannot initialize SDL_image; " << IMG_GetError() << endl;
    frameRate = 1000 / 30;
    //SDL_WM_SetIcon( IMG_Load("data/Icon.png"), NULL );
    cout << "initialized SDL" << endl;
    Sprite = new Graphics{};
    contr = new Controller{};
    Health = new Hud{};
    Item = new ItemManager{};
    Baddy = new Enemy{};
    Hero = new Player{};
    Level = new LevelManager{};
    menu = new Menu{};
    comp = new ComputerPlayer{};

    contr->addObserver(Hero);
    contr->addObserver(Baddy);
    contr->addObserver(Level);
    contr->addObserver(menu);
    // the order of adding observers determines
    //   the order of drawing
    Sprite->addObserver(Level);
    Sprite->addObserver(Item);
    Sprite->addObserver(Baddy);
    Sprite->addObserver(Hero);
    Sprite->addObserver(Health);
    Sprite->addObserver(menu);
    Hero->addObserver(Baddy);
    Baddy->addObserver(Hero);
    Hero->addObserver(Health);
    Hero->addObserver(menu);
    Hero->addObserver(Level);
    Baddy->addObserver(Level);
    Level->addObserver(Hero);
    Level->addObserver(Baddy);
    Baddy->addObserver(Health);
    Baddy->addObserver(menu);
    menu->addObserver(Level);
    menu->addObserver(this);
    menu->addObserver(Hero);
    menu->addObserver(Baddy);
    Baddy->addObserver(comp);
    Hero->addObserver(comp);
    comp->addObserver(Baddy);
    comp->addObserver(Hero);


    // categorize objects
    Level->category = "Game";
    Hero->category = "Game";
    Baddy->category = "Game";
    Item->category = "Game";
    Health->category = "Game";
    
    menu->category = "Menu";

    view = View::MenuInterface;
}

void System::notify(State &st) {
    if (st.type == StateType::toggleview) {
        if (view == View::MenuInterface) view = View::Game;
        else if (view == View::Game) view = View::MenuInterface;
    }
}

void System::Run()
{
    while ( contr->IsQuit() == false )
    {
        frameStart = SDL_GetTicks();
        contr->update(view);
        Sprite->update(view);
        
        //cout << "drawn sprite" << endl;
        frameDuration = SDL_GetTicks() - frameStart;
        if( frameDuration < frameRate )
            SDL_Delay(frameRate - frameDuration);
    }
}

System::~System()
{
    delete Sprite;
    delete contr;
    delete Health;
    delete Item;
    delete Baddy;
    delete Hero;
    delete Level;
    delete menu;
    SDL_Quit();
}
