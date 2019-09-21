#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <stdio.h>#include <fstream>
#include "doctor.h"

using namespace std;

class patient{private:
    int id;
    int doctor_id;
    int record_id;
    string name;
    string phoneNumber;
    char gender;
    string email;
    string Blood_Type;
public:
    patient();
    patient(int newID, int newDoctorID, int newRecordID, string newName, string newPhone, char newGender, string newEmail, string newBloodType);
    int getID();
    void setID(int newID);
    int getDoctorID();
    void setDoctorID(int newDoctorID);
    int getRecordID();
    void setRecordID(int newRecordID);
    string getName();
    void setName(string newName);
    string getPhoneNumber();
    void setPhoneNumber(string newPhone);
    char getGender();
    void setGender(char newGender);
    string getEmail();
    void setEmail(string newEmail);
    string getBloodType();
    void setBloodType(string newBloodType);
    void print();};

void printPatients(patient arr[], int numPatients);
void findPatient(string patientName, patient arr[], int numPatients, doctor arrDocs[]);
void initializePatients(patient patientArr[]);
void addPatient(patient patientArr[]);
void modifyPatient(patient patientArr[]);
void managePatients(int selection2, patient patientArr[], doctor doctorArr[]);

#endif // SALESPERSON_H_INCLUDED
