#include <fstream>
#include <iostream>
#include "customer.h"
using namespace std;

Customer::Customer()
{    first = "";
    last = "";    preferred = false;
    car = "";
    bill = 0.0;
}string Customer::getName()
{
    return first + " " + last;
}
void Customer::setName(string firstN, string lastN)
{
    first = firstN;
    last = lastN;
}
void Customer::setPreferred(bool newPreferred)
{
    preferred = newPreferred;
}
bool Customer::getPreferred()
{
    return preferred;
}
double Customer::getBill()
{
    return bill;
}

void Customer::setBill(double newBill)
{
    bill = newBill;
}
void Customer::setCar(string newCar)
{
    car = newCar;
}
string Customer::getCar()
{
    return car;
}void readCustomers(Customer custArr[])
{
    string first = "";
    string last = "";
    bool preferred = false;
    string car = "";
    double bill = 0.0;
    int totalnum = 0;

    ifstream inFile;
    inFile.open("customers.txt");
    inFile >> totalnum;
    for(int i = 0; i < totalnum; i++)
    {
        inFile >> first >> last >> preferred >> car >> bill;
        custArr[i].setName(first, last);
        custArr[i].setPreferred(preferred);
        custArr[i].setCar(car);
        custArr[i].setBill(bill);
    }
}

void printCustomers(Customer custArr[], int length)
{
    cout << "\n" << "Name\t" << "\t     Preferred?\t" << "Car\t" << "\tBill\n";
    cout << "________________________________________________________" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << custArr[i].getName() << "\t\t" << custArr[i].getPreferred() << "\t" << custArr[i].getCar() << "      \t" << custArr[i].getBill() << endl;
    }
}