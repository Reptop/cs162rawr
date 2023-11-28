#include "game.h"
#include "player.h"
#include "wumpus.h"

#include <cstdlib>
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

void Game::manualShuffle(vector<pair<int, int>> &array) {
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

  // shuffle using the manually implemented Fisher-Yates algorithm
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

  // start with 3 arrows
  this->num_arrows = 3;

  Gold *gold;
  Wumpus *wumpus;
  Stalactite *stalactite1, *stalactite2;
  Bat *bat1, *bat2;

  // create the game board: 2D vector of Room objects
  board.resize(this->length);

  // resize each inner vector to have 'numCols' columns
  for (int i = 0; i < this->length; ++i)
    board[i].resize(this->width);

  // assign all events randomly
  assignEvents(board, gold, wumpus, stalactite1, stalactite2, bat1, bat2);
}

void Game::display_game() const {
  cout << endl << "Arrows remaining: " << this->num_arrows << endl;

  // Function to draw horizontal line
  auto drawLine = [this]() {
    for (int i = 0; i < this->width; ++i)
      cout << "-----";
    cout << endl;
  };

  // Draw top line
  drawLine();

  for (int i = 0; i < this->length; ++i) {
    for (int j = 0; j < this->width; ++j) {
      cout << "|| "; // Start each cell with a border

      if (board[i][j].hasAdventurer())
        cout << "*";
      else if (board[i][j].hasEvent() && debug_view)
        cout << board[i][j].getEventType(); // Show event type in debug view
      else
        cout << " "; // Empty space

      cout << " "; // End each cell with a space
    }
    cout << "||" << endl; // End each row with a border
    drawLine();           // Draw line after each row
  }
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
  if (!p.isAlive)
    return true;

  else if (p.isAlive && p.hasGold && p.currentX == p.initialX &&
           p.currentY == p.initialY)
    return true;

  else if (p.killedWumpus == true)
    return true;

  return false;
}

void Game::move_up() {
  // Clear the player's current position
  board[p.currentX][p.currentY].setPlayerPresence(false);

  // move player up, wrapping around if necessary
  if (p.currentX - 1 < 0)
    p.currentX = length - 1;
  else
    --p.currentX;

  // Set the player's new position
  board[p.currentX][p.currentY].setPlayerPresence(true);
}

void Game::move_down() {
  // Clear the player's current position
  board[p.currentX][p.currentY].setPlayerPresence(false);

  // Move player down, wrapping around if necessary
  if (p.currentX + 1 == length) {
    p.currentX = 0;
  } else {
    ++p.currentX;
  }

  // Set the player's new position
  board[p.currentX][p.currentY].setPlayerPresence(true);
}

void Game::move_left() {
  // Clear current position
  board[p.currentX][p.currentY].setPlayerPresence(false);

  // Move player left, wrap around if necessary
  if (p.currentY - 1 < 0)
    p.currentY = length - 1;
  else
    --p.currentY;

  // Set new position
  board[p.currentX][p.currentY].setPlayerPresence(true);
}

void Game::move_right() {
  // Clear current position
  board[p.currentX][p.currentY].setPlayerPresence(false);

  // Move player right, wrap around if necessary
  if (p.currentY + 1 >= length)
    p.currentY = 0;
  else
    ++p.currentY;

  // Set new position
  board[p.currentX][p.currentY].setPlayerPresence(true);
}

char Game::get_dir() {
  // get direction of arrow:
  char dir;
  while (true) {
    cout << "\nFire an arrow...." << endl;
    cout << "W-up" << endl;
    cout << "A-left" << endl;
    cout << "S-down" << endl;
    cout << "D-right" << endl;

    cout << "Enter direction: " << endl;
    cin >> dir;
    cin.clear();
    cin.ignore(1000000, '\n');

    if (dir == 'W' || dir == 'w' || dir == 'A' || dir == 'a' || dir == 'S' ||
        dir == 's' || dir == 'D' || dir == 'd')
      break;
    else
      cout << "\nInvalid input. Enter W, A, S, or D.\n" << endl;
  }

  return dir;
}

pair<int, int> Game::giveRandomCoords() {
  pair<int, int> randomCoord;

  randomCoord.first = rand() % length;
  randomCoord.second = rand() % width;

  // Check if the randomly selected coordinate has an event
  if (board[randomCoord.first][randomCoord.second].hasEvent())
    // Recursively call the function again if the coordinate is not empty
    return giveRandomCoords();
  else
    // If the coordinate is empty, return it
    return randomCoord;
}

void Game::repositionWumpus() {
  pair<int, int> currentCoord;
  bool foundWumpus = false;

  // Find current position of the Wumpus
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      if (board[i][j].hasEvent() && board[i][j].getEventType() == "W") {
        currentCoord = make_pair(i, j);
        delete board[i][j].getEvent(); // Delete the current Wumpus
        board[i][j].setEvent(nullptr); // Set the current position to null
        foundWumpus = true;
        break; // Stop searching once Wumpus is found
      }
    }
    if (foundWumpus)
      break;
  }

  if (foundWumpus) {
    pair<int, int> randomCoord = giveRandomCoords();
    Wumpus *wumpus = new Wumpus;
    board[randomCoord.first][randomCoord.second].setEvent(
        wumpus); // Place the Wumpus at the new location
  }
}

void Game::wumpus_move() {

  // after a missed arrow, 75% chance that the wumpus is moved to a different
  cout << "\n----------------------------------" << endl;
  cout << "You missed the wumpus!" << endl;
  cout << "----------------------------------" << endl;

  if (rand() % 4 < 3) {
    cout << "\n----------------------------------------" << endl;
    cout << "The Wumpus moved to a random empty room!" << endl;
    cout << "----------------------------------------" << endl;

    // make wumpus move to different random room that is empty
    repositionWumpus();

  } else {
    cout << "\n----------------------------------------" << endl;
    cout << "Luckily, the wumpus did not move anywhere..." << endl;
    cout << "----------------------------------------" << endl;
  }
}

void Game::fire_north(int &arrowX, int &arrowY,
                      const vector<vector<Room>> &grid) {

  cout << "\nFired North!\n" << endl;

  for (int i = 0; i < 3; ++i) {
    --arrowX;

    // boundary check
    if (arrowX < 0) {
      cout << "\nArrow hit a wall.\n" << endl;
      break; // arrow hits the wall
    }

    // Check if the arrow hits the Wumpus
    if (grid[arrowX][arrowY].hasEvent() &&
        grid[arrowX][arrowY].getEventType() == "W") {
      cout << "\n-----------------------------" << endl;
      cout << "KILLED THE WUMPUS! You win, Player." << endl;
      cout << "-----------------------------" << endl;
      p.killedWumpus = true; // Arrow hit the Wumpus
      break;                 // Arrow has hit the target, no need to continue
    }
  }

  if (!p.killedWumpus)
    wumpus_move();

  return;
}

void Game::fire_west(int &arrowX, int &arrowY,
                     const vector<vector<Room>> &grid) {

  cout << "\nFired West!\n" << endl;

  for (int i = 0; i < 3; ++i) {
    --arrowY;

    // boundary check
    if (arrowY < 0) {
      cout << "\nArrow hit a wall.\n" << endl;
      break;
    }

    // Check if the arrow hits the Wumpus
    if (grid[arrowX][arrowY].hasEvent() &&
        grid[arrowX][arrowY].getEventType() == "W") {
      cout << "\n-----------------------------" << endl;
      cout << "KILLED THE WUMPUS! You win, Player." << endl;
      cout << "-----------------------------" << endl;
      p.killedWumpus = true; // Arrow hit the Wumpus
      break;                 // Arrow has hit the target, no need to continue
    }
  }

  if (!p.killedWumpus)
    wumpus_move();

  return;
}

void Game::fire_east(int &arrowX, int &arrowY,
                     const vector<vector<Room>> &grid) {

  cout << "\nFired East!\n" << endl;

  for (int i = 0; i < 3; ++i) {
    ++arrowY;

    // boundary check
    if (arrowY > length) {
      cout << "\nArrow hit a wall.\n" << endl;
      break;
    }

    // Check if the arrow hits the Wumpus
    if (grid[arrowX][arrowY].hasEvent() &&
        grid[arrowX][arrowY].getEventType() == "W") {
      cout << "\n-----------------------------" << endl;
      cout << "KILLED THE WUMPUS! You win, Player." << endl;
      cout << "-----------------------------" << endl;
      p.killedWumpus = true; // Arrow hit the Wumpus
      break;                 // Arrow has hit the target, no need to continue
    }
  }

  if (!p.killedWumpus)
    wumpus_move();

  return;
}

void Game::fire_south(int &arrowX, int &arrowY,
                      const vector<vector<Room>> &grid) {

  cout << "\nFired South!\n" << endl;

  for (int i = 0; i < 3; ++i) {
    ++arrowX;

    // boundary check
    if (arrowY > length) {
      cout << "\nArrow hit a wall.\n" << endl;
      break;
    }

    // Check if the arrow hits the Wumpus
    if (grid[arrowX][arrowY].hasEvent() &&
        grid[arrowX][arrowY].getEventType() == "W") {
      cout << "\n-----------------------------" << endl;
      cout << "KILLED THE WUMPUS! You win, Player." << endl;
      cout << "-----------------------------" << endl;

      // killed wumpus
      p.killedWumpus = true;
      break;
    }
  }

  if (!p.killedWumpus)
    wumpus_move();

  return;
}

void Game::fire_arrow(int x, int y) {
  // The player may fire arrow...
  char dir = get_dir();
  int arrowX = x;
  int arrowY = y;

  // decrement number of total arrows
  --num_arrows;

  switch (dir) {
  case 'W':
  case 'w':
    fire_north(x, y, board);
    break;

  case 'A':
  case 'a':
    fire_west(x, y, board);
    break;

  case 'S':
  case 's':
    fire_south(x, y, board);
    break;

  case 'D':
  case 'd':
    fire_east(x, y, board);
    break;
  }

  return;
}

// handle player movement
void Game::move(int c) {
  if (c == 'f' && num_arrows > 0)
    fire_arrow(p.currentX, p.currentY);

  else if (c == 'f' && num_arrows == 0) {
    cout << "\n--------------------------" << endl;
    cout << "      NO ARROWS LEFT" << endl;
    cout << "--------------------------" << endl;
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

// handle player movement
void Game::inverted_move(int c) {
  if (c == 'f' && num_arrows > 0)
    fire_arrow(p.currentX, p.currentY);

  else if (c == 'f' && num_arrows == 0) {
    cout << "\n--------------------------" << endl;
    cout << "      NO ARROWS LEFT" << endl;
    cout << "--------------------------" << endl;
  }

  switch (c) {
  case 'w':
    move_down();
    break;
  case 'a':
    move_right();
    break;
  case 's':
    move_up();
    break;
  case 'd':
    move_left();
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
  cin.clear();
  cin.ignore(100000, '\n');

  return c;
}

void Game::checkPercepts(const vector<vector<Room>> &grid) {

  // get the current player position
  int row = p.currentX;
  int col = p.currentY;

  // north
  if (row > 0 && grid[row - 1][col].hasEvent())
    grid[row - 1][col].getEvent()->percept();

  // south
  if (row < grid.size() - 1 && grid[row + 1][col].hasEvent())
    grid[row + 1][col].getEvent()->percept();

  // west
  if (col > 0 && grid[row][col - 1].hasEvent())
    grid[row][col - 1].getEvent()->percept();

  // east
  if (col < grid[row].size() - 1 && grid[row][col + 1].hasEvent())
    grid[row][col + 1].getEvent()->percept();
}

void Game::movement(const int &input) {
  if (!p.isConfused)
    move(input);
  else if (p.isConfused && p.invertedCounter > 0) {
    // invert movement
    --p.invertedCounter;
    inverted_move(input);
  } else if (p.invertedCounter == 0) {
    cout << "\n---------------------------" << endl;
    cout << "You are no longer confused!" << endl;
    cout << "Movement is back to normal!" << endl;
    cout << "\n---------------------------" << endl;

    p.isConfused = false;
    p.invertedCounter = 5;
  }
}

void Game::play_game(int w, int l, bool d) {
  set_up(w, l);
  this->debug_view = d;

  setInitialPos(board);

  char input, arrow_input;

  while (!check_win(p)) {
    // print game board
    display_game();

    // display percerts around player's location
    checkPercepts(board);

    // 1. get input
    input = get_input();

    // 2. move player
    movement(input);

    // 3. may or may not encounter events
    if (board[p.currentX][p.currentY].hasEvent())
      board[p.currentX][p.currentY].getEvent()->encounter(p);
  }

  return;
}
