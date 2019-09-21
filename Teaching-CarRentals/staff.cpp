#include <fstream>
#include <iostream>
#include "staff.h"

using namespace std;

Staff::Staff()
{    first = "";
    last = "";
    car = "";
    salary = 0;
}
string Staff::getName()
{
    return first + " " + last;
}
void Staff::setName(string firstN, string lastN)
{
    first = firstN;
    last = lastN;
}

double Staff::getSalary()
{
    return salary;
}

void Staff::setSalary(double newSalary)
{
    salary = newSalary;
}
void Staff::setCar(string newCar)
{
    car = newCar;
}

string Staff::getCar()
{
    return car;
}void readStaff(Staff staffArr[])
{
    string first = "";
    string last = "";
    string car = "";
    int salary = 0.0;
    int totalnum = 0;

    ifstream inFile;
    inFile.open("staff.txt");
    inFile >> totalnum;
    for(int i = 0; i < totalnum; i++)
    {
        inFile >> first >> last >> car >> salary;
        staffArr[i].setName(first, last);
        staffArr[i].setCar(car);
        staffArr[i].setSalary(salary);
    }
}

void printStaff(Staff staffArr[], int length)
{
    cout << "\n" << "Name\t\t\t"  << "Car\t\t" << "Bill\n";
    cout << "________________________________________________________" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << staffArr[i].getName() << "\t\t" << staffArr[i].getCar() << "   \t" << staffArr[i].getSalary() << endl;
    }
}
