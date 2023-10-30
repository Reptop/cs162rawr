#ifndef GAME_H
#define GAME_H

#include <iostream>
#define MAX_SIZE 5

using namespace std;

/*
 *Function: getInputs
 * Description: Takes in user input
 * Parameters: int for scrubbedinput, and for the player number
 * Pre-conditions: User must have inputted some number
 * Post Conditions: Assigns a number to scrubbedInput
 */
void getInputs(string, string, int &, int &);

/*
 *Function: playTurn
 * Description: Performs one turn for the player, including all background
 * Parameters: single pointer char array, int for player, moneyBallRack, score
 * Pre-conditions: User inputted their choice of moneyBallRack
 * Post Conditions: Computes a single turn for one player; outputs their board
 */
void playTurn(char arr[MAX_SIZE][MAX_SIZE], int, int, int &, double);

/*
 *Function: printAll
 * Description: To modulate my printBoard implementation; im not smart
 * Parameters: single pointer char array, int for total Score
 * Pre-conditions: Board must have fully been calculated
 * Post Conditions: Prints the entire board fully into terminal
 */
void printAll(char arr[MAX_SIZE][MAX_SIZE], int &, double);

/*
 *Function: inputChecking
 * Description: Scrubs input for only valid numbers (1-5)
 * Parameters: A string n
 * Pre-conditions: A user must have inputted something into input stream
 * Post Conditions: function parses through input and outputs and int
 */
int inputChecking(string);

/*
 *Function: printBoard
 * Description: Prints pieces of the board
 * Parameters: single pointer char array, int for total, start, limit, rac
 * Pre-conditions: board must be fully calculated
 * Post Conditions: Board will be outputted into terminal
 */
void printBoard(char arr[MAX_SIZE][MAX_SIZE], int &, int, int, int, double);

/*
 *Function: starryBalls
 * Description: Function for starry ball logic; returns 3 or 0
 * Parameters: N/A
 * Pre-conditions: board must be fully calculated
 * Post Conditions: Board will be populated with starrry balls
 */
int starryBalls(double);

/*
 *Function: computeBoard
 * Description: Computes logic for all racks; sets rack elements to X, O, or M
 * Parameters: single pointer char array, moneyBallRack id
 * Pre conditions: single pointer array must be initilized
 * Post Conditions: Board will be populated with specific game notation
 */
void computeBoard(char arr[MAX_SIZE][MAX_SIZE], int, double);

/*
 *Function: computeMoneyBoard
 * Description: Seperate function to only compute for the moneyBallRack
 * Parameters: Single pointer char array, integer for moneyBallRack id
 * Pre conditions: Game board must have been fully computed
 * Post Conditions: gameBoard is modified with moneyboard logic
 */
void computeMoneyBoard(char arr[MAX_SIZE][MAX_SIZE], int moneyBallRack, double);

/*
 *Function: playAgain
 * Description: Return false/true if user does not want to play again
 * Parameters: N/A
 * Pre conditions: Game must have ended
 * Post Conditions: Stops game loop or continues
 */
bool playAgain();

/*
 *Function: checkWin
 * Description: Calculates the winner of game
 * Parameters: two integer variables for player total score
 * Pre conditions: Both parameters should be initilized
 * Post Conditions: Outputs the winner of game
 */
void checkWin(int, int);

/*
 *Function: errorMsg
 * Description: outputs error message, prompting user to try again
 * Parameters: N/A
 * Pre conditions: Arrays must be initilized to correct types
 * Post Conditions: Prompts the user to try again
 */
void errorMsg();

/*
 *function: sucesss
 * description: returns true or false depending on a players fg percentage
 * parameters: double for player chance
 * pre conditions: used in the context of computing shot sucesss
 * post conditions: inputs X or O character in char array
 */
bool success(double);

#endif
