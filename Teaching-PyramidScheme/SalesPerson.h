#ifndef SALESPERSON_H_INCLUDED
#define SALESPERSON_H_INCLUDED

#include "RegionalManager.h"
#include "Customers.h"
#include <stdio.h>#include <fstream>

class SalesPerson{private:    std::string first, last;
    bool isMale;    Customer *custArray;
    double totalSales;
    int numCustomers;
public:
    int ID;
    void print();    SalesPerson();    std::string getName();    void setName(std::string firstN, std::string lastN);
    void setIsMale();
    bool getIsMale();
    void setNumCustomers(int num);
    int getNumCustomers();
    void setTotalSales();
    double getTotalSales();
    void addCustomer(Customer c);
    void setCustomerAtIndex(int index, Customer c);
    Customer getCustomerAtIndex(int index);
    Customer * getCustomers();};

#endif // SALESPERSON_H_INCLUDED
