#include "slot.h"
#include "doctor.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>

using namespace std;
//default constructor
slot::slot()
{
    id = -1;
    date_id = 0;
    doctor_id = 0;
    available = true;
}
//constructor with parameters
slot::slot(int newID, int newDateID, int newDoctorID, bool newAvailble)
{
    id = newID;
    date_id = newDateID;
    doctor_id = newDoctorID;
    available = newAvailble;
}
//get slot id
int slot::getID()
{
    return id;
}
//set slot id
void slot::setId(int newID)
{
    id = newID;
}
//get slot's date id
int slot::getDateID()
{
    return date_id;
}
//set slot's date id
void slot::setDateID(int newDateID)
{
    date_id = newDateID;
}
//get availability of slot
bool slot::getAvailible()
{
    return available;
}
//set availability of slot
void slot::setAvailible(bool newAvailable)
{
    available = newAvailable;
}
//print slot information
void slot::printSlot()
{
    if(id != -1)
    cout << "Id: " << id << "\nDateID: " << date_id << "\nDoctorID: " << doctor_id << "\nAvaiable? "<< available << "\n\n";
}
//print all slot information that are available
void showAvailableSlots(slot arr[], int numSlots)
{
    for(int i = 0; i < numSlots; i++)
    {
        if(arr[i].getAvailible())
            arr[i].printSlot();
    }
}
//print all slot information that is not available
void showUnavailableSlots(slot arr[], int numSlots)
{
    for(int i = 0; i < numSlots; i++)
    {
        if(!arr[i].getAvailible())
            arr[i].printSlot();
    }
}
//print all slots
void showAllSlots(slot arr[], int numSlots)
{
    for(int i = 0; i < numSlots; i++)
    {
            arr[i].printSlot();
    }
}
//show all slots that hold a given doctor id
void showDoctorSlots(slot arr[], int numSlots, int docID)
{
    for(int i = 0; i < numSlots; i++)
    {
        if(arr[i].getAvailible() && docID == arr[i].getDoctorID())
            arr[i].printSlot();
    }
}
//print all slots that exist between two times
void showSlotsBetweenTimes(slot arr[], int numSlots, date_time dateArr[], int numDate_time, date_time first, date_time second)
{
    date_time d;
    bool greaterFirst = false;
    bool lessSecond = false;
    //loop over all slots
    for(int i = 0; i < numSlots; i++)
    {
        greaterFirst = false;
        lessSecond = false;
        //check if the current slot is available
        if(arr[i].getAvailible())
        {  //find the corresponding date_time to the current slot
            for(int j = 0; j < numDate_time; j++)
                if(arr[i].getDateID() == dateArr[j].getID())
                    d = dateArr[j];
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
                arr[i].printSlot();
        }

    }
}
//get slot's doctor id
int slot::getDoctorID()
{
    return doctor_id;
}
//set slot's doctor id
void slot::setDoctorID(int newDoctorID)
{
    doctor_id = newDoctorID;
}
//read in slot information to data structure
void initializeSlots(slot slotArr[])
{
    int num = 0;
    int tempInt1 = 0;
    int tempInt2 = 0;
    int tempInt3 = 0;
    bool tempBool = true;
    string tempString1 = "";
    ifstream inFile;
    inFile.open("Slots.txt");
    inFile >> num;
    for(int i = 0; i < num; i++)
    {
        inFile >> tempInt1 >> tempInt2 >> tempInt3 >> tempString1;
        slotArr[i] = slot(tempInt1, tempInt2, tempInt3, true);
    }
    inFile.close();
}
//prints all slots between two dates
void slotsInTimeRange(slot slotArr[], date_time dateTimeArr[])
{
    char tempChar = ' ';
    int selection3, selection4, selection5, selection6, selection7 = 0;
    date_time date1;
    date_time date2;
    cout << "enter the first date in the format xx\\xx\\xxxx" << endl;
    cin >> selection3 >> tempChar >> selection4 >> tempChar >> selection5;
    cout << "enter the first time in the format xx:xx" << endl;
    cin >> selection6 >> tempChar >> selection7;
    cout << "is this in the morning? y/n" << endl;
    cin >> tempChar;
    if(tempChar == 'y')
        date1 = date_time(999, selection3, selection4, selection5, selection6, selection7, 'a');
    else
        date1 = date_time(999, selection3, selection4, selection5, selection6, selection7, 'p');

    cout << "enter the second date in the format xx\\xx\\xxxx" << endl;
    cin >> selection3 >> tempChar >> selection4 >> tempChar >> selection5;
    cout << "enter the second time in the format xx:xx" << endl;
    cin >> selection6 >> tempChar >> selection7;
    cout << "is this in the morning? y/n" << endl;
    cin >> tempChar;
    if(tempChar == 'y')
        date2 = date_time(888, selection3, selection4, selection5, selection6, selection7, 'a');
    else
        date2 = date_time(888, selection3, selection4, selection5, selection6, selection7, 'p');
    showSlotsBetweenTimes(slotArr, 50, dateTimeArr, 40, date1, date2);
}
//add a slot to the slot data structure
void addSlot(date_time dateTimeArr[], slot slotArr[])
{
    char tempChar = ' ';
    int selection2, selection3, selection4, selection5, selection6, selection7 = 0;
    date_time date1;
    date_time date2;
    cout << "enter the new date id" << endl;
    cin >> selection2;
    cout << "enter the date in the format xx\\xx\\xxxx" << endl;
    cin >> selection3 >> tempChar >> selection4 >> tempChar >> selection5;
    cout << "enter the time in the format xx:xx" << endl;
    cin >> selection6 >> tempChar >> selection7;
    cout << "is this in the morning? y/n" << endl;
    cin >> tempChar;
    if(tempChar == 'y')
        date1 = date_time(selection2, selection3, selection4, selection5, selection6, selection7, 'a');
    else
        date1 = date_time(selection2, selection3, selection4, selection5, selection6, selection7, 'p');

    for(int i = 0; i < 40; i++)
    {
        if(dateTimeArr[i].getID() == -1)
        {
            dateTimeArr[i] = date1;
            break;
        }
    }
    cout << "enter the slot id" << endl;
    cin >> selection3;
    cout << "enter the doctor id" << endl;
    cin >> selection5;
    for(int i = 0; i < 50; i++)
    {
        if(slotArr[i].getID() == -1)
        {
            slotArr[i] = slot(selection3, selection2, selection5, true);
            slotArr[i].printSlot();
            break;
        }
    }
}
//modify an existing slot
void modifySlot(slot slotArr[])
{
    char tempChar = ' ';
    int selection2, selection3, selection4, selection5, selection6, selection7 = 0;
    cout << "enter the slot id to update" << endl;
    cin >> selection3;
    for(int i = 0; i < 50; i++)
    {
        if(slotArr[i].getID() == selection3)
        {
            cout << "which info would you like to modify?" << endl;
            cout << "1. slot_id" << endl;
            cout << "2. date_id" << endl;
            cout << "3. doctor_id" << endl;
            cout << "4. availability" << endl;
            cin >> selection4;
            switch(selection4)
            {
                case 1:
                    cout << "Enter the new slot id" << endl;
                    cin >> selection5;
                    slotArr[i].setId(selection5);
                    break;
                case 2:
                    cout << "Enter the new date id" << endl;
                    cin >> selection5;
                    slotArr[i].setDateID(selection5);
                    break;
                case 3:
                    cout << "enter the new doctor id" << endl;
                    cin >> selection5;
                    slotArr[i].setDoctorID(selection5);
                    break;
                case 4:
                    cout << "is the appointment available? y/n" << endl;
                    cin >> tempChar;
                    if(tempChar == 'y')
                        slotArr[i].setAvailible(true);
                    if(tempChar == 'n')
                        slotArr[i].setAvailible(false);
                    break;
            }
            slotArr[i].printSlot();
            break;
        }
    }
}
//manage slots
void manageSlots(int selection2, date_time dateTimeArr[], slot slotArr[], doctor doctorArr[])
{
    string selectionString = " ";
    int selection3 = 0;
    switch(selection2)
    {
        case 1:
            for(int i = 0; i < 50; i++)
                showAvailableSlots(slotArr, 50);
            break;
        case 2:
            for(int i = 0; i < 50; i++)
                showUnavailableSlots(slotArr, 50);
            break;
        case 3:
            for(int i = 0; i < 50; i++)
                showAllSlots(slotArr, 50);
            break;
        case 4:
            cout << "enter a doctor's name" << endl;
            cin >> selectionString;
            for(int i = 0; i < 10; i++)
                if(doctorArr[i].getName() == selectionString)
                    showDoctorSlots(slotArr, 50, doctorArr[i].getID());
            break;
        case 5:
            slotsInTimeRange(slotArr, dateTimeArr);
            break;
        case 6:
            addSlot(dateTimeArr, slotArr);
            break;
        case 7:
            modifySlot(slotArr);
            break;
        case 8:
            cout << "enter the slot id to remove" << endl;
            cin >> selection3;
            for(int i = 0; i < 50; i++)
            {
                if(slotArr[i].getID() == selection3)
                {
                    slotArr[i] = slot();
                }
            }
            break;
        case 9:
            break;
    }
}
//add appointment for lab
void addLab(slot slotArr[], date_time dateTimeArr[], appointment appointmentArr[])
{
    int selection2, selection3, selection4, selection5, selection6, selection7, tempYear, tempMonth, tempDay, counter = 0;
    string selectionString = "";
    cout << "please enter the new appointment id" << endl;
    cin >> selection3;
    cout << "please enter the doctor id" << endl;
    cin >> selection4;
    cout << "please enter the patient id" << endl;
    cin >> selection5;
    do{
        cout << "please enter the slot id. (must be greater than 30)" << endl;
        cin >> selection6;
    }while(selection6 < 31);
    cout << "please enter the reason" << endl;
    cin >> selectionString;
    cout << "please enter the diagnosis id" << endl;
    cin >> selection7;
    cout << "please enter the prescribed medication" << endl;
    cin >> selectionString;
    for(int i = 0; i < 50; i++)
    {
        if(slotArr[i].getID() == selection6)
        {
            for(int j = 0; j < 40; j++)
            {
                if(dateTimeArr[j].getID() == slotArr[i].getDateID())
                {
                    tempYear = dateTimeArr[j].getYear();
                    tempMonth = dateTimeArr[j].getMonth();
                    tempDay = dateTimeArr[j].getDay();
                }
            }
            for(int k = 30; k < 40; k++)
            {
                if(!slotArr[k].getAvailible())
                {
                    for(int j = 0; j < 40; j++)
                    {
                        if(slotArr[k].getDateID() == dateTimeArr[j].getID() && tempYear == dateTimeArr[j].getYear() && tempMonth == dateTimeArr[j].getMonth() && tempDay == dateTimeArr[j].getDay() && slotArr[i].getDateID() != dateTimeArr[i].getID())
                            counter++;
                    }
                }
            }
            break;
        }
    }
    if(counter > 0)
        cout << "\nOnly one lab appointment per day can be scheduled!\n" << endl;
    else
    {
        for(int i = 0; i < 40; i++)
        {
            if(appointmentArr[i].getID() == -1)
            {
                slotArr[selection6-1].setAvailible(false);
                appointmentArr[i] = appointment(selection3, selection4, selection5, selection6, selectionString, selection7, selectionString);
                break;
            }
        }
    }
}
//manage labs
void manageLab(int selection2, slot slotArr[], date_time dateTimeArr[], appointment appointmentArr[])
{
    int selection3 = 0;
    string selectionString = "";
    switch(selection2)
    {
        case 1:
            addLab(slotArr, dateTimeArr, appointmentArr);
            break;
        case 2:
            cout << "please enter the appointment id to delete" << endl;
            cin >> selection3;
            for(int i = 0; i < 40; i++)
                if(appointmentArr[i].getID() == selection3)
                    appointmentArr[i] = appointment();
            break;
        case 3:
            for(int i = 0; i < 40; i++)
                if(appointmentArr[i].getSlotID() > 30)
                    appointmentArr[i].printAppointment();
            break;
    }
}










