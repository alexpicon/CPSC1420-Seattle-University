// Alex Picon
// p3x.cpp
// Purpose: Play the game chutes and ladders
// Input: Name, Amount of players and Enter
// Output: The game chutes and ladders 

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// constants
const int LADDERS = 9, CHUTES = 10;
const int MAX_SPACE = 100, P_MAX = 6, P_MIN = 2, MAX_ROLL = 6;
const char YES = 'y';

// function declaring
void setup(int board[]);
void welcomeMessage();
void goodbyeMessage();
void playOneMatch(int board[]);
int playTurn(int board[], string name, int spot);
int spinSpinner();
int chuteladderChange(int board[], int spot);
bool hasWon(int spot, string name);


// function calls (main function)
int main()
{
    int board[MAX_SPACE+1] = {0}; 
    char playAgain = YES;

    setup(board);
    welcomeMessage();
    srand(time(0));

    while (tolower(playAgain) == YES) {
        playOneMatch(board);
        cout << endl
             << "Do you want to play again? (y/n) ";
        cin >> playAgain;
    }
    goodbyeMessage();

    return 0;
}

// Prepares the board with chutes and ladders
void setup(int board[])
{
    int ladderList[LADDERS] = {1, 4, 9, 23, 28, 36, 51, 71, 80};
    int ladderChange[LADDERS] = {37, 10, 12, 21, 56, 8, 15, 19, 20};
    int chuteList[CHUTES] = {98, 95, 93, 87, 64, 62, 56, 49, 48, 16};
    int chuteChange[CHUTES] = {20, 20, 20, 63, 4, 43, 3, 38, 22, 10};
    
    for (int i = 0; i < LADDERS; i++) {
        board[ladderList[i]] = ladderChange[i];
    }
    for (int i = 0; i < CHUTES; i++) {
        board[chuteList[i]] = -chuteChange[i];
    }
}

// Plays one match
void playOneMatch(int board[])
{
    int pCount = 0, turnVal = 0;
    bool isGameActive = true;
    int pSpot[P_MAX] = {0};
    string pNames[P_MAX] = {"", "", "", "", "", ""};

    pCount = 0;
    turnVal = 0;
    isGameActive = true;

    while (pCount > P_MAX || pCount < P_MIN) {
        cout << endl << "How many are playing? (" << P_MIN << " - " << P_MAX
                << " players): ";
        cin >> pCount;
    }
    for (int i = 0; i < pCount; i++) {
        cout << endl << "Player " << i + 1 << ", what is your name? ";
        cin >> pNames[i];
    }
    cin.get();

    while (isGameActive) {
        pSpot[turnVal] = playTurn(board, pNames[turnVal], pSpot[turnVal]);
        isGameActive = !hasWon(pSpot[turnVal], pNames[turnVal]);
        if (turnVal < pCount - 1) {
            turnVal++;
        } else {
            turnVal = 0;
        }
    }
}

// welcome func. definition
void welcomeMessage()
{
    cout << endl << endl
         << "-----------------------------------------------" << endl
         << " It's time for Chutes and Ladders! 🕳🪜" << endl
         << " Let's play! 🤙" << endl
         << "-----------------------------------------------" << endl
         << " Be the first person to reach the 100th square! " << endl
         << "-----------------------------------------------"
         << endl << endl;
}

// goodbye func. definition
void goodbyeMessage()
{
    cout << endl << endl
         << "See you next time! Hope you enjoyed 👋"
         << endl << endl;
}

// spin func. definition
int spinSpinner()
{
    return rand() % MAX_ROLL + 1;
}

// spot func. definition
// returns spot + ladder/chute change
int chuteladderChange(int board[], int spot)
{
    int change = board[spot];
    if (change > 0) {
        cout << "You landed on a ladder and moved ";
        cout << change << " spaces forward." << endl;
    } else if (change < 0) {
        cout << "You landed on a chute and moved ";
        cout << -change << " spaces backward." << endl;
    }
    return spot + change;
}

// turn func. definition
// returns new spot
int playTurn(int board[], string name, int spot)
{
    int roll = 0;

    cout << endl << endl
         << "************************************" << endl
         << name << " , it is your turn!" << endl;
    cout << "Your current position is " << spot << "." << endl;
    cout << "Press enter to roll the dice 🎲";
    cin.get();
    roll = spinSpinner();
    cout << "------------------------------------" << endl
         << "You rolled a " << roll << ". 🥸" << endl
         << "------------------------------------" << endl;
         
    if (roll + spot <= MAX_SPACE) {
        spot = chuteladderChange(board, spot + roll);
        cout << "Your new position is " << spot << ". 😎";
    } else {
        cout << "You went over " << MAX_SPACE << ", your position";
        cout << " is still " << spot << ".";
    }
    cout << endl;
    return spot;
}

// game ends, player wins
// returns false 
bool hasWon(int spot, string name)
{

    if (spot == MAX_SPACE) {
        cout << endl << "🎉 " << name << " has won! 🎉" << endl;
        return true;
    }
    return false;
}