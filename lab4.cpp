//Alex Picon
//lab4.cpp

#include <iostream>

using namespace std;

int main()
{

  int num1, num2, large, small; 

  cout << endl;
  
  cout << "Enter 2 integers: ";
  cin >> num1 >> num2;
      
  if (num1 >= num2){
    large = num1;
    small = num2;
    cout << endl;
    cout << "Larger number: " << large << endl;
    cout << "Smaller number: " << small;
  }else{
    large = num2;
    small = num1;
    cout << endl;
    cout << "Larger number: " << large << endl;
    cout << "Smaller number: " << small;
  }
  
  if ( large % small == 0 ){
    cout << endl << endl << "Yes, " << large << " is a multiple of " << small
         << " and the other factor is " << large/small;
    cout << endl << endl;
  }else{
    cout << endl << endl << "No, " << large << " is not a multiple of " << small;
    cout << endl << endl;
  }
      
  return 0;
}
