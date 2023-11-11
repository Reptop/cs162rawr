#include "menu.h"
#include "coffee.h"
#include <fstream>
#include <iostream>

using namespace std;

// function defintions from menu.h goes here

// default constructor
Menu::Menu() : coffee_arr(nullptr) { cout << "Created Menu" << endl; }

// non-default contructor
Menu::Menu(int length) : coffee_arr(new Coffee[length]), num_coffee(0) {}

void Menu::load_data(ifstream &inFile) {
  inFile >> num_coffee;

  coffee_arr = new Coffee[num_coffee];

  for (int i = 0; i < num_coffee; ++i)
    coffee_arr[i].load_data(inFile);
}

Menu &Menu::operator=(const Menu &existing_menu) {
  cout << "Used assignment operator overload" << endl;

  // check if existing_menu is the same
  if (this == &existing_menu) {
    return *this;
  }

  // allocate new resources first
  Coffee *new_coffee_arr = new Coffee[existing_menu.num_coffee];

  for (int i = 0; i < existing_menu.num_coffee; ++i) {
    new_coffee_arr[i] = existing_menu.coffee_arr[i];
  }

  // delete old resources
  delete[] coffee_arr;
  coffee_arr = nullptr;

  // re-assign pointer and re-assign num_coffee
  coffee_arr = new_coffee_arr;
  num_coffee = existing_menu.num_coffee;

  // return the current object
  return *this;
}

Menu::Menu(const Menu &existing_menu)
    : num_coffee(existing_menu.num_coffee),
      coffee_arr(new Coffee[existing_menu.num_coffee]) {

  cout << "used copy contructor" << endl;
  for (int i = 0; i < num_coffee; ++i)
    coffee_arr[i] = existing_menu.coffee_arr[i];
}

Menu::~Menu() {
  if (coffee_arr != nullptr) {
    delete[] coffee_arr;
    cout << "destructor" << endl;
    coffee_arr = nullptr;
  }
}

void Menu::print_a_coffee(int index) {
  // testing
  coffee_arr[index].print_coffee();
}

void Menu::print_all_coffee() {
  cout << "---------------------------------" << endl;

  for (int i = 0; i < num_coffee; ++i) {
    cout << i + 1 << ". " << endl;
    coffee_arr[i].print_coffee();
  }

  cout << "---------------------------------" << endl;
}

void Menu::print_coffee_names() {
  for (int i = 0; i < num_coffee; ++i) {
    cout << i + 1 << ". " << coffee_arr[i].get_name() << endl;
  }
}

int Menu::inputScrubbing(string n) {
  if (n.length() > 1)
    return -1;
  if (n >= "0" && n <= to_string(num_coffee))
    return n[0] - '0';
  return -1;
}

Coffee Menu::search_coffee_by_name(string name, bool &found) {
  Coffee results;

  for (int i = 0; i < num_coffee; ++i) {
    if (coffee_arr[i].get_name() == name) {
      found = true;
      return coffee_arr[i];
    }
  }

  return results;
}

Menu Menu::search_coffee_by_price(float budget, bool &found) {
  Menu temp(this->num_coffee);
  int j = 0;

  for (int i = 0; i < num_coffee; ++i) {
    float small_cost = coffee_arr[i].get_small_cost();
    float medium_cost = coffee_arr[i].get_medium_cost();
    float large_cost = coffee_arr[i].get_large_cost();

    if (small_cost > budget && medium_cost > budget && large_cost > budget)
      continue;

    temp.coffee_arr[j].set_name(coffee_arr[i].get_name());

    if (small_cost <= budget) {
      temp.coffee_arr[j].set_small_cost(small_cost);
      found = true;
    }
    if (medium_cost <= budget)
      temp.coffee_arr[j].set_medium_cost(medium_cost);

    if (large_cost <= budget)
      temp.coffee_arr[j].set_large_cost(large_cost);

    // increment the counter for the number of coffees in the temp menu
    ++j;
  }

  // update the number of coffees in the temp menu after processing all items
  temp.num_coffee = j;

  return temp;
}

bool Menu::check_duplicates(const Coffee &newCoffee) {
  for (int i = 0; i < num_coffee; ++i) {
    if (newCoffee.get_name() == coffee_arr[i].get_name())
      return true;
  }
  return false;
}

void Menu::update_file() {
  ofstream outFile("menu.txt");

  outFile << num_coffee << endl;

  for (int i = 0; i < num_coffee; ++i) {
    outFile << coffee_arr[i].get_name() << " " << coffee_arr[i].get_small_cost()
            << " " << coffee_arr[i].get_medium_cost() << " "
            << coffee_arr[i].get_large_cost() << endl;
  }
}

// make the coffee const
void Menu::add_to_menu(const Coffee &coffee_to_add) {

  Coffee *new_array = new Coffee[num_coffee + 1];
  for (int i = 0; i < num_coffee; ++i) {
    new_array[i] = coffee_arr[i];
  }

  // deletes old array
  delete[] coffee_arr;

  // points to new array
  coffee_arr = new_array;

  ++num_coffee;
  coffee_arr[num_coffee - 1] = coffee_to_add;

  update_file();

  return;
}

void Menu::filtered_print() {
  for (int i = 0; i < num_coffee; ++i) {
    cout << "NAME: " << coffee_arr[i].get_name() << endl;
    if (coffee_arr[i].get_small_cost() != 0) {
      cout << "SMALL COST: " << coffee_arr[i].get_small_cost() << endl;
    }
    if (coffee_arr[i].get_medium_cost() != 0) {
      cout << "MEDIUM COST: " << coffee_arr[i].get_medium_cost() << endl;
    }
    if (coffee_arr[i].get_large_cost() != 0) {
      cout << "LARGE COST: " << coffee_arr[i].get_large_cost() << endl;
    }
    cout << "\n";
  }
}

void Menu::remove_from_menu(int index_of_coffee_on_menu) {
  Coffee *new_array = new Coffee[num_coffee - 1];

  // separate index for new array
  int j = 0;

  for (int i = 0; i < num_coffee; ++i) {
    if (i != index_of_coffee_on_menu) {
      new_array[j] = coffee_arr[i];
      ++j;
    }
  }

  delete[] coffee_arr;
  coffee_arr = new_array;
  --num_coffee;

  update_file();

  return;
}
