#include "record.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>

//get record id
int record::getID()
{
    return id;
}
//set record id
void record::setID(int newID)
{
    id = newID;
}
//get patient id of current record
int record::getPatientID()
{
    return patient_id;
}
//set patient id for current record
void record::setPatientID(int newPatientID)
{
    patient_id = newPatientID;
}
//get note
string record::getNote()
{
    return note;
}
//set note
void record::setNote(string newNote)
{
    note = newNote;
}
//print record information
void record::print()
{
    cout << "Id: " << id << "\nPatientID: " << patient_id << "\nNote: " << note << "\n\n";
}
//default record constructor
record::record()
{
    id = -1;
    patient_id = -1;
    note = "";
}
//record constructor with parameters
record::record(int newID, int newPatientID, string newNote)
{
    id = newID;
    patient_id = newPatientID;
    note = newNote;
}
void newRecord(record recordArr[])
{
    int selection3, selection4, selection5 = 0;
    string selectionString = "";
    for(int i = 0; i < 20; i++)
    {
        if(recordArr[i].getID() == -1)
        {
            cout << "please enter the id" << endl;
            cin >> selection3;
            cout << "please enter the patient_id" << endl;
            cin >> selection4;
            cout << "please enter the note" << endl;
            cin >> selectionString;
            recordArr[i] = record(selection3, selection4, selectionString);
            break;
        }
    }
}
//modify an existing record
void modifyRecord(record recordArr[])
{
    int selection3, selection4, selection5 = 0;
    string selectionString = "";
    cout << "what is the id of the record to modify?" << endl;
    cin >> selection3;
    for(int i = 0; i < 20; i++)
    {
        if(recordArr[i].getID() == selection3)
        {
            cout << "which criteria should be updated?" << endl;
            cout << "1. id" << endl;
            cout << "2. patient id" << endl;
            cout << "3. note" << endl;
            cin >> selection4;
            switch(selection4)
            {
                case 1:
                    cout << "please enter the new id" << endl;
                    cin >> selection5;
                    recordArr[i].setID(selection5);
                case 2:
                    cout << "please enter the new patient id" << endl;
                    cin >> selection5;
                    recordArr[i].setPatientID(selection5);
                case 3:
                    cout << "please enter the new note" << endl;
                    getline(cin, selectionString);
                    recordArr[i].setNote(selectionString);
            }
        }
    }
}
//manage records
void manageRecords(int selection2, record recordArr[])
{
    int selection3, selection4, selection5 = 0;
    string selectionString = "";
    switch(selection2)
    {
        case 1:
            newRecord(recordArr);
            break;
        case 2:
            modifyRecord(recordArr);
            break;
        case 3:
            for(int i = 0; i < 20; i++)
                if(recordArr[i].getID() != -1)
                    recordArr[i].print();
            break;
        case 4:
            cout << "please enter the id of the record to delete" << endl;
            cin >> selection4;
            for(int i = 0; i < 20; i++)
                if(recordArr[i].getID() == selection4)
                    recordArr[i] = record();
            break;
    }
}
