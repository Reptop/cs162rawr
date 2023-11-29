#include "player.h"

Player::Player()
    : isAlive(true), hasGold(false), killedWumpus(false), isConfused(false),
      currentX(0), currentY(0), initialX(0), initialY(0), invertedCounter(5),
      hasArmor(false), armorHealth(2), turnCount(0) {}
