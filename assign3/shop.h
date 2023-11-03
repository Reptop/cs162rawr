#ifndef SHOP_H
#define SHOP_H

#include "menu.h"
#include "order.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Shop {
private:
  Menu m;
  string phone;
  string address;
  float revenue;    // shop revenue
  Order *order_arr; // order array
  int num_orders;   // number or orders

public:
  // need to include accessor functions and mutator functions for private member
  // when appropriate need to include constructors and destructors where
  // appropriate need to use 'const' when appropriate

  // default constructor
  Shop();

  // non default constructor
  Shop(ifstream &);

  // destructor
  ~Shop();

  // getters

  // Suggested functions

  // reads from files to correctly populate coffee, menu, etc.
  void load_data(ifstream &);
  void view_shop_detail();
  void add_to_menu();
  void remove_from_menu();
  void search_by_name();
  void search_by_price();
  void place_order();
  Shop clone_shop();
};

#endif
