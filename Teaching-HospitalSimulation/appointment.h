#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED
#include <stdio.h>#include <fstream>
#include "date_time.h"
#include "slot.h"
using namespace std;

class slot;

class appointment{
private:
    int id;
    int doctor_id;
    int patient_id;
    int slot_id;
    string reason;
    int diagnosis_id;
    string prescribed_medication;
public:
    appointment();
    appointment(int newId, int newDoctorID, int newPatientID, int newSlotID, string newReason, int newDiagnosisID, string newPrescribedMedication);
    int getID();
    void setID(int newID);
    int getDoctorID();
    void setDoctorID(int newDoctorID);
    int getPatientID();
    void setPatientID(int newPatientID);
    int getSlotID();
    void setSlotID(int newSlotID);
    string getReason();
    void setReason(string newReason);
    int getDiagnosisID();
    void setDiagnosisID(int newDiagnosisID);
    string getPrescription();
    void setPrescription(string newPrescription);
    void printAppointment();
};
void showAppointmentsByDoctor(appointment arr[], int numAppointments, int docID);
void showAppointmentsBypatient(appointment arr[], int numAppointments, int patientID);
void showAppointmentsBetweenTimes(date_time dateArr[], int numDates, slot arrSlots[], int numSlots, appointment arr[], int numAppointments, date_time first, date_time second);
void scheduleAppointment(appointment appointmentArr[], slot slotArr[]);
void modifyAppointment(appointment appointmentArr[]);
void manageAppointments(int selection2, appointment appointmentArr[], slot slotArr[]);

#endif // APPOINTMENT_H_INCLUDED
