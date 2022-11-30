// Alex Picon
// p4x.cpp
// Purpose: Playing a memory game, different size board 
// depending if beginner or expert
// Input: Experience level (Beg. or Exp.), row and column chosen 
// Output: The memory game (board, questions, etc.)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// constants
const int BEGINNER_SECONDS = 5;
const int EXPERT_SECONDS = 2;
const int SCREEN_HEIGHT = 40;
const int PROCESS_TIME = 2;
const int SIZE = 12;  
const int ROW = 3;
const int COL = 4;
const int COL_WIDTH = 3;
const int MAX_VAL = 10;
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
const char LETTER_LIST[ROW*COL] = {'A','B','C','D','E','F','G','H','I','J','K','L'};

// function declaring
void welcomeMessage();
bool getExperience();
void setBoard(char board[][COL], int rowCount);
void displayBoard(const char board[][COL], int rowCount, int c1Row = -1, int c1Col = -1, 
int c2Row = -1, int c2Col = -1);
void getFirstCard(char board[][COL], int &c1Row, int &c1Col, int rowCount);
void getSecondCard(char board[][COL], int &c2Row, int &c2Col, int c1Row, 
int c1Col, int rowCount);
void clearScreen();
void waitingTime(int seconds);
void goodbyeMessage();

int main()
{
  // variables
  int waitSeconds;
  int turns = 0;
  int matches = 0;
  int rowCount;
  int card1Row, card1Col, card2Row, card2Col;
  char ans;
  char board[ROW*2][COL];

  bool expert;
  
  cout << endl << endl << endl;

  srand(time(0));
  
  welcomeMessage();
  cout << "Would you like to play? (y/n) ⎆ ";
  cin >> ans;
  cin.get();

  while(tolower(ans) == YES){
    expert = getExperience();

    if(expert){
      waitSeconds = EXPERT_SECONDS;
    
      rowCount = ROW*2;
    }else{
      waitSeconds = BEGINNER_SECONDS;
      rowCount = ROW;
    }
    
    setBoard(board, rowCount);

    matches = 0;
    turns = 0;

    while((rowCount*COL)/2 > matches){
    

      clearScreen();

      displayBoard(board, rowCount);

      cout << "Pick you first card ①: " << endl;
      getFirstCard(board, card1Row, card1Col, rowCount);

      clearScreen();

      displayBoard(board, rowCount, card1Row, card1Col);

      cout << "Pick your second card ⓶: " << endl;
      getSecondCard(board, card2Row, card2Col, card1Row, card1Col, rowCount);

      clearScreen();

      displayBoard(board, rowCount, card1Row, card1Col, card2Row, card2Col);

  
      if(board[card1Row][card1Col] == board[card2Row][card2Col]){
        cout << "You got a match 🤩 YAY!🥳 " << endl;
        waitingTime(PROCESS_TIME);
      
        matches++;
       
        board[card1Row][card1Col] = BLANK;
        board[card2Row][card2Col] = BLANK;
      }else{
        waitingTime(waitSeconds);
      }
      
      turns++;
      
    }
    cout << "It took you " << turns << " turns to finish 😝" << endl;
    if(turns <= SIZE/2){
      cout << "Guess what...a perfect game 💯" << endl;
    }
    cout << endl << "Would you like to play again? (y/n) ⎆ ";
    cin >> ans;
  }

  cout << endl << endl << endl;

  return 0;
}

// welcome function
void welcomeMessage()
{
  cout << endl
       << endl
       << "-----------------------------------------------" << endl
       << " It's time for a Memory Game! 👾" << endl
       << " Let's play! 🤙" << endl
       << "-----------------------------------------------" << endl
       << "Match every card with its pair taking the least" << endl
       << "turns possible! There must be none left to win!" << endl
       << "-----------------------------------------------" << endl
       << endl;
}

// goodbye function
void goodbyeMessage()
{
  cout << endl
       << endl
       << "See you next time! Hope you enjoyed 👋"
       << endl
       << endl;
}

// checks whether player is experienced or not
bool getExperience()
{
  char experience = 'e';
  cout << "Are you a beginner or somewhat experienced? (b/e): ";
  cin >> experience;
  cin.get();
  if(experience == EXP){
    return true;
  }else{
    return false;
  }
}

void setBoard(char board[][COL], int rowCount)
{
  int row, col, numLetters = rowCount*COL/2;
  bool disfuncValue = true;
  for(int r = 0; r < rowCount; r++){
    for(int c = 0; c < COL; c++){
      board[r][c] = BLANK;
    }
  }
  for(int i = 0; i < numLetters; i++){
    disfuncValue = true;
    
    while(disfuncValue){
      row = rand() % rowCount;
      col = rand() % COL;
      if(board[row][col] == BLANK){
        board[row][col] = LETTER_LIST[i];
        disfuncValue = false;
      }
    }
  
    disfuncValue = true;
    while(disfuncValue){
      row = rand() % rowCount;
      col = rand() % COL;
      if(board[row][col]==BLANK){
        board[row][col] = LETTER_LIST[i];
        disfuncValue = false;
      }
    }
  }
  
}

// displays board game in the 3x4 size
void displayBoard(const char board[][COL], int rowCount, int c1Row, int c1Col, 
int c2Row, int c2Col)
{
  cout << SPACE << SPACE << SPACE;

  // column values
  for(int c = 0; c < COL; c++){
    cout << setw(COL_WIDTH) << SPACE << c << SPACE;
  }

  cout << endl;

  // row values
  for(int r = 0; r < rowCount; r++){
    cout << setw(COL_WIDTH) << r;
    for(int c = 0; c < COL; c++){

      if((r == c1Row && c == c1Col)||(r == c2Row && c == c2Col)||
      (board[r][c]==BLANK)){
        cout << setw(COL_WIDTH) << OPEN << board[r][c] << CLOSE;
      }else{
        cout << setw(COL_WIDTH) << OPEN << STAR << CLOSE;
      }
    }
    cout << endl << endl;
  }
}

// function where user picks a card and 
// filters cards that have been chosen already
void getFirstCard(char board[][COL], int &c1Row, int &c1Col, int rowCount)
{
  bool disfuncValue = true;
  while(disfuncValue){
    // resetting values for no infinite loop
    c1Row= R_CHECK;
    c1Col = C_CHECK;
    while((c1Row >= rowCount || c1Row < 0)){
      cout << "Enter a row number: ";
      cin >> c1Row;
    }

    while ((c1Col >= COL || c1Col < 0)){
      cout << "Enter a column number: ";
      cin >> c1Col;
    }
    disfuncValue = false; 

    // 'disfuncValue = true' to repeat if a value is already chosen
    if(board[c1Row][c1Col] == BLANK){
      cout << "This value has been cleared, try again: " << endl;
      disfuncValue = true;
    }else if(c1Row == R_CHECK && c1Col == C_CHECK){
      cout << "This value has already been chosen, try again: " << endl;
      disfuncValue = true;
    }
  }
}

// function where user picks a second card and 
// filters cards that have been chosen already
void getSecondCard(char board[][COL], int &c2Row, int &c2Col, int c1Row, 
int c1Col, int rowCount)
{
  bool disfuncValue = true;
  while(disfuncValue){
    // resetting values for no infinite loop
    c2Row= R_CHECK;
    c2Col = C_CHECK;
    while((c2Row >= rowCount || c2Row < 0)){
      cout << "Enter a second row number: ";
      cin >> c2Row;
    }

    while ((c2Col >= COL || c2Col < 0)){
      cout << "Enter a second column number: ";
      cin >> c2Col;
    }
    disfuncValue = false; 

    // 'disfuncValue = true' to repeat if a value is already chosen
    if(board[c2Row][c2Col] == BLANK){
      cout << "This value has been cleared, try again: " << endl;
      disfuncValue = true;
    }else if(c2Row == R_CHECK && c2Col == C_CHECK){
      cout << "This value has already been chosen, try again: " << endl;
      disfuncValue = true;
    }
  }
}

void clearScreen()
{
  for(int i = 0; i < SCREEN_HEIGHT; i++){
    cout << endl;
  }
}

void waitingTime(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}