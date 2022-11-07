// Alex Picon
// p2.cpp
// Purpose: Program that plays children's game Hi Ho! Cherry-O.
// Input: Entering amount of players, Rand values/Pressing enter.
// Output: Ask amount of players, spinner and gameplay of each player turn.

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

const int MAX_CHERRIES = 10;
const int MAX_SPIN = 7;
const int ONE_CHERRY = 1;
const int TWO_CHERRY = 2;
const int THREE_CHERRY = 6;
const int FOUR_CHERRY = 4;
const int SPILL = 3;
const int DOG = 5;
const int BIRD = 7;
const int P1 = 0;
const int P2 = 1;
const int P3 = 2;
const int P4 = 3;
const int P_MAX = 4;
const int P_MIN = 2;

int main() {
  int pvalue = 0;
  int pcount = 0;
  int p1num = 0;
  int p2num = 0;
  int p3num = 0;
  int p4num = 0;
  int roll;

  cout << "-----------------------------------------------" << endl
       << " It's time for Hi Ho! Cherry-O! 🍒 " << endl
       << " Let's play! 😄 " << endl
       << "-----------------------------------------------" << endl
       << "Pick all cherries off your tree, put them in" << endl
       << "your bucket, and beat the opponent! Birds and" << endl
       << "dogs will steal cherries from you! Have fun 🤙 " << endl
       << "-----------------------------------------------" << endl;

  srand(time(NULL));

  cout << endl << endl;

  while (pcount < P_MIN || pcount > P_MAX) {
    cout << "How many players? (" << P_MIN << "-" << P_MAX << "): ";
    cin >> pcount;
    cin.get();
  }

    cout << endl << endl << "Hit enter to begin ⎆";
    cin.get();

    while (p1num < MAX_CHERRIES && p2num < MAX_CHERRIES &&
           p3num < MAX_CHERRIES && p4num < MAX_CHERRIES) {

      // Player 1 rolls the dice and gets a constant result
      if (pvalue == P1) {
        cout << endl << endl << "Player 1, it's your turn! ⏳ " << endl << endl;
        cout << "Cherries in bucket 🪣: " << p1num << endl;
        cout << "Cherries in tree 🌳: " << MAX_CHERRIES - p1num << endl << endl;
        cout << "Player 1, press enter to roll the dice ⎆ 🎲";
        cin.get();
        roll = rand() % MAX_SPIN + 1;
        cout << endl << "You spun a " << roll << "!" << endl;

        switch (roll) {
        case ONE_CHERRY:
          cout << "A cherry is removed from the tree and placed in the bucket.";
          p1num += 1;
          break;
        case TWO_CHERRY:
          cout << "Two cherries are removed from the tree and placed in the "
                  "bucket.";
          p1num += 2;
          break;
        case THREE_CHERRY:
          cout << "Three cherries are removed from the tree and placed in the "
                  "bucket.";
          p1num += 3;
          break;
        case FOUR_CHERRY:
          cout << "Four cherries are removed from the tree and placed in the "
                  "bucket.";
          p1num += 4;
          break;
        case SPILL:
          cout << "Put all of the cherries back on the tree.";
          p1num = 0;
          break;
        case DOG:
        case BIRD:
          cout << "Return 2 cherries from the bucket to the tree.";
          p1num -= 2;
        }
        // Player 1 number can't go negative
        if (p1num < 0) {
          p1num = 0;
        } else if (p1num > MAX_CHERRIES) {
          p1num = MAX_CHERRIES;
        }

        cout << endl << endl;
        cout << "Player 1: " << endl
             << "Cherries in bucket 🪣: " << p1num << endl
             << "Cherries in tree 🌳: " << MAX_CHERRIES - p1num << endl;

      } else if (pvalue == P2) { // Player 2 rolls the dice and gets a constant result
        cout << endl << endl << "Player 2, it's your turn! ⏳ " << endl << endl;
        cout << "Cherries in bucket 🪣: " << p2num << endl;
        cout << "Cherries in tree 🌳: " << MAX_CHERRIES - p2num << endl << endl;
        cout << "Player 2, press enter to roll the dice ⎆ 🎲";
        cin.get();
        roll = rand() % MAX_SPIN + 1;
        cout << endl << "You spun a " << roll << "!" << endl;

        switch (roll) {
        case ONE_CHERRY:
          cout << "A cherry is removed from the tree and placed in the bucket.";
          p2num += 1;
          break;
        case TWO_CHERRY:
          cout << "Two cherries are removed from the tree and placed in the "
                  "bucket.";
          p2num += 2;
          break;
        case THREE_CHERRY:
          cout << "Three cherries are removed from the tree and placed in the "
                  "bucket.";
          p2num += 3;
          break;
        case FOUR_CHERRY:
          cout << "Four cherries are removed from the tree and placed in the "
                  "bucket.";
          p2num += 4;
          break;
        case SPILL:
          cout << "Put all of the cherries back on the tree.";
          p2num = 0;
          break;
        case DOG:
        case BIRD:
          cout << "Return 2 cherries from the bucket to the tree.";
          p2num -= 2;
        }
        // Player 2 number can't go negative
        if (p2num < 0) {
          p2num = 0;
        } else if (p2num > MAX_CHERRIES) {
          p2num = MAX_CHERRIES;
        }

        cout << endl << endl;
        cout << "Player 2: " << endl
             << "Cherries in bucket 🪣: " << p2num << endl
             << "Cherries in tree 🌳:" << MAX_CHERRIES - p2num << endl;

      } else if (pvalue == P3) { // Player 3 rolls the dice and gets a constant result
        cout << endl << endl << "Player 3, it's your turn! ⏳ " << endl << endl;
        cout << "Cherries in bucket 🪣: " << p3num << endl;
        cout << "Cherries in tree 🌳: " << MAX_CHERRIES - p3num << endl << endl;
        cout << "Player 3, press enter to roll the dice ⎆ 🎲";
        cin.get();
        roll = rand() % MAX_SPIN + 1;
        cout << endl << "You spun a " << roll << "!" << endl;

        switch (roll) {
        case ONE_CHERRY:
          cout << "A cherry is removed from the tree and placed in the bucket.";
          p3num += 1;
          break;
        case TWO_CHERRY:
          cout << "Two cherries are removed from the tree and placed in the "
                  "bucket.";
          p3num += 2;
          break;
        case THREE_CHERRY:
          cout << "Three cherries are removed from the tree and placed in the "
                  "bucket.";
          p3num += 3;
          break;
        case FOUR_CHERRY:
          cout << "Four cherries are removed from the tree and placed in the "
                  "bucket.";
          p3num += 4;
          break;
        case SPILL:
          cout << "Put all of the cherries back on the tree.";
          p3num = 0;
          break;
        case DOG:
        case BIRD:
          cout << "Return 2 cherries from the bucket to the tree.";
          p3num -= 2;
        }
        // Player 3 number can't go negative
        if (p3num < 0) {
          p3num = 0;
        } else if (p3num > MAX_CHERRIES) {
          p3num = MAX_CHERRIES;
        }

        cout << endl << endl;
        cout << "Player 3: " << endl
             << "Cherries in bucket 🪣: " << p3num << endl
             << "Cherries in tree 🌳:" << MAX_CHERRIES - p3num << endl;

      } else {
        cout << endl << endl << "Player 4, it's your turn! ⏳ " << endl << endl;
        cout << "Cherries in bucket 🪣: " << p4num << endl;
        cout << "Cherries in tree 🌳: " << MAX_CHERRIES - p4num << endl << endl;
        cout << "Player 4, press enter to roll the dice ⎆ 🎲";
        cin.get();
        roll = rand() % MAX_SPIN + 1;
        cout << endl << "You spun a " << roll << "!" << endl;

        switch (roll) {
        case ONE_CHERRY:
          cout << "A cherry is removed from the tree and placed in the bucket.";
          p4num += 1;
          break;
        case TWO_CHERRY:
          cout << "Two cherries are removed from the tree and placed in the "
                  "bucket.";
          p4num += 2;
          break;
        case THREE_CHERRY:
          cout << "Three cherries are removed from the tree and placed in the "
                  "bucket.";
          p4num += 3;
          break;
        case FOUR_CHERRY:
          cout << "Four cherries are removed from the tree and placed in the "
                  "bucket.";
          p4num += 4;
          break;
        case SPILL:
          cout << "Put all of the cherries back on the tree.";
          p4num = 0;
          break;
        case DOG:
        case BIRD:
          cout << "Return 2 cherries from the bucket to the tree.";
          p4num -= 2;
        }
        // Player 4 number can't go negative
        if (p4num < 0) {
          p4num = 0;
        } else if (p4num > MAX_CHERRIES) {
          p4num = MAX_CHERRIES;
        }

        cout << endl << endl;
        cout << "Player 4: " << endl
             << "Cherries in bucket 🪣: " << p4num << endl
             << "Cherries in tree 🌳:" << MAX_CHERRIES - p4num << endl;
      }

      pvalue++;
      if (pvalue >= pcount) {
        pvalue = 0;
      }
      cout << endl << endl;
    }

    if (p1num >= MAX_CHERRIES) {
      cout << "🎉 Player 1 has won! 🎉";
    } else if (p2num >= MAX_CHERRIES) {
      cout << "🎉 Player 2 has won! 🎉";
    } else if (p3num >= MAX_CHERRIES) {
      cout << "🎉 Player 3 has won! 🎉";
    } else {
      cout << "🎉 Player 4 has won! 🎉";
    }
  
  cout << endl << endl << "See you next time! 👋";
  cout << endl << endl;

  return 0;
}