/*********************************************************************
** Program Filename: shop.cpp
** Author: Raed Kabir
** Date: 11/12/2023
** Description: This file consists of all function defintions for shop.h
** Input: N/A
** Output: N/A
*********************************************************************/

#include "shop.h"
#include "coffee.h"
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

// function defintions from shop.h goes here

Shop::Shop() : order_arr(nullptr), revenue(0), num_orders(0) {
  cout << "Created Shop" << endl;
}

Shop::~Shop() {
  // if not allocated, no need to delete
  if (order_arr != nullptr) {
    delete[] order_arr;
    order_arr = nullptr;
  }
}

// Copy constructor
Shop::Shop(const Shop &existing_shop)
    : m(existing_shop.m), phone(existing_shop.phone),
      address(existing_shop.address), revenue(existing_shop.revenue),
      num_orders(existing_shop.num_orders) {

  // Allocate new memory for the order_arr only if there are orders.
  if (num_orders > 0) {
    order_arr = new Order[num_orders];
    for (int i = 0; i < num_orders; ++i) {
      order_arr[i] =
          existing_shop
              .order_arr[i]; // Assuming Order has a working copy constructor.
    }
  } else
    order_arr = nullptr;
}

Shop &Shop::operator=(const Shop &existing_shop) {
  if (this == &existing_shop)
    return *this;

  // calls the assignment operator overload for the menu
  m = existing_shop.m;
  phone = existing_shop.phone;
  address = existing_shop.address;
  revenue = existing_shop.revenue;

  if (order_arr != nullptr)
    delete[] order_arr;

  num_orders = existing_shop.num_orders;

  if (num_orders > 0) {
    order_arr = new Order[num_orders];

    for (int i = 0; i < num_orders; ++i)
      order_arr[i] = existing_shop.order_arr[i];

  } else
    order_arr = nullptr;

  return *this;
}

void Shop::load_data(ifstream &shop_info, ifstream &menu_info) {
  getline(shop_info, phone);
  getline(shop_info, address);

  m.load_data(menu_info);
}

void Shop::view_shop_detail() {
  cout << "\nADDRESS: " << address << endl;
  cout << "PHONE #: " << phone << endl;
  cout << "REVENUE: " << revenue << endl;

  cout << "\nMenu: " << endl;

  m.print_all_coffee();

  cout << "Order info: " << endl;
  if (order_arr == nullptr)
    cout << "\nNo orders to display" << endl;

  else {
    for (int i = 0; i < num_orders; ++i) {
      cout << order_arr[i].get_id() << " " << order_arr[i].get_coffee_name()
           << " " << order_arr[i].get_coffee_size() << " "
           << order_arr[i].get_quantity() << endl;
    }
  }

  return;
}

void Shop::add_to_menu() {
  Coffee newCoffee;
  string name;
  float small_cost;
  float medium_cost;
  float large_cost;

  cout << "Enter coffee's name: ";
  getline(cin, name);
  newCoffee.set_name(name);

  small_cost = newCoffee.get_valid_cost("small");
  newCoffee.set_small_cost(small_cost);

  medium_cost = newCoffee.get_valid_cost("medium");
  newCoffee.set_medium_cost(medium_cost);

  large_cost = newCoffee.get_valid_cost("large");
  newCoffee.set_large_cost(large_cost);

  // check for duplicates first, then add to the array
  if (m.check_duplicates(newCoffee)) {
    cout << "\n  Coffee already added\n" << endl;
    return;

  } else {
    m.add_to_menu(newCoffee);
    cout << "\nCoffee Added!\n";
  }

  return;
}

void Shop::remove_from_menu() {
  string rawInput;
  int clean;
  m.print_all_coffee();

  while (true) {
    cout << "\nEnter a number to choose a drink: ";
    cin >> rawInput;
    clean = m.inputScrubbing(rawInput);

    if (clean == -1) {
      cout << "\nInvalid input. Enter a number.\n" << endl;
    } else {
      m.remove_from_menu(clean - 1);
      break;
    }
  }

  cout << "\nCoffee Removed.\n" << endl;

  // clear buffer
  cin.clear();
  cin.ignore(10000, '\n');

  return;
}

void Shop::search_by_name() {
  string name;
  bool found = false;
  cout << "Enter coffee name: ";
  getline(cin, name);

  Coffee results = m.search_coffee_by_name(name, found);

  if (found) {
    cout << "---------------------------------" << endl;

    cout << "\nResults: " << endl;
    results.print_coffee();

    cout << "---------------------------------" << endl;
  } else
    // prompt user
    cout << "\nCoffee not found!\n";

  return;
}

void Shop::search_by_price() {
  bool found = false;
  string rawBudget;
  float budget;

  while (true) {
    cout << "Enter your budget: ";
    getline(cin, rawBudget);
    try {
      budget = stof(rawBudget);
      if (budget <= 0)
        throw invalid_argument("Budget must be positive");
      break;
    } catch (const invalid_argument &) {
      cout << "\nInvalid input. Please enter a valid number for your budget.\n"
           << endl;
    }
  }

  Menu temp;
  // uses assignment operator overload
  temp = m.search_coffee_by_price(budget, found);

  if (!found) {
    cout << "\nNo coffee found\n" << endl;
  }

  else {
    cout << "Results: " << endl;
    temp.filtered_print();
  }

  return;
}

void Shop::place_order() {
  string rawInput;
  int input;
  char size;
  int quantity;
  float revenue;

  while (true) {
    m.print_coffee_names();
    cout << "\nWhich drinks above would you like to order?" << endl;
    cout << "Enter a number that corresponds to your choice: ";
    getline(cin, rawInput);

    input = m.inputScrubbing(rawInput);
    if (input == -1 || input == 0)
      cout << "\nInvalid input. Enter a number.\n" << endl;
    else
      break;
  }

  process_order(input, size, quantity, revenue);

  cout << "\nPlaced Order!\n" << endl;
  return;
}

void Shop::process_order(int &input, char &size, int &quantity,
                         float &revenue) {
  string name;
  Order newOrder;

  cout << '\n';
  m.print_a_coffee(input - 1);
  name = m.get_name_from_index(input - 1);
  size = process_size();
  quantity = process_quantity();
  revenue = m.process_cost(input - 1, size, quantity);

  this->revenue += revenue;

  newOrder.set_id(num_orders + 1);
  newOrder.set_quantity(quantity);
  newOrder.set_coffee_name(name);
  newOrder.set_coffee_size(size);

  add_to_order_arr(newOrder);
}

void Shop::add_to_order_arr(const Order &newOrder) {

  Order *new_array = new Order[num_orders + 1];
  for (int i = 0; i < num_orders; ++i) {
    new_array[i] = order_arr[i];
  }

  // deletes old array
  delete[] order_arr;

  // points to new array
  order_arr = new_array;

  ++num_orders;
  order_arr[num_orders - 1] = newOrder;

  update_order_file();

  return;
}

void Shop::update_order_file() {
  ofstream outFile("orders.txt");

  if (outFile.fail()) {
    cout << "\nCould not open order.txt file!\n" << endl;
    return;
  }

  for (int i = 0; i < num_orders; ++i) {
    outFile << order_arr[i].get_id() << " " << order_arr[i].get_coffee_name()
            << " " << order_arr[i].get_coffee_size() << " "
            << order_arr[i].get_quantity() << endl;
  }
}

int Shop::process_quantity() {
  string input;
  int quantity;

  while (true) {
    cout << "\nEnter quantity: ";
    getline(cin, input);
    try {
      quantity = stoi(input);
      if (quantity <= 0)
        throw invalid_argument("Cost must be positive.");

      // breaks out of the loop
      return quantity;

    } catch (const invalid_argument &) {
      cout << "\nInvalid input. Please enter a valid number for the quantity.\n"
           << endl;
    }
  }
}

char Shop::process_size() {
  char size;

  while (true) {
    cout << "\nEnter the size: s-small, m-medium, l-large: ";
    cin >> size;

    if (size == 's' || size == 'm' || size == 'l')
      break;
    else {
      cout << "\nInvalid input. Enter s(small), m(medium), or l(large)" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
  }

  cin.clear();
  cin.ignore(10000, '\n');
  return size;
}

void Shop::stats() {
  int input = 0;

  if (order_arr == nullptr) {
    cout << "\nOrder array is empty! Cannot view stats.\n" << endl;
    return;
  }

  while (true) {
    string name = "Drink does not exist";

    cout << "Which statistics would you like to see?\n" << endl;
    cout << "1. Best seller of a specific size." << endl;
    cout << "2. Drink that makes the most revenue of all sizes combined."
         << endl;
    cout << "3. Return to command menu" << endl;

    cout << '\n';
    cout << "Enter a number that corresponds to your choice: ";
    cin >> input;

    if (input == 3) {
      cin.ignore(100000, '\n');
      cin.clear();
      break;
    }

    switch (input) {
    case 1:
      best_seller_size();
      break;

    case 2:
      // stuff
      break;

    default:
      cout << "\nInvalid input. Enter 1 or 2\n" << endl;
      cin.clear();
      cin.ignore(100000, '\n');
      break;
    }
  }
}

void Shop::best_seller_size() {
  char n;
  cout << "Which size would you like to check?" << endl;
  cout << "Enter size (s/m/l): ";
  cin >> n;

  if (n != 's' && n != 'm' && n != 'l') {
    cout << "Invalid input! Enter a valid size" << endl;
    return;
  }

  string name;
  int maxQuantity = 0;

  for (int i = 0; i < num_orders; ++i) {
    if (order_arr[i].get_coffee_size() == n) {
      int quantity = order_arr[i].get_quantity();
      if (quantity > maxQuantity) {
        maxQuantity = quantity;
        name = order_arr[i].get_coffee_name();
      }
    }
  }

  if (maxQuantity > 0)
    cout << "\nBest seller of " << n << " size is: " << name << endl;
  else
    cout << "\nNo orders found for size " << n << endl;
}

Shop Shop::clone_shop() {
  Shop cloned_shop;

  cloned_shop = *this; // test AOO

  Shop cloned_shop2 = *this; // test CC

  cout << "Shop cloned successfully!" << endl;

  return cloned_shop;
}
