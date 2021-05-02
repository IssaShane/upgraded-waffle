#include "LevelManager.h"
#include "State.h"
#include <iostream>

using namespace std;

LevelManager::LevelManager() {
    levels.emplace_back(new Level{"data/Map1.png", 386});
    levels.emplace_back(new Level{"data/Map2.png", 386});
    levels.emplace_back(new Level{"data/Map3.png", 224});
    levels.emplace_back(new Level{"data/Map4.png", 224});
    activeMap = 1;
}

LevelManager::~LevelManager() {
    for (int i = 0; i < levels.size(); i++) delete levels[i];
}

void LevelManager::draw( SDL_Surface *Screen, bool IsInMenu ) {
    if (IsInMenu == false) levels[activeMap-1]->draw(Screen);
}

void LevelManager::notify(State &st) {
    if (st.type == StateType::setlevel) activeMap = st.stat;
    else if (st.type == StateType::draw) draw(st.Screen,false);
    else if (st.type == StateType::iscoll) {
        //cout << "Level::iscoll" << endl;
        // Collision with Wall or Floor
        if (levels[activeMap-1]->IsColliding(st.pos)) {
            /*cout << "collision: ";
            if (st.user == User::p1) cout << "p1" << endl;
            else if (st.user == User::p2) cout << "p2" << endl; */
            // Collision with Floor
            if (levels[activeMap-1]->findFloor(st.pos) < st.pos.y + st.pos.h) {
                //cout << "floor" << endl;
                State newst = this->getState();
                newst.type = StateType::floorcoll;
                newst.user = st.user;
                newst.view = View::Game;
                newst.pos.y = levels[activeMap-1]->findFloor(st.pos);
                this->setState(newst);
                this->notifyObservers();
            }
            // Collision with wall
            else {
                cout << "wall" << endl;
                State newst = this->getState();
                newst.type = StateType::yescoll;
                newst.user = st.user;
                newst.view = View::Game;
                this->setState(newst);
                this->notifyObservers();
            }
            
        }
    }
}

int LevelManager::returnCollY() {
    if (activeMap >= 1 && activeMap <= levels.size())
        return levels[activeMap-1]->Colly;
}

int LevelManager::returnAltChange() {
    if ( activeMap == 4 )
    {
        return 96;
    }
    else
    {
        return 0;
    }
}

int LevelManager::returnAltStart()
{
    if ( activeMap == 4 )
    {
        return 128;
    }
    else
    {
        return 0;
    }
}

int LevelManager::returnAltEnd()
{
    if ( activeMap == 4 )
    {
        return 480;
    }
    else
    {
        return 0;
    }
}

int LevelManager::returnCurrentLevel()
{
    return activeMap;
}
