#include "bats.h"

#include <iostream>

using namespace std;

// Bats Implementation

Bat::Bat() : Event("B") {}

Bat::~Bat() {
  // testing
}

void Bat::percept() {
  // testing
  cout << "Test" << endl;
}
void Bat::encounter() { cout << "Bat Encounter Testing" << endl; }

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
