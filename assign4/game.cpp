#include "game.h"
#include "player.h"

#include <iostream>
#include <ncurses.h>
#include <random>
#include <vector>

using namespace std;

// Game Implementation

Game::Game() {
  // Game constructor
  // Your code here:
}

Game::~Game() {
  // Game destructor
  // Your code here:
}

void Game::setValidWid(string &rawWid, int &wid) {
  while (true) {
    cout << "Enter the cave's width (any positive integer): ";
    getline(cin, rawWid);
    try {
      wid = stoi(rawWid);
      if (wid <= 0)
        throw invalid_argument("Width must be positive.");

      if (wid <= 4 || wid >= 50)
        throw invalid_argument(
            "Invalid dimensions; width must be between 4-50 (inclusive)");

      break;

    } catch (const invalid_argument &) {
      cerr << "\nInvalid input. Please enter a valid number for the width.\n"
           << endl;
    }
  }
}

void Game::setMode(bool &debug) {
  char input;
  while (true) {
    cout << "Play in debug mode? (y/n): ";
    cin >> input;
    if (input == 'Y' || input == 'y') {
      debug = true;
      this->debug_view = true;
      break;
    } else if (input == 'N' || input == 'n') {
      debug = false;
      this->debug_view = false;
      break;
    } else {
      cerr << "\nInvalid input. Enter y or n\n" << endl;
      cin.clear();
      cin.ignore(100000, '\n');
    }
  }
}

void Game::setValidLen(string &rawLen, int &len) {
  while (true) {
    cout << "Enter the cave's width (any positive integer): ";
    getline(cin, rawLen);
    try {
      len = stoi(rawLen);
      if (len <= 0)
        throw invalid_argument("Width must be positive.");

      break;

    } catch (const invalid_argument &) {
      cerr << "\nInvalid input. Please enter a valid number for the width.\n"
           << endl;
    }
  }
}

void Game::manualShuffle(std::vector<std::pair<int, int>> &array) {
  random_device rd;
  mt19937 g(rd());

  for (int i = array.size() - 1; i > 0; --i) {
    uniform_int_distribution<> dis(0, i);
    int j = dis(g);
    std::swap(array[i], array[j]);
  }
}

void Game::placeEventsRandomly(vector<vector<Room>> &grid,
                               vector<Event *> &eventList) {
  int numRows = grid.size();
  int numCols = grid[0].size();

  vector<pair<int, int>> cellIndices;
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      cellIndices.emplace_back(i, j);
    }
  }

  // Shuffle using the manually implemented Fisher-Yates algorithm
  manualShuffle(cellIndices);

  for (int i = 0; i < eventList.size(); ++i) {
    int row = cellIndices[i].first;
    int col = cellIndices[i].second;
    grid[row][col].setEvent(eventList[i]);
  }
}

void Game::assignEvents(vector<vector<Room>> &grid, Gold *&gold,
                        Wumpus *&wumpus, Stalactite *&stalactite1,
                        Stalactite *&stalactite2, Bat *&bat1, Bat *&bat2) {

  // Create event pointers to avoid object slicing when upcasting
  // Also store on heap so it doesnt get deleted when out of scope
  gold = new Gold;
  wumpus = new Wumpus;
  stalactite1 = new Stalactite;
  stalactite2 = new Stalactite;
  bat1 = new Bat;
  bat2 = new Bat;

  vector<Event *> eventList;
  eventList.assign({gold, wumpus, stalactite1, stalactite2, bat1, bat2});

  placeEventsRandomly(grid, eventList);
}

void Game::set_up(int l, int w) {
  // set up
  this->length = l;
  this->width = w;

  this->num_arrows = 3; // start with 3 arrows

  Gold *gold;
  Wumpus *wumpus;
  Stalactite *stalactite1, *stalactite2;
  Bat *bat1, *bat2;

  // Create the game board: 2D vector of Room objects
  board.resize(this->length);

  // Resize each inner vector to have 'numCols' columns
  for (int i = 0; i < this->length; ++i)
    board[i].resize(this->width);

  assignEvents(board, gold, wumpus, stalactite1, stalactite2, bat1, bat2);
}

// Note: you need to modify this function
void Game::display_game() const {
  cout << endl << endl;
  cout << "Arrows remaining: " << this->num_arrows << endl;

  string line = "";
  for (int i = 0; i < this->width; ++i)
    line += "-----";

  for (int i = 0; i < this->length; ++i) {
    cout << line << endl;
    for (int j = 0; j < this->width; ++j) {
      if (board[i][j].hasEvent() == true && debug_view) {
        string eventType = board[i][j].getEventType();
        cout << eventType;
        cout << " ||";
      } else if (board[i][j].hasAdventurer() == true) {
        cout << "*";
        cout << " ||";
      } else {
        cout << "  ||";
      }

      cout << " ";
    }
    cout << endl;
  }
  cout << line << endl;
}

void Game::setInitialPos(vector<vector<Room>> &roomList) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      if (!roomList[i][j].hasEvent()) {
        p.initialX = i;
        p.initialY = j;

        p.currentX = i;
        p.currentY = j;
        roomList[i][j].setPlayerPresence(true);
        break;
      }
    }
    break;
  }
}

bool Game::check_win(const Player &p) const {
  // check if game over/win
  // Your code here:

  if (p.isAlive && !p.hasGold)
    return false;

  else if (!p.isAlive)
    return false;

  else if (p.isAlive && p.hasGold && p.currentX == p.initialX &&
           p.currentY == p.initialY)
    return true;

  return false;
}

void Game::move_up() {
  // move player up
  // Your code here:

  cout << "Game::move_up() is not implemented..." << endl;

  board[p.currentX][p.currentY];
  return;
}

void Game::move_down() {
  // move player down
  // Your code here:

  cout << "Game::move_down() is not implemented..." << endl;
  return;
}

void Game::move_left() {
  // move player left
  // Your code here:

  cout << "Game::move_left() is not implemented..." << endl;
  return;
}

void Game::move_right() {
  // move player right
  // Your code here:

  cout << "Game::move_right() is not implemented..." << endl;
  return;
}

char Game::get_dir() {
  // get direction of arrow:
  char dir;
  // Note: error checking is needed!!
  // Your code here:
  cout << "Fire an arrow...." << endl;
  cout << "W-up" << endl;
  cout << "A-left" << endl;
  cout << "S-down" << endl;
  cout << "D-right" << endl;

  cout << "Enter direction: " << endl;
  cin >> dir;
  cin.ignore(256, '\n');

  return dir;
}

void Game::wumpus_move() {
  // after a missed arrow, 75% chance that the wumpus is moved to a different
  // room

  // How to get 75%?
  // Hint: generate a random number from 0-3, if the number is not 0, then move

  // Your code here:
  cout << "Game::wumpus_move() is not implemented..." << endl;

  return;
}

void Game::fire_arrow() {
  // The player may fire arrow...
  char dir = get_dir();
  // Your code here:
  cout << "Game::fire_arrow() is not implemented..." << endl;

  return;
}

void Game::move(int c) {
  // Handle player's action: move or fire an arrow
  if (c == 'f') {
    Game::fire_arrow();
    return;
  }

  switch (c) {
  case 'w':
    move_up();
    break;
  case 'a':
    move_left();
    break;
  case 's':
    move_down();
    break;
  case 'd':
    move_right();
    break;
  }
}

char Game::get_input() {
  // get action, move direction or firing an arrow

  char c;

  // Note: error checking is needed!!
  // Your code here:
  cout << endl << endl << "Player move..." << endl << endl;
  cout << "W-up" << endl;
  cout << "A-left" << endl;
  cout << "S-down" << endl;
  cout << "D-right" << endl;
  cout << "f-fire an arrow" << endl;

  cout << "Enter input: " << endl;
  cin >> c;
  cin.ignore(256, '\n');

  return c;
}

// Note: you need to modify this function
void Game::play_game(int w, int l, bool d) {
  set_up(w, l);
  this->debug_view = d;

  cout << "Before: " << endl;
  cout << p.currentX << endl;
  cout << p.currentY << endl;

  setInitialPos(board);

  cout << "After: " << endl;
  cout << p.currentX << endl;
  cout << p.currentY << endl;

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      cout << board[i][j].hasAdventurer() << " ";
    }
    cout << endl;
  }

  char input, arrow_input;

  while (!check_win(p)) {
    // print game board
    display_game();

    // display percerts around player's location
    // Your code here:

    // Player move...
    // 1. get input
    input = get_input();

    // 2. move player
    move(input);

    // 3. may or may not encounter events
    // Your code here:
  }

  return;
}
