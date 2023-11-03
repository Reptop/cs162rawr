#ifndef MENU_H
#define MENU_H

#include "coffee.h"
#include <fstream>
#include <string>

using namespace std;

class Menu {
private:
  int num_coffee;
  Coffee *coffee_arr;

public:
  // need to include accessor functions and mutator functions for private member
  // when appropriate need to include constructors, copy constructors,
  // assignment operator overload, and destructors where appropriate need to use
  // 'const' when appropriate

  // default constructor
  Menu();

  // non-default constructor
  Menu(int);

  // destructor
  ~Menu();

  // Suggested functions:
  Coffee search_coffee_by_name(string name);

  Menu search_coffee_by_price(float budget);

  // add a coffee object into the Menu
  void add_to_menu(Coffee &coffee_to_add);

  // remove a coffee object from the Menu
  void remove_from_menu(int index_of_coffee_on_menu);

  // feel free to add more member functions

  void populateMenu();
};

#endif
