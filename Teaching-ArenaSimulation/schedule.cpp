#include "schedule.h"
#include <vector>
#include <iostream>

//default constructor for schedule
schedule::schedule()
{
    eventName = "";
}

//prints all current events past and present
void printAllEvents(vector<schedule> scheduleVector)
{
    for(int i = 0; i < scheduleVector.size(); i++)
    {
        cout << "Event Name: " << scheduleVector[i].GeteventName() << endl;
        cout << "Date: " << scheduleVector[i].GetscheduleDate().Getmonth() << "/" << scheduleVector[i].GetscheduleDate().Getday() << "/" << scheduleVector[i].GetscheduleDate().Getyear() << "\t" << scheduleVector[i].GetscheduleDate().Gethour() << ":" << scheduleVector[i].GetscheduleDate().Getminutes() << "\n" << endl;
    }
}

//cancels an event, refunds tickets, and adjusts bank account
void cancelEvent(string tmpStr, vector<schedule> &scheduleVector, vector<ticket> &ticketVector, bankAccount b)
{
    for(int i = 0; i < scheduleVector.size(); i++)
    {
        if(scheduleVector[i].GeteventName() == tmpStr)
        {
            scheduleVector.erase(scheduleVector.begin()+i);
        }

    }

    for(int i = 0; i < ticketVector.size(); i++)
    {
        if(ticketVector[i].Getname() == tmpStr)
        {
            b.SetcashOnHand(b.GetcashOnHand()-ticketVector[i].Getprice());
            ticketVector.erase(ticketVector.begin()+i);
        }

    }
}

//adjust any event's information
void adjustEvent(string tmpStr, vector<schedule> &scheduleVector, vector<ticket> &ticketVector)
{
    int inputInt = 0;
    int temp = 0;
    string inputStr = "";
    date newEventDate;
    for(int i = 0; i < scheduleVector.size(); i++)
    {
        if(tmpStr == scheduleVector[i].GeteventName())
        {
            cout << "Enter the value you would like to change" << endl;
            cout << "1. Event Name" << endl;
            cout << "2. Date" << endl;
            cin >> inputInt;
            switch(inputInt)
            {
            case 1:
                cout << "What is the new Event name?" << endl;
                cin >> inputStr;
                scheduleVector[i].SeteventName(inputStr);
                break;
            case 2:
                cout << "Enter the year of the event" << endl;
                cin >> temp;
                newEventDate.Setyear(temp);
                cout << "Enter the month of the event" << endl;
                cin >> temp;
                newEventDate.Setmonth(temp);
                cout << "Enter the day of the event" << endl;
                cin >> temp;
                newEventDate.Setday(temp);
                cout << "Enter the hour of the event" << endl;
                cin >> temp;
                newEventDate.Sethour(temp);
                cout << "Enter the minutes of the event" << endl;
                cin >> temp;
                newEventDate.Setminutes(temp);
                scheduleVector[i].SetscheduleDate(newEventDate);
                break;
            }
            for(int j = 0; j < ticketVector.size(); j++)
            {
                if(scheduleVector[i].GeteventName() == ticketVector[j].Getname())
                {
                    ticketVector[j].Setname(scheduleVector[i].GeteventName());
                    ticketVector[j].SetticketDate(scheduleVector[i].GetscheduleDate());
                }

            }
        }
    }
}

//main menu for schedules
void scheduleMenu(int selection, vector<schedule> &scheduleVector, vector<ticket> &ticketVector, bankAccount b)
{
    string newEventName = "";
    string tmpStr = "";
    int temp = -1;
    schedule newEvent;
    date newEventDate;
    ticket t;
    switch(selection)
    {
    case 1:
        cout << "Enter the name of the new event" << endl;
        cin >> newEventName;
        newEvent.SeteventName(newEventName);
        cout << "Enter the year of the event" << endl;
        cin >> temp;
        newEventDate.Setyear(temp);
        cout << "Enter the month of the event" << endl;
        cin >> temp;
        newEventDate.Setmonth(temp);
        cout << "Enter the day of the event" << endl;
        cin >> temp;
        newEventDate.Setday(temp);
        cout << "Enter the hour of the event" << endl;
        cin >> temp;
        newEventDate.Sethour(temp);
        cout << "Enter the minutes of the event" << endl;
        cin >> temp;
        newEventDate.Setminutes(temp);
        newEvent.SetscheduleDate(newEventDate);
        scheduleVector.push_back(newEvent);
        for(int i = 0; i < 50; i++)
            for(int j = 0; j < 10; j++)
            {
                t.Setname(newEventName);
                t.Setprice(45);
                t.SetsectionNum(i);
                t.SetseatNum(j);
                t.SetticketDate(newEventDate);
                ticketVector.push_back(t);
            }
        break;
    case 2:
        printAllEvents(scheduleVector);
        break;
    case 3:
        cout << "What is the name of the event to adjust" << endl;
        cin >> tmpStr;
        adjustEvent(tmpStr, scheduleVector, ticketVector);
        break;
    case 4:
        cout << "What is the name of the event to cancel" << endl;
        cin >> tmpStr;
        cancelEvent(tmpStr, scheduleVector, ticketVector, b);
        break;
    case 5:
        cout << "Enter the year of the event" << endl;
        cin >> temp;
        newEventDate.Setyear(temp);
        cout << "Enter the month of the event" << endl;
        cin >> temp;
        newEventDate.Setmonth(temp);
        cout << "Enter the day of the event" << endl;
        cin >> temp;
        newEventDate.Setday(temp);
        cout << "Enter the hour of the event" << endl;
        cin >> temp;
        newEventDate.Sethour(temp);
        cout << "Enter the minutes of the event" << endl;
        cin >> temp;
        newEventDate.Setminutes(temp);
        for(int i = 0; i < scheduleVector.size(); i++)
        {
            if(scheduleVector[i].GetscheduleDate().Getyear() == newEventDate.Getyear() &&
               scheduleVector[i].GetscheduleDate().Getmonth() == newEventDate.Getmonth() &&
               scheduleVector[i].GetscheduleDate().Getday() == newEventDate.Getday() &&
               scheduleVector[i].GetscheduleDate().Gethour() == newEventDate.Gethour() &&
               scheduleVector[i].GetscheduleDate().Getminutes() == newEventDate.Getminutes())
            {
                cout << "Event Name: " << scheduleVector[i].GeteventName() << endl;
                cout << "Date: " << scheduleVector[i].GetscheduleDate().Getmonth() << "/" << scheduleVector[i].GetscheduleDate().Getday() << "/" << scheduleVector[i].GetscheduleDate().Getyear() << "\t" << scheduleVector[i].GetscheduleDate().Gethour() << ":" << scheduleVector[i].GetscheduleDate().Getminutes() << "\n" << endl;
            }
        }
        break;
    case 6:
        break;
    }
}
