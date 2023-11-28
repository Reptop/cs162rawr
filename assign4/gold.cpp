#include "gold.h"
#include "player.h"

#include <iostream>

using namespace std;

// Gold Implementation

Gold::Gold() : Event("G") {}

Gold::~Gold() {
  // testing
}

void Gold::percept() {
  // testing
  cout << "\nYou see a glimmer nearby...\n" << endl;
}
void Gold::encounter(Player &p) {
  cout << "\n---------------------------------" << endl;
  cout << "You found the Wumpus' Gold!" << endl;
  cout << "You picked up the Gold" << endl;
  cout << "---------------------------------" << endl;
}

void Gold::performAction() {
  // test
}

void Gold::setType(const string someType) {
  // test
  type = someType;
}

string Gold::getType() {
  // returns string
  return type;
}
