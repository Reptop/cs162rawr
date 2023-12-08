// The following is an example program that
// does some basic, limited testing of your
// ways_to_top() implementation.

#include <iostream>

#include "stairs.h"

using namespace std;

int main() {
  cout << ways_to_top(3) << endl;  // Should print 4
  cout << ways_to_top(4) << endl;  // Should print 7
  cout << ways_to_top(5) << endl;  // Should print 13
                                   //
                                   //
  cout << ways_to_top(20) << endl; // Should print 13
                                   //
                                   //
  cout << ways_to_top(40) << endl; // Should print 13
}
