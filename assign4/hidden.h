#ifndef HIDDEN_H
#define HIDDEN_H

#include "event.h"
#include "player.h"
#include <iostream>

// Hidden Interface

class Hidden : public Event {

public:
  Hidden();
  ~Hidden();

  void percept() override;
  void encounter(Player &p) override;
  void performAction() override;
  void setType(string) override;
  string getType() override;
};

#endif
