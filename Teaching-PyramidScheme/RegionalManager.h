#ifndef REGIONALMANAGER_H_INCLUDED
#define REGIONALMANAGER_H_INCLUDED
#include <stdio.h>
#include "SalesPerson.h"

class SalesPerson;

class RegionalManager{
    int ID;
    void print();
    void setSalary(int newSalary);
    int getIdOfWorstSalesPerson();
    void fireSalesman(int identifier);
    SalesPerson * getSubordinates();
    void setSubordinateAtIndex(int index, SalesPerson s);

#endif // REGIONALMANAGER_H_INCLUDED