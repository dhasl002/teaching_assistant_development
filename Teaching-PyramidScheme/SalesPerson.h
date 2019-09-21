#ifndef SALESPERSON_H_INCLUDED
#define SALESPERSON_H_INCLUDED

#include "RegionalManager.h"
#include "Customers.h"
#include <stdio.h>

class SalesPerson{
    bool isMale;
    double totalSales;
    int numCustomers;

    int ID;
    void print();
    void setIsMale();
    bool getIsMale();
    void setNumCustomers(int num);
    int getNumCustomers();
    void setTotalSales();
    double getTotalSales();
    void addCustomer(Customer c);
    void setCustomerAtIndex(int index, Customer c);
    Customer getCustomerAtIndex(int index);
    Customer * getCustomers();

#endif // SALESPERSON_H_INCLUDED