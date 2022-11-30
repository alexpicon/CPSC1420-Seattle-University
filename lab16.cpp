// Alex Picon
// lab16.cpp

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
const int COFFEE_FIELD = 7;
const int NAME_FIELD = 10;
const int MAX_NUM = 150;
const string F_NAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";

void printRecord(Person p);
void printList(const Person clients[], int count);
void sortList(Person clients[], int count);
void findOldest(const Person clients[], int count);
void findLeast(const Person clients[], int count);
double averageAge(const Person clients[], int count);
int totalCups(const Person clients[], int count);

int main()
{
    Person clients[MAX_NUM];
    int count = 0;
    int cupTotal;
    double ageAvg;
    ifstream infile;

    infile.open(F_NAME);
    if (infile.fail())
    {
        cout << "file error...existing program...press enter...";
        cin.get();
        return 0;
    }

    while (infile >> clients[count].name 
                  >> clients[count].age 
                  >> clients[count].coffee)
    {
        count++;
    }
    infile.close();

    ageAvg = averageAge(clients, count);
    cupTotal = totalCups(clients, count);

    cout << endl;

    printList(clients, count);

    cout << endl;
    cout << "The average age is " << ageAvg << "." << endl
         << endl;
    cout << "The total of all coffee cups drank each day is "
         << cupTotal << ".";

    findOldest(clients, count);

    findLeast(clients, count);

    printList(clients, count);

    sortList(clients, count);

    printList(clients, count);

    cout << endl;

    return 0;
}

void printRecord(Person p)
{

    cout << left << setw(NAME_FIELD) << p.name
         << right << setw(AGE_FIELD) << p.age
         << setw(COFFEE_FIELD) << p.coffee
         << endl;
}

void findOldest(const Person clients[], int count)
{

    Person oldestPerson = clients[0];

    for (int i = 1; i < count; i++)
    {

        if (clients[i].age > oldestPerson.age)
        {
            oldestPerson = clients[i];
        }
    }
    cout << endl
         << endl;
    cout << "The oldest person is " << oldestPerson.name
         << "." << endl
         << "At " << oldestPerson.age
         << " years old, she drinks " << oldestPerson.coffee
         << " cups of coffee a day." << endl;
}

void findLeast(const Person clients[], int count)
{

    Person leastCaffd = clients[0];

    for (int i = 1; i < count; i++)
    {

        if (clients[i].coffee < leastCaffd.coffee)
        {
            leastCaffd = clients[i];
        }
    }
    cout << endl;
    cout << "The one who drinks the least is "
         << leastCaffd.name << "." << endl
         << "At "
         << leastCaffd.age << " years old, she drinks "
         << leastCaffd.coffee << " cups of coffee a day."
         << endl
         << endl;
}

void printList(const Person clients[], int count)
{
    cout << endl;

    cout << setw(NAME_FIELD) << left << "Name"
         << setw(AGE_FIELD) << right << "Age"
         << setw(COFFEE_FIELD) << "Coffee"
         << endl;
    cout << setw(NAME_FIELD) << left << string(NAME_FIELD - 1, '-')
         << setw(AGE_FIELD) << right << string(AGE_FIELD - 1, '-')
         << setw(COFFEE_FIELD) << string(COFFEE_FIELD - 1, '-')
         << endl;
    for (int i = 0; i < count; i++)
    {
        printRecord(clients[i]);
    }
    cout << endl;
}

void sortList(Person clients[], int count)
{

    for (int currMin = 0; currMin < count - 1; currMin++)
    {
        for (int currUnsorted = count - 1; currUnsorted > currMin; currUnsorted--)
        {

            if (clients[currUnsorted].name < clients[currMin].name)
            {
                // clients[currMin] -= clients[currUnsorted]
                // clients[currUnsorted] += clients[currMin]
                // clients[currMin] = clients[currUnsorted] - clients[currMin]
                swap(clients[currMin], clients[currUnsorted]);
            }
        }
    }
}

double averageAge(const Person clients[], int count)
{
    double average;
    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += clients[i].age;
    }

    average = (double)(sum) / count;
    return average;
}

int totalCups(const Person clients[], int count)
{
    int cups = 0;
    for (int i = 0; i < count; i++)
    {
        cups += clients[i].coffee;
    }

    return cups;
}