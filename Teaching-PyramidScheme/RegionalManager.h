#ifndef REGIONALMANAGER_H_INCLUDED
#define REGIONALMANAGER_H_INCLUDED
#include <stdio.h>#include <fstream>
#include "SalesPerson.h"

class SalesPerson;

class RegionalManager{private:    int salary;    std::string first, last;    SalesPerson* subordinates;public:
    int ID;
    void print();    RegionalManager();    std::string getName();    void setName(std::string firstN, std::string lastN);
    void setSalary(int newSalary);    int getSalary();
    int getIdOfWorstSalesPerson();
    void fireSalesman(int identifier);
    SalesPerson * getSubordinates();
    void setSubordinateAtIndex(int index, SalesPerson s);};

#endif // REGIONALMANAGER_H_INCLUDED
