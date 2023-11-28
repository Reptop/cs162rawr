/******************************************************
** Program: main.cpp
** Author: Raed Kabir
** Date: 11/20/2023
** Description:
** Input:
** Output:
******************************************************/

#include "game.h"
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <vector>

using namespace std;

int main() {
  // set the random seed
  srand(time(NULL));

  string rawWid, rawLen;
  int wid = 5, len = 5;
  bool debug = false;

  Game g;

  // get two inputs: size of the cave(wid and len)
  g.setValidWid(rawWid, wid);
  g.setValidLen(rawLen, len);

  // get the 3rd input --> debug mode or not
  g.setMode(debug);

  // play game
  g.play_game(wid, len, debug);

  endwin();

  return 0;
}
