#include <stdio.h>#include <fstream>
#include <iostream>
#include "Customers.h"

//Default constructor for the customer, initializes all member variable
Customer::Customer()
{
    first = "";
    last = "";
    moneySpent = 0;
}
//returns the first and last name of the customerstd::string Customer::getName()
{
    std::string str = first + last;
    return str;
}
//sets the first and last name of the customervoid Customer::setName(std::string firstN, std::string lastN)
{
    first = firstN;
    last = lastN;
}
//returns the total amount of money spent by the customer
double Customer::getMoneySpent()
{
    return moneySpent;
}
//adds an additional Charge the total amount of money that the customer has spent
void Customer::setMoneySpent(double additionalCharge)
{
    moneySpent += additionalCharge;
}
//prints the customer's member variables
void Customer::print()
{
    std::cout<< "\t\tCustomer:\t " << first << " " << last << "\t\t" << moneySpent << std::endl;
}
