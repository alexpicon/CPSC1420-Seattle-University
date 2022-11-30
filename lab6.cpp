//Alex Picon
//lab6.cpp

#include <iostream>
#include <cctype>

using namespace std;

const char MORE = 'y';

int main()
{
  int num1, num2;
  char again = MORE;
  bool ask;
  
  cout << endl << endl;
  
  while (tolower(again) == MORE){
    cout << endl << "Provide 2 whole numbers that are multiples (no 0): ";
    cin >> num1 >> num2;
    ask = true;
    
    if (num1 >= num2 && num1 % num2 == 0){
      cout << num1 << " is a multiple of " << num2 <<
        ", and the other factor is " << num1/num2 << endl << endl;
    }else if (num2 >= num1 && num2 % num1 == 0){
      cout << num2 << " is a multiple of " << num1 <<
        ", and the other factor is " << num2/num1 << endl << endl;
    }else{
      cout << endl << "These 2 numbers aren't multiples. Try again. " << endl;
      ask = false;
    }
    
    if (ask){
      cout << endl << "Would you like to play again? [y/n] ";
      cin >> again;
    }
  }
  
  return 0;
}