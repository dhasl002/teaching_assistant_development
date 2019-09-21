#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
#include "diagnosis.h"

using namespace std;

class record{
private:
    int id;
    int patient_id;
    string note;
public:

    record();
    record(int newID, int newPatientID, string newNote);
    int getID();
    void setID(int newID);
    int getPatientID();
    void setPatientID(int newPatientID);
    string getNote();
    void setNote(string newNote);
    void print();
};
void newRecord(record recordArr[]);
void modifyRecord(record recordArr[]);
void manageRecords(int selection2, record recordArr[]);
#endif // RECORD_H_INCLUDED
