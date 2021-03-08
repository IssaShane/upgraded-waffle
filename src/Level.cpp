#include "Level.h"
#include "GameObject.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Level::Level(const char *filename, int CollY) {
    Img = IMG_Load(filename);
    Colly = CollY;
    ifstream collfile;
    string collfilename = filename;
    collfilename = collfilename.substr(0,collfilename.length()-4) + ".txt";
    collfile.open(collfilename);
    // parse collision text file
    string line;
    while (getline(collfile,line)) {
        int x,y,w,h;
        char c;
        stringstream str;
        str << line;
        str >> x;
        str >> c;
        str >> y;
        str >> c;
        str >> w;
        str >> c;
        str >> h;
        floor.emplace_back(SDL_Rect{x,y,w,h});
    }
    collfile.close();
    cout << "floor: " << endl;
    for (SDL_Rect r : this->floor) {
        cout << r << endl;
    }
}

// WARNING: this gives a SHALLOW copy; this->Img will point to the same data
//   as other.Img
Level::Level(const Level &other) {
    this->Img = other.Img;
    this->Colly = other.Colly;
    for (SDL_Rect r : other.floor) this->floor.emplace_back(r);
}

void Level::draw( SDL_Surface *Screen ) {
    SDL_BlitSurface( Img, NULL, Screen, NULL );
}

bool Level::IsColliding(const SDL_Rect &rect) const {
    for (SDL_Rect block : this->floor) {
        if (IsCollision(block,rect)) return true;
    }
    return false;
}

int Level::findFloor(const SDL_Rect &pos) const {
    for (SDL_Rect block : this->floor) {
        if (block.x < pos.x && block.x + block.w > pos.x) return block.y;
    }
    return 0;
}

Level::~Level()
{
    SDL_FreeSurface( Img );
    Img = nullptr;
}
