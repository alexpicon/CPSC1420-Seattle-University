// Alex Picon
// lab11.cpp

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// constants variables
const int ROW = 5;
const int COL = 8;
const int COL_WIDTH = 5;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

int main()
{
    // variables
    ifstream infile;
    int table[ROW][COL] = {0};
    int rowSum = 0;
    int colSum = 0;
    int total = 0;

    infile.open(F_NAME);
    if (infile.fail())
    {
        cout << "file failure...existing program...press enter...";
        cin.get();
        return 0;
    }

    cout << endl
         << endl;
    // building table with numbers from file
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            infile >> table[r][c];
        }
    }

    infile.close();

    // printing "Total" header
    cout << setw((COL_WIDTH) * (COL)) << ' ';
    cout << "Total" << endl;

    // printing table
    for (int r = 0; r < ROW; r++)
    {
        rowSum = 0;
        for (int c = 0; c < COL; c++)
        {
            cout << setw(COL_WIDTH) << table[r][c];
            rowSum += table[r][c];
        }
        // printing column with row totals
        cout << setw(COL_WIDTH) << rowSum << endl;
    }

    // printing row with column totals
    for (int c = 0; c < COL; c++)
    {
        colSum = 0;
        for (int r = 0; r < ROW; r++)
        {
            colSum += table[r][c];
        }
        cout << setw(COL_WIDTH) << colSum;
    }
    // calculating total for all numbers of table
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            total += table[r][c];
        }
    }

    // printing total for all numbers of table
    cout << setw(COL_WIDTH) << total << endl
         << endl;
    return 0;
}