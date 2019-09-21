#include <stdio.h>#include <fstream>
#include <iostream>
#include "SalesPerson.h"
#include "RegionalManager.h"


//default constructor for regional manager. Initializes all member variables
RegionalManager::RegionalManager()
{
    ID = 0;
    salary = 0;
    first = "";
    last = "";
    SalesPerson s;
    subordinates = new SalesPerson[5];
    for(int i = 0; i < 5; i++)
        subordinates[i] = s;
}
//returns the first and last name of the regional managerstd::string RegionalManager::getName()
{
    std::string str = first + last;
    return str;
}
//sets the first and last name of the regional managervoid RegionalManager::setName(std::string firstN, std::string lastN)
{
    first = firstN;
    last = lastN;
}
//sets the salary of the regional manager
void RegionalManager::setSalary(int newSalary)
{
    salary = newSalary;
}
//returns the salary of the regional managerint RegionalManager::getSalary()
{
    return salary;
}
//returns the list of salesPersons working under the regional manager
SalesPerson * RegionalManager::getSubordinates()
{
    return subordinates;
}
//fires a sales person based on their id and then evenly distributes the customers to the rest of the sales staff
void RegionalManager::fireSalesman(int identifier)
{
    int it = 0;
    for(int i = 0; i < 5; i++)
    {
        if(subordinates[i].ID == identifier)
        {
            for(int j = 0; j < subordinates[i].getNumCustomers(); j++)
            {
                if(it != i)
                {
                    subordinates[it].addCustomer(subordinates[i].getCustomerAtIndex(j));
                    subordinates[it].setNumCustomers(subordinates[it].getNumCustomers()+1);
                }
                else
                    j--;
                it++;
            }
            SalesPerson s;
            subordinates[i] = s;
            break;
        }
    }
}
//given a new sales person, it will be added to the regional managers subordinates at a given index
void RegionalManager::setSubordinateAtIndex(int index, SalesPerson s)
{
    subordinates[index] = s;
}
//returns the index of the sales person with the lowest total sales
int RegionalManager::getIdOfWorstSalesPerson()
{
    double lowestSales = 99999999;
    int id = -1;
    for(int i = 0; i < 5; i++)
    {
        if(subordinates[i].getTotalSales() < lowestSales)
        {
            lowestSales = subordinates[i].getTotalSales();
            id = subordinates[i].ID;
        }
    }
    return id;
}
//prints the regional managers informations
void RegionalManager::print()
{
    std::cout << "\nManager:\t" << first << " " << last << "\t" << salary << "\n________________________________________" << std::endl;
    for(int i = 0; i < 5; i++)
    {
        if(subordinates[i].ID != 0)
            subordinates[i].print();
    }
}
