// Alex Picon
// lab14.cpp

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Person
{
  int age;
  int coffee;
  string name;
};

const int AGE_FIELD = 4;
const int COFFEE_FIELD = 4;
const int NAME_FIELD = 15;
const int MAX_NUM = 150;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";

void printRecord(Person p);
double averageAge(const Person clients[], int count);
int totalCups(const Person clients[], int count);

int main()
{
  Person clients[MAX_NUM];
  int count = 0;
  ifstream infile;

  infile.open(F_NAME);
  if (infile.fail()) {
    cout << "file error...existing program...press enter...";
    cin.get();
    return 0;
  }

  while (infile >> clients[count].name
                >> clients[count].age
                >> clients[count].coffee) {
    count++;
  }
  infile.close();

  cout << endl;
  
  cout << left
       << setw(NAME_FIELD) << "Name"
       << setw(AGE_FIELD) << "Age"
       << setw(COFFEE_FIELD) << "Cups"
       << endl << endl;

  for (int i = 0; i < count; i++) {
    printRecord(clients[i]);
  }

  double ageAvg = averageAge(clients, count);
  int cupTotal = totalCups(clients, count);

  cout << endl;

  cout << "The average age is " << ageAvg << endl;
  cout << "The total of all coffee cups is " << cupTotal;

  cout << endl << endl;

  return 0;
}

void printRecord(Person p) 
{
  cout << left
       << setw(NAME_FIELD) << p.name
       << setw(AGE_FIELD) << p.age
       << setw(COFFEE_FIELD) << p.coffee 
       << endl;
  }
  
double averageAge(const Person clients[], int count) 
{  
  double average;
  int sum = 0;
  
  for (int i = 0; i < count; i++) {
    sum += clients[i].age;
  }
  
  average = (double)(sum) / count;
  return average;
}

int totalCups(const Person clients[], int count)
{
  int cups = 0;
  for (int i = 0; i < count; i++) {
    cups += clients[i].coffee;
  }
  
  return cups;
}
