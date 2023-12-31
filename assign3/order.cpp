/*********************************************************************
** Program Filename: order.cpp
** Author: Raed Kabir
** Date: 11/12/2023
** Description: This file consists of all function defintions for order.h
** Input: N/A
** Output: N/A
*********************************************************************/
#include "order.h"

Order::Order() {
  // empty
}

Order::~Order() {
  // empty - not needed
}

int Order::get_id() const {
  // return id
  return id;
}

string Order::get_coffee_name() const {
  // return id
  return coffee_name;
}

char Order::get_coffee_size() const {
  // return coffee size
  return coffee_size;
}

int Order::get_quantity() const {
  // return id
  return quantity;
}

void Order::set_id(const int id) {
  // set_id
  this->id = id;
}

void Order::set_coffee_name(const string coffee_name) {
  // set coffee name
  this->coffee_name = coffee_name;
}

void Order::set_coffee_size(const char coffee_size) {
  // set coffee size
  this->coffee_size = coffee_size;
}

void Order::set_quantity(const int quantity) {
  // set quantity
  this->quantity = quantity;
}
