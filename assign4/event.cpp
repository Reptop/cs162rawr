#include "event.h"
#include <iostream>

using namespace std;

// Event Implementation

Event::Event() : type("") {}

Event::Event(const string type) : type(type) {}

bool Event::playAgain(Player &p) {

  char yn;

  while (true) {
    cout << "\n-----------------------------------------" << endl;
    cout << "      Would you like to play again?" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "Enter (y/n): ";
    cin >> yn;

    if (yn == 'Y' || yn == 'y')
      return true;
    else if (yn == 'N' || yn == 'n')
      return false;
    else
      cout << "\nEnter y or n\n" << endl;
  }
}

Event::~Event() {}
