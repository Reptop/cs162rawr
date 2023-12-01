#ifndef CATALOG_H
#define CATALOG_H

#include <fstream>
#include <iostream>

using namespace std;

// a struct to hold info of a team
struct Team {
  string name;      // name of the team
  string owner;     // owner of the team
  int market_value; // market value of the team
  int num_player;   // number of players in the team
  struct Player *p; // an array that holds all players
  float total_ppg;  // total points per game
};

// a struct to hold info of a player
struct Player {
  string name;   // name of the player
  int age;       // age of the player
  string nation; // nationality of the player
  float ppg;     // points per game of the player
  float fg;      // field goal percentage
};

/**************************************************
 * Name: create_teams()
 * Description: This function will dynamically allocate
                an array of teams (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Team array of requested size is created and return
 ***********************************************/
Team *create_teams(int);

/**************************************************
 * Name: populate_team_data()
 * Description: This function will fill a single team struct
                with information that is read in from the file
 * Parameters:  Team* - pointer to the Team array
                int - index of the Team in the array to be filled
                ifstream& - input file to get information from
 * Pre-conditions: Team array has been allocated;
                   provided index is less than the array size
 * Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team *teamList, int, ifstream &);

/**************************************************
 * Name: create_players()
 * Description: This function will dynamically allocate
                an array of players (of the requested size)
 * Parameters: int - size of the array
 * Pre-conditions: none
 * Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player *create_players(int);

/**************************************************
 * Name: populate_player_data()
 * Description: This function will fill a single player struct
                with information that is read in from the file
 * Parameters:  Player* - pointer to the Player array
                int - index of the Player in the array to be filled
                ifstream& - input file to get information from
 * Pre-conditions: Player array has been allocated;
                   provided index is less than the array size
 * Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player *, int, ifstream &);

/**************************************************
 * Name: delete_info()
 * Description: This function will  delete all the memory that was dynamically
 *allocated Parameters: Team* - the Team array Pre-conditions: the provided Team
 *array hasn't been freed yet Post-conditions: the Team array, with all Players
 *inside, is freed
 ***********************************************/
void delete_info(Team *, int);

/*
 *Function: errorMsg
 * Description: outputs multiple error messages based on error ID
 * Parameters: error ID
 * Pre conditions: error ID must be initialized
 * Post Conditions: Prompts the user to try again
 */
void errorMsgs(int);

void optionList(int);

/*
 *Function: clearBuffer
 * Description: Clears input stream
 * Parameters: N/A
 * Pre conditions: Should have buffer present in input stream
 * Post Conditions: Input stream is cleared
 */
void clearBuffer();

/*
 *Function: inputScrubbing
 * Description: Scrubs string for valid integers
 * Parameters: an input string
 * Pre conditions: String parameter should be initilaized
 * Post Conditions: String is converted to an integer
 */
int inputScrubbing(string);

/*
 *Function: initTeamList
 * Description: initilizes dynamic array for teams
 * Parameters: Team pointer, filestream, int
 * Pre conditions: All paramters are declared
 * Post Conditions: Team array is initilaized
 */
Team *initTeamList(Team *, ifstream &, int &);

/*
 *Function: fileorScreen
 * Description: prompts user if they would want a console or file output
 * Parameters: N/A
 * Pre conditions: user chooses an option from list
 * Post Conditions: returns 1 or 2 depending on choice
 */
int fileOrScreen();

/*
 *Function: printTeamToConsole
 * Description: prompts user if they want the team info to console
 * Parameters: Team array, length of array, string input, boolean for found
 * Pre conditions: User chooses to print team info to connsole
 * Post Conditions: Team info is printed to console
 */
void printTeamToConsole(const Team *, int, string, bool &);

/*
 *Function: printTeamtoFile
 * Description: prompts user if they want the team info to file
 * Parameters: Team array, length of array, string input, boolean for found
 * Pre conditions: User chooses to print team info to connsole
 * Post Conditions: Team info is printed to file
 */
void printTeamToFile(const Team *, int, string, bool &);

/*
 *Function: searchTeam
 * Description: Searches for a specific team
 * Parameters: Team array, length of array
 * Pre conditions: User chooses search team option
 * Post Conditions: user is prompted for a display type
 */
void searchTeam(Team *, int);

/*
 *Function: getFileName
 * Description: prompts user for file name
 * Parameters: fileStream object
 * Pre conditions: program starts
 * Post Conditions: file is opened and user can access an optionList
 */
void getFileName(ifstream &);

/*
 *Function: printToptoConsole
 * Description: prints top scorers to the console
 * Parameters: Team array, array length
 * Pre conditions: user wants to output info to file
 * Post Conditions: top scorers are printed to console
 */
void printTopToConsole(const Team *, int);

/*
 *Function: printToptoFile
 * Description: prints top scorers to file
 * Parameters: Team array, array length
 * Pre conditions: user wants to output info to file
 * Post Conditions: top scorers are printed to file
 */
void printToptoFile(const Team *, int);

/*
 *Function: printToptoFile
 * Description: a functions to print top scorers to either console or file
 * Parameters: Team array, array length
 * Pre conditions: user wants to output the top scorers
 * Post Conditions: user is prompted for a display output
 */
void displayTop(Team *, int);

/*
 *Function: swapPlayers
 * Description: a function to swap players
 * Parameters: player array, player array length
 * Pre conditions: user wants to display top scorers
 * Post Conditions: player element is swapped
 */
void swapPlayers(Player *, Player *);

/*
 *Function: swapTeams
 * Description: a function to swap teams
 * Parameters: team array, team array length
 * Pre conditions: user wants to sort teams
 * Post Conditions: team element is swapped
 */
void swapTeams(Team *, Team *);

/*
 *Function: sortTeams
 * Description: a function to s
 * Parameters: player array, player array length
 * Pre conditions: user wants to sort teams
 * Post Conditions: player array is sorted
 */
void sortTeams(Player *, int);

/*
 * Function: computeTeamTotalPPG
 * Description: a function to compute a teams's total PPG
 * Parameters: Team array
 * Pre conditions: only called when user wants to sort by totalPPG
 * Post Conditions: returns the total PPG
 */
double computeTeamTotalPPG(const Team *);

/*
 * Function: sortTeamsByTotalPPG
 * Description: a function to sort teamss by total PPG
 * Parameters: Team array
 * Pre conditions: only called when user wants to sort by totalPPG
 * Post Conditions: Team array is sorted
 */
void sortTeamsByTotalPPG(Team *, int);

/*
 * Function: sortTeamsPrintConsole
 * Description: a function to print sorted array to console
 * Parameters: Team array
 * Pre conditions: user wants to print team array to console
 * Post Conditions: Sorted team array is printed to console
 */
void sortTeamPrintConsole(Team *, int);

/*
 * Function: sortTeamsPrintFile
 * Description: a function to print sorted array to file
 * Parameters: Team array, array length
 * Pre conditions: user wants to print team array to file
 * Post Conditions: Sorted team array is printed to file
 */
void sortTeamPrintFile(Team *, int);

/*
 * Function: performSortTeams
 * Description: overarching function to perform actual sort of teams
 * Parameters: Team array, array length
 * Pre conditions: user wants to sort teams
 * Post Conditions: user is prompted for display type
 */
void performSortTeams(Team *, int);

/*
 * Function: performSortPlayers
 * Description: overarching function to perform actual sort of players
 * Parameters: Player array, array length
 * Pre conditions: user wants to sort players
 * Post Conditions: user is prompted for display type
 */
void performSortPlayers(Team *, int);

/*
 * Function: printNationToConsole
 * Description: Function to display players of specific nation to console
 * Parameters: Team array, array length, string input, boolean for if found
 * Pre conditions: user wants to display info to console
 * Post Conditions: information is printed to console
 */
void printNationToConsole(const Team *, int, string, bool &);

/*
 * Function: printNationToFile
 * Description: Function to display players of specific nation to file
 * Parameters: Team array, array length, string input, boolean for if found
 * Pre conditions: user wants to display info to file
 * Post Conditions: information is printed to file
 */
void printNationToFile(const Team *, int, string, bool &);

/*
 * Function: searchNation
 * Description: checks if string input equals any player's nationality
 * Parameters: Team array, array length
 * Pre conditions: user wants search by nationality
 * Post Conditions: prompted for display type
 */
void searchNation(Team *, int);

/*
 * Function: gets player accuracy
 * Description: gets a specifc players accuracy
 * Parameters: Team array, array length, player name
 * Pre conditions: user wants to simulate a game
 * Post Conditions: prompts user for moneyball rack
 */
double getPlayerChance(Team *, int, string);

/*
 * Function: simulationNames
 * Description: gets player names for simulation
 * Parameters: Team array, string for player1, player2 double for players
 * Pre conditions: user wants to start a simluation
 * Post Conditions: Prompts user for moneyball rack
 */
void simulationNames(Team *, string &, string &, int, double &, double &);

/*
 * Function: simulate
 * Description: Driver for simulation
 * Parameters: Team array, array length
 * Pre conditions: user wants to start a simluation
 * Post Conditions: Prompts user for moneyball rack
 */
void simulate(Team *, int);

/*
 * Function: computeInput
 * Description: function to process user commands: 1,2,3 etc
 * Parameters: Team array, array length, int for command
 * Pre conditions: user inputs a number corresponding to a command
 * Post Conditions: processes desired command input
 */
void computeInput(Team *, int, int);

#endif
