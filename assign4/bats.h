#ifndef BATS_H
#define BATS_H

#include "event.h"
#include <iostream>

// Bats Interface

class Bat : public Event {
public:
  Bat();
  ~Bat();
  void percept() override;
  void encounter() override;
  void performAction() override;
  void setType(const string) override;
  string getType() override;
};

#endif
