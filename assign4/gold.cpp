#include "gold.h"

#include <iostream>

using namespace std;

// Gold Implementation

Gold::Gold() : Event("G") {}

Gold::~Gold() {
  // testing
}

void Gold::percept() {
  // testing
  cout << "Test" << endl;
}
void Gold::encounter() {
  cout << "\nYou found the Wumpus' Gold!\n" << endl;
  cout << "You picked up the Gold" << endl;
}

void Gold::performAction() {
  // test
}
void Gold::setType(const string someType) {
  // test
  type = someType;
}
string Gold::getType() { return type; }
