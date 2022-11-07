//Alex Picon                                                                                                                   
//lab7.cpp                                                                                                                     

#include <iostream>
#include <iomanip>

using namespace std;

const int MIN = 3;
const int MAX = 9;
const int WIDTH_FIRST_COLUMN = 1;
const int WIDTH_COLUMN = 3;
const char SPACE = ' ';

int main()
{
  int x = 0;

  cout << endl << endl;

  while (x < MIN || x > MAX){
    cout << "Number (between " << MIN << " and " << MAX << "): ";
    cin >> x;
    cin.get();
  }

  cout << endl << endl;

  //PATTERN 1                                                                                            
  for (int r = 1; r <= x; r++)
    cout << x;

  cout << endl << endl;

  //PATTERN 2                                                                                     
  for (int c = 1; c <= x; c++)
    cout << "1" << endl;

  cout << endl << endl;

  //PATTERN 3                                                                                              
  // printing the upper left corner
  cout << setw(WIDTH_FIRST_COLUMN) << SPACE;
  // printing header row
  for (int c = 1; c <=x ; c++) {
      cout << setw(WIDTH_COLUMN) << c;
  }
  cout << endl;

  for (int r = 1; r <= x; r++) {
      // printing the first column
      cout << setw(WIDTH_FIRST_COLUMN) << r;
      // printing the multiplication values
      for (int c = 1; c <= x; c++) {
          cout << setw(WIDTH_COLUMN) << c*r;
      }
      cout << endl;
  }
  cout << endl << endl;

  //PATTERN 4                                                                
  for (int r = 1; r <= x; ++r){
    for(int c = 1; c <= r; ++c){
      cout << r << SPACE;
    }
    cout << endl;
  }
  cout << endl << endl;

  //PATTERN 5         
  // printing top part                                                     
  for (int r = 1; r <= x; r++){
    cout << string(r-1, SPACE) << r << endl;
  }
  //printing bottom part
  for (int r = x-1; r > 0; r--){
    cout << string(r-1, SPACE) << r << endl;
  }
  cout << endl;

  // PATTERN 6
  // first line (r=1)
  cout << string(x-1, SPACE) << 1 << endl;
  // upper half: lines between 2 and x
  for (int r = 2; r <= x; r++) {
      cout << string(x-r, SPACE) << r << string(2*r-3, SPACE) << r << endl;
  }
  // lower half: lines between x-1 and 2
  for (int r = x-1; r > 1; r--) {
      cout << string(x-r, SPACE) << r << string(2*r-3, SPACE) << r << endl;
  }
  // last line (r=1)
  cout << string(x-1, SPACE) << 1 << endl;
  cout << endl << endl;

return 0;
}