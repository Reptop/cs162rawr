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
  cout << "\n----------------------------------" << endl;
  cout << "You encounter a stalactite...\n" << endl;
  cout << "The stalactite suddenly falls directly from above!" << endl;
  cout << "----------------------------------" << endl;

  if (success()) {
    cout << "\n----------------------------------" << endl;
    cout << "Luckily, you managed to dodge the stalactite safely!" << endl;
    cout << "----------------------------------" << endl;
  } else {

    if (p.armorHealth > 0 && p.hasArmor) {
      --p.armorHealth;

      cout << "\n----------------------------------" << endl;
      cout << "Luckily, Your shiny armor saved you!" << endl;
      cout << "----------------------------------" << endl;

    } else if (p.armorHealth == 0 || !p.hasArmor) {
      cout << "You fail to dodge the stalactite..." << endl;
      cout << "         YOU ARE DEAD" << endl;
      p.isAlive = false;
    }
  }
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
