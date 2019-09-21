#include <iostream>
#include "diagnosis.h"
#include "patient.h"
#include "doctor.h"
#include "slot.h"
#include "appointment.h"
#include "record.h"


using namespace std;

int main()
{
    char tempGender = ' ';
    string tempName, tempEmail, selectionString, selectionString2, tempBloodType, tempPhoneNumber = "";
    int counter = 0;
    int selection, selection2, selection3, selection4, selection5, selection6, selection7, tempID, tempDoctorID, tempRecordId, num, tempYear, tempMonth, tempDay = 0;
    char selectionChar = ' ';
    char tempChar = ' ';
    bool goBack = false;
    date_time date1;
    date_time date2;

    diagnosis diagnosisArr[50];
    patient patientArr[20];
    doctor doctorArr[10];
    slot slotArr[50];
    date_time dateTimeArr[40];
    appointment appointmentArr[40];
    record recordArr[20];

    initializeDiagnosis(diagnosisArr);
    initializePatients(patientArr);
    initializeDoctors(doctorArr);
    initializeSlots(slotArr);
    initializeDateTime(dateTimeArr);

    do{
        goBack = true;
        cout << "Welcome to HMS. Please choose an action:\n" << endl;
        cout << "1. Manage Appointments" << endl;
        cout << "2. Manage Slots" << endl;
        cout << "3. Manage Doctors" << endl;
        cout << "4. Manage Patients" << endl;
        cout << "5. Manage Patients' records" << endl;
        cout << "6. Manage lab" << endl;
        cout << "7. Exit" << endl;
        cin >> selection;

        switch(selection)
        {
            case 1:
                cout << "1. Schedule a new appointment" << endl;
                cout << "2. Show all appointments" << endl;
                cout << "3. Modify an existing appointment" << endl;
                cout << "4. Remove an appointment" << endl;
                cout << "5. Go Back" << endl;
                cin >> selection2;
                manageAppointments(selection2, appointmentArr, slotArr);
                break;
            case 2:
                cout << "1. Show available slots" << endl;
                cout << "2. Show unavailable slots" << endl;
                cout << "3. Show all slots" << endl;
                cout << "4. Show all available slots by doctors name" << endl;
                cout << "5. Show all slots by time range" << endl;
                cout << "6. Add new slot" << endl;
                cout << "7. Update slot" << endl;
                cout << "8. Remove a slot" << endl;
                cout << "9. Go Back" << endl;
                cin >> selection2;
                manageSlots(selection2, dateTimeArr, slotArr, doctorArr);
                break;
            case 3:
                cout << "1. Show all doctors" << endl;
                cout << "2. Update doctors' info" << endl;
                cout << "3. Delete doctor" << endl;
                cout << "4. Search for doctor" << endl;
                cout << "5. Go Back" << endl;
                cin >> selection2;
                manageDoctors(selection2, doctorArr, appointmentArr);
                break;
            case 4:
                cout << "1. Add Patient" << endl;
                cout << "2. Update patient's info" << endl;
                cout << "3. Delete patient" << endl;
                cout << "4. View all patients" << endl;
                cout << "5. Search for patient" << endl;
                cout << "6. Search for patient by doctor's name" << endl;
                cout << "7. Show patient's appointments by time range" << endl;
                cout << "8. Go Back" << endl;
                cin >> selection2;
                managePatients(selection2, patientArr, doctorArr);
                break;
            case 5:
                cout << "1. Add new record" << endl;
                cout << "2. Update record" << endl;
                cout << "3. show all record" << endl;
                cout << "4. delete record" << endl;
                cin >> selection2;
                manageRecords(selection2, recordArr);
                break;
            case 6:
                cout << "1. Add new lab appointment" << endl;
                cout << "2. Delete lab appointment" << endl;
                cout << "3. Show all lab appointments" << endl;
                cin >> selection2;
                manageLab(selection2, slotArr, dateTimeArr, appointmentArr);
                break;
            case 7:
                goBack = false;
                break;
        }
    }while(goBack);
    return 0;
}
