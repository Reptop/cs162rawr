/******************************************************
** Program: run_catalog.cpp
** Author: Raed Kabir
** Date: 10/29/2023
** Description: implements functions for entire program
** Input: string for filename, teams names, and player names. Ints for output
*type
** Output: A list of information depending on chosen command
******************************************************/
#include "catalog.h"
#include "game.h"
#include <fstream>

using namespace std;

// Driver code
int main() {
  // variable declarations
  string rawInput;
  int cleanInput;
  int length;
  string inputFile;
  ifstream fileStream;

  // dynamic team array initialized to nullptr
  struct Team *teamList = nullptr;

  // functions to start entire program
  getFileName(fileStream);

  // populates teamList
  teamList = initTeamList(teamList, fileStream, length);
  populate_team_data(teamList, length, fileStream);

  // sort players by their total ppg to start program
  performSortPlayers(teamList, length);

  while (true) {
    optionList(1);
    cout << "\n>> ";
    getline(cin, rawInput);
    cleanInput = inputScrubbing(rawInput);

    if (cleanInput == 6)
      break;
    else
      computeInput(teamList, cleanInput, length);
  }

  cout << "\nSee ya!\n" << endl;

  // delete all info in heap
  delete_info(teamList, length);

  return 0;
}
