#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED

using namespace std;

class Staff{
    string car;
    int salary;

    void setSalary(double newSalary);
    string getCar();
void printStaff(Staff staffArr[], int length);

#endif // STAFF_H_INCLUDED