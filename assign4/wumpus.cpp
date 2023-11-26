#include "wumpus.h"

#include <iostream>

using namespace std;

// Wumpus Implementation

Wumpus::Wumpus() : Event("W") {}

Wumpus::~Wumpus() {
  // testing
}

void Wumpus::percept() {
  // testing
  cout << "Test" << endl;
}
void Wumpus::encounter() {
  // testing
  cout << "Wumpus Encounter Testing" << endl;
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
