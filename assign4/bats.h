#ifndef BATS_H
#define BATS_H

#include "event.h"
#include "player.h"
#include <iostream>

// Bats Interface

class Bat : public Event {
public:
  Bat();
  ~Bat();
  void percept() override;
  void encounter(Player &) override;
  void performAction() override;
  void setType(const string) override;
  string getType() override;
};

#endif
