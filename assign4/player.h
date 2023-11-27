#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
public:
  bool isAlive;
  bool hasGold;

  int initialX;
  int initialY;

  int currentX;
  int currentY;

  Player();
};

#endif
