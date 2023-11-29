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
  cout << "\n----------------------------------" << endl;
  cout << "You encounter the Wumpus..." << endl;
  cout << "          Uh oh..." << endl;
  cout << "----------------------------------" << endl;

  if (p.armorHealth > 0 && p.hasArmor) {
    --p.armorHealth;

    cout << "\n----------------------------------" << endl;
    cout << "WAIT, Your shiny armor saved you!" << endl;
    cout << "----------------------------------" << endl;

  } else if (p.armorHealth == 0 || !p.hasArmor) {
    cout << "\n----------------------------------" << endl;
    cout << " You have made a grave mistake..." << endl;
    cout << "         YOU ARE DEAD" << endl;
    cout << "----------------------------------" << endl;
    p.isAlive = false;
  }
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
