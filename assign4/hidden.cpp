#include "hidden.h"
#include <iostream>

using namespace std;

// Hidden Implementation

Hidden::Hidden() : Event("H") {}

Hidden::~Hidden() {}

void Hidden::percept() {}

void Hidden::encounter(Player &p) {}

void Hidden::performAction() {}

void Hidden::setType(const string someType) {
  // test
  type = someType;
}
string Hidden::getType() {
  // testing
  return type;
}
