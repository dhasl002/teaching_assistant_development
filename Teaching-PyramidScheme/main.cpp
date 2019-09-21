#include <iostream>
#include "SalesPerson.h"
#include "Customers.h"
#include "RegionalManager.h"
using namespace std;

//reads input file and puts input into correct classes
void readFile(string nameOfFile, RegionalManager& r)
{
    ifstream infile;
    string temp = "";
    string temp2 = "";
    int tempInt = 0;
    double tempDouble = 0;
    infile.open(nameOfFile.c_str());

    //reading in regional manager info
    infile >> r.ID;
    infile >> temp >> temp2;
    r.setName(temp, temp2);
    infile >> tempInt;
    r.setSalary(tempInt);

    //reading in salesPerson
    for(int i = 0; i < 5; i++)
    {
        SalesPerson tempS;
        infile >> tempS.ID;
        infile >> temp >> temp2;
        tempS.setName(temp, temp2);
        infile >> temp;
        if(temp == "Male")
            tempS.setIsMale();
        infile >> tempInt;
        tempS.setNumCustomers(tempInt);
        //reading in customers
        for(int j = 0; j < tempInt; j++)
        {
            Customer tempC;
            infile >> temp >> temp2;
            tempC.setName(temp, temp2);
            infile >> tempDouble;
            tempC.setMoneySpent(tempDouble);
            tempS.setCustomerAtIndex(j, tempC);
        }
        tempS.setTotalSales();
        r.setSubordinateAtIndex(i,tempS);
    }
}

int main()
{
    RegionalManager r;
    readFile("input.txt", r);
    r.print();
    r.fireSalesman(r.getIdOfWorstSalesPerson());
    cout << "=======================================================================" << endl;
    r.print();
    return 0;
}
