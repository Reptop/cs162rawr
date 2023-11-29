#ifndef GAME_H
#define GAME_H

#include "armor.h"
#include "bats.h"
#include "gold.h"
#include "player.h"
#include "room.h"
#include "stalactites.h"
#include "wumpus.h"

#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

// Game interface
class Game {
private:
  // declare a 2D vector of Room objects
  vector<vector<Room>> board;

  Player p;

  // other member variables:
  int length;      // length of the board
  int width;       // width of the board
  int num_arrows;  // keep track of number of errors remaining
  bool debug_view; // debug mode or not

  // feel free to add more variables...

public:
  // suggested functions:
  Game();
  ~Game();

  void set_up(int, int);

  void display_game() const;

  bool check_win(const Player &) const;

  char get_dir();
  void wumpus_move();
  void fire_arrow(int, int);

  void move_up();
  void move_down();
  void move_left();
  void move_right();
  void move(int);

  char get_input();

  void play_game(int, int, bool);

  // feel free (and you will need) to add more functions...

  void setValidWid(string &, int &);
  void setValidLen(string &, int &);
  void setMode(bool &);

  void assignEvents(vector<vector<Room>> &, Gold *&, Wumpus *&, Stalactite *&,
                    Stalactite *&, Bat *&, Bat *&, Armor *&);

  void manualShuffle(vector<pair<int, int>> &);

  void setInitialPos(vector<vector<Room>> &);

  void placeEventsRandomly(vector<vector<Room>> &, vector<Event *> &);

  void checkPercepts(const vector<vector<Room>> &);

  void fire_north(int &, int &, const vector<vector<Room>> &);

  void fire_west(int &, int &, const vector<vector<Room>> &);

  void fire_east(int &, int &, const vector<vector<Room>> &);

  void fire_south(int &, int &, const vector<vector<Room>> &);

  pair<int, int> giveRandomCoords();

  void repositionWumpus();

  void inverted_move(int);

  void movement(const int &);

  void blockRandom();
};
#endif
