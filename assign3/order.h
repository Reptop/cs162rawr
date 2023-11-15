#ifndef ORDER_H
#define ORDER_H
#include <string>

using namespace std;

class Order {
private:
  int id;
  string coffee_name;
  char coffee_size;

  int quantity;

public:
  /*********************************************************************
   ** Function: Order()
   ** Description: Default constructor
   ** Parameters: N/A
   ** Pre-Conditions: Order needs to be declared
   ** Post-Conditions: Order is declared with default values
   *********************************************************************/
  Order();

  /*********************************************************************
   ** Function: ~Order()
   ** Description: destructor
   ** Parameters: N/A
   ** Pre-Conditions: Order needs to be declared
   ** Post-Conditions: Order is deleted when out of scope
   *********************************************************************/
  ~Order();

  // getters
  /*********************************************************************
   ** Function: get_id()
   ** Description: getter for order id
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: order name is returned
   *********************************************************************/
  int get_id() const;

  /*********************************************************************
   ** Function: get_coffee_name()
   ** Description: getter for coffee_name
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: coffee_name name is returned
   *********************************************************************/
  string get_coffee_name() const;

  /*********************************************************************
   ** Function: get_coffee_size()
   ** Description: getter for coffee_size
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: coffee_size is returned
   *********************************************************************/
  char get_coffee_size() const;

  /*********************************************************************
   ** Function: get_quantity()
   ** Description: getter for coffee_quantity
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: coffee_quantity is returned
   *********************************************************************/
  int get_quantity() const;

  /*********************************************************************
   ** Function: set_id()
   ** Description: setter for coffee_quantity
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: order_id is set
   *********************************************************************/
  void set_id(const int);

  /*********************************************************************
   ** Function: set_coffee_name()
   ** Description: setter for coffee_name
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: coffee_name is set
   *********************************************************************/
  void set_coffee_name(const string);

  /*********************************************************************
   ** Function: set_coffee_size()
   ** Description: setter for coffee_size
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: coffee_size is set
   *********************************************************************/
  void set_coffee_size(const char);

  /*********************************************************************
   ** Function: set_coffee_quantity()
   ** Description: setter for coffee_quantity
   ** Parameters: N/A
   ** Pre-Conditions: order needs to be declared
   ** Post-Conditions: coffee_quantity is set
   *********************************************************************/
  void set_quantity(const int);
};
#endif
