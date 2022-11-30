// Alex Picon
// p4.cpp
// Purpose: Playing a memory game
// Input: Experience level (Beg. or Exp.), c1Rowand c1Column chosen 
// Output: The memory game (board game, questions, etc.)

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// constants
const int BEGINNER_SECONDS = 5;
const int EXPERT_SECONDS = 2;
const int SCREEN_HEIGHT = 40;
const int MAX_MATCHES = 6;
const int PROCESS_TIME = 2;
const int SIZE = 12;
const int ROW = 3;
const int COL = 4;
const int COL_WIDTH = 3;
const int R_CHECK = -1;
const int C_CHECK = -1;
const char YES = 'y';
const char BEG = 'b';
const char EXP = 'e';
const char SPACE = ' ';
const char STAR = '*';
const char BLANK = '_';
const char OPEN = '[';
const char CLOSE = ']';
const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";

// function declaring
void welcomeMessage();
int getExperience();
void waitingTime(int seconds);
bool readFile(char board[][COL]);
void displayBoard(const char board[][COL], int c1Row = -1, int c1Col = -1, 
int c2Row = -1, int c2Col = -1);
void getFirstCard(char board[][COL], int &c1Row, int &c1Col);
void getSecondCard(char board[][COL], int &c2Row, int &c2Col, int c1Row, int c1Col);
void clearScreen();
void goodbyeMessage();

// functions
int main()
{
  char board[ROW][COL];
  char ans;
  int card1Row, card1Col;
  int card2Row, card2Col;
  int turns = 0; 
  int matches = 0;
  int waitSeconds;

  cout << endl << endl;

  srand(time(0));

  welcomeMessage();

  cout << "Would you like to play? (y/n) ⎆ ";
  cin >> ans;
  cin.get();

  while(tolower(ans) == YES){
    waitSeconds = getExperience();

    if(readFile(board)){
      return 0;
    }

    matches = 0;
    turns = 0;

    while(SIZE/2 > matches && SIZE/2 <= MAX_MATCHES){ // SIZE/2 is matches needed to win

      clearScreen();

      displayBoard(board);

      cout << "Pick you first card ①: ";
      getFirstCard(board, card1Row, card1Col);

      clearScreen();

      displayBoard(board, card1Row, card1Col);

      cout << "Pick your second card ⓶: ";
      getSecondCard(board, card2Row, card2Col, card1Row, card1Col);

      clearScreen();

      displayBoard(board, card1Row, card1Col, card2Row, card2Col);

      // checks if 2 cards have same value
      if(board[card1Row][card1Col] == board[card2Row][card2Col]){
        cout << "You got a match 🤩 YAY!🥳 " << endl;
        waitingTime(PROCESS_TIME);
        matches++;

        // sets vals to balnk since they have been chosen already
        board[card1Row][card1Col] = BLANK;
        board[card2Row][card2Col] = BLANK;

      }else{
        waitingTime(waitSeconds);
      }

      turns++;
    }

    cout << "It took you " << turns << " turns to finish 😝" << endl;

    if(SIZE/2 >= turns){
      cout << "Guess what...a perfect game 💯" << endl;
    }

    cout << endl << "Would you like to play again? (y/n) ⎆ ";
    cin >> ans;
    cin.get();
  }

  cout << endl << endl;
  return 0;
}

// welcome function
void welcomeMessage()
{
  cout << endl << endl
       << "-----------------------------------------------" << endl
       << " It's time for a Memory Game! 👾" << endl
       << " Let's play! 🤙" << endl
       << "-----------------------------------------------" << endl
       << "Match every card with its pair taking the least" << endl
       << "turns possible! There must be none left to win!" << endl
       << "-----------------------------------------------" << endl << endl;
}

// goodbye function
void goodbyeMessage()
{
  cout << endl << endl
       << "See you next time! Hope you enjoyed 👋"
       << endl << endl;
}

// waiting time function
void waitingTime(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}

// function reading one of the two files randomly 
bool readFile(char board[][COL])
{
  ifstream infile;

  if (rand() % 2 < 1){
    infile.open(FILE1);
  }else{
    infile.open(FILE2);
  }

  if (infile.fail()){
    cout << "file failure...existing program...press enter...";
    cin.get();
    return true;
  }

  for(int r = 0; r < ROW; r++){
    for(int c = 0; c < COL; c++){
      infile >> board[r][c];
    }
  }

  infile.close();
  return false;
}

// displays board game in the 3x4 size
void displayBoard(const char board[][COL], int c1Row, int c1Col, int c2Row, int c2Col)
{
  // giving correct spacing
  cout << SPACE << SPACE << SPACE; 

  // column values
  for(int c = 0; c < COL; c++){
    cout << setw(COL_WIDTH) << SPACE << c << SPACE;
  }

  cout << endl;

  // row alues
  for(int r = 0; r < ROW; r++){
    cout << setw(COL_WIDTH) << r;

    for (int c = 0; c < COL; c++){
    
      if((r == c1Row && c == c1Col) || (r == c2Row && c == c2Col) || (board[r][c] == BLANK)){
        cout << setw(COL_WIDTH) << OPEN << board [r][c] << CLOSE;
      }else{
        cout << setw(COL_WIDTH) << OPEN << STAR << CLOSE;
      }
    }
    cout << endl << endl; 
  }
}

// function where user picks a card and filters cards that have been chosen already
void getFirstCard(char board[][COL], int &c1Row, int &c1Col)
{
  bool disfuncValue = true;
  while(disfuncValue){

    c1Row = R_CHECK;
    c1Col = C_CHECK;

    while((c1Row >= ROW || c1Row < 0)){
      cout << "Enter a row number (0,1,2): ";
      cin >> c1Row;
    }

    while ((c1Col >= COL || c1Col < 0)){
      cout << "Enter a column number (0,1,2,3): ";
      cin >> c1Col;
    }

    disfuncValue = false; 

    if(board[c1Row][c1Col] == BLANK){
      cout << "This value has been cleared, try again: " << endl;
      disfuncValue = true;
    }else if(c1Row == R_CHECK && c1Col == C_CHECK){
      cout << "This value has already been chosen, try again: " << endl;
      disfuncValue = true;
    }
  }
}

// function where user picks a second card and filters cards that have been chosen already
void getSecondCard(char board[][COL], int &c2Row, int &c2Col, int c1Row, int c1Col)
{
  bool disfuncValue = true;
  while(disfuncValue){
  
    c2Row = R_CHECK;
    c2Col = C_CHECK;

    while((c2Row >= ROW || c2Row < 0)){
      cout << "Enter a second row number (0,1,2): ";
      cin >> c2Row;
    }

    while ((c2Col >= COL || c2Col < 0)){
      cout << "Enter a second column number (0,1,2,3): ";
      cin >> c2Col;
    }

    disfuncValue = false; 

    if(board[c2Row][c2Col] == BLANK){
      cout << "This value has been cleared, try again: " << endl;
      disfuncValue = true;
    }else if(c2Row == R_CHECK && c2Col == C_CHECK){
      cout << "This value has already been chosen, try again: " << endl;
      disfuncValue = true;
    }
  }
}

int getExperience()
{
  char experience = 'e';

  cout << "Are you a beginner or somewhat experienced? (b/e): ";
  cin >> experience;
  cin.get();

  if(experience == EXP){
    return EXPERT_SECONDS;
  }else{
    return BEGINNER_SECONDS;
  }
}

void clearScreen()
{
  for(int i = 0; i < SCREEN_HEIGHT; i++){
    cout << endl;
  }
}