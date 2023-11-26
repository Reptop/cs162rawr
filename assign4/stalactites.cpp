#include "stalactites.h"

#include <iostream>

using namespace std;

// Stalactites Implementation

Stalactite::Stalactite() : Event("S") {}

Stalactite::~Stalactite() {
  // testing
}

void Stalactite::percept() {
  // percept
}
void Stalactite::encounter() {
  // test
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
