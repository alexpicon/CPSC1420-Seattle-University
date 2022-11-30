//Alex Picon
//p1.cpp
//Purpose: Program that plays a word game with the user (similar to MadLibs)

#include <iostream>
#include <string>

using namespace std;

int main()
{
    
  string name, cityName, superName, profession, animal, petName;
  int age, hours;
 
  cout << endl << endl;

  cout << "-----------------------------------------------" << endl << endl
       << " Welcome to Alex's Wonderland! " << endl
       << " Where you exchange words for a cool story!" << endl
       << " (1 WORD/NUMBER PER ANSWER)" << endl << endl
       << "-----------------------------------------------" << endl << endl;

  cout << "What's your name? ";
  getline(cin, name);
  cout << "What's your favorite city? ";
  getline(cin, cityName);
  cout << "What's your dream profession? ";
  getline(cin, profession);
  cout << "What would be your superhero name? ";
  getline(cin, superName);
  cout << "What's your favorite animal? ";
  getline(cin, animal);
  cout << "What's a good petname? ";
  getline(cin, petName);
  cout << "What's your age? ";
  cin >> age;
  cout << "What's your favorite number? ";
  cin >> hours;

  cout << endl << endl; 
  
  cout << "-----------------------------------------------" << endl << endl
       << "A long time ago in a galaxy far, far away..."
       << endl
       << "a supervillain named Dr. Hammy"
       << endl
       << "was taking over the city of " << cityName << "."
       << endl
       << age << " years ago, " << name << " was born to save the world."
       << endl
       << name << " planned to become a(n) " << profession << ","
       << endl
       << "but as time went on became a superhero; " << superName << "." 
       << endl
       << superName << " had adopted a(n) " << animal << "; " << petName << "."
       << endl
       << "Lastly, together they beat Dr. Hammy in " << hours << " hours!"
       << endl
       << "-----------------------------------------------" << endl << endl;
  cout << "Thank you for playing " << name << "! Hope you enjoyed :D"
       << endl << endl
       << "-----------------------------------------------" << endl << endl;

  return 0;
}