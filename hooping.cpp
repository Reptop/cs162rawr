/******************************************************
** Program: hooping.cpp
** Author: Raed Kabir
** Date: 10/5/2023
** Description: This program is a basketball shooting game simulator
** Input: Player inputs a number to choose as their money ball rack
** Output: This program outputs what balls scored and missed, and a player's
*total score
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

void errorMsg() {
  cout << "Invalid input for either input." << endl;
  cout << "Both inputs must be between 1 and 5 (inclusive)" << endl;
}

void clearBuffer() {
  cin.clear();
  cin.ignore(1000000, '\n');
}

void checkWin(int pt1, int pt2) {
  if (pt1 > pt2)
    cout << "Player 1 Wins!\n" << endl;
  else if (pt1 < pt2)
    cout << "Player 2 Wins!\n" << endl;
  else
    cout << "It's a Tie!!\n" << endl;
}

// return false if user does not want to play again; otherwise, returns true
bool playAgain() {
  char n;
  bool running = true;

  while (running) {
    cout << "Do you want to play again? Enter (Y/N)" << endl;
    cin >> n;
    if (n == 'N' || n == 'n') {
      cout << "Thanks for playing!" << endl;
      return false;
    } else if (n == 'Y' || n == 'y') {
      break;
    } else {
      cout << "Invalid input. Try again.\n" << endl;
      clearBuffer();
    }
  }
  return true;
}

// seperate function to only compute for the moneyBallRack
void computeMoneyBoard(char arr[MAX_SIZE][MAX_SIZE], int moneyBallRack) {
  for (int i = 0; i < MAX_SIZE; ++i) {
    if (success()) {
      arr[moneyBallRack][i] = 'M';
    } else {
      arr[moneyBallRack][i] = 'X';
    }
  }
}

// computes logic for all racks; sets rack elements to X, O, or M
void computeBoard(char arr[MAX_SIZE][MAX_SIZE], int moneyBallRack) {
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j) {
      // if the loop reaches the last element, check for moneyball success
      if (j == MAX_SIZE - 1) {
        if (success()) {
          arr[i][j] = 'M';
        } else {
          arr[i][j] = 'X';
        }
      } else if (success()) {
        arr[i][j] = 'O';
      } else {
        arr[i][j] = 'X';
      }
    }
  }
  // overwriting with moneyboard logic
  computeMoneyBoard(arr, moneyBallRack - 1);
}

int starryBalls() {
  if (success()) {
    cout << "Starry: " << 'W' << "          | 3 pts" << endl;
    return 3;
  } else {
    cout << "Starry: " << 'X' << "          | 0 pts" << endl;
    return 0;
  }
}

// prints elements within each rack, excluding starryballs
void printFirstHalf(char arr[MAX_SIZE][MAX_SIZE], int &totalScore) {
  int rack_number = 1;
  int counter = 0;
  for (int i = 0; i < 2; ++i) {
    cout << "Rack " << rack_number << ": ";
    ++rack_number;
    for (int j = 0; j < MAX_SIZE; ++j) {
      cout << arr[i][j] << " ";
      if (arr[i][j] == 'O')
        counter += 1;
      else if (arr[i][j] == 'M') {
        counter += 2;
      }
    }
    cout << " | " << counter << " pts";
    counter = 0;
    cout << endl;
  }
  totalScore += starryBalls();
}

void printSecondHalf(char arr[MAX_SIZE][MAX_SIZE], int &totalScore) {
  int rack_number = 3;
  int counter = 0;
  for (int i = 2; i < 4; ++i) {
    cout << "Rack " << rack_number << ": ";
    ++rack_number;
    for (int j = 0; j < MAX_SIZE; ++j) {
      cout << arr[i][j] << " ";
      if (arr[i][j] == 'O')
        counter += 1;
      else if (arr[i][j] == 'M') {
        counter += 2;
      }
    }
    cout << " | " << counter << " pts";
    counter = 0;
    cout << endl;
  }
  totalScore += starryBalls();
  cout << "Rack " << rack_number << ": ";
  for (int i = 0; i < MAX_SIZE; ++i) {
    cout << arr[MAX_SIZE - 1][i] << " ";
    if (arr[MAX_SIZE - 1][i] == 'O')
      counter += 1;
    else if (arr[MAX_SIZE - 1][i] == 'M') {
      counter += 2;
    }
  }
  cout << " | " << counter << " pts";
  cout << endl;
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

// Performs one turn for the player, including all background computation
void playTurn(char arr[MAX_SIZE][MAX_SIZE], int p, int moneyBallRack, int &pt) {
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
  printFirstHalf(arr, pt);
  printSecondHalf(arr, pt);

  cout << "\n";
  cout << "Total Score: " << pt << endl;
}

void getInputs(string input1, string input2, int &scrubbed1, int &scrubbed2) {
  cout << "Player 1, Where do you want to put your money ball rack?" << endl;
  cout << "Enter 1-5: ";

  getline(cin, input1);
  scrubbed1 = inputScrubbing(input1);

  cout << "Scrubbed: " << scrubbed1 << endl;
  cout << "Player 2, Where do you want to put your money ball rack?" << endl;
  cout << "Enter 1-5: ";

  getline(cin, input2);
  scrubbed2 = inputScrubbing(input2);
  cout << "Scrubbed: " << scrubbed2 << endl;
}

// Game Driver
int main() {
  srand(time(NULL));
  bool running = true;
  string input1;
  string input2;
  int scrubbedInput1;
  int scrubbedInput2;
  int playerTotal1;
  int playerTotal2;
  char rack1[MAX_SIZE][MAX_SIZE];

  cout << "Welcome to the basketball shooting contest!" << endl;

  while (running) {
    getInputs(input1, input2, scrubbedInput1, scrubbedInput2);

    if (scrubbedInput1 == -1 || scrubbedInput2 == -1) {
      errorMsg();
    } else {
      playTurn(rack1, 1, scrubbedInput1, playerTotal1);
      playTurn(rack1, 2, scrubbedInput2, playerTotal2);
      checkWin(playerTotal1, playerTotal2);

      if (!playAgain())
        running = false;
      // clear buffer; throw away everything in input stream
      else
        clearBuffer();
    }
  }
  return 0;
}
