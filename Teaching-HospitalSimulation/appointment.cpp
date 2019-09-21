#include "appointment.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>

//get appointment id
int appointment::getID()
{
    return id;
}
//set appointment id
void appointment::setID(int newID)
{
    id = newID;
}
//get appointment's doctor id
int appointment::getDoctorID()
{
    return doctor_id;
}
//set appointment's doctor id
void appointment::setDoctorID(int newDoctorID)
{
    doctor_id = newDoctorID;
}
//get appointment's patient id
int appointment::getPatientID()
{
    return patient_id;
}
//set appointment's patient id
void appointment::setPatientID(int newPatientID)
{
    patient_id = newPatientID;
}
//get appointment's slot id
int appointment::getSlotID()
{
    return slot_id;
}
//set appointment's slot id
void appointment::setSlotID(int newSlotID)
{
    slot_id = newSlotID;
}
//get appointment reason
string appointment::getReason()
{
    return reason;
}
//set appointment reason
void appointment::setReason(string newReason)
{
    reason = newReason;
}
//get appointment's diagnosis id
int appointment::getDiagnosisID()
{
    return diagnosis_id;
}
//set appointment's diagnosis id
void appointment::setDiagnosisID(int newDiagnosisID)
{
    diagnosis_id = newDiagnosisID;
}
//get appointment's prescription
string appointment::getPrescription()
{
    return prescribed_medication;
}
//set appointment's prescription
void appointment::setPrescription(string newPrescription)
{
    prescribed_medication = newPrescription;
}
//print appointment
void appointment::printAppointment()
{
    cout << "Id: " << id  << "\nDoctorID: " << doctor_id  << "\nPatientID: " << patient_id << "\nSlotId: " << slot_id << "\nReason: " << reason << "\nDiagnosisID: "<< diagnosis_id << endl;
}
//show all appointments for a given doctor id
void showAppointmentsByDoctor(appointment arr[], int numAppointments, int docID)
{
    for(int i = 0; i < numAppointments; i++)
    {
        if(arr[i].getDoctorID() == docID)
            arr[i].printAppointment();
    }
}
//show all appointments for a given patient id
void showAppointmentsBypatient(appointment arr[], int numAppointments, int patientID)
{
    for(int i = 0; i < numAppointments; i++)
    {
        if(arr[i].getPatientID() == patientID)
            arr[i].printAppointment();
    }
}
//show all appointments between two dates
void showAppointmentsBetweenTimes(date_time arrDate[], int numDates, slot arrSlots[], int numSlots, appointment arr[], int numAppointments, date_time first, date_time second)
{
    date_time d;
    bool greaterFirst = false;
    bool lessSecond = false;
    for(int i = 0; i < numAppointments; i++)
    {
        //extract date_time
        for(int j = 0; j < numSlots; j++)
        {
            if(arr[i].getSlotID() == arrSlots[j].getID())
            {
                for(int k = 0; k < numDates; k++)
                {
                    if(arrSlots[j].getDateID() == arrDate[k].getID())
                        d = arrDate[k];
                }
            }
        }
        //compare the derived date time to the given boundaries
        if(d.getYear() > first.getYear())
            greaterFirst = true;
        else if(d.getYear() == first.getYear())
        {
            if(d.getMonth() > first.getMonth())
                greaterFirst = true;
            else if(d.getMonth() == first.getMonth())
            {
                if(d.getDay() > first.getDay())
                    greaterFirst = true;
                else if(d.getDay() == first.getDay())
                {
                    if(d.getAM_PM() == 'p' && first.getAM_PM() == 'a')
                        greaterFirst = true;
                    else if(d.getAM_PM() == first.getAM_PM())
                    {
                        if(d.getHours() > first.getHours())
                            greaterFirst = true;
                        else if(d.getHours() == first.getHours())
                        {
                            if(d.getMinutes() > first.getMinutes())
                                greaterFirst = true;
                        }
                    }
                }
            }
        }
        if(d.getYear() < second.getYear())
            lessSecond = true;
        else if(d.getYear() == second.getYear())
        {
            if(d.getMonth() < second.getMonth())
                lessSecond = true;
            else if(d.getMonth() == second.getMonth())
            {
                if(d.getDay() < second.getDay())
                    lessSecond = true;
                else if(d.getDay() == second.getDay())
                {
                    if(d.getAM_PM() == 'a' && second.getAM_PM() == 'p')
                        lessSecond = true;
                    else if(d.getAM_PM() == second.getAM_PM())
                    {
                        if(d.getHours() < second.getHours())
                            lessSecond = true;
                        else if(d.getHours() == second.getHours())
                        {
                            if(d.getMinutes() < second.getMinutes())
                                lessSecond = true;
                        }
                    }
                }
            }
        }
        if(lessSecond && greaterFirst)
            arr[i].printAppointment();
    }
}
//default constructor
appointment::appointment()
{
    id = -1;
    doctor_id = 0;
    patient_id = 0;
    slot_id = 0;
    reason = "";
    diagnosis_id = 0;
    prescribed_medication = "";
}
//constructor with parameters
appointment::appointment(int newId, int newDoctorID, int newPatientID, int newSlotID, string newReason, int newDiagnosisID, string newPrescribedMedication)
{
    id = newId;
    doctor_id = newDoctorID;
    patient_id = newPatientID;
    slot_id = newSlotID;
    reason = newReason;
    diagnosis_id = newDiagnosisID;
    prescribed_medication = newPrescribedMedication;
}
//schedule appointment
void scheduleAppointment(appointment appointmentArr[], slot slotArr[])
{
    string selectionString, selectionString2 = "";
    int selection3, selection4, selection5, selection6, selection7 = 0;
    cout << "please enter the new appointment id" << endl;
    cin >> selection3;
    cout << "please enter the doctor id" << endl;
    cin >> selection4;
    cout << "please enter the patient id" << endl;
    cin >> selection5;
    cout << "please enter the slot id" << endl;
    cin >> selection6;
    cout << "please enter the reason" << endl;
    cin >> selectionString;
    cout << "please enter the diagnosis id" << endl;
    cin >> selection7;
    cout << "please enter the prescribed medication" << endl;
    cin >> selectionString2;
    for(int i = 0; i < 40; i++)
    {
        if(appointmentArr[i].getID() == -1)
        {
            for(int j = 0; j < 50; j++)
                if(selection6 == slotArr[j].getID())
                    slotArr[j].setAvailible(false);
            appointmentArr[i] = appointment(selection3, selection4, selection5, selection6, selectionString, selection7, selectionString2);
            appointmentArr[i].printAppointment();
            break;
        }
    }
}
//modify an existing appointment
void modifyAppointment(appointment appointmentArr[])
{
    string selectionString= "";
    int selection3, selection4, selection5 = 0;
    cout << "which appointment id will be modified?" << endl;
    cin >> selection3;
    for(int i = 0; i < 40; i++)
    {
        if(appointmentArr[i].getID() == selection3)
        {
            cout << "which criteria of the appointment would you like to modify?" << endl;
            cout << "1. id" << endl;
            cout << "2. doctor_id" << endl;
            cout << "3. patient_id" << endl;
            cout << "4. slot_id" << endl;
            cout << "5. reason" << endl;
            cout << "6. diagnosis_id" << endl;
            cout << "7. medication" << endl;
            cin >> selection4;
            switch(selection4)
            {
                case 1:
                    cout << "please enter a new id" << endl;
                    cin >> selection5;
                    appointmentArr[i].setID(selection5);
                    break;
                case 2:
                    cout << "please enter a new doctor id" << endl;
                    cin >> selection5;
                    appointmentArr[i].setDoctorID(selection5);
                    break;
                case 3:
                    cout << "please enter a new patient id" << endl;
                    cin >> selection5;
                    appointmentArr[i].setPatientID(selection5);
                    break;
                case 4:
                    cout << "please enter a new slot id" << endl;
                    cin >> selection5;
                    appointmentArr[i].setSlotID(selection5);
                    break;
                case 5:
                    cout << "please enter a new reason" << endl;
                    cin >> selectionString;
                    appointmentArr[i].setReason(selectionString);
                    break;
                case 6:
                    cout << "please enter a new diagnosis id" << endl;
                    cin >> selection5;
                    appointmentArr[i].setDiagnosisID(selection5);
                    break;
                case 7:
                    cout << "please enter a new medication" << endl;
                    cin >> selectionString;
                    appointmentArr[i].setPrescription(selectionString);
                    break;
            }
            appointmentArr[i].printAppointment();
            break;
        }
    }
}
//Manage Appointments
void manageAppointments(int selection2, appointment appointmentArr[], slot slotArr[])
{
    cout << selection2;
    int selection3 = 0;
    switch(selection2)
    {
        case 1:
            scheduleAppointment(appointmentArr, slotArr);
            break;
        case 2:
            for(int i = 0; i < 40; i++)
                if(appointmentArr[i].getID() != -1)
                    appointmentArr[i].printAppointment();
            break;
        case 3:
            modifyAppointment(appointmentArr);
            break;
        case 4:
            cout << "enter the id of the appointment to cancel" << endl;
            cin >> selection3;
            for(int i = 0; i < 40; i++)
                if(appointmentArr[i].getID() == selection3)
                    appointmentArr[i] = appointment();
        case 5:
            break;
    }
}



















