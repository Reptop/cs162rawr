#include "coffee.h"
#include <iostream>

using namespace std;

Coffee::Coffee() : small_cost(0), medium_cost(0), large_cost(0) {}

Coffee::Coffee(string name, float small_cost, float medium_cost,
               float large_cost)
    : name(name), small_cost(small_cost), medium_cost(medium_cost),
      large_cost(large_cost) {}

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

void Coffee::load_data(ifstream &inFile) {
  inFile >> name;
  inFile >> small_cost;
  inFile >> medium_cost;
  inFile >> large_cost;
}

float Coffee::get_valid_cost(const string &size) {
  string input;
  float cost;

  while (true) {
    cout << "Enter coffee's " << size << " cost: ";
    getline(cin, input);
    try {
      cost = stof(input);
      if (cost <= 0) {
        throw invalid_argument("Cost must be positive.");
      }

      // breaks out of the loop
      return cost;

    } catch (const invalid_argument &) {
      cout << "\nInvalid input. Please enter a valid number for the cost.\n"
           << endl;
    }
  }
}

void Coffee::print_coffee() const {
  // print everything
  cout << "NAME: " << name << endl;
  cout << "SMALL COST: " << small_cost << endl;
  cout << "MEDIUM COST: " << medium_cost << endl;
  cout << "LARGE COST: " << large_cost << endl;
  cout << "\n";
}
