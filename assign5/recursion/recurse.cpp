/******************************************************
** Program: recurse.cpp
** Author: Raed Kabir
** Date: 6/10/2023
** Description: Contains testing procedure for stairs problem
** Input: N/A
** Output: Total number of ways to traverse stair of N size
******************************************************/

// The following is an example program that
// does some basic, limited testing of your
// ways_to_top() implementation.

#include "stairs.h"
#include <iostream>

using namespace std;

int main() {
  cout << ways_to_top(3) << endl; // Should print 4
  cout << ways_to_top(4) << endl; // Should print 7
  cout << ways_to_top(5) << endl; // Should print 13
}
