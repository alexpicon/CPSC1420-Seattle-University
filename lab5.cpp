//Alex Picon
//lab5.cpp

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  const char MORE = 'y';

  int num1, num2, large, small;
  char again = 'y';

  while (tolower(again) == MORE) {
    cout << endl << "Enter 2 integers: ";
    cin >> num1 >> num2;
    
    if (num1 >= num2) {
      large = num1;
      small = num2;
    } else {
      large = num2;
      small = num1;
    }
    cout << endl;
    cout << "Larger number: " << large << endl;
    cout << "Smaller number: " << small << endl;
    
    if (small == 0) {
      cout << endl << "The smaller number can't be a zero.";
    } else if (large % small == 0) {
      cout << endl << "Yes, " << large << " is a multiple of " << small
           << " and the other factor is " << large/small;
    } else {
      cout << endl << "No, " << large << " is not a multiple of " << small;
    }
    cout << endl << endl << "Would you like to play again? [y/n] ";
    cin >> again;
  }
  
  return 0;
} 
