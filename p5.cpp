// Alex Picon
// p5.cpp
// Purpose: Playing the game Monopoly with 2-6 players
// Input: Player count, player names, Enter key
// Output: The game monopoly, questions, a monopoly map

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// constants
const int MAX_ROLL = 6;
const int BONUS_TAX = 200;
const int CHANCE_BONUS = 50;
const int MIN_PLAYER = 2;
const int MAX_PLAYER = 6;
const int MAX_SPACE = 45;
const int BASE_VAL = 0;
const int BASE_MONEY = 1500;
const int CANT_BE_PURCHASED = -1;
const int PROPERTY_HAS_NO_OWNER = 0;
const char YES = 'y';
// special effects or positions
const string CHANCE = "Chance";
const string CHAPEL = "Chapel of St. Ignatius";
const string TAX_LOC = "Income Tax";
const string FEES_LOC = "Fees";
// widths for the map table
const int LOCATIONS_WIDTH = 38;
const int OWNER_WIDTH = 13;
const int PLAYERS_WIDTH = 29;
const string F_NAME = "/home/fac/sreeder/class/cs1420/p5input.dat";
// enabling autoplay will make 3 AIs play quickly.
// useful for testing
const bool AUTOPLAY = false;

struct BoardSpace {
    string name;
    int owner;
    int purchaseCost;
    int rentCost;
};

struct PlayerStats {
    string pName;
    int position = 0;
    int money = 1500;
    BoardSpace location;
};

void welcomeMessage();

void congratulateWinner(const PlayerStats playerArr[], int playerCount);

// reads file, sets boardspace arr if it fails it returns to main
// returns number of spaces on the board
bool setBoard(BoardSpace board[], int &spaceCount);

// finds number of players
int askPlayersNumber();

// for each player, values reset and player gets a name
void askPlayersNames(PlayerStats playerArr[], int playerCount);

// starts a new game, sets all values of players and board owners
// asks for number of players and names
void newGame(BoardSpace board[], PlayerStats playerArr[], int &playerCount,
             int &playerTurn, bool &isGameActive);

// helper function to display every message with the player name
string playerPrefix(PlayerStats player);

// displays die rolls and return total
int getTotalRollValue(PlayerStats playerArr[], int playerTurn);

// when a player passes through go, give them bonus and recalculate position
void
playerPassesThroughGo(PlayerStats playerArr[], int playerTurn, int spaceCount);

// handle reward when chance benefits player
void playerChanceBonus(PlayerStats playerArr[], int playerTurn);

// handle moving player to the chapel
void playerChanceToChapel(BoardSpace board[], PlayerStats playerArr[],
                          int playerTurn);

// handle chance, throws dice and calls appropiate handler
void playerLandedOnChance(BoardSpace board[], PlayerStats playerArr[],
                          int playerTurn);

// collect tax from players
void playerLandedOnTaxCollection(PlayerStats playerArr[], int playerTurn);

// charges rent from player
void playerLandedInOwnedProperty(PlayerStats playerArr[], int playerTurn);

// player chooses to buy unowned property and has enough money
void playerBuysProperty(BoardSpace board[], PlayerStats playerArr[],
                        int playerTurn);

// ask player if property should be bought, handle response
void playerLandedInBuyableProperty(BoardSpace board[], PlayerStats playerArr[],
                                   int playerTurn);

// handle case when a user lands in unowned property but can't afford purchase
void playerLandedInPropertyWithoutEnoughMoney(PlayerStats playerArr[],
                                              int playerTurn);

// displays a message with the player's money at the end of the turn
void
displayMoneyEndingTurn(const PlayerStats playerArr[], const int playerTurn);

// returns if game isn't over, changes player position and money
// changes ownership of spaces on the board
bool isNextTurn(BoardSpace board[], PlayerStats playerArr[], int playerTurn,
                int spaceCount);

void goodbyeMessage();

// returns a value between 1 and MAX_ROLL
int rollDice();

// pauses the game momentarily until the user hits enter
void pauseGame();

// returns true when receiving YES, can be autoplayed
bool isPositiveAnswer();

// returns true when receiving YES, always asks user, can't be autoplayed
bool isPositiveUserAnswer();

// displays headers for the "game map"
void showGameHeaders();

// displays the "game map"
void showGame(const BoardSpace board[], const PlayerStats playerArr[],
              int spaceCount, int playerCount);

int main()
{
  int playerCount;
  int playerTurn;
  int spaceCount;
  bool playAgain;
  bool isGameActive;
  PlayerStats playerArr[MAX_PLAYER];
  BoardSpace board[MAX_SPACE];

  srand(time(0));

  welcomeMessage();

  // if board doesn't set up, it turns off the game
  if (setBoard(board, spaceCount)) {
    cout << "file failure...exiting program...press enter";
    pauseGame();
    return 0;
  }

  cout << "Ready to play? (y/n): ";
  playAgain = isPositiveAnswer();

  while (playAgain) {
    newGame(board, playerArr, playerCount, playerTurn, isGameActive);

    while (isGameActive) {
      isGameActive = isNextTurn(board, playerArr, playerTurn, spaceCount);
      showGame(board, playerArr, spaceCount, playerCount);

      playerTurn++;

      if (playerTurn >= playerCount) {
        playerTurn = 0;
      }
    }

    congratulateWinner(playerArr, playerCount);

    cout << "Do you want to play again? (y/n) ";
    playAgain = isPositiveUserAnswer();
  }

  goodbyeMessage();

  return 0;
}

void welcomeMessage()
{
  cout << endl << endl
       << "-----------------------------------------------" << endl
       << " Welcome to Alex's Monopoly! 👾" << endl
       << " *Affiliated with Seattle U*" << endl
       << " Time to play! 🤙" << endl
       << "-----------------------------------------------" << endl
       << " Remain financially solvent, force opponents " << endl
       << " into bankrupcy, and have fun buying and " << endl
       << " developing properties. Good luck and have fun!" << endl
       << "-----------------------------------------------" << endl << endl;
}

void congratulateWinner(const PlayerStats playerArr[], const int playerCount)
{
  int winnerAmount = BASE_VAL;
  string winner;

  for (int i = 0; i < playerCount; i++) {
    if (playerArr[i].money > winnerAmount) {
      winner = playerArr[i].pName;
    }
  }

  cout << "Congratulations " << winner << ", you have won!";
  cout << endl << endl;
}

bool setBoard(BoardSpace board[], int &spaceCount)
{
  ifstream infile;
  string storeLine;
  spaceCount = 0;

  infile.open(F_NAME);

  if (infile.fail()) {
    return true;
  }

  // using while instead of for cuz MAX_SPACE
  // is only the max number of tiles not the actual total
  while (getline(infile, board[spaceCount].name)) {
    infile >> board[spaceCount].owner;
    infile >> board[spaceCount].purchaseCost;
    infile >> board[spaceCount].rentCost;

    getline(infile, storeLine);
    spaceCount++;
  }

  infile.close();
  return false;
}

int askPlayersNumber()
{
  int playerCount;
  if (AUTOPLAY) {
    playerCount = 3;

  } else {
    playerCount = -1;

    while (playerCount > MAX_PLAYER || playerCount < MIN_PLAYER) {
      cout << "How many players? (2-6): ";
      cin >> playerCount;
    }
  }

  return playerCount;
}

void askPlayersNames(PlayerStats playerArr[], const int playerCount)
{
  for (int i = 0; i < playerCount; i++) {
    cout << "Player " << i + 1 << ", what is your name? ";

    if (AUTOPLAY) {
      const string names[4] = {"Drago", "Sandor", "Khaleesi"};
      playerArr[i].pName = names[i];

    } else {
      cin >> playerArr[i].pName;
    }
    playerArr[i].position = BASE_VAL;
    playerArr[i].money = BASE_MONEY;
  }
}

void newGame(BoardSpace board[], PlayerStats playerArr[], int &playerCount,
             int &playerTurn, bool &isGameActive)
{
  // resetting values to their base
  playerCount = BASE_VAL;
  isGameActive = true;

  // resetting BoardSpace ownership
  for (int i = 0; i < MAX_SPACE; i++) {
    if (board[i].owner != CANT_BE_PURCHASED) {
      board[i].owner = BASE_VAL;
    }
  }

  playerCount = askPlayersNumber();
  askPlayersNames(playerArr, playerCount);
  cout << endl;

  // makes first player random based on number of players
  playerTurn = rand() % playerCount;
  pauseGame();
}

string playerPrefix(PlayerStats player)
{
  string ret = "[" + player.pName + "] ";
  return ret;
}

int getTotalRollValue(PlayerStats playerArr[], int playerTurn)
{
  int roll1, roll2, total;
  string prefix = playerPrefix(playerArr[playerTurn]);

  cout << prefix << playerArr[playerTurn].pName << " it is your turn!" << endl
       << prefix << "You currently have " << playerArr[playerTurn].money
       << " bucks!" << endl << endl
       << prefix << "Hit enter to roll the dice: ";

  pauseGame();

  roll1 = rollDice();
  roll2 = rollDice();
  total = roll1 + roll2;

  cout << endl;
  cout << prefix << "Your first roll is a " << roll1 << " and your second roll is a "
       << roll2 << "." << endl
       << prefix << "Move " << total << " spaces forward." << endl << endl;

  return total;
}

void playerPassesThroughGo(PlayerStats playerArr[], const int playerTurn,
                           const int spaceCount)
{
  playerArr[playerTurn].position -= spaceCount;
  playerArr[playerTurn].money += BONUS_TAX;

  cout << playerPrefix(playerArr[playerTurn]) << "You have collected "
       << BONUS_TAX << " for passing through Go" << endl;
}

void playerChanceBonus(PlayerStats playerArr[], const int playerTurn)
{
  playerArr[playerTurn].money += CHANCE_BONUS;

  cout << playerPrefix(playerArr[playerTurn]) << "You have gained "
       << CHANCE_BONUS << " bucks!" << endl;
}

void playerChanceToChapel(BoardSpace board[], PlayerStats playerArr[],
                          const int playerTurn)
{
  cout << playerPrefix(playerArr[playerTurn]) << "You have been moved to "
       << CHAPEL << ".";

  for (int i = 0; i < MAX_SPACE; i++) {
    if (board[i].name == CHAPEL) {
      playerArr[playerTurn].position = i;
      playerArr[playerTurn].location = board[i];
    }
  }
}

void playerLandedOnChance(BoardSpace board[], PlayerStats playerArr[],
                          const int playerTurn)
{
  int chanceRoll;
  string prefix = playerPrefix(playerArr[playerTurn]);
  cout << prefix << "You have landed on a Chance tile, something will happen!"
       << endl << prefix << "Hit enter to see what happens: ";

  pauseGame();

  chanceRoll = rand() % MAX_ROLL + 1;
  cout << prefix << "You rolled a " << chanceRoll << "." << endl;

  // chance outcome spot
  if (chanceRoll <= MAX_ROLL / 2) {
    playerChanceBonus(playerArr, playerTurn);

  } else {
    playerChanceToChapel(board, playerArr, playerTurn);
  }

  pauseGame();
  cout << endl;
}

void playerLandedOnTaxCollection(PlayerStats playerArr[],
                                 const int playerTurn)
{
  string prefix = playerPrefix(playerArr[playerTurn]);

  cout << prefix << "You pay " << BONUS_TAX << " bucks in taxes!" << endl;
  playerArr[playerTurn].money -= BONUS_TAX;

  pauseGame();

  cout << endl;
}

void playerLandedInOwnedProperty(PlayerStats playerArr[], int playerTurn)
{
  BoardSpace currLocation = playerArr[playerTurn].location;
  string prefix = playerPrefix(playerArr[playerTurn]);
  playerArr[playerTurn].money -= currLocation.rentCost;
  playerArr[currLocation.owner - 1].money += currLocation.rentCost;

  cout << prefix << "Unlucky! This space is owned by "
       << playerArr[currLocation.owner - 1].pName << "." << endl
       << prefix << playerArr[currLocation.owner - 1].pName << " takes "
       << currLocation.rentCost << " bucks due to rent." << endl;

  pauseGame();
}

void playerBuysProperty(BoardSpace board[], PlayerStats playerArr[],
                        int playerTurn)
{
  BoardSpace currLocation = playerArr[playerTurn].location;
  string prefix = playerPrefix(playerArr[playerTurn]);

  cout << endl << prefix << "You bought " << currLocation.name << " for "
       << currLocation.purchaseCost << "." << endl;

  board[playerArr[playerTurn].position].owner = playerTurn + 1;
  playerArr[playerTurn].money -= currLocation.purchaseCost;
}

void playerLandedInBuyableProperty(BoardSpace board[], PlayerStats playerArr[],
                                   int playerTurn)
{
  BoardSpace currLocation = playerArr[playerTurn].location;
  string prefix = playerPrefix(playerArr[playerTurn]);

  cout << prefix << "Do you want to buy this property for "
       << currLocation.purchaseCost << "? ";

  if (playerArr[playerTurn].money == currLocation.purchaseCost) {
    cout << endl << prefix << "[WARNING: buying this property will bankrupt you, are you sure?]";
  }

  cout << "(y/n)";
  if (isPositiveAnswer()) {
    playerBuysProperty(board, playerArr, playerTurn);

  } else {
    cout << prefix << "You passed on " << currLocation.name;
  }

  pauseGame();
}

void playerLandedInPropertyWithoutEnoughMoney(PlayerStats playerArr[],
                                              int playerTurn)
{
  string prefix = playerPrefix(playerArr[playerTurn]);
  cout << prefix << "You don't have enough money to buy this property.";
  pauseGame();
}

void displayMoneyEndingTurn(const PlayerStats playerArr[], const int playerTurn)
{
  string prefix = playerPrefix(playerArr[playerTurn]);
  cout << prefix;

  if (playerArr[playerTurn].money > 0) {
    cout << "You end the turn with " << playerArr[playerTurn].money
         << " bucks.";

  } else {
    cout << "You lost all your money :(";
  }

  cout << endl << endl;
}

bool isNextTurn(BoardSpace board[], PlayerStats playerArr[], int playerTurn,
                int spaceCount)
{
  BoardSpace currLocation;
  string locationName;
  int locationOwner;
  string prefix = playerPrefix(playerArr[playerTurn]);

  playerArr[playerTurn].position += getTotalRollValue(playerArr, playerTurn);

  // checks if player goes directly over go
  if (playerArr[playerTurn].position >= spaceCount) {
    playerPassesThroughGo(playerArr, playerTurn, spaceCount);
  }

  playerArr[playerTurn].location = board[playerArr[playerTurn].position];
  currLocation = playerArr[playerTurn].location;
  locationName = currLocation.name;
  locationOwner = currLocation.owner;

  cout << prefix << playerArr[playerTurn].pName << ", you have landed on "
       << locationName << ".";

  pauseGame();
  cout << endl << endl;

  if (locationName == CHANCE) {
    playerLandedOnChance(board, playerArr, playerTurn);

  } else if (locationName == TAX_LOC || locationName == FEES_LOC) {
    playerLandedOnTaxCollection(playerArr, playerTurn);

  } else if (locationOwner == PROPERTY_HAS_NO_OWNER) {

    if (playerArr[playerTurn].money >= currLocation.purchaseCost) {
      playerLandedInBuyableProperty(board, playerArr, playerTurn);

    } else {
      playerLandedInPropertyWithoutEnoughMoney(playerArr, playerTurn);
    }

  } else if (locationOwner != playerTurn + 1 &&
             locationOwner != CANT_BE_PURCHASED) {
    playerLandedInOwnedProperty(playerArr, playerTurn);
  }

  displayMoneyEndingTurn(playerArr, playerTurn);

  // checks if the player has no money and stops right there
  if (playerArr[playerTurn].money <= BASE_VAL) {
    return false;
  }

  return true;
}

void goodbyeMessage()
{
  cout << endl << endl
       << "See you next time! Hope you enjoyed 👋 "
       << endl << endl;
}

int rollDice()
{
  return rand() % MAX_ROLL + 1;
}

void pauseGame()
{
  if (!AUTOPLAY) {
    cin.get();
  }
}

bool isPositiveUserAnswer()
{
  char response;
  cin >> response;
  return tolower(response) == YES;
}

bool isPositiveAnswer()
{
  bool result;
  if (AUTOPLAY) {
    result = true;

  } else {
    result = isPositiveUserAnswer();
  }

  return result;
}

void showGameHeaders()
{
  cout << left << setw(LOCATIONS_WIDTH) << "Locations";
  cout << left << setw(OWNER_WIDTH) << "Owner";
  cout << left << setw(PLAYERS_WIDTH) << "Players in Location";
  cout << endl;
  cout << left << setw(LOCATIONS_WIDTH);
  cout << string(LOCATIONS_WIDTH - 1, '-');
  cout << left << setw(OWNER_WIDTH);
  cout << string(OWNER_WIDTH - 1, '-');
  cout << left << setw(PLAYERS_WIDTH);
  cout << string(PLAYERS_WIDTH - 1, '-');
  cout << endl;
}

void showGame(const BoardSpace board[], const PlayerStats playerArr[],
              const int spaceCount, const int playerCount)
{
  string players;
  showGameHeaders();
  for (int i = 0; i < spaceCount; i++) {
    cout << left << setw(LOCATIONS_WIDTH) << board[i].name;
    cout << left << setw(OWNER_WIDTH);
    if (board[i].owner != PROPERTY_HAS_NO_OWNER &&
        board[i].owner != CANT_BE_PURCHASED) {
      cout << playerArr[board[i].owner - 1].pName;

    } else {
      cout << "";
    }

    players = "";

    for (int pnum = 0; pnum < playerCount; pnum++) {
      if (i == playerArr[pnum].position) {
        players += playerArr[pnum].pName + " ";
      }
    }

    cout << left << setw(PLAYERS_WIDTH) << players;
    cout << endl;
  }

  cout << endl;
}