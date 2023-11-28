#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include "player.h"
#include <iostream>

// Gold Interface

class Gold : public Event {
public:
  Gold();
  ~Gold();
  void percept() override;
  void encounter(Player &) override;
  void performAction() override;
  void setType(string) override;
  string getType() override;
};

#endif
