#ifndef CUSTOMERS_H_INCLUDED
#define CUSTOMERS_H_INCLUDED

#include <stdio.h>#include <fstream>

class Customer{private:    std::string first, last;
    double moneySpent;public:    Customer();
    void print();    std::string getName();    void setName(std::string firstN, std::string lastN);
    double getMoneySpent();
    void setMoneySpent(double additionalCharge);};

#endif // CUSTOMERS_H_INCLUDED
