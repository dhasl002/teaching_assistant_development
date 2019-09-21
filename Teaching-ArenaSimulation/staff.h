#ifndef STAFF_H
#define STAFF_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class staff
{
    public:
        staff();
        int Getid() { return id; }
        void Setid( int val) { id = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getjob() { return job; }
        void Setjob(string val) { job = val; }
        int Getsalary() { return salary; }
        void Setsalary(int val) { salary = val; }
    protected:
    private:
        int id;
        string name;
        string job;
        int salary;
};
//main menu for staff
void staffMenu(int selection, vector<staff> &staffVector);
//prints all staff
void printAllStaff(vector<staff> staffVector);
//given an id the function will print the information of that staff member
void printStaffById(int selection, vector<staff> staffVector);
//given a job, the program will print all staff members of that job
void printStaffByJob(string str, vector<staff> staffVector);
//fire a staff member based on their id
void fireSalesman(int selection, vector<staff> &staffVector);

#endif // STAFF_H
