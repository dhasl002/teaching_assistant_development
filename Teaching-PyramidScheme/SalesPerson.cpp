#include <stdio.h>#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "SalesPerson.h"
#include "RegionalManager.h"
#include "Customers.h"

//default constructor for Sales people. Initializes all member variables
SalesPerson::SalesPerson()
{
    ID = 0;
    totalSales = 0;
    first = "";
    last = "";
    isMale = false;
    Customer c;
    numCustomers = 0;
    custArray = new Customer[10];
    for(int i = 0; i < 10; i++)
        custArray[i] = c;
}
//returns the first and last name of the sales personstd::string SalesPerson::getName()
{
    std::string str = first + last;
    return str;
}
//By default the member variable isMale is set to false, meaning this is a woman. This function should be called if the worker is male;
void SalesPerson::setIsMale()
{
    isMale = true;
}
//returns true if the worker is male and false if the worker is female
bool SalesPerson::getIsMale()
{
    return isMale;
}
//sets the first and last name of the Sales Personvoid SalesPerson::setName(std::string firstN, std::string lastN)
{
    first = firstN;
    last = lastN;
}
//returns the list of subordinates working for this sales Person
Customer * SalesPerson::getCustomers()
{
    return custArray;
}
//sets the total Sales for this SalesPerson by adding up all of the customers spendings
void SalesPerson::setTotalSales()
{
    double tot = 0;
    for(int i = 0; i < 10; i++)
        tot += custArray[i].getMoneySpent();
    totalSales = tot;
}
//returns the total amount of sales that this sales person has made
double SalesPerson::getTotalSales()
{
    return totalSales;
}
//sets the number of customers for this sales person
void SalesPerson::setNumCustomers(int num)
{
    numCustomers = num;
}
//returns the number of customers for this sales person
int SalesPerson::getNumCustomers()
{
    return numCustomers;
}
//adds the passed customer to the custArray
void SalesPerson::addCustomer(Customer c)
{
    custArray[numCustomers] = c;
    numCustomers++;
}
//gets a customer from the custArray at a given index
Customer SalesPerson::getCustomerAtIndex(int index)
{
    return custArray[index];
}
//gets a customer from the custArray at a given index
void SalesPerson::setCustomerAtIndex(int index, Customer c)
{
    custArray[index] = c;
}
//prints the information of the Sales person
void SalesPerson::print()
{
    std::cout << "\tSalesPerson:\t " << first << " " << last << "\t\t" << ID << "\t\t" << totalSales << "\n_______________________________________________________________________" <<std::endl;
    for(int i = 0; i < numCustomers; i++)
    {
        if(custArray[i].getMoneySpent() != 0)
            custArray[i].print();
    }
}
