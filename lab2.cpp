// Alex Picon
// lab2.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{

  string word;
  int number1;
  int number2;
  float float1;
  float float2;
  
  cout << endl << endl;

  cout << "What's your favorite word? ";
  cin >> word;

  cout << "Your favorite word is " << word;

  cout << endl;

  cout << "Choose 2 whole numbers: ";
  cin >> number1 >> number2;

  cout << "The division of " << number1 << " by " << number2 << " is " << number1/number2
       << endl
       << "The module of " << number1 << " by " << number2 << " is " << number1%number2
       << endl;

  cout << "Choose 2 floating point numbers: ";
  cin >> float1 >> float2;;

  cout << "The division of " << float1 << " by " << float2 << " is " << float1/float2
       << endl << endl;
  
  return 0;
}