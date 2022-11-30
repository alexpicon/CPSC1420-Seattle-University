// Alex Picon
// lab12.cpp

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//constants
const int MAX_SIZE = 50;
const int INDEX_COL = 5;
const int NUM_COL = 8;
const int DIGITS = 3;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";

//function declaring
float getSum(const float table[], int lineNum);
void printTable(const float table[], int lineNum);

//main function
int main()
{
    //variables
    ifstream infile;
    float table[MAX_SIZE] = {0};
    float line;
    int lineNum = 0;

    //file open & fail message
    infile.open(FILENAME);
    if (infile.fail()){

        cout << "file failure...existing program...press enter...";
        cin.get();
        return 0;
    }

    //get numbers
    while (infile >> line){
        table[lineNum++] = line;
    }

    infile.close();

    //printing table and total at the bottom
    printTable(table, lineNum);
    cout << endl << endl;
    cout << "Total is " << getSum(table, lineNum);
    cout << endl << endl;

    return 0;
}

//total sum function
float getSum(const float table[], int lineNum)
{
    float sum = 0;

    //adds table[i] to sum each 
    //time i is less than lineNum
    for (int i = 0; i < lineNum; i++){
        sum += table[i];
    }
    return sum;
}

//print table function
void printTable(const float table[], int lineNum)
{
    cout << endl;

    //prints table labels
    cout << setw(INDEX_COL) << "Index";
    cout << setw(NUM_COL) << " Value" << endl;

    //prints values of index and infile 
    for (int i = 0; i < lineNum; i++){
         cout << setw(INDEX_COL) << i << setw(NUM_COL) << fixed << showpoint
             << setprecision(DIGITS) << table[i] << endl;
    }
}