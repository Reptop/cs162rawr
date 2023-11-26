#ifndef STALACTITES_H
#define STALACTITES_H

#include "event.h"
#include <iostream>

// Stalactites Interface

class Stalactite : public Event {
public:
  Stalactite();
  ~Stalactite();
  void percept() override;
  void encounter() override;
  void performAction() override;
  void setType(string) override;
  string getType() override;
};

#endif
