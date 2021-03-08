#ifndef FIGHTER_H
#define FIGHTER_H

#include "GameObject.h"
#include "Observer.h"
#include "Subject.h"

class Fighter : public GameObject, public Observer, public Subject {
  public:
    Fighter(const char*,SDL_Rect,SDL_Rect);
    void checkHealth(SDL_Rect POS, bool IsAttacking, int power);
    void attack();

    virtual void notify(State&) override;
    //virtual void move(int,int) override;

    void setPosY(int newy);
    void UpdateItems(int Type, int TimesCollected);

    //getters
    int getHealth();
    bool IsAttacking();
    int getPower();
    double getBoost();
    double getSpecial();

  protected:
    //Stats
    bool Attacking;
    int Health;
    double Boost;
    int Power;
    int Altitude;
    bool IsAltChange;
    int Speed;
    int gravity;
    double Special;
    bool IsEnabledShield;
    User user;
    bool IsComputer;
};

#endif