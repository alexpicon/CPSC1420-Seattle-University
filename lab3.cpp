// Alex Picon
// lab3.cpp

#include <iostream>

using namespace std;

int main()
{

  int num1, num2;

  cout << endl;
  
  cout << "Enter 2 integers (x y): ";
  cin >> num1 >> num2;
      

  if ( num1 % num2 == 0 ){
    cout << endl << "Yes, " << num1 << " is a multiple of " << num2 <<
      ", and the other factor is " << num1/num2;
    cout << endl << endl;
      
  }else{
    cout << endl << "No, " << num1 << " is not a multiple of " << num2;
    cout << endl << endl;
      
    return 0;
  }
}