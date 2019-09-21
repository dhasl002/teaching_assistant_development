#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED
#include "appointment.h"
#include <stdio.h>#include <fstream>

using namespace std;

class appointment;

class doctor{private:
    int id;
    string username;
    string password;
    string name;
    string phoneNumber;
    string skill;
public:
    doctor(int newID, string newUsername, string newPassword, string newName, string newPhoneNumber, string newSkill);
    doctor();
    string getPhoneNumber();
    void setPhoneNumer(string newPhoneNumber);
    int getID();
    void setID(int newID);
    string getUsername();
    void setUsername(string newUsername);
    string getPassword();
    void setPassword(string password);
    string getName();
    void setName(string newName);
    string getSkill();
    void setSkill(string newSkill);
    void print();};

void printDoctors(doctor arr[], int numDoctors);
void findDoctor(string doctorName, doctor arr[], int numDoctors);
void initializeDoctors(doctor doctorArr[]);
void modifyDoctor(doctor doctorArr[]);
void manageDoctors(int selection2, doctor doctorArr[], appointment appointmentArr[]);
void deleteDoctor(doctor doctorArr[], appointment appointmentArr[]);
#endif // SALESPERSON_H_INCLUDED
