/******************************************************
** Program: catalog.cpp
** Author: Raed Kabir
** Date: 10/29/2023
** Description: Contains functions definitions for entire program
** Input: NA - this file only contains function definitions
** Output: NA - this file only contains functions definitions
******************************************************/

#include "catalog.h"
#include "game.h"
#include <fstream>
#include <iostream>

using namespace std;

//***************************************************
// Beginning of required functions

Team *create_teams(int n) {
  Team *teamList = new Team[n];
  return teamList;
}

Player *create_players(int n) {
  Player *playerList = new Player[n];

  return playerList;
}

void populate_player_data(Player *playerList, int n, ifstream &fileStream) {
  for (int i = 0; i < n; ++i) {
    fileStream >> playerList[i].name >> playerList[i].age >>
        playerList[i].nation >> playerList[i].ppg >> playerList[i].fg;
  }
}

void populate_team_data(Team *teamList, int n, ifstream &fileStream) {
  for (int i = 0; i < n; ++i) {
    fileStream >> teamList[i].name >> teamList[i].owner >>
        teamList[i].market_value >> teamList[i].num_player;

    teamList[i].p = create_players(teamList[i].num_player);
    populate_player_data(teamList[i].p, teamList[i].num_player, fileStream);
  }
}

void delete_info(Team *teamList, int n) {
  for (int i = 0; i < n; ++i) {
    // delete Player array in each Team struct
    // this deletes data inside out
    delete[] teamList[i].p;
    teamList[i].p = nullptr;
  }
  delete[] teamList;
  teamList = nullptr;
}

//***************************************************
// End of required functions

//***************************************************
// Beginning of self-made functions for user input and console output

// error messeges for a given error ID
void errorMsgs(int n) {
  switch (n) {
  case 1:
    cout << "\n        Team could not be found!\n" << endl;
    break;
  case 2:
    cout << "\n       The file does not exist!\n" << endl;
    break;
  case 3:
    cout << "\nInvalid Input! Enter a number 1-6 (inclusive)\n" << endl;
    break;
  }
}

// to print out every options
void optionList(int n) {
  switch (n) {
  case 1:
    cout << "\nWhich option would you like to choose?" << endl;
    cout << "1. Search team by its name" << endl;
    cout << "2. Display the top scorer of each team" << endl;
    cout << "3. Search players by nationality" << endl;
    cout << "4. Sort teams by total points per game" << endl;
    cout << "5. Simulate basketball game" << endl;
    cout << "6. Quit" << endl;
    break;

  case 2:
    cout << "How would you like the information displayed?" << endl;
    cout << "1. Print to screen (Press 1)" << endl;
    cout << "2. Print to file (Press 2)" << endl;
    break;
  }
}

// clear buffer in input stream
void clearBuffer() {
  cin.clear();
  cin.ignore(1000000, '\n');
}

// scrub for only valid inputs
int inputScrubbing(string n) {
  if (n == "1" || n == "2" || n == "3" || n == "4" || n == "5" || n == "6")
    return n[0] - '0';
  return -1;
}

// initilize the team dynamic array
Team *initTeamList(Team *teamList, ifstream &fileStream, int &length) {
  fileStream >> length;
  teamList = create_teams(length);

  return teamList;
}

// a functions that allows user to decide for printing to file or screen
int fileOrScreen() {
  string choice;
  int scrubbedChoice;

  optionList(2);

  while (true) {
    cout << ">> ";
    getline(cin, choice);
    scrubbedChoice = inputScrubbing(choice);

    if (scrubbedChoice == 1)
      return 1;
    else if (scrubbedChoice == 2)
      return 2;
    else if (cin.fail() || scrubbedChoice == -1) {
      cout << "Invalid Input. Enter a number (1 or 2)" << endl;
    }
  }
}
//***********************************************************
// End of functions for user input and console output

//***********************************************************
// Beginning self-made functions containing logic for core procsses

// prints player to console
void printConsoleTeamPlayers(const Player *playerList, int length) {
  cout << "\nAll Players: \n" << endl;
  for (int i = 0; i < length; ++i) {
    cout << "NAME: " << playerList[i].name << endl;
    cout << "AGE: " << playerList[i].age << endl;
    cout << "NATIONALITY: " << playerList[i].nation << endl;
    cout << "POINTER PER GAME: " << playerList[i].ppg << endl;
    cout << "FIELD GOAL PERCENTAGE: " << playerList[i].fg << endl;
    cout << "\n";
  }
}

// prints team player to file
void printFileTeamPlayers(const Player *playerList, int length,
                          ofstream &outFile) {

  outFile << "\nAll Players: \n" << endl;
  for (int i = 0; i < length; ++i) {
    outFile << "NAME: " << playerList[i].name << endl;
    outFile << "AGE: " << playerList[i].age << endl;
    outFile << "NATIONALITY: " << playerList[i].nation << endl;
    outFile << "POINTER PER GAME: " << playerList[i].ppg << endl;
    outFile << "FIELD GOAL PERCENTAGE: " << playerList[i].fg << endl;
    outFile << "\n";
  }
}

// prints team to console
void printTeamToConsole(const Team *teamList, int length, string nameInput) {
  bool found = false;

  for (int i = 0; i < length; ++i) {
    if (teamList[i].name == nameInput) {
      cout << "\nResult: " << endl;
      cout << "NAME: " << teamList[i].name << endl;
      cout << "OWNER: " << teamList[i].owner << endl;
      cout << "MARKET VALUE: " << teamList[i].market_value << endl;
      cout << "# OF PLAYERS: " << teamList[i].num_player << endl;
      printConsoleTeamPlayers(teamList[i].p, teamList[i].num_player);
      found = true;
      break;
    } else
      continue;
  }
  if (!found) {
    errorMsgs(1);
  }
}

// prints team to file
void printTeamToFile(const Team *teamList, int length, string nameInput) {
  string fileName;
  bool found = false;

  cout << "Please provide desired filename: ";
  getline(cin, fileName);
  // clearBuffer();

  ofstream outFile(fileName, ios::app);

  for (int i = 0; i < length; ++i) {
    if (teamList[i].name == nameInput) {
      outFile << "\nResult: " << endl;
      outFile << "NAME: " << teamList[i].name << endl;
      outFile << "OWNER: " << teamList[i].owner << endl;
      outFile << "MARKET VALUE: " << teamList[i].market_value << endl;
      outFile << "# OF PLAYERS: " << teamList[i].num_player << endl;
      outFile << "\n";
      printFileTeamPlayers(teamList[i].p, teamList[i].num_player, outFile);
      found = true;
      break;
    } else
      continue;
  }
  if (found)
    cout << "\nFile Appended!" << endl;
  else
    errorMsgs(1);
}

// To search for specific team
void searchTeam(Team *teamList, int length) {
  int outputType = fileOrScreen();
  string nameInput;
  bool found = false;

  cout << "Enter the team's name: ";
  getline(cin, nameInput);

  if (outputType == 1)
    printTeamToConsole(teamList, length, nameInput);

  else if (outputType == 2)
    printTeamToFile(teamList, length, nameInput);
}

// To search for specific file name; otherwise, reprompt
void getFileName(ifstream &fileStream) {
  string inputFile;

  while (true) {
    cout << "Enter a file name: ";
    cin >> inputFile;
    clearBuffer();
    fileStream.open(inputFile);

    if (fileStream.fail()) {
      errorMsgs(2);
      fileStream.clear();
    }

    else {
      cout << "\nFile Opened!" << endl;
      break;
    }
  }
}

// Print top scoreers specific team
void printToptoFile(const Team *teamList, int length) {
  string fileName;

  cout << "Please provide desired filename: ";
  getline(cin, fileName);

  ofstream outFile(fileName, ios::app);

  outFile << "\nTop scorer for each team: \n" << endl;

  outFile << "--------------------------------------------" << endl;
  for (int i = 0; i < length; ++i) {
    outFile << "TEAM NAME: " << teamList[i].name << endl;
    outFile << "TOP SCORER: " << teamList[i].p[0].name << endl;
    outFile << "POINTS PER GAME: " << teamList[i].p[0].ppg << endl;
    outFile << "\n";
  }
  outFile << "--------------------------------------------" << endl;

  cout << "\nFile Appended!\n" << endl;
}

void printTopToConsole(const Team *teamList, int length) {

  cout << "\nTop scorer for each team: \n" << endl;

  cout << "--------------------------------------------" << endl;

  for (int i = 0; i < length; ++i) {
    cout << "TEAM NAME: " << teamList[i].name << endl;
    cout << "TOP SCORER: " << teamList[i].p[0].name << endl;
    cout << "POINTS PER GAME: " << teamList[i].p[0].ppg << endl;
    cout << "\n";
  }
  cout << "--------------------------------------------" << endl;
}

void displayTop(Team *teamList, int length) {
  int outputType = fileOrScreen();

  if (outputType == 1)
    printTopToConsole(teamList, length);
  else if (outputType == 2)
    printToptoFile(teamList, length);
}

void performSortTeams(Team *teamList, int length) {
  sortTeamsByTotalPPG(teamList, length);
  int outputType = fileOrScreen();

  if (outputType == 1)
    sortTeamPrintConsole(teamList, length);
  else if (outputType == 2)
    sortTeamPrintFile(teamList, length);
}

void performSortPlayers(Team *teamList, int length) {
  for (int i = 0; i < length; ++i)
    sortTeams(teamList[i].p, teamList[i].num_player);
}

void printNationToConsole(const Team *teamList, int length, string nation,
                          bool &found) {
  cout << "-----------------------------------------" << endl;
  cout << "Results: " << endl;

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < teamList[i].num_player; ++j) {
      if (teamList[i].p[j].nation == nation) {
        cout << "NAME: " << teamList[i].p[j].name << endl;
        cout << "AGE: " << teamList[i].p[j].age << endl;
        cout << "\n";
        found = true;
      }
    }
  }
  if (!found)
    cout << "\nPlayer not found!\n" << endl;
  cout << "-----------------------------------------" << endl;
}

void printNationToFile(const Team *teamList, int length, string nation,
                       bool &found) {
  string fileName;
  cout << "Please provide desired filename: ";
  getline(cin, fileName);
  ofstream outFile(fileName, ios::app);

  outFile << "-----------------------------------------" << endl;
  outFile << "Results: " << endl;

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < teamList[i].num_player; ++j) {
      if (teamList[i].p[j].nation == nation) {
        outFile << "NAME: " << teamList[i].p[j].name << endl;
        outFile << "AGE: " << teamList[i].p[j].age << endl;
        outFile << "\n";
        found = true;
      }
    }
  }

  if (!found)
    cout << "\nPlayer not found!\n" << endl;

  outFile << "-----------------------------------------";
}

void searchNation(Team *teamList, int length) {
  int outputType = fileOrScreen();
  string nation;
  bool found = false;

  cout << "Enter the player’s nationality: ";
  getline(cin, nation);

  if (outputType == 1)
    printNationToConsole(teamList, length, nation, found);

  else if (outputType == 2)
    printNationToFile(teamList, length, nation, found);
}

void swapPlayers(Player *a, Player *b) {
  // make a temp for swapping purposes
  Player temp = *a;
  *a = *b;
  *b = temp;
}

void sortTeams(Player *arr, int length) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; i < length - j - 1; j++) {
      if (arr[j].ppg < arr[j + 1].ppg)
        swapPlayers(&arr[j], &arr[j + 1]);
    }
  }
}

// End of self-made functions for core procsses
//******************************************************************

// Beginning of Extra credit functions
//******************************************************************

void swapTeams(Team *a, Team *b) {
  // make a temp for swapping purposes
  Team temp = *a;
  *a = *b;
  *b = temp;
}

double computeTeamTotalPPG(const Team *team) {
  double totalPPG = 0.0;
  for (int i = 0; i < team->num_player; ++i) {
    totalPPG += team->p[i].ppg;
  }
  return totalPPG;
}

void sortTeamsByTotalPPG(Team *teamList, int length) {
  for (int i = 0; i < length - 1; ++i) {
    for (int j = 0; j < length - i - 1; ++j) {
      if (computeTeamTotalPPG(&teamList[j]) <
          computeTeamTotalPPG(&teamList[j + 1])) {
        // swap teams
        swapTeams(&teamList[j], &teamList[j + 1]);
      }
    }
  }
}

void sortTeamPrintConsole(Team *teamList, int length) {
  cout << "-----------------------------------------" << endl;
  cout << "\nSorted Teams by Total PPG:\n";
  for (int i = 0; i < length; ++i) {
    cout << "TEAM NAME: " << teamList[i].name << endl;
    cout << "TOTAL PPG: " << computeTeamTotalPPG(&teamList[i]) << endl;
    cout << "\n";
  }
  cout << "-----------------------------------------" << endl;
}

void sortTeamPrintFile(Team *teamList, int length) {
  string fileName;
  cout << "Please provide desired filename: ";
  getline(cin, fileName);
  ofstream outFile(fileName, ios::app);

  outFile << "-----------------------------------------" << endl;
  outFile << "\nSorted Teams by Total PPG:\n";
  for (int i = 0; i < length; ++i) {
    outFile << "TEAM NAME: " << teamList[i].name << endl;
    outFile << "TOTAL PPG: " << computeTeamTotalPPG(&teamList[i]) << endl;
    outFile << "\n";
  }
  outFile << "-----------------------------------------" << endl;
  cout << "\nFile Appended!" << endl;
}

void simulate(Team *teamList, int length) {
  string input1;
  string input2;
  string name1;
  string name2;
  int scrubbedInput1;
  int scrubbedInput2;
  int playerTotal1;
  int playerTotal2;
  double chance1;
  double chance2;
  char rack1[MAX_SIZE][MAX_SIZE];

  srand(time(NULL));
  cout << "\nStarted Basketball Simulator\n" << endl;
  simulationNames(teamList, name1, name2, length, chance1, chance2);

  while (true) {
    getInputs(input1, input2, scrubbedInput1, scrubbedInput2);

    if (scrubbedInput1 == -1 || scrubbedInput2 == -1)
      errorMsg();
    else {
      playTurn(rack1, 1, scrubbedInput1, playerTotal1, chance1);
      playTurn(rack1, 2, scrubbedInput2, playerTotal2, chance2);
      checkWin(playerTotal1, playerTotal2);

      if (!playAgain()) {
        clearBuffer();
        break;
      }
      // clear buffer; throw away everything in input stream
      else
        clearBuffer();
    }
  }
}

void simulationNames(Team *teamList, string &name1, string &name2, int length,
                     double &chance1, double &chance2) {
  while (true) {
    cout << "Enter the name for player 1: ";
    getline(cin, name1);
    cout << "Enter the name for player 2: ";
    getline(cin, name2);

    if (getPlayerChance(teamList, length, name1) == -1 ||
        (getPlayerChance(teamList, length, name2) == -1))
      cout << "\nCould not find players!\n" << endl;
    else {
      chance1 = getPlayerChance(teamList, length, name1);
      chance2 = getPlayerChance(teamList, length, name2);
      break;
    }
  }
}

double getPlayerChance(Team *teamList, int length, string name) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < teamList[i].num_player; ++j) {
      if (teamList[i].p[j].name == name)
        return teamList[i].p[j].fg;
    }
  }
  return -1;
}
// End of Extra credit functions
//******************************************************************

// Start of driver function for core procsses
//******************************************************************
void computeInput(Team *teamList, int n, int length) {
  switch (n) {
  case 1:
    searchTeam(teamList, length);
    break;
  case 2:
    displayTop(teamList, length);
    break;
  case 3:
    searchNation(teamList, length);
    break;
  case 4:
    performSortTeams(teamList, length);
    break;
  case 5:
    simulate(teamList, length);
    break;
  case -1:
    errorMsgs(3);
  }
}

// End of driver function for core procsses
//******************************************************************
