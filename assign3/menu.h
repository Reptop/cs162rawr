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
  /*********************************************************************
   ** Function: Menu()
   ** Description: Default constructor
   ** Parameters: N/A
   ** Pre-Conditions: Menu needs to be declared
   ** Post-Conditions: Menu is declared with default values
   *********************************************************************/
  Menu();

  /*********************************************************************
   ** Function: Menu(int)
   ** Description: Non-Default constructor
   ** Parameters: int for coffee_arr size
   ** Pre-Conditions: Menu needs a valid size for its array
   ** Post-Conditions: Menu is declared with Non-Default values
   *********************************************************************/
  Menu(int);

  // BIG THREE
  /*********************************************************************
   ** Function: Menu(const Menu&)
   ** Description: Copy constructor
   ** Parameters: Menu object
   ** Pre-Conditions: Another menu object needs to initilized
   ** Post-Conditions: A new menu object is made with copied values
   *********************************************************************/
  Menu(const Menu &);

  /*********************************************************************
   ** Function: Menu operator=()
   ** Description: Assignment operator overload
   ** Parameters: Copies information fron another pre-existing Menu object
   ** Pre-Conditions: Another menu object needs to initilized
   ** Post-Conditions: A pre-existing menu object is made with copied values
   *********************************************************************/
  Menu &operator=(const Menu &m);

  /*********************************************************************
   ** Function: ~Menu()
   ** Description: Destructor
   ** Parameters: N/A
   ** Pre-Conditions: Menu object needs to be declared
   ** Post-Conditions: Menu object is deleted when out of scope
   *********************************************************************/
  ~Menu();

  /*********************************************************************
   ** Function: search_coffee_by_name()
   ** Description: searches coffee by name
   ** Parameters: string, bool reference
   ** Pre-Conditions: Coffee must be initilized with Non-Default values
   ** Post-Conditions: if found; coffee details are printed to terminal
   *********************************************************************/
  Coffee search_coffee_by_name(string, bool &);

  /*********************************************************************
   ** Function: search_coffee_by_price()
   ** Description: searches coffee by name supplied by user
   ** Parameters: float, bool reference
   ** Pre-Conditions: user supplies all informatn what coffee search
   ** Post-Conditions: price is searched; if found, prints coffees
   *********************************************************************/
  Menu search_coffee_by_price(float, bool &);

  /*********************************************************************
   ** Function: add_to_menu()
   ** Description: adds coffee to menu object
   ** Parameters: const coffee object
   ** Pre-Conditions: user supplies all information for coffee to add
   ** Post-Conditions: coffee is added to dynamic array
   *********************************************************************/
  void add_to_menu(const Coffee &);

  /*********************************************************************
   ** Function: remove_from_menu()
   ** Description: removes coffee from menu given coffee index
   ** Parameters: int index
   ** Pre-Conditions: User supplies valid index
   ** Post-Conditions: coffee is removed from dynamic array
   *********************************************************************/
  void remove_from_menu(int);

  /*********************************************************************
   ** Function: print_a_coffee()
   ** Description: prints coffee from menu given coffee index
   ** Parameters: int index
   ** Pre-Conditions: User supplies valid index
   ** Post-Conditions: coffee is printed from dynamic array
   *********************************************************************/
  void print_a_coffee(int);

  /*********************************************************************
   ** Function: print_all_coffee()
   ** Description: prints all coffee from menu
   ** Parameters: N/A
   ** Pre-Conditions: User selects to see menu info
   ** Post-Conditions: prints all coffee's to terminal
   *********************************************************************/
  void print_all_coffee();

  /*********************************************************************
   ** Function: load_data()
   ** Description: loads data for all coffee
   ** Parameters: ifstream object
   ** Pre-Conditions: coffee_arr must be initilized to some value
   ** Post-Conditions: loads all coffee information into coffee array
   *********************************************************************/
  void load_data(ifstream &);

  /*********************************************************************
   ** Function: inputScrubbing()
   ** Description: checks for type errors
   ** Parameters: string input
   ** Pre-Conditions: user inputs a string
   ** Post-Conditions: string is converted to an int
   *********************************************************************/
  int inputScrubbing(string);

  /*********************************************************************
   ** function: update_file()
   ** description: updates menu and order text files
   ** parameters: n/a
   ** pre-conditions: user adds/removes a new item or orders
   ** post-conditions: string is converted to an int
   *********************************************************************/
  void update_file();

  /*********************************************************************
   ** function: check_duplicates()
   ** description: checks if there is a duplicate item being added
   ** parameters: N/A
   ** pre-conditions: user adds a new coffee object
   ** post-conditions: prompts user that their added item is a duplicate
   *********************************************************************/
  bool check_duplicates(const Coffee &);

  /*********************************************************************
   ** function: filtered_print()
   ** description: prints out filtered list of coffee's under budget
   ** parameters: N/A
   ** pre-conditions: user requests to sort by budget
   ** post-conditions: prints out filtered list given bugdet
   *********************************************************************/
  void filtered_print();

  /*********************************************************************
   ** function: print_coffee_names()
   ** description: prints only a coffee name
   ** parameters: N/A
   ** pre-conditions: user requests to order
   ** post-conditions: prints a list of coffee names
   *********************************************************************/
  void print_coffee_names();

  /*********************************************************************
   ** function: process_cost()
   ** description: checks for max cost given a size
   ** parameters: int, char, int
   ** pre-conditions: user requests to see statistics
   ** post-conditions: prints out the best selling coffee of a specific size
   *********************************************************************/
  float process_cost(int, char, int);

  /*********************************************************************
   ** function: get_name_from_index()
   ** description: gets coffee_name given an index
   ** parameters: int index
   ** pre-conditions: user supplies an index
   ** post-conditions: prompts user that their added item is a duplicate
   *********************************************************************/
  string get_name_from_index(int);
};

#endif
