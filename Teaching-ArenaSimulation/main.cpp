#include <iostream>
#include <vector>
#include "ticket.h"
#include "parking.h"
#include "staff.h"
#include "schedule.h"
#include "concessionStand.h"
#include "bankAccount.h"
using namespace std;

int main()
{
    parking p;
    int selection = 0;
    vector<ticket> ticketVector;
    vector<parking> parkingVector;
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 30; j++)
        {
            p.Setprice(10);
            p.SetsectionNum(i);
            p.SetspaceNum(j);
            parkingVector.push_back(p);
        }

    vector<staff> staffVector;
    vector<schedule> scheduleVector;
    concessionStand conStand;
    bankAccount b;
    bool exit = false;

    //main menu
    while(!exit)
    {
        cout << "Main menu:" << endl;
        cout << "1. Manage Tickets" << endl;
        cout << "2. Manage Schedule" << endl;
        cout << "3. Manage Parking" << endl;
        cout << "4. Manage Staff" << endl;
        cout << "5. Manage Bank Account" << endl;
        cout << "6. Manage Concession Stand" << endl;
        cout << "7. Exit" << endl;
        cin >> selection;

        switch(selection)
        {
        case 1:
            cout << "1. Show all ticket info" << endl;
            cout << "2. Show all available tickets" << endl;
            cout << "3. Show all unavailable tickers" << endl;
            cout << "4. Sell/Refund ticket" << endl;
            cout << "5. Update ticket info" << endl;
            cout << "6. Search for ticket by date" << endl;
            cout << "7. Main menu" << endl;
            cin >> selection;
            ticketMenu(selection, ticketVector, b);
            break;
        case 2:
            cout << "1. Create new event" << endl;
            cout << "2. Print all event information" << endl;
            cout << "3. Adjust event information" << endl;
            cout << "4. Cancel an event" << endl;
            cout << "5. Print events on a certain date" << endl;
            cout << "6. Main menu" << endl;
            cin >> selection;
            scheduleMenu(selection, scheduleVector, ticketVector, b);
            break;
        case 3:
            cout << "1. Show all parking info" << endl;
            cout << "2. Print parking info by Section" << endl;
            cout << "3. Print parking sections with a certain amount of empty spaces" << endl;
            cout << "4. Mark parking space empty/taken" << endl;
            cout << "5. Main menu" << endl;
            cin >> selection;
            parkingMenu(selection, parkingVector, b);
            break;
        case 4:
            cout << "1. Show all staff info" << endl;
            cout << "2. Print a staff member's info by id" << endl;
            cout << "3. Print all staff of certain job" << endl;
            cout << "4. Create new staff member" << endl;
            cout << "5. Fire existing staff member" << endl;
            cout << "6. Main menu" << endl;
            cin >> selection;
            staffMenu(selection, staffVector);
            break;
        case 5:
            cout << "1. print bank account information" << endl;
            cout << "2. Adjust bank account information" << endl;
            cout << "3. Calculate a given month's ticket sales" << endl;
            cout << "4. Pay off debt" << endl;
            cout << "5. Estimate time until debt is payed off" << endl;
            cout << "6. Main menu" << endl;
            cin >> selection;
            bankMenu(selection, b, ticketVector);
            break;
        case 6:
            cout << "1. Show concession stand info" << endl;
            cout << "2. Sell item" << endl;
            cout << "3. Print total lifetime sales amount" << endl;
            cout << "4. Order inventory" << endl;
            cout << "5. Main menu" << endl;
            cin >> selection;
            concessionMenu(selection, conStand, b);
            break;
        case 7:
            exit = true;
        }
    }
    return 0;
}
