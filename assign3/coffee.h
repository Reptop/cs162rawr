#ifndef COFFEE_H
#define COFFEE_H

#include <fstream>
#include <string>

using namespace std;

class Coffee {
private:
  string name;
  float small_cost;
  float medium_cost;
  float large_cost;

public:
  /*********************************************************************
   ** Function: Coffee()
   ** Description: Default constructor
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee is declared with default values
   *********************************************************************/
  Coffee();

  /*********************************************************************
   ** Function: Coffee()
   ** Description: Default constructor
   ** Parameters: string, float, float, float
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee is declared with supplied values
   *********************************************************************/
  Coffee(string, float, float, float);

  /*********************************************************************
   ** Function: ~Coffee()
   ** Description: destructor
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee is deleted when out of scope
   *********************************************************************/
  ~Coffee();

  /*********************************************************************
   ** Function: set_name()
   ** Description: setter for Coffee name
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee name fields is set to supplied name
   *********************************************************************/
  void set_name(const string &);

  /*********************************************************************
   ** Function: set_small_cost()
   ** Description: setter for Coffee small_cost
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee small_cost fields is set to supplied small_cost
   *********************************************************************/
  void set_small_cost(const float &);

  /*********************************************************************
   ** Function: set_medium_cost()
   ** Description: setter for Coffee medium_cost
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee medium_cost fields is set to supplied medium_cost
   *********************************************************************/
  void set_medium_cost(const float &);

  /*********************************************************************
   ** Function: set_large_cost()
   ** Description: setter for Coffee large_cost
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee large_cost fields is set to supplied large_cost
   *********************************************************************/
  void set_large_cost(const float &);

  /*********************************************************************
   ** Function: get_name()
   ** Description: getter for Coffee name
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee name is returned
   *********************************************************************/
  string get_name() const;

  /*********************************************************************
   ** Function: get_small_cost()
   ** Description: getter for Coffee small_cost
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee small_cost is returned
   *********************************************************************/
  float get_small_cost() const;

  /*********************************************************************
   ** Function: get_medium_cost()
   ** Description: getter for Coffee small_cost
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee medium_cost is returned
   *********************************************************************/
  float get_medium_cost() const;

  /*********************************************************************
   ** Function: get_large_cost()
   ** Description: getter for Coffee small_cost
   ** Parameters: N/A
   ** Pre-Conditions: Coffee needs to be declared
   ** Post-Conditions: Coffee large_cost is returned
   *********************************************************************/
  float get_large_cost() const;

  // self-made functions

  /*********************************************************************
   ** Function: load_data()
   ** Description: loads menu.txt
   ** Parameters: ifstream object
   ** Pre-Conditions: textfile exists
   ** Post-Conditions: coffee information is streamed into each coffee
   *********************************************************************/
  void load_data(ifstream &);

  /*********************************************************************
   ** Function: get_valid_cost()
   ** Description: returns a float that is a valid cost for a new coffee
   ** Parameters: string object specifying size
   ** Pre-Conditions: user wants to create a new price a for a new coffee
   ** Post-Conditions: returns a float that is a valid coffee cost
   *********************************************************************/
  float get_valid_cost(const string &);

  /*********************************************************************
   ** Function: print_coffee()
   ** Description: prints all fields of a coffee
   ** Parameters: N/A
   ** Pre-Conditions: coffee is declared with non default fields
   ** Post-Conditions: returns a float that is a valid coffee cost
   *********************************************************************/
  void print_coffee() const;
};
#endif
