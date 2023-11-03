#include "coffee.h"
#include <iostream>

using namespace std;

Coffee::Coffee() : small_cost(0), medium_cost(0), large_cost(0) {}

Coffee::~Coffee() {}

// getters
string Coffee::get_name() const {
  // get coffee name
  return name;
}

float Coffee::get_small_cost() const {
  // get coffee small_cost
  return small_cost;
}

float Coffee::get_medium_cost() const {
  // get coffee medium_cost
  return medium_cost;
}

float Coffee::get_large_cost() const {
  // get coffee large_cost
  return large_cost;
}

// setters
void Coffee::set_name(const string &name) {
  // set the name of coffee;
  this->name = name;
}

void Coffee::set_small_cost(const float &small_cost) {
  // set small_cost of coffee;
  this->small_cost = small_cost;
}

void Coffee::set_medium_cost(const float &medium_cost) {
  // set medium_cost of coffee;
  this->medium_cost = medium_cost;
}

void Coffee::set_large_cost(const float &large_cost) {
  // set large_cost of coffee;
  this->large_cost = large_cost;
}

void Coffee::print_coffee() const {
  // print everything
  cout << "NAME: " << name << endl;
  cout << "SMALL_COST: " << small_cost << endl;
  cout << "MEDIUM_COST: " << medium_cost << endl;
  cout << "LARGE_COST: " << large_cost << endl;
  cout << "\n";
}
