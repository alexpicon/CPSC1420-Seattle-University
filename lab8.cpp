// Alex Picon
// lab8.cpp

#include <iostream>

using namespace std;

// function declare
void welcomeMessage();
int input();
int summation(int x);
void goodbyeMessage();

const char YES = 'y';
const int MIN = 5;
const int MAX = 25;

// all 4 functions called in main function
int main() {

  char again = YES;
  int result = 0;
  int inputVal = 0;

  welcomeMessage();

  while (tolower(again) == YES) {
    inputVal = input();
    result = summation(inputVal);
    cout << endl
         << "The sum from 1 to " << inputVal << " is equal to " << result << "."
         << endl
         << endl;

    cout << "Would you like to play again? (y/n): ";
    cin >> again;
  }

  goodbyeMessage();

  return 0;
}

// welcome function definition
void welcomeMessage() {
  cout << endl << endl << "Welcome to Alex's lab 8!";
}

// input function definition
int input() {

  int input;
  int count = 0;

  cout << endl
       << endl
       << "Enter a whole number between " << MIN << " and " << MAX << ": ";
  cin >> input;

  while (count == 0) {

    if (input < MIN || input > MAX) {
      cout << "Try again: ";
      cin >> input;

    } else {
      return input;
      count = 1;
    }
  }
  return 0;
}

// summation function definition
int summation(int x) {
  return x * (x + 1) / 2;
}

// goodbye function definition
void goodbyeMessage() {
  cout << endl << "Goodbye!";
}