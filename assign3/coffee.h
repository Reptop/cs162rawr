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

  // destructor
  ~Coffee();

  void set_name(const string &);
  void set_small_cost(const float &);
  void set_medium_cost(const float &);
  void set_large_cost(const float &);
  string get_name() const;
  float get_small_cost() const;
  float get_medium_cost() const;
  float get_large_cost() const;
  void print_coffee() const; // print the coffee object
};

// assigment operator overload:
//   an existing object is assigned the value of another exising object:
//
//     //copy constructor is not being made here because we're not creating
//     another object
//
//     exisinng_dog_1 = existing_dog_2;
//
//     deep copies can be turned into shallow copies
//
//     redefine what the assigment operator does:
//
//      void operator=(const book&, other_book);
//
//

//      void book::operator=(const book&, other_book) {
//
//       // check if book is literally the exact same thing as the other book
//      if (this == &other_book) {
//       return;
//      }
//
//        if (pages != nullptr) {
//          delete [] pages;
//          pages = nullptr;
//        }
//
//        this->book = other_book.n_pages;
//        pages = new page[n_pages];
//
//        for (int i = 0; i < n pages; ++i) {
//          book[i] = other_book[i];
//        }
//      }
#endif
