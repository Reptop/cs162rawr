#ifndef EVENT_H
#define EVENT_H

#include "player.h"
#include <iostream>
using namespace std;

// Event Interface
// Note: this must be an abstract class!

class Event {

protected:
  string type;

public:
  Event();
  Event(const string);
  virtual void performAction() = 0;
  virtual void encounter(Player &) = 0;
  virtual void percept() = 0;

  // event identifier
  virtual string getType() = 0;
  virtual void setType(const string) = 0;

  virtual ~Event();
};
#endif
