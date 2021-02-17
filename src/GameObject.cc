#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject() {
  Img = NULL;
  visible = false;
}

GameObject::GameObject(const char* filename) {
  Img = IMG_Load( filename );
  if (Img == NULL) cout << "cannot load game object img" << endl;
  // create and set magenta as the transparent colour
  Uint32 colorkey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
  SDL_SetColorKey( Img, SDL_TRUE, colorkey );
  visible = true;
}

GameObject::GameObject(const char* filename, const SDL_Rect Pos) {
  Img = IMG_Load( filename );
  if (Img == NULL) cout << "cannot load game object img" << endl;
  // create and set magenta as the transparent colour
  Uint32 colorkey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
  SDL_SetColorKey( Img, SDL_TRUE, colorkey );
  visible = true;

  this->Pos = Pos; // copy by value
  this->Clip = SDL_Rect{0,0,32,32};
  this->Coll = this->Pos;
}

GameObject::GameObject(const char* filename, const SDL_Rect Pos, const SDL_Rect Clip) {
  Img = IMG_Load( filename );
  if (Img == NULL) cout << "cannot load game object img" << endl;
  // create and set magenta as the transparent colour
  Uint32 colorkey = SDL_MapRGB( Img->format, 0xFF, 0, 0xFF );
  SDL_SetColorKey( Img, SDL_TRUE, colorkey );
  visible = true;

  this->Pos = Pos; // copy by value
  this->Clip = Clip;
  this->Coll = this->Pos;
}

GameObject::~GameObject() {
  SDL_FreeSurface(Img);
  Img = NULL;
}

void GameObject::draw( SDL_Surface *Screen ) {
  if (visible) SDL_BlitSurface( Img, &Clip, Screen, &Pos);
}

void GameObject::draw( SDL_Surface *Screen, bool vis) {
  if (vis) SDL_BlitSurface( Img, &Clip, Screen, &Pos);
}

void GameObject::move(int x, int y) {
  this->Pos.x += x;
  this->Pos.y += y;
}

void GameObject::moveHorizontal(int x) {
  this->Pos.x += x;
}

void GameObject::moveVertical(int y) {
  this->Pos.y += y;
}

void GameObject::setPos(const SDL_Rect newPos) {
  this->Pos = newPos;
}

void GameObject::setPos(int x, int y) {
  this->Pos.x = x;
  this->Pos.y = y;
}

void GameObject::setPos(int x, int y, int w, int h) {
  this->Pos.x = x;
  this->Pos.y = y;
  this->Pos.w = w;
  this->Pos.h = h;
}

void GameObject::reveal() { this->visible = true; }
void GameObject::hide() { this->visible = false; }

SDL_Rect GameObject::getPos() const { return this->Pos; }
SDL_Rect GameObject::getClip() const { return this->Clip; }
SDL_Rect GameObject::getColl() const { return this->Coll; }
bool GameObject::IsVisible() const { return this->visible; }

std::ostream & operator<<(std::ostream &out, const SDL_Rect &r) {
  out << "(" << r.x << "," << r.y << "," << r.w << "," << r.h << ")";
  return out;
}

bool IsCollision(const SDL_Rect &A, const SDL_Rect &B) {
  if (A.x < B.x + B.w &&
    A.x + A.w > B.x &&
    A.y < B.y + B.h &&
    A.y + A.h > B.y) 
    return true;
  else return false;
}