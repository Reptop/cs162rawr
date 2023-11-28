#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include "player.h"

#include <iostream>
using namespace std;

// Wumpus Interface

class Wumpus : public Event {
public:
  Wumpus();
  ~Wumpus();
  void percept() override;
  void encounter(Player &) override;
  void performAction() override;
  void setType(const string) override;
  string getType() override;
};

#endif
