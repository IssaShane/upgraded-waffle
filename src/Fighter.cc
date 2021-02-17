#include "Fighter.h"
#include <iostream>

using namespace std;

Fighter::Fighter(const char* filename, SDL_Rect pos, SDL_Rect clip) : GameObject{filename,pos,clip}{}

void Fighter::checkHealth( SDL_Rect POS, bool IsAttacking, int power ) {
  if ( IsAttacking == true && IsEnabledShield == false )
  {
    if ( Pos.x < POS.x + POS.w &&
        Pos.x + Pos.w > POS.x &&
        Pos.y < POS.y + POS.h &&
        Pos.y + Pos.h > POS.y )
    {
      Health -= power;
    }
  }
}

void Fighter::attack() {
  State st = this->getState();
  st.type = StateType::attack;
  st.pos = this->getPos();
  st.power = this->getPower();
  this->setState(st);
  this->notifyObservers();
}

void Fighter::notify(State &st) {
  if (st.type == StateType::draw) {
    //cout << "player notify draw" << endl;
    this->draw(st.Screen);
  }
  else if (st.type == StateType::noaction) {
    Attacking = false;
    Clip.x = 0;
    Speed = 5;
    IsEnabledShield = false;
  }
  else if (st.type == StateType::passiveupdate) {
    if ( Special <= 0 ) Power = 1;

    if ( Boost <= 0 ) Speed = 5;

    //Updating frame and direction
    if ( frame > 1 && Attacking == false ) frame = 0;
    Clip.x = frame * 32;

    //Wrap player to other side of screen
    if ( Pos.x < 0 ) Pos.x = 640;
    if ( Pos.x > 640 ) Pos.x = 0;
  }
}

void Fighter::setPosY(int newy) {
  Pos.y = newy;
}

void Fighter::UpdateY( int CollY, int currentLevel ) {
  if ( currentLevel == 4 && IsAltChange == true )
  {
    CollY = 352;
  }
  else if ( currentLevel == 4 && IsAltChange == false )
  {
    CollY = 224;
  }

  if ( Pos.y > CollY - 48 )
  {
    Pos.y -= 15;
  }
  if ( Pos.y < CollY - 48 )
  {
    Pos.y += 15;
  }
}

void Fighter::updateAlt( int AltChangeStart, int AltChangeEnd, int AltChange ) {
  if ( Pos.x > AltChangeStart && Pos.x < AltChangeEnd )
  {
    IsAltChange = true;
  }
  else
  {
    IsAltChange = false;
  }
}

void Fighter::UpdateItems( int Type, int TimesCollected ) {
  //bool IsCollected = false;
  //If the power up is a BoostUp
  if ( Type == 1 && TimesCollected == 1 )
  {
    Boost = 5;
    //IsCollected = true;
  }
}

int Fighter::getHealth() { return Health; }
bool Fighter::IsAttacking() { return Attacking; }
int Fighter::getPower() { return Power; }
double Fighter::getBoost() { return Boost; }
double Fighter::getSpecial() { return Special; }


