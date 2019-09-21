#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED

using namespace std;

class Staff{private:    string first, last;
    string car;
    int salary;
public:    Staff();    string getName();    void setName(string firstN, string lastN);    double getSalary();
    void setSalary(double newSalary);    void setCar(string newCar);
    string getCar();};void readStaff(Staff staffArr[]);
void printStaff(Staff staffArr[], int length);

#endif // STAFF_H_INCLUDED
