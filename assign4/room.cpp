#include "room.h"
#include <iostream>
using namespace std;

// Room Implementation

Room::Room() : event(nullptr), hasPlayer(false) {}

Room::~Room() {
  // delete just in case
  delete event;
  event = nullptr;
}

void Room::setEvent(Event *e) {
  // event setter
  event = e;
}

Event *Room::getEvent() const {
  // event getter
  return event;
}

void Room::setPlayerPresence(bool presence) const {
  // set player presence
  presence = hasPlayer;
}

string Room::getEventType() const {
  // returns that type;
  return event->getType();
}

Room &Room::operator=(const Room &other) {
  cout << "Used assignment operator overload" << endl;

  if (this == &other)
    return *this;

  Event *new_event;

  new_event = event;

  delete event;
  event = new_event;

  hasPlayer = other.hasPlayer;

  return *this;
}

bool Room::hasEvent() const {
  // return if has event
  if (event != nullptr)
    return true;
  else
    return false;
}

bool Room::hasAdventurer() const {
  // return bool
  return hasPlayer;
}
