// Alex Picon
// lab13.cpp

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// constants variables
const int ROW = 5;
const int COL = 8;
const int COL_WIDTH = 5;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

// function declaring
int calcTotal(int table[][COL]);
void printTable(const int table[][COL]);

int main()
{
    // variables
    ifstream infile;
    int table[ROW][COL] = {0};
    int total;

    infile.open(F_NAME);
    if (infile.fail()){
        cout << "file failure...existing program...press enter...";
        cin.get();
        return 0;
    }

    cout << endl << endl;

    // building table with numbers from file
    for (int r = 0; r < ROW; r++){
        for (int c = 0; c < COL; c++){
            infile >> table[r][c];
        }
    }

    // prints total label
    cout << setw((COL_WIDTH) * (COL)) << ' ';
    cout << "Total" << endl;
  
    // prints table
    printTable(table);

    // sets int total to the total value
    total = calcTotal(table);

    // prints total
    cout << setw(COL_WIDTH) << total << endl << endl;
    return 0;
}

int calcTotal(int table[][COL])
{
    // calculates table total
    int total = 0;
    for (int r = 0; r < ROW; r++){
        for (int c = 0; c < COL; c++)
        {
            total += table[r][c];
        }
    }
    return total;
}

void printTable(const int table[][COL])
{
    int rowSum;
    int colSum;

    // printing table
    for (int r = 0; r < ROW; r++){
        rowSum = 0;
        for (int c = 0; c < COL; c++){
            cout << setw(COL_WIDTH) << table[r][c];
            rowSum += table[r][c];
        }
        // printing column with row totals
        cout << setw(COL_WIDTH) << rowSum << endl;
    }

    // printing row with column totals
    for (int c = 0; c < COL; c++){
        colSum = 0;
        for (int r = 0; r < ROW; r++){
            colSum += table[r][c];
        }
        cout << setw(COL_WIDTH) << colSum;
    }
}