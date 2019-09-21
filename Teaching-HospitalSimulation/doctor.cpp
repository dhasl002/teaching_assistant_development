#include "appointment.h"
#include "doctor.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>

using namespace std;
//get docot's phone number
string doctor::getPhoneNumber()
{
    return phoneNumber;
}
//set doctor's phone number
void doctor::setPhoneNumer(string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}
//get doctor's id
int doctor::getID()
{
    return id;
}
//set doctor's id
void doctor::setID(int newID)
{
    id = newID;
}
//get doctor's username
string doctor::getUsername()
{
    return username;
}
//set doctor's username
void doctor::setUsername(string newUsername)
{
    username = newUsername;
}
//get doctor's password
string doctor::getPassword()
{
    return password;
}
//set doctor's password
void doctor::setPassword(string newPassword)
{
    password = newPassword;
}
//get doctor's name
string doctor::getName()
{
    return name;
}
//set doctor's name
void doctor::setName(string newName)
{
    name = newName;
}
//get doctor's skill
string doctor::getSkill()
{
    return skill;
}
//set doctor's skill
void doctor::setSkill(string newSkill)
{
    skill = newSkill;
}
//find doctor and prints information based on doctor name
void findDoctor(string doctorName, doctor arr[], int numDoctors)
{
    for(int i = 0; i < numDoctors; i++)
    {
        if(doctorName == arr[i].getName())
        {
            cout << "id: " << arr[i].getID()  << "\nusername: " << arr[i].getUsername() << "\npassword: " << arr[i].getPassword() << "\nname: " << arr[i].getName() << "\nphone number: " << arr[i].getPhoneNumber() << "\nskill: "<< arr[i].getSkill() << "\n\n";
            break;
        }
    }
}
//constructor with parameters
doctor::doctor(int newID, string newUsername, string newPassword, string newName, string newPhoneNumber, string newSkill)
{
    id = newID;
    username = newUsername;
    password = newPassword;
    name = newName;
    phoneNumber = newPhoneNumber;
    skill = newSkill;
}
//default constructor
doctor::doctor()
{
    id = -1;
    username = "";
    password = "";
    name = "";
    phoneNumber = "";
    skill = "";
}
//print doctor's information
void doctor::print()
{
    cout << "id: " << id << "\nusername: " << username << "\npassword: " << password << "\nname: " << name << "\nphone number: " << phoneNumber << "\nskill: "<< skill << "\n\n";
}
//read in doctor information to data structure
void initializeDoctors(doctor doctorArr[])
{
    int num = 0;
    int tempInt1 = 0;
    int tempInt2 = 0;
    string tempString1 = "";
    string tempString2 = "";
    string tempString3 = "";
    string tempString4 = "";
    string tempString5 = "";
    ifstream inFile;
    inFile.open("Doctors.txt");
    inFile >> num;
    for(int i = 0; i < num; i++)
    {
        inFile >> tempInt1 >> tempString1 >> tempString2 >> tempString3 >> tempString5 >> tempString4;
        //cout << tempInt1 << tempString1 << tempString2 << tempString3 << tempString5 << tempString4;
        doctorArr[i] = doctor(tempInt1, tempString1, tempString2, tempString3, tempString5, tempString4);
    }
    inFile.close();
}
//modify a doctor's information
void modifyDoctor(doctor doctorArr[])
{
    char tempChar = ' ';
    int  selection3, selection4, selection5 = 0;
    string selectionString = "";
    cout << "Enter the id of the doctor to modify" << endl;
    cin >> selection3;
    for(int i = 0; i < 10; i++)
        if(doctorArr[i].getID() == selection3)
        {
            cout << "which info would you like to modify?" << endl;
            cout << "1. Id" << endl;
            cout << "2. Username" << endl;
            cout << "3. Password" << endl;
            cout << "4. Name" << endl;
            cout << "5. PhoneNumber" << endl;
            cout << "6. Skill"<< endl;
            cin >> selection4;
            switch(selection4)
            {
                case 1:
                    cout << "Enter the new value: " << endl;
                    cin >> selection5;
                    doctorArr[i].setID(selection5);
                    break;
                case 2:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    doctorArr[i].setUsername(selectionString);
                    break;
                case 3:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    doctorArr[i].setPassword(selectionString);
                    break;
                case 4:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    doctorArr[i].setName(selectionString);
                    break;
                case 5:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    doctorArr[i].setPhoneNumer(selectionString);
                    break;
                case 6:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    doctorArr[i].setSkill(selectionString);
                    break;
            }
            doctorArr[i].print();
            break;
        }
}
//delete a doctor based on doctor id
void deleteDoctor(doctor doctorArr[], appointment appointmentArr[])
{
    char tempChar = ' ';
    int  selection3, selection4, selection5 = 0;
    cout << "Enter the id of the Doctor to delete: " << endl;
    cin >> selection5;
    for(int i = 0; i < 10; i++)
        if(doctorArr[i].getID() == selection5)
        {
            for(int j = 0; j < 40; j++)
            {
                if(appointmentArr[j].getDoctorID() == selection5)
                {
                    cout << "WARNING! This doctor has an appointment scheduled, are you sure you would like to delete the doctor and appointment(s)? y/n" << endl;
                    cin >> tempChar;
                    if(tempChar == 'y')
                    {
                        for(int k = 0; k < 40; k++)
                            if(appointmentArr[j].getDoctorID() == selection5)
                                appointmentArr[j] = appointment();
                        doctorArr[i] = doctor();
                    }
                    break;
                }
                else
                    doctorArr[i] = doctor();
            }
            break;
        }
}
//manage doctors
void manageDoctors(int selection2, doctor doctorArr[], appointment appointmentArr[])
{
    char tempChar = ' ';
    int  selection3, selection4, selection5 = 0;
    string selectionString = "";
    switch(selection2)
    {
        case 1:
            for(int i = 0; i < 10; i++)
                if(doctorArr[i].getID() != -1)
                    doctorArr[i].print();
            break;
        case 2:
            modifyDoctor(doctorArr);
                break;
        case 3:
            deleteDoctor(doctorArr, appointmentArr);
            break;
        case 4:
            cout << "Enter the name of the Doctor: " << endl;
            cin >> selectionString;
            findDoctor(selectionString, doctorArr, 10);
            break;
        case 5:
            break;
    }
}



















