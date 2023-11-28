#include "stalactites.h"
#include "player.h"

#include <iostream>

using namespace std;

// Stalactites Implementation

Stalactite::Stalactite() : Event("S") {}

Stalactite::~Stalactite() {
  // testing
}

void Stalactite::percept() {
  // percept
  cout << "\nYou hear water dripping...\n" << endl;
}

bool Stalactite::success() {
  if (rand() % 2 == 0)
    return false;
  else
    return true;
}

void Stalactite::encounter(Player &p) {
  cout << "----------------------------------" << endl;
  cout << "\nYou encounter a stalactite...\n" << endl;
  cout << "The stalactite suddenly falls directly from above!" << endl;
  if (success())
    cout << "Luckily, you managed to dodge the stalactite safely!" << endl;
  else {
    cout << "You fail to dodge the stalactite..." << endl;
    cout << "         YOU ARE DEAD" << endl;
    p.isAlive = false;
  }
  cout << "----------------------------------" << endl;
}

void Stalactite::performAction() {
  // test
}
void Stalactite::setType(const string typeSet) {
  // testing
  type = typeSet;
}
string Stalactite::getType() {
  // testing
  return type;
}
