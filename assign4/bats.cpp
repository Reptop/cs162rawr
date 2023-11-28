#include "bats.h"
#include "player.h"

#include <iostream>

using namespace std;

// Bats Implementation

Bat::Bat() : Event("B") {}

Bat::~Bat() {
  // testing
}

void Bat::percept() {
  // percept
  cout << "\nYou hear wings flapping...\n" << endl;
}

void Bat::encounter(Player &p) {
  // encounter
  cout << "\n----------------------------------" << endl;
  cout << "You encountered SUPER BATS!" << endl;
  cout << "The bats used confuse ray on you..." << endl;
  cout << "Your movement is now INVERTED for the next 5 moves..." << endl;
  cout << "----------------------------------" << endl;

  p.isConfused = true;
}

void Bat::performAction() {
  // test
}
void Bat::setType(const string someType) {
  // testing
  type = someType;
}
string Bat::getType() {
  // testing
  return type;
}
