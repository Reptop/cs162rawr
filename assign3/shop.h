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
  /*********************************************************************
   ** Function: Shop()
   ** Description: Default constructor
   ** Parameters: N/A
   ** Pre-Conditions: Shop needs to be declared
   ** Post-Conditions: Shop is declared with default values
   *********************************************************************/
  Shop();

  /*********************************************************************
   ** Function: Shop()
   ** Description: non-default constructor
   ** Parameters: N/A
   ** Pre-Conditions: Shop needs to be declared
   ** Post-Conditions: Shop is declared with values streamed from a text file
   *********************************************************************/
  Shop(ifstream &, int &);

  /*********************************************************************
   ** Function: Shop()
   ** Description: copy constructor
   ** Parameters: shop object
   ** Pre-Conditions: Shop needs to be declared with non-default values
   ** Post-Conditions: A new shop is created with copied values from other shops
   *********************************************************************/
  Shop(const Shop &);

  /*********************************************************************
   ** Function: Shop() &operator
   ** Description: assignment operator overload
   ** Parameters: shop object
   ** Pre-Conditions: Two pre-existing shops need to be declared
   ** Post-Conditions: a shop receives copied values from other shops
   *********************************************************************/
  Shop &operator=(const Shop &s);

  /*********************************************************************
   ** Function: ~Shop()
   ** Description: destructor
   ** Parameters: N/A
   ** Pre-Conditions: A shop objects needs to be out of scope
   ** Post-Conditions: Shop's dynamic arrays are to be deleted from heap
   *********************************************************************/
  ~Shop();

  /*********************************************************************
   ** Function: load_data()
   ** Description: reads information from text files
   ** Parameters: two ifstream objects
   ** Pre-Conditions: A shop objects needs to be out of scope
   ** Post-Conditions: loads data into specific fields in Shop
   *********************************************************************/
  void load_data(ifstream &, ifstream &);

  /*********************************************************************
   ** Function: view_shop_detail()
   ** Description: prints shop information to terminal
   ** Parameters: N/A
   ** Pre-Conditions: user asks to see shop information
   ** Post-Conditions: prints shop address and phone number
   *********************************************************************/
  void view_shop_detail();

  /*********************************************************************
   ** Function: add_to_menu()
   ** Description: adds a coffee object to a dynamic array
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information about a new coffee
   ** Post-Conditions: new coffee is added to coffee_arr
   *********************************************************************/
  void add_to_menu();

  /*********************************************************************
   ** Function: remove_from_menu()
   ** Description: removes a coffee object from a dynamic array
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information on what coffee to remove
   ** Post-Conditions: coffee is removed from coffee_arr
   *********************************************************************/
  void remove_from_menu();

  /*********************************************************************
   ** Function: search_by_name()
   ** Description: searches coffee by name supplied by user
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information on what coffee search for
   ** Post-Conditions: coffee is searched; if found, print to terminal
   *********************************************************************/
  void search_by_name();

  /*********************************************************************
   ** Function: search_by_price()
   ** Description: searches coffee by name supplied by user;
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information on what coffee search for
   ** Post-Conditions: coffee is searched; if found, print to terminal
   *********************************************************************/
  void search_by_price();

  /*********************************************************************
   ** Function: place_order()
   ** Description: places coffee order
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information on their order
   ** Post-Conditions: add order to order dynamic array
   *********************************************************************/
  void place_order();

  /*********************************************************************
   ** Function: process_order()
   ** Description: processes and computes order supplied by user
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information on their order
   ** Post-Conditions: adds order to coffee array
   *********************************************************************/
  void process_order(int &, char &, int &, float &);

  /*********************************************************************
   ** Function: update_order_file()
   ** Description: processes and computes order supplied by user
   ** Parameters: N/A
   ** Pre-Conditions: user supplies all information on their order
   ** Post-Conditions: prints order to orders.txt
   *********************************************************************/
  void update_order_file();

  /*********************************************************************
   ** Function: process_size()
   ** Description: processes and computes size supplied by user
   ** Parameters: N/A
   ** Pre-Conditions: user supplies a valid size
   ** Post-Conditions: sets size field of new order to s, m, l
   *********************************************************************/
  char process_size();

  /*********************************************************************
   ** Function: process_quantity()
   ** Description: processes the order quantity from user
   ** Parameters: N/A
   ** Pre-Conditions: user supplies a valid number for quantity
   ** Post-Conditions: sets size field of a new order object to provided
   *quantity
   *********************************************************************/
  int process_quantity();

  /*********************************************************************
   ** Function: clone_shop()
   ** Description: tests AOO and CO
   ** Parameters: N/A
   ** Pre-Conditions: A shop must be declared
   ** Post-Conditions: Clones a shop object
   *********************************************************************/
  Shop clone_shop();

  /*********************************************************************
   ** Function: stats()
   ** Description: to display stats about coffee sales
   ** Parameters: N/A
   ** Pre-Conditions: A shop must be declared with populated fields
   ** Post-Conditions: ouptputs specific statistics to terminal
   *********************************************************************/
  void stats();

  /*********************************************************************
   ** Function: add_to_order_arr()
   ** Description: Adds a order to the order dynamic array
   ** Parameters: N/A
   ** Pre-Conditions: User must have supplied the order information
   ** Post-Conditions: adds new order to dynamic array
   *********************************************************************/
  void add_to_order_arr(const Order &);

  /*********************************************************************
   ** Function: best_seller_size()
   ** Description: Finds best seller of specific size
   ** Parameters: N/A
   ** Pre-Conditions: coffee arr must be populated
   ** Post-Conditions: prints best seller of a specific size to terminal
   *********************************************************************/
  void best_seller_size();

  /*********************************************************************
   ** Function: best_revenue_coffee()
   ** Description: Finds best seller of all sizes
   ** Parameters: N/A
   ** Pre-Conditions: coffee arr must be populated
   ** Post-Conditions: prints best seller of a all sizes to terminal
   *********************************************************************/
  void best_revenue_coffee();
};

#endif
