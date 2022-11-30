// Alex Picon
// lab15.cpp

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_SIZE = 75;
const int WORD_NOT_FOUND = -1;
const char YES = 'y';

const string F_NAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";

int findWord(const string wordList[], const int numWords, string word);

int main()
{
    int index;
    string wordList[MAX_SIZE];
    string answer;
    string word;
    int numWords = 0;
    char playAgain;
    ifstream infile;

    infile.open(F_NAME);
    if (infile.fail()){
        cout << "file error...existing program...press enter...";
        cin.get();
        return 0;
    }

    while (infile >> word){
        wordList[numWords] = word;
        numWords++;
    }

    infile.close();

    cout << endl
         << endl;

    cout << "Ready to play? (y/n): ";
    cin >> playAgain;
    cin.get();

    while (tolower(playAgain) == YES){
        cout << endl;

        cout << "Type a word: ";
        cin >> answer;

        cout << endl;

        index = findWord(wordList, numWords, answer);

        if (index == WORD_NOT_FOUND){
            cout << "The word "
                 << "'" << answer << "'"
                 << " was not found." << endl
                 << endl;
        } else {
            cout << "Index of "
                 << "'" << answer << "'"
                 << " is " << index << endl
                 << endl;
        }

        cout << "Want to play again? (y/n): ";
        cin >> playAgain;
        cin.get();
    }

    cout << endl << endl;
    return 0;
}

// findWord returns the position of a word in an array,
// or returns WORD_NOT_FOUND if the word couldn't by found.
int findWord(const string wordList[], const int numWords, string word)
{
    int pos = 0;
    while (pos < numWords && wordList[pos] != word){
        pos++;
    }

    if (pos == numWords){
        return WORD_NOT_FOUND;

    } else {
        return pos;
    }
}