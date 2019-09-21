#include "patient.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>

using namespace std;
//constructor with parameters
patient::patient(int newID, int newDoctorID, int newRecordID, string newName, string newPhone, char newGender, string newEmail, string newBloodType)
{
    id = newID;
    doctor_id = newDoctorID;
    record_id = newRecordID;
    name = newName;
    phoneNumber = newPhone;
    gender = newGender;
    email = newEmail;
    Blood_Type = newBloodType;
}
//default constructor
patient::patient()
{
    id = -1;
    doctor_id = 0;
    record_id = 0;
    name = "";
    phoneNumber = "";
    gender = ' ';
    email = "";
    Blood_Type = "";
}
//get patient's id
int patient::getID()
{
    return id;
}
//set patient's id
void patient::setID(int newID)
{
    id = newID;
}
//get patient's doctor id
int patient::getDoctorID()
{
    return doctor_id;
}
//set patient's doctor id
void patient::setDoctorID(int newDoctorID)
{
    doctor_id = newDoctorID;
}
//get patient's record id
int patient::getRecordID()
{
    return record_id;
}
//set patient's record id
void patient::setRecordID(int newRecordID)
{
    record_id = newRecordID;
}
//get patient's name
string patient::getName()
{
    return name;
}
//set patient's name
void patient::setName(string newName)
{
    name = newName;
}
//get patient's phone number
string patient::getPhoneNumber()
{
    return phoneNumber;
}
// set patient's phone number
void patient::setPhoneNumber(string newPhone)
{
    phoneNumber = newPhone;
}
//get patient's gender
char patient::getGender()
{
    return gender;
}
//set patients gender
void patient::setGender(char newGender)
{
    gender = newGender;
}
//get patient's email
string patient::getEmail()
{
    return email;
}
//set patient's email
void patient::setEmail(string newEmail)
{
    email = newEmail;
}
//get patient's blood type
string patient::getBloodType()
{
    return Blood_Type;
}
//set patient's blood type
void patient::setBloodType(string newBloodType)
{
    Blood_Type = newBloodType;
}
//find patient based on name
void findPatient(string patientName, patient arr[], int numPatients, doctor arrdocs[])
{
    for(int i = 0; i < numPatients; i++)
    {
        if(patientName == arr[i].getName())
        {
            arr[i].print();
            break;
        }
        for(int j = 0; j < 10; j++)
        {
            if(arr[i].getDoctorID() == arrdocs[j].getID() && patientName == arrdocs[j].getName())
            {
                arr[i].print();
                break;
            }
        }

    }
}
//print patient's information
void patient::print()
{
    cout << "Id: " << id << "\nDoctorID: " <<  doctor_id << "\nRecordID: " << record_id << "\nName: " << name << "\nPhone: " << phoneNumber << "\nGender: " << gender << "\nEmail: " << email << "\nBloodType: " << Blood_Type << "\n\n";
}
//read in patient information to data structure
void initializePatients(patient patientArr[])
{
    int num = 0;
    int tempInt1 = 0;
    int tempInt2 = 0;
    int tempInt3 = 0;
    int tempInt4 = 0;
    string tempString1 = "";
    string tempString2 = "";
    string tempString3 = "";
    string tempString4 = "";
    char tempChar = ' ';
    ifstream inFile;
    inFile.open("Patients.txt");
    inFile >> num;
    for(int i = 0; i < num; i++)
    {
        inFile >> tempInt1 >> tempInt2 >> tempInt3 >> tempString1 >> tempString4 >> tempChar >> tempString2 >> tempString3;
        //cout << tempChar << endl;
        patientArr[i] = patient(tempInt1, tempInt2, tempInt3, tempString1, tempString4, tempChar, tempString2, tempString3);
    }
    inFile.close();
}
//add new patient
void addPatient(patient patientArr[])
{
    string tempName, tempEmail, selectionString, selectionString2, tempBloodType, tempPhoneNumber = "";
    int tempID, tempDoctorID, tempRecordId = 0;
    char tempGender = ' ';
    cout << "please enter patient id" << endl;
    cin >> tempID;
    cout << "please enter doctor id" << endl;
    cin >> tempDoctorID;
    cout << "please enter record id" << endl;
    cin >> tempRecordId;
    cout << "please enter name" << endl;
    cin >> tempName;
    cout << "please enter phone number" << endl;
    cin >> tempPhoneNumber;
    cout << "please enter gender" << endl;
    cin >> tempGender;
    cout << "please enter email" << endl;
    cin >> tempEmail;
    cout << "please enter blood type" << endl;
    cin >> tempBloodType;
    for(int i = 0; i < 20; i++)
    {
        if(patientArr[i].getID() == -1)
        {
            patientArr[i] = patient(tempID, tempDoctorID, tempRecordId, tempName, tempPhoneNumber, tempGender, tempEmail, tempBloodType);
            patientArr[i].print();
            break;
        }
    }
}
//modify a patients information
void modifyPatient(patient patientArr[])
{
    int selection3, selection4, selection5 = 0;
    char selectionChar = ' ';
    string selectionString, selectionString2 = " ";
    cout << "Enter the id of the paient to modify" << endl;
    cin >> selection3;
    for(int i = 0; i < 20; i++)
        if(patientArr[i].getID() == selection3)
        {
            cout << "which info would you like to modify?" << endl;
            cout << "1. Id" << endl;
            cout << "2. Doctor Id" << endl;
            cout << "3. Record Id" << endl;
            cout << "4. Name" << endl;
            cout << "5. PhoneNumber" << endl;
            cout << "6. Gender"<< endl;
            cout << "7. Email"<< endl;
            cout << "8. BloodType"<< endl;
            cin >> selection4;
            switch(selection4)
            {
                case 1:
                    cout << "Enter the new value: " << endl;
                    cin >> selection5;
                    patientArr[i].setID(selection5);
                    break;
                case 2:
                    cout << "Enter the new value: " << endl;
                    cin >> selection5;
                    patientArr[i].setDoctorID(selection5);
                    break;
                case 3:
                    cout << "Enter the new value: " << endl;
                    cin >> selection5;
                    patientArr[i].setRecordID(selection5);
                    break;
                case 4:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    patientArr[i].setName(selectionString);
                    break;
                case 5:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString2;
                    patientArr[i].setPhoneNumber(selectionString2);
                    break;
                case 6:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionChar;
                    patientArr[i].setGender(selectionChar);
                    break;
                case 7:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    patientArr[i].setEmail(selectionString);
                    break;
                case 8:
                    cout << "Enter the new value: " << endl;
                    cin >> selectionString;
                    patientArr[i].setBloodType(selectionString);
                    break;
            }
            patientArr[i].print();
            break;
        }
}
//manage patients
void managePatients(int selection2, patient patientArr[], doctor doctorArr[])
{
    string tempName, tempEmail, selectionString, selectionString2, tempBloodType, tempPhoneNumber = "";
    int tempID, tempDoctorID, tempRecordId, selection5 = 0;
    char tempGender = ' ';
    switch(selection2)
    {
        case 1:
            addPatient(patientArr);
            break;
        case 2:
            modifyPatient(patientArr);
            break;
        case 3:
            cout << "Enter the id of the Patient to delete: " << endl;
            cin >> selection5;
            for(int i = 0; i < 20; i++)
                if(patientArr[i].getID() == selection5)
                {
                    patientArr[i] = patient();
                }
            break;
        case 4:
            for(int i = 0; i < 20; i++)
                if(patientArr[i].getID() != -1)
                    patientArr[i].print();
            break;
        case 5:
            cout << "Enter the name of the Patient to find" << endl;
            cin >> selectionString;
            findPatient(selectionString, patientArr, 20, doctorArr);
            break;
        case 6:
            cout << "Enter the name of the Doctor" << endl;
            cin >> selectionString;
            findPatient(selectionString, patientArr, 20, doctorArr);
            break;
        case 7:
            break;
    }
}

