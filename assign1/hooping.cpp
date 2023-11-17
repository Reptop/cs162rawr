/******************************************************
** Program: hooping.cpp
** Author: Raed Kabir
** Date: 10/5/2023
** Description: This program is a basketball shooting game simulator.
** Input: User inputs total number of desired players and their money ball rack.
** Output: This program outputs an entire score board with specific notation for
*each ball, and the total scores for each player and rack
******************************************************/

#include <iostream>
using namespace std;
#define MAX_SIZE 5

/*
 *Function: sucesss
 * Description: returns true or false depending on a 50/50 chance
 * Parameters: N/A
 * Pre conditions: used in the context of computing shot sucesss
 * Post Conditions: determines if array consits of specific notation
 */
bool success() {
  // implementing 50% chance
  if (rand() % 2 == 0)
    return false;
  else
    return true;
}

/*
 *Function: endGame
 * Description: Free's the entire 3D array, and the playerScore array
 * Parameters: triple pointer char array, pointer int array, int for players
 * Pre conditions: Arrays must be initilized to correct types
 * Post Conditions: Arrays must be deleted from heap
 */
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

/*
 *Function: errorMsg
 * Description: outputs error message, prompting user to try again
 * Parameters: N/A
 * Pre conditions: Arrays must be initilized to correct types
 * Post Conditions: Prompts the user to try again
 */
void errorMsg() {
  cout << "Invalid input." << endl;
  cout << "Inputs must be between 1 and 5 (inclusive)" << endl;
}

/*
 *Function: clearBuffer
 * Description: Clears input stream
 * Parameters: N/A
 * Pre conditions: Should have buffer present in input stream
 * Post Conditions: Input stream is cleared
 */
void clearBuffer() {
  cin.clear();
  cin.ignore(1000000, '\n');
}

/*
 *Function: checkWin
 * Description: Calculates the winner of game
 * Parameters: Pointer array for all scores, int for number of players
 * Pre conditions: Both arrays should be populated
 * Post Conditions: Outputs the winner of game
 */
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

/*
 *Function: playAgain
 * Description: Return false/true if user does not want to play again
 * Parameters: N/A
 * Pre conditions: Game must have ended
 * Post Conditions: Stops game loop or continues
 */
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

/*
 *Function: computeMoneyBoard
 * Description: Seperate function to only compute for the moneyBallRack
 * Parameters: Single pointer char array, integer for moneyBallRack id
 * Pre conditions: Game board must have been fully computed
 * Post Conditions: gameBoard is modified with moneyboard logic
 */
void computeMoneyBoard(char *arr[MAX_SIZE], int moneyBallRack) {
  for (int i = 0; i < MAX_SIZE; ++i) {
    if (success())
      arr[moneyBallRack][i] = 'M';
    else
      arr[moneyBallRack][i] = 'X';
  }
}

/*
 *Function: computeBoard
 * Description: Computes logic for all racks; sets rack elements to X, O, or M
 * Parameters: single pointer char array, moneyBallRack id
 * Pre conditions: single pointer array must be initilized
 * Post Conditions: Board will be populated with specific game notation
 */
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

/*
 *Function: starryBalls
 * Description: Function for starry ball logic; returns 3 or 0
 * Parameters: N/A
 * Pre-conditions: board must be fully calculated
 * Post Conditions: Board will be populated with starrry balls
 */
int starryBalls() {
  if (success()) {
    cout << "Starry: " << 'W' << "          | 3 pts" << endl;
    return 3;
  } else {
    cout << "Starry: " << 'X' << "          | 0 pts" << endl;
    return 0;
  }
}

/*
 *Function: printBoard
 * Description: Prints pieces of the board
 * Parameters: single pointer char array, int for total, start, limit, rac
 * Pre-conditions: board must be fully calculated
 * Post Conditions: Board will be outputted into terminal
 */
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

/*
 *Function: inputScrubbing
 * Description: Scrubs input for only valid numbers (1-5)
 * Parameters: A string n
 * Pre-conditions: A user must have inputted something into input stream
 * Post Conditions: function parses through input and outputs and int
 */
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

/*
 *Function: printAll
 * Description: To modulate my printBoard implementation; im not smart
 * Parameters: single pointer char array, int for total Score
 * Pre-conditions: Board must have fully been calculated
 * Post Conditions: Prints the entire board fully into terminal
 */
void printAll(char *arr[MAX_SIZE], int &pt) {
  printBoard(arr, pt, 0, 2, 1);
  printBoard(arr, pt, 2, 3, 3);
  printBoard(arr, pt, 3, 5, 4);
}

/*
 *Function: playTurn
 * Description: Performs one turn for the player, including all background
 * Parameters: single pointer char array, int for player, moneyBallRack, score
 * Pre-conditions: User inputted their choice of moneyBallRack
 * Post Conditions: Computes a single turn for one player; outputs their board
 */
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

/*
 *Function: getInputs
 * Description: Takes in user input
 * Parameters: int for scrubbedinput, and for the player number
 * Pre-conditions: User must have inputted some number
 * Post Conditions: Assigns a number to scrubbedInput
 */
void getInputs(int &scrubbed, int player) {
  string input;
  cout << "Player " << player
       << ", Where do you want to put your money ball rack?" << endl;
  cout << "Enter 1-5: ";
  getline(cin, input);
  scrubbed = inputScrubbing(input);
}

/*
 *Function: initRack
 * Description: Initialize each element in the 3D array to contain a 2D array
 * Parameters: N/A
 * Pre-conditions: User must have initilized a triple pointer
 * Post Conditions: assigns a 2D array for each player
 */
char **initRack() {
  char **rack = new char *[MAX_SIZE];
  for (int i = 0; i < MAX_SIZE; ++i)
    rack[i] = new char[MAX_SIZE];
  return rack;
}

/*
 *Function: getPlayers
 * Description: Gets total number of players playing the game
 * Parameters: int n for total players
 * Pre-conditions: Program must have started
 * Post Conditions: assigns total players to n
 */
void getPlayers(int &n) {
  bool valid = false;

  while (!valid) {
    cout << "How many players?: ";
    cin >> n;
    clearBuffer();
    valid = true;
  }
}

/*
 *Function: playGame
 * Description: Drives entire game for every player
 * Parameters: triple char pointer, total playes,array for scores
 * Pre-conditions: User must have typed in valid integer
 * Post Conditions: Program runs entire game
 */
void playGame(char ***racks, int players, int *playerScores) {

  int i;

  for (i = 0; i < players; i++) {
    racks[i] = initRack();
    int scrubbedInput;
    getInputs(scrubbedInput, i + 1);
    if (scrubbedInput == -1) {
      // Sets the iterator back by 1 due to invalid input
      errorMsg();
      for (int j = 0; j < MAX_SIZE; ++j)
        delete[] racks[i][j];
      delete[] racks[i];
      --i;
    } else {
      // play a turn for each player
      playerScores[i] = 0; // Initialize score to 0
      playTurn(racks[i], i + 1, scrubbedInput, playerScores[i]);
    }
  }
}
/*
 *Function: main
 * Description: Drives every function
 * Parameters: N/A
 * Pre-conditions: Program must start
 * Post Conditions: Calls every function in the game
 */
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
