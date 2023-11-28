#include "wumpus.h"
#include "player.h"

#include <iostream>

using namespace std;

// Wumpus Implementation

Wumpus::Wumpus() : Event("W") {}

Wumpus::~Wumpus() {
  // testing
}

void Wumpus::percept() {
  // percept
  cout << "\nYou smell a terrible stench...\n" << endl;
}
void Wumpus::encounter(Player &p) {
  // testing
  cout << "----------------------------------" << endl;
  cout << "\nYou encounter the Wumpus...\n" << endl;
  cout << "You have made a grave mistake..." << endl;
  cout << "         YOU ARE DEAD" << endl;
  p.isAlive = false;
  cout << "----------------------------------" << endl;
}

void Wumpus::performAction() {
  // test
}
void Wumpus::setType(const string someType) {
  // test
  type = someType;
}
string Wumpus::getType() {
  // testing
  return type;
}
