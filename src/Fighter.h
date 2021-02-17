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

    void setPosY(int newy);
    void UpdateY(int CollY, int currentLevel);
    void updateAlt(int AltChangeStart, int AltChangeEnd, int AltChange);
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
    double Special;
    bool IsEnabledShield;
};

#endif