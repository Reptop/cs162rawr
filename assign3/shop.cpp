#include "shop.h"
#include "coffee.h"
#include <algorithm>
#include <cstdint>
#include <fstream>

using namespace std;

// function defintions from shop.h goes here

Shop::Shop() : order_arr(nullptr), revenue(0), num_orders(0) {}

Shop::Shop(ifstream &inFile)
    : m(0), revenue(0), order_arr(nullptr), num_orders(0) {
  int length;
  inFile.open("menu.txt");
  inFile >> length;

  // m = Menu(length);
}

void Shop::initArr(int length) {
  // testing
  order_arr = new Order[length];
}

Shop::~Shop() {
  // if not allocated, no need to delete
  if (order_arr != nullptr) {
    delete[] order_arr;
    order_arr = nullptr;
  }
}

void Shop::load_data(ifstream &inFile) {
  // reads from files to correctly populate coffee, menu, etc.
  // Your code goes here:

  inFile.open("shop_info.txt");

  getline(inFile, phone);
  getline(inFile, address);

  inFile.close();
  inFile.open("menu.txt");

  int length;

  inFile >> length;

  string name;
  float sCost;
  float mCost;
  float lCost;

  for (int i = 0; i < length; ++i) {
    inFile >> name >> sCost >> mCost >> lCost;
  }

  return;
}

void Shop::view_shop_detail() {
  // handle "View shop detail" option
  // print shop address, phone number, revenue, menu, and order
  // Your code goes here:

  cout << "\nADDRESS: " << address << endl;
  cout << "PHONE #: " << phone << endl;
  cout << "REVENUE: " << revenue << endl;

  // inFile.open("menu.txt");

  return;
}

void Shop::add_to_menu() {
  // handle "Add coffee to menu" option
  // Hint: call Menu::add_to_menu(Coffee& coffee_to_add);
  // Your code goes here:
  cout << "Shop::add_to_menu() not implemented..." << endl;

  return;
}

void Shop::remove_from_menu() {
  // handle "Remove coffee from menu" option
  // Hint: call Menu::remove_from_menu(int index_of_coffee_on_menu);
  // Your code goes here:
  cout << "Shop::remove_from_menu() not implemented..." << endl;

  return;
}

void Shop::search_by_name() {
  // handle "Search by coffee name" option
  // Hint: call Menu::search_coffee_by_name(string name);
  // Your code goes here:
  cout << "Shop::search_by_name() not implemented..." << endl;

  return;
}

void Shop::search_by_price() {
  // handle "Search by coffee price" option
  // Hint: call Menu::search_coffee_by_price(float budget);
  // Your code goes here:
  cout << "Shop::search_by_price() not implemented..." << endl;

  return;
}

void Shop::place_order() {
  // handle "Place order" option
  // Your code goes here:
  cout << "Shop::place_order() not implemented..." << endl;

  return;
}

Shop Shop::clone_shop() {
  // handle "Clone a shop" option
  // note: the purpose of this option is to test
  // your big three implementation
  Shop cloned_shop;

  cloned_shop = *this; // test AOO

  Shop cloned_shop2 = *this; // test CC

  cout << "Shop cloned successfully!" << endl;

  return cloned_shop;
}
