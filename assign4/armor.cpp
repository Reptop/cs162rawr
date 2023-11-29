#include "armor.h"
#include "player.h"

#include <iostream>

using namespace std;

// Wumpus Implementation

Armor::Armor() : Event("A") {}

Armor::~Armor() {
  // testing
}

void Armor::percept() {
  // percept
  cout << "\nYou feel the power...\n" << endl;
}

void Armor::encounter(Player &p) {
  // encounter
  cout << "\n----------------------------------" << endl;
  cout << "You find a POWERFUL piece of armor...\n" << endl;
  cout << "This armor will protect you from 2 fatal encounters..." << endl;
  cout << "----------------------------------" << endl;

  p.hasArmor = true;
}

void Armor::performAction() {
  // test
}
void Armor::setType(const string someType) {
  // test
  type = someType;
}
string Armor::getType() {
  // testing
  return type;
}
