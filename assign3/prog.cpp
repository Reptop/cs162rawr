#include "display.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  // your main function lives here
  cout << "Welcome to Coffee++" << endl;

  ifstream inFile;

  int choice = -1;
  Shop s(inFile);

  //  populate your Shop:
  //  your code here:

  s.load_data(inFile);

  while (choice != QUIT) {
    choice = get_choice();
    perform_action(s, choice);
  }

  cout << "Bye!" << endl;

  return 0;
}
