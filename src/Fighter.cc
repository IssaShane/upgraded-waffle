#include "Fighter.h"
#include <iostream>

using namespace std;

Fighter::Fighter(const char* filename, SDL_Rect pos, SDL_Rect clip) : GameObject{filename,pos,clip} {
  gravity = 3;
  IsComputer = false;
}

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
  if (!Attacking || IsComputer) {
    Attacking = true;
    State st = this->getState();
    st.type = StateType::attack;
    st.pos = this->getPos();
    st.power = this->getPower();
    this->setState(st);
    this->notifyObservers();
  }
}

void Fighter::notify(State &st) {
  if (st.type == StateType::draw) {
    //cout << "player notify draw" << endl;
    this->draw(st.Screen);
  }
  else if (st.type == StateType::noaction) {
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

    // make the player fall with gravity
    if (Pos.x > 0 && Pos.x + Pos.w < 640) moveVertical(gravity);

    // Query the level for collisions with the walls/floors
    State newst = this->getState();
    newst.type = StateType::iscoll;
    newst.pos = this->getPos();
    newst.view = View::Game;
    newst.user = this->user;
    this->setState(newst);
    this->notifyObservers();

    // Update the AI
    newst.type = StateType::aiupdate;
    newst.pos = this->getPos();
    newst.user = this->user;
    newst.view = View::Game;
    this->setState(newst);
    this->notifyObservers();
  }
  // Collision with a wall
  else if (st.type == StateType::yescoll && st.user == this->user) {
    if (this->dir == 2) moveHorizontal(this->Speed);
    else if (this->dir == 3) moveHorizontal((-1)*Speed);
  }
  // Collision with the floor
  else if (st.type == StateType::floorcoll && st.user == this->user) {
    /*cout << "Fighter::floorcoll: ";
    if (st.user == User::p1) cout << "p1";
    else if (st.user == User::p2) cout << "p2";
    cout << endl;*/
    //moveVertical((-1)*gravity);
    Pos.y = st.pos.y - Pos.h;
  }
  // Receive instructions from AI
  else if (this->IsComputer && st.type == StateType::aicommand 
    && this->user == st.user) {
      //cout << "receiving AICOmmand" << endl;
    if (st.command == AICommand::move) {
      if (st.pos.x > this->getPos().x) {
        Pos.x += Speed;
        dir = 3;
        Clip.y = 0;
        if (Attacking == false) frame += 1;
      }
      else if (st.pos.x < this->getPos().x) {
        Pos.x -= Speed;
        dir = 2;
        Clip.y = 48;
        if (Attacking == false) frame += 1;
      }
    }
    else if (st.command == AICommand::AI_attack) {
      cout << "AI Attack: ";
      if (st.user == User::p1) cout << "p1" << endl;
      else if (st.user == User::p2) cout << "p2" << endl;
      Power = 5;
      Clip.x = 64;
      frame = 2;
      Special -= 1.5;
      this->attack();
    }
    else if (st.command == AICommand::shield) {
      IsEnabledShield = true;
    }
  }
  // Receive Instructions on Whether or not AI should be on
  else if (st.type == StateType::setaitrue && st.user == this->user) {
    IsComputer = true;
    Speed = 1;
  }
  else if (st.type == StateType::setaifalse && st.user == this->user) {
    IsComputer = false;
  }
  else if (st.type == StateType::keyup && !IsComputer) {
    Attacking = false;
  }
}

/*void Fighter::move(int x, int y) {
  SDL_Rect newpos = this->getPos();
  newpos.x += x;
  newpos.y += y;
  State newst = this->getState();
  newst.type = StateType::iscoll;
  newst.pos = newpos;
  this->setState(newst);
  this->notifyObservers();
}*/

void Fighter::setPosY(int newy) {
  Pos.y = newy;
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


