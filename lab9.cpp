// Alex Picon
// lab9.cpp

#include <iostream>
#include <string>

using namespace std;

void input(string &strOne, string &strTwo);
void swapStr(string &strOne, string &strTwo);
void output(string strOne, string strTwo);

int main()
{

    string wordOne, wordTwo;

    // code starts
    cout << endl << endl;
    cout << "This program will ask for two strings." << endl;
    cout << "Then it will print them then reverse the words.";
    cout << endl;

    input(wordOne, wordTwo);
    output(wordOne, wordTwo);
    swapStr(wordOne, wordTwo);
    output(wordOne, wordTwo);

    cout << endl
         << endl
         << endl;

    return 0;
}

// Input Function
void input(string &strOne, string &strTwo)
{
    cout << endl;
    cout << "Enter two single words, please: ";
    cin >> strOne >> strTwo;
    cout << endl;
}

// Swapper Function
void swapStr(string &strOne, string &strTwo)
{
    string strSwap = strOne;
    strOne = strTwo;
    strTwo = strSwap;
}

// Output Function
void output(string strOne, string strTwo)
{
    cout << endl;
    cout << "strOne is " << strOne << " and strTwo is " << strTwo;
    cout << endl;
}