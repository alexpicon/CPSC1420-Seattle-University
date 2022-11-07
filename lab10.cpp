// Alex Picon
// lab10.cpp

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 30;
const int COL_WIDTH = 5;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";

int main()
{
  ifstream infile;
  int num;
  int negNum[MAX_SIZE];
  int oddNum[MAX_SIZE];
  int evenNum[MAX_SIZE];
  int count[3] = {0, 0, 0};
  // could also do negCount = 0, evenCount = 0, oddCount = 0

  infile.open(F_NAME);
  if (infile.fail())
  {
    cout << "file failure...existing program...press enter...";
    cin.get();
    return 0;
  }

  while (infile >> num)
  {
    if (num < 0)
    {
      negNum[count[0]] = num;
      count[0]++;
    }
    else if (num > 0)
    {
      if (num % 2 == 0)
      {
        evenNum[count[1]] = num;
        count[1]++;
      }
      else
      {
        oddNum[count[2]] = num;
        count[2]++;
      }
    }
  }
    cout << endl << endl;
    cout << "Negative Numbers: " << endl;
    cout << setw(COL_WIDTH) << "Index";
    cout << setw(COL_WIDTH) << " Value" << endl;
    for (int i = 0; i < count[0]; i++)
    {
      cout << setw(COL_WIDTH) << i;
      cout << setw(COL_WIDTH) << negNum[i] << endl;
    }
    cout << endl << endl;
    cout << "Even Numbers: " << endl;
    cout << setw(COL_WIDTH) << "Index";
    cout << setw(COL_WIDTH) << " Value" << endl;
    for (int i = 0; i < count[1]; i++)
    {
      cout << setw(COL_WIDTH) << i;
      cout << setw(COL_WIDTH) << evenNum[i] << endl;
    }
    cout << endl << endl;
    cout << "Odd Numbers: " << endl;
    cout << setw(COL_WIDTH) << "Index";
    cout << setw(COL_WIDTH) << " Value" << endl;
    for (int i = 0; i < count[2]; i++)
    {
      cout << setw(COL_WIDTH) << i;
      cout << setw(COL_WIDTH) << oddNum[i] << endl;
    }

    cout << endl << endl;
    infile.close();
    return 0;
  }
