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

  // BIG THREE
  Menu(const Menu &);
  Menu &operator=(const Menu &m);
  ~Menu();

  // Suggested functions:
  Coffee search_coffee_by_name(string, bool &);

  Menu search_coffee_by_price(float, bool &);

  // add a coffee object into the Menu
  void add_to_menu(const Coffee &);

  // remove a coffee object from the Menu
  void remove_from_menu(int);

  // feel free to add more member functions

  void print_a_coffee(int);

  void print_all_coffee();

  void load_data(ifstream &);

  int inputScrubbing(string);

  void update_file();

  bool check_duplicates(const Coffee &);

  void filtered_print();

  void print_coffee_names();
};

#endif
