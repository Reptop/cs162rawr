#ifndef ROOM_H
#define ROOM_H

#include "event.h"

using namespace std;

// Room Interface
// Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room {
private:
  Event *event;
  bool hasPlayer;

public:
  Room();
  ~Room();

  Room &operator=(const Room &other);

  void setEvent(Event *);
  Event *getEvent() const;
  void setPlayerPresence(bool);
  string getEventType() const;
  bool hasEvent() const;
  bool hasAdventurer() const;

  // 何は欲しいかな。。。
};

#endif
