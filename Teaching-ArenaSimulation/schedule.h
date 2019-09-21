#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "date.h"
#include "ticket.h"
#include "bankAccount.h"
#include <string>
#include <vector>

using namespace std;

class schedule
{
    public:
        schedule();
        date GetscheduleDate() { return scheduleDate; }
        void SetscheduleDate(date val) { scheduleDate = val; }
        string GeteventName() { return eventName; }
        void SeteventName(string val) { eventName = val; }
    protected:
    private:
        date scheduleDate;
        string eventName;
};
//main menu for schedules
void scheduleMenu(int selection, vector<schedule> &scheduleVector, vector<ticket> &ticketVector, bankAccount b);
//prints all current events past and present
void printAllEvents(vector<schedule> scheduleVector);
//adjust any event's information
void adjustEvent(string tmpStr, vector<schedule> &scheduleVector, vector<ticket> &ticketVector);
//cancels an event, refunds tickets, and adjusts bank account
void cancelEvent(string tmpStr, vector<schedule> &scheduleVector, vector<ticket> &ticketVector, bankAccount b);

#endif // SCHEDULE_H
