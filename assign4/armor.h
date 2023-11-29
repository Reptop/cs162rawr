#ifndef ARMOR_H
#define ARMOR_H

#include "event.h"
#include "player.h"

#include <iostream>
using namespace std;

// Armor Interface

class Armor : public Event {
public:
  Armor();
  ~Armor();
  void percept() override;
  void encounter(Player &) override;
  void performAction() override;
  void setType(const string) override;
  string getType() override;
};

#endif
