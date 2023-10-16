/******************************************************
** Program: hooping.cpp
** Author: Raed Kabir
** Date: 10/5/2023
** Description: This program is a basketball shooting game simulator
** Input: User inputs total number of players and their money ball rack
** Output: This program outputs an entire score board with specific notation for
*each ball
******************************************************/

#include <iostream>
using namespace std;
#define MAX_SIZE 5

// returns true if ball successfully scored; otherwise, return false
bool success() {
  // implementing 50% chance
  if (rand() % 2 == 0)
    return false;
  else
    return true;
}

// free's the entire 3D array, and the playerScore array
void endGame(char ***racks, int *playerScores, int players) {
  // free all memory inside out, even more so given the 3D array
  for (int p = 0; p < players; p++) {
    for (int i = 0; i < MAX_SIZE; ++i) {
      delete[] racks[p][i];
    }
    delete[] racks[p];
  }
  delete[] racks;
  delete[] playerScores;
}

// ouputs error message, prompting user to try again
void errorMsg() {
  cout << "Invalid input." << endl;
  cout << "Inputs must be between 1 and 5 (inclusive)" << endl;
}

void clearBuffer() {
  cin.clear();
  cin.ignore(1000000, '\n');
}

void checkWin(int *playerScores, int players) {
  // set default maxScore to the first element
  int maxScore = playerScores[0];
  // set the winner to player 1 by default
  int winner = 1;
  // flag to check for ties
  bool tie = false;

  for (int i = 1; i < players; i++) {
    if (playerScores[i] > maxScore) {
      maxScore = playerScores[i];
      winner = i + 1;
      tie = false;
    } else if (playerScores[i] == maxScore)
      tie = true;
  }

  if (tie)
    cout << "It's a tie with " << maxScore << " points!\n" << endl;
  else {
    cout << "Player " << winner << " Wins with " << maxScore << " points!\n"
         << endl;
  }
}

// return false if user does not want to play again; otherwise, returns true
bool playAgain() {
  char n;
  bool running = true;

  while (running) {
    cout << "Do you want to play again? Enter (Y/N): " << endl;
    cout << ">> ";
    cin >> n;
    if (n == 'N' || n == 'n') {
      cout << "Thanks for playing!" << endl;
      return false;
    } else if (n == 'Y' || n == 'y')
      break;
    else {
      cout << "Invalid input. Try again.\n" << endl;
      clearBuffer();
    }
  }
  return true;
}

// seperate function to only compute for the moneyBallRack
void computeMoneyBoard(char *arr[MAX_SIZE], int moneyBallRack) {
  for (int i = 0; i < MAX_SIZE; ++i) {
    if (success())
      arr[moneyBallRack][i] = 'M';
    else
      arr[moneyBallRack][i] = 'X';
  }
}

// computes logic for all racks; sets rack elements to X, O, or M
void computeBoard(char *arr[MAX_SIZE], int moneyBallRack) {
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j) {
      // if the loop reaches the last element, check for moneyball success
      if (j == MAX_SIZE - 1) {
        if (success())
          arr[i][j] = 'M';
        else
          arr[i][j] = 'X';
      } else if (success())
        arr[i][j] = 'O';
      else
        arr[i][j] = 'X';
    }
  }
  // overwriting with moneyboard logic; found this implementation very easy
  computeMoneyBoard(arr, moneyBallRack - 1);
}

// function for starry ball logic; returns 3 or 0 for total score calculation
int starryBalls() {
  if (success()) {
    cout << "Starry: " << 'W' << "          | 3 pts" << endl;
    return 3;
  } else {
    cout << "Starry: " << 'X' << "          | 0 pts" << endl;
    return 0;
  }
}

// prints pieces of the board, while also outputting scores for each rack
void printBoard(char *arr[MAX_SIZE], int &totalScore, int start, int limit,
                int rack_number) {

  int counter = 0;

  for (int i = start; i < limit; ++i) {
    cout << "Rack " << rack_number << ": ";
    ++rack_number;
    for (int j = 0; j < MAX_SIZE; ++j) {
      cout << arr[i][j] << " ";
      if (arr[i][j] == 'O')
        counter += 1;
      else if (arr[i][j] == 'M')
        counter += 2;
    }
    cout << " | " << counter << " pts";
    counter = 0;
    cout << endl;
  }
  if (start == 0 || start == 2)
    totalScore += starryBalls();
}

// scrubs input for only valid numbers - takes first instance of valid number
int inputScrubbing(string n) {
  for (int i = 0; i < n.length(); ++i) {
    // detecting a char between 1 and 5
    if (n[i] >= '1' && n[i] <= '5') {
      // convert to actual integer using ascii
      return n[i] - '0';
    }
  }
  return -1;
}

// to modulate my printBoard implementation; there is a better way of doing this
// I'm just not smart enough to figure that out
void printAll(char *arr[MAX_SIZE], int &pt) {
  printBoard(arr, pt, 0, 2, 1);
  printBoard(arr, pt, 2, 3, 3);
  printBoard(arr, pt, 3, 5, 4);
}

// Performs one turn for the player, including all background computation
void playTurn(char *arr[MAX_SIZE], int p, int moneyBallRack, int &pt) {
  pt = 0;

  computeBoard(arr, moneyBallRack);

  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j) {
      if (arr[i][j] == 'O')
        pt += 1;
      else if (arr[i][j] == 'M')
        pt += 2;
      else
        pt += 0;
    }
  }
  printAll(arr, pt);

  cout << "\n";
  cout << "Total Score: " << pt << endl;
}

void getInputs(int &scrubbed, int player) {
  string input;
  cout << "Player " << player
       << ", Where do you want to put your money ball rack?" << endl;
  cout << "Enter 1-5: ";
  getline(cin, input);
  scrubbed = inputScrubbing(input);
}

// initialize each element in the 3D array to contain a 2D array
char **initRack() {
  char **rack = new char *[MAX_SIZE];
  for (int i = 0; i < MAX_SIZE; ++i)
    rack[i] = new char[MAX_SIZE];
  return rack;
}

// gets total number of players playing the game
void getPlayers(int &n) {
  bool valid = false;

  while (!valid) {
    cout << "How many players?: ";
    cin >> n;

    if (cin.fail()) {
      cout << "Enter a positive integer" << endl;
      clearBuffer();
    } else {
      clearBuffer();
      valid = true;
    }
  }
}

// this function runs the entire game once for each player
void playGame(char ***racks, int players, int *playerScores) {

  int i;
  for (i = 0; i < players; i++) {
    racks[i] = initRack();
    int scrubbedInput;
    getInputs(scrubbedInput, i + 1);
    if (scrubbedInput == -1) {
      // Sets the iterator back by 1 due to invalid input
      errorMsg();
      --i;
    } else
      // play a turn for each player
      playTurn(racks[i], i + 1, scrubbedInput, playerScores[i]);
  }
}

// Game Driver
int main() {
  srand(time(NULL));
  bool running = true;
  int players;

  getPlayers(players);
  cout << "Welcome to the basketball shooting contest!" << endl;

  while (running) {
    // triple pointer char so I can create a dynamic array of characters
    // We are essentially making a jagged array
    // Also, we are essentially storing a 2D array within each element
    int *playerScores = new int[players];
    char ***racks = new char **[players];

    playGame(racks, players, playerScores);
    checkWin(playerScores, players);

    // delete everything each round; no memory leaks this way
    endGame(racks, playerScores, players);

    if (!playAgain())
      running = false;
    // clear buffer; throw away everything in input stream
    else
      clearBuffer();
  }
  return 0;
}
