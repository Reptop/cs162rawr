#include "display.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  // your main function lives here
  cout << "Welcome to Coffee++" << endl;
  Shop s;
  ifstream inFile;
  int choice = -1;

  ifstream shop_info("shop_info.txt");
  ifstream menu_info("menu.txt");

  if (shop_info.is_open() || menu_info.is_open()) {

    //  populate your Shop:
    s.load_data(shop_info, menu_info);

    while (choice != QUIT) {
      choice = get_choice();
      perform_action(s, choice);
    }

    cout << "Bye!" << endl;
  }

  else
    cout << "\nCould not open either files\n;" << endl;

  return 0;
}
