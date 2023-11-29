#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
public:
  bool isConfused;
  bool isAlive;
  bool hasGold;
  bool killedWumpus;
  bool hasArmor;

  int invertedCounter;
  int turnCount;
  int armorHealth;

  int initialX;
  int initialY;

  int currentX;
  int currentY;

  Player();
};

#endif
