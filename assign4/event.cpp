#include "event.h"
#include <iostream>

using namespace std;

// Event Implementation

Event::Event() : type("") {}

Event::Event(const string type) : type(type) {}

Event::~Event() {}
