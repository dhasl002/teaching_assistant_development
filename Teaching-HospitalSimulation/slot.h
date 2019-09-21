#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED
#include <stdio.h>#include <fstream>
#include "doctor.h"
#include "date_time.h"

using namespace std;

class doctor;
class appointment;

class slot{private:
    int id;
    int date_id;
    int doctor_id;
    bool available;
public:
    slot();
    slot(int newID, int newDateID, int newDoctorID, bool newAvailble);
    int getID();
    void setId(int newID);
    int getDateID();
    void setDateID(int newDateID);
    int getDoctorID();
    void setDoctorID(int newDoctorID);
    bool getAvailible();
    void setAvailible(bool newAvailable);
    void printSlot();};

void showAvailableSlots(slot arr[], int numSlots);
void showUnavailableSlots(slot arr[], int numSlots);
void showAllSlots(slot arr[], int numSlots);
void showDoctorSlots(slot arr[], int numSlots, int docID);
void showSlotsBetweenTimes(slot arr[], int numSlots, date_time dateArr[], int numDateTime, date_time first, date_time second);
void initializeSlots(slot slotArr[]);
void slotsInTimeRange(slot slotArr[], date_time dateTimeArr[]);
void addSlot(date_time dateTimeArr[], slot slotArr[]);
void manageSlots(int selection2, date_time dateTimeArr[], slot slotArr[], doctor doctorArr[]);
void addLab(slot slotArr[], date_time dateTimeArr[], appointment appointmentArr[]);
void manageLab(int selection2, slot slotArr[], date_time dateTimeArr[], appointment appointmentArr[]);
#endif // SALESPERSON_H_INCLUDED
