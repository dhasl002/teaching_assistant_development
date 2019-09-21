#include <iostream>
#include "staff.h"

using namespace std;

//default constructor for staff
staff::staff()
{
    id = 0;
    name = "";
    job = "";
    salary = 0;
}

//prints all staff
void printAllStaff(vector<staff> staffVector)
{
    for(int i = 0; i < staffVector.size(); i++)
    {
        cout << "Id: " << staffVector[i].Getid() << endl;
        cout << "Name: " << staffVector[i].Getname() << endl;
        cout << "Job: " << staffVector[i].Getjob() << endl;
        cout << "Salary: " << staffVector[i].Getsalary() << "\n" << endl;
    }
}

//given an id the function will print the information of that staff member
void printStaffById(int selection, vector<staff> staffVector)
{
    for(int i = 0; i < staffVector.size(); i++)
    {
        if(selection == staffVector[i].Getid())
        {
            cout << "Id: " << staffVector[i].Getid() << endl;
            cout << "Name: " << staffVector[i].Getname() << endl;
            cout << "Job: " << staffVector[i].Getjob() << endl;
            cout << "Salary: " << staffVector[i].Getsalary() << "\n" << endl;
        }
    }
}

//given a job, the program will print all staff members of that job
void printStaffByJob(string str, vector<staff> staffVector)
{
    cout << str << endl;
    for(int i = 0; i < staffVector.size(); i++)
    {
        if(str == staffVector[i].Getjob())
        {
            cout << "Id: " << staffVector[i].Getid() << endl;
            cout << "Name: " << staffVector[i].Getname() << endl;
            cout << "Job: " << staffVector[i].Getjob() << endl;
            cout << "Salary: " << staffVector[i].Getsalary() << "\n" << endl;
        }
    }
}

//fire a staff member based on their id
void fireSalesman(int selection, vector<staff> &staffVector)
{
    for(int i = 0; i < staffVector.size(); i++)
    {
        if(selection == staffVector[i].Getid())
        {
            staffVector.erase(staffVector.begin()+i);
        }
    }
}

//main menu for staff
void staffMenu(int selection, vector<staff> &staffVector)
{
    staff s;
    string str = " ";
    switch(selection)
    {
    case 1:
        printAllStaff(staffVector);
        break;
    case 2:
        cout << "Enter the id of staff member to print" << endl;
        cin >> selection;
        printStaffById(selection, staffVector);
        break;
    case 3:
        cout << "Enter the job of staff member to print" << endl;
        cin >> str;
        printStaffByJob(str, staffVector);
        break;
    case 4:
        cout << "Enter the id of the new staff member" << endl;
        cin >> selection;
        s.Setid(selection);
        cout << "Enter the name of the new staff member" << endl;
        cin >> str;
        s.Setname(str);
        cout << "Enter the job of the new staff member" << endl;
        cin >> str;
        s.Setjob(str);
        cout << "Enter the salary of the new staff member" << endl;
        cin >> selection;
        s.Setsalary(selection);
        staffVector.push_back(s);
        break;
    case 5:
        cout << "Enter the id of staff member to fire" << endl;
        cin >> selection;
        fireSalesman(selection, staffVector);
        break;
    case 6:
        break;
    }
}
