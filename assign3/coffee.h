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
  // need to include accessor functions and mutator functions for private member
  // when appropriate need to include constructors and destructors where
  // appropriate need to use 'const' when appropriate

  // default constructor
  Coffee();

  Coffee(string, float, float, float);

  // destructor
  ~Coffee();

  // setters
  void set_name(const string &);
  void set_small_cost(const float &);
  void set_medium_cost(const float &);
  void set_large_cost(const float &);

  // getters
  string get_name() const;
  float get_small_cost() const;
  float get_medium_cost() const;
  float get_large_cost() const;

  // self-made functions
  void load_data(ifstream &);
  float get_valid_cost(const string &);
  void print_coffee() const; // print the coffee object
};
#endif
