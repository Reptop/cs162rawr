#include "display.h"
#include <iostream>

using namespace std;

/* name: print_options()
 * description: print possible options to the user
 * parameters: none
 * pre-condition: none
 * post-conditon: none
 */
void print_options() {
  cout << endl;
  cout << "What would you like to do: " << endl;
  cout << "  1. View shop info " << endl;
  cout << "  2. Add an item to menu " << endl;
  cout << "  3. Remove an item from menu " << endl;
  cout << "  4. Search by coffee name " << endl;
  cout << "  5. Search by price " << endl;
  cout << "  6. Place an order " << endl;
  cout << "  7. Clone a shop " << endl;
  cout << "  8. View additional statistics " << endl;
  cout << "  9. Log out " << endl;
  cout << endl;
}

int inputScrubbing(string n) {
  if (n == "1" || n == "2" || n == "3" || n == "4" || n == "5" || n == "6" ||
      n == "7" || n == "8" || n == "9")
    return n[0] - '0';
  return -1;
}

int get_choice() {
  string rawInput;
  int choice = -1;

  while (true) {
    print_options();
    cout << "Enter a number that corresponds to your choice. " << endl;
    cout << ">> ";
    getline(cin, rawInput);
    choice = inputScrubbing(rawInput);

    if (choice == -1) {
      cout << "\nInvalid Input! Enter a number 1-8 (inclusive)\n" << endl;
    } else {
      break;
    }
  }
  return choice;
}

void perform_action(Shop &s, int choice) {
  switch (choice) {
  case 1:
    s.view_shop_detail();
    break;
  case 2:
    s.add_to_menu();
    break;
  case 3:
    s.remove_from_menu();
    break;
  case 4:
    s.search_by_name();
    break;
  case 5:
    s.search_by_price();
    break;
  case 6:
    s.place_order();
    break;
  case 7:
    s.clone_shop();
    break;
  case 8:
    s.stats();
  case QUIT:
    break;
  }

  return;
}
