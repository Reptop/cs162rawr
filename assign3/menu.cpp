#include "menu.h"

using namespace std;

// function defintions from menu.h goes here

Coffee Menu::search_coffee_by_name(string name) {
  Coffee found;
  // search coffee with a specific name
  // return the coffee if found
  // Your code goes here:

  return found;
}

Menu Menu::search_coffee_by_price(float budget) {
  Menu temp;
  // search coffee with a specific budget
  // return all coffee that is under the budget
  // Hint: Since a Menu object contains an array of coffee
  //       You may return a Menu object that contains all valid coffees
  // Your code goes here:

  return temp;
}

void Menu::add_to_menu(Coffee &coffee_to_add) {
  // add a coffee object into the Menu
  // Your code goes here:

  return;
}

void Menu::remove_from_menu(int index_of_coffee_on_menu) {
  // remove a coffee object from the Menu
  // Your code goes here:

  return;
}
