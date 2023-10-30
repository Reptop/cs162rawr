#include "shop.h"

using namespace std;

//function defintions from shop.h goes here

void Shop::load_data(){
	//reads from files to correctly populate coffee, menu, etc.
	//Your code goes here: 
	cout << "Shop::load_data() not implemented..." << endl;

	return;
}


void Shop::view_shop_detail(){
	//handle "View shop detail" option
	//print shop address, phone number, revenue, menu, and order
	//Your code goes here: 
	cout << "Shop::view_shop_detail() not implemented..." << endl;


	return;
}

void Shop::add_to_menu(){
	//handle "Add coffee to menu" option
	//Hint: call Menu::add_to_menu(Coffee& coffee_to_add);
	//Your code goes here: 
	cout << "Shop::add_to_menu() not implemented..." << endl;

	return;
}

void Shop::remove_from_menu(){
	//handle "Remove coffee from menu" option
	//Hint: call Menu::remove_from_menu(int index_of_coffee_on_menu);
	//Your code goes here: 
	cout << "Shop::remove_from_menu() not implemented..." << endl;

	return;
}


void Shop::search_by_name(){
	//handle "Search by coffee name" option
	//Hint: call Menu::search_coffee_by_name(string name);
	//Your code goes here: 
	cout << "Shop::search_by_name() not implemented..." << endl;

	return;
}

void Shop::search_by_price(){
	//handle "Search by coffee price" option
	//Hint: call Menu::search_coffee_by_price(float budget);
	//Your code goes here: 
	cout << "Shop::search_by_price() not implemented..." << endl;

	return;
}

void Shop::place_order() {
	//handle "Place order" option
	//Your code goes here: 
	cout << "Shop::place_order() not implemented..." << endl;

	return;
}

Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}