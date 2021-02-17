#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class GameObject {
  public:
    // constructors & destructors
    GameObject();
    GameObject(const char*);
    GameObject(const char*, const SDL_Rect, const SDL_Rect);
    GameObject(const char*, const SDL_Rect);
    ~GameObject();

    // action functions
    virtual void draw( SDL_Surface* );
    void draw( SDL_Surface*, bool );

    // getters 
    SDL_Rect getPos() const;
    SDL_Rect getClip() const;
    SDL_Rect getColl() const;
    bool IsVisible() const;

    // setters
    void move(int, int);
    void moveVertical(int);
    void moveHorizontal(int);
    void setPos(const SDL_Rect);
    void setPos(int, int);
    void setPos(int, int, int, int);
    void reveal();
    void hide();


  protected:
    SDL_Surface *Img;
    SDL_Rect Clip;
    SDL_Rect Pos;
    // the portion of the image that will be collidable; 
    //   position begins at the object's current position
    SDL_Rect Coll; 
    
    // Animation
    int frame; // current frame on a spritesheet
    int dir; // direction that the object is facing; also found on spritesheet
    bool visible; // whether or not to draw the object
};

std::ostream & operator<<(std::ostream&, const SDL_Rect&);

bool IsCollision(const SDL_Rect&, const SDL_Rect&);

#endif