#include "ComputerPlayer.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

ComputerPlayer::ComputerPlayer() {
  user = User::p2;
  delay_period = 15;
  delay = delay_period;
}

void ComputerPlayer::notify(State &st) {
  // Update the position we're tracking
  if (st.type == StateType::aiupdate && st.user == this->user) {
    this->pos = st.pos;
  }
  // Order the player we're controlling to act
  else if (st.type == StateType::aiupdate && st.user != this->user) {
    State newst = this->getState();
    newst.type = StateType::aicommand;
    newst.pos = st.pos;
    newst.user = this->user;
    newst.view = View::Game;
    if (IsCollision(st.pos,this->pos) && delay <= 0) {
      newst.command = AICommand::AI_attack;
      delay = 30;
    }
    else newst.command = AICommand::move;
    delay--;
    this->setState(newst);
    //cout << "sending AICommand" << endl;
    this->notifyObservers();
  }
}