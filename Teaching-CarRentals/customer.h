#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

using namespace std;

class Customer{private:    string first, last;    bool preferred;
    string car;
    double bill;
public:    Customer();    string getName();    void setName(string firstN, string lastN);    void setPreferred(bool newPreferred);    bool getPreferred();    double getBill();
    void setBill(double newBill);    void setCar(string newCar);
    string getCar();};void readCustomers(Customer custArr[]);void printCustomers(Customer custArr[], int length);


#endif // CUSTOMER_H_INCLUDED
