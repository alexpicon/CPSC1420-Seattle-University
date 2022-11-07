// Alex
// p3.cpp
// Purpose: Play the game chutes and ladders (2 players)
// Input: Name and Enter
// output: The game chutes and ladders

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// constants
const int MAX_SPACE = 100, MAX_ROLL = 6;
const char YES = 'y';

// function declaring
void welcomeMessage();
void goodbyeMessage();
void playOneMatch();
int spinSpinner();
int chuteladderChange(int spot);
int playTurn(string name, int spot);

// function calls (main function)
int main()
{
    char again = YES;

    welcomeMessage();
    srand(time(0));

    while (tolower(again) == YES) {
        playOneMatch();
        cout << endl
             << "Would you like to play again? (y/n): ";
        cin >> again;
    }
    goodbyeMessage();

    return 0;
}

void playOneMatch()
{
    int p1Spot = 0;
    int p2Spot = 0;
    int turnVal = 0;
    string p1;
    string p2;

    cout << "Player 1, enter your name: ";
    getline(cin, p1);

    cout << "Player 2, enter your name: ";
    getline(cin, p2);

    cout << "Press enter to continue ⎆";
    cin.get();

    p1Spot = 0;
    p2Spot = 0;

    while (p1Spot < MAX_SPACE && p2Spot < MAX_SPACE) {
        if (turnVal == 0) {
            p1Spot = playTurn(p1, p1Spot);
            turnVal++;
        } else {
            p2Spot = playTurn(p2, p2Spot);
            turnVal = 0;
        }
    }
    if (p1Spot == MAX_SPACE) {
        cout << endl << "🎉 " << p1 << " has won! 🎉" << endl;
    } else {
        cout << endl << "🎉 " << p2 << " has won! 🎉" << endl;
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
// returns dice value
int spinSpinner()
{
    return rand() % MAX_ROLL + 1;
}

// spot func. definition
// returns spot + ladder/chute change
int chuteladderChange(int spot)
{
    if (spot == 1){
        cout << "You landed on a ladder!" << endl;
        return spot + 37;
    } else if (spot == 4) {
        cout << "You landed on a ladder!" << endl;
        return spot + 10;
    } else if (spot == 9) {
        cout << "You landed on a ladder!" << endl;
        return spot + 12;
    } else if (spot == 23) {
        cout << "You landed on a ladder!" << endl;
        return spot + 21;
    } else if (spot == 28) {
        cout << "You landed on a ladder!" << endl;
        return spot + 56;
    } else if (spot == 36) {
        cout << "You landed on a ladder!" << endl;
        return spot + 8;
    } else if (spot == 51) {
        cout << "You landed on a ladder!" << endl;
        return spot + 15;
    } else if (spot == 71) {
        cout << "You landed on a ladder!" << endl;
        return spot + 19;
    } else if (spot == 80) {
        cout << "You landed on a ladder!" << endl;
        return spot + 20;
    } else if (spot == 98) {
        cout << "You landed on a chute!" << endl;
        return spot - 20;
    } else if (spot == 95) {
        cout << "You landed on a chute!" << endl;
        return spot - 20;
    } else if (spot == 93) {
        cout << "You landed on a chute!" << endl;
        return spot - 20;
    } else if (spot == 87) {
        cout << "You landed on a chute!" << endl;
        return spot - 63;
    } else if (spot == 64) {
        cout << "You landed on a chute!" << endl;
        return spot - 4;
    } else if (spot == 62) {
        cout << "You landed on a chute!" << endl;
        return spot - 43;
    } else if (spot == 56) {
        cout << "You landed on a chute!" << endl;
        return spot - 3;
    } else if (spot == 49) {
        cout << "You landed on a chute!" << endl;
        return spot - 38;
    } else if (spot == 48) {
        cout << "You landed on a chute!" << endl;
        return spot - 22;
    } else if (spot == 16) {
        cout << "You landed on a chute!" << endl;
        return spot - 10;
    }
    return spot;
}

// turn func. definition
// returns new spot
int playTurn(string name, int spot)
{
    int roll = 0;
    int newSpot = 0;

    cout << endl << endl
         << "************************************" << endl
         << name << " , it is your turn!" << endl;
    cout << "Your current position is " << spot << "." << endl;
    cout << "Press enter to roll the dice 🎲 ";
    cin.get();
    roll = spinSpinner();
    cout << "------------------------------------" << endl
         << "You rolled a " << roll << ". 🥸" << endl
         << "------------------------------------" << endl;
    if (roll + spot <= MAX_SPACE) {
        newSpot = chuteladderChange(spot + roll);
        cout << "Your new position is " << newSpot << ". 😎";
    } else { 
        newSpot = spot;
        cout << "You went over " << MAX_SPACE << ", your position";
        cout << " is still " << newSpot << ".";
    }

    cout << endl;

    return newSpot;
}