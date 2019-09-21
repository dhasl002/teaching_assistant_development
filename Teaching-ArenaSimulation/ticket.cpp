#include "ticket.h"
#include <vector>
#include <iostream>
#include "bankAccount.h"

using namespace std;

//default constructor for tickets
ticket::ticket()
{
    sectionNum = 0;
    seatNum = 0;
    price = 0;
    sold = false;
    name = "";
}

//prints all tickets
void printTickets(vector<ticket> ticketArr)
{
    for(int i = 0; i < ticketArr.size(); i++)
    {
        cout << "Section Number: " << ticketArr[i].GetsectionNum() << endl;
        cout << "Seat Number: " << ticketArr[i].GetseatNum() << endl;
        cout << "Price: " << ticketArr[i].Getprice() << endl;
        cout << "Available: " << ticketArr[i].Getsold() << endl;
        cout << "Name: " << ticketArr[i].Getname() << "\n" <<endl;
    }
}

//prints all available tickets
void printAvailableTickets(vector<ticket> ticketArr)
{
    for(int i = 0; i < ticketArr.size(); i++)
    {
        if(!ticketArr[i].Getsold())
        {
            cout << "Section Number: " << ticketArr[i].GetsectionNum() << endl;
            cout << "Seat Number: " << ticketArr[i].GetseatNum() << endl;
            cout << "Price: " << ticketArr[i].Getprice() << endl;
            cout << "Available: " << ticketArr[i].Getsold() << endl;
            cout << "name: " << ticketArr[i].Getname() << "\n" <<endl;
        }
    }
}

//prints all unavailable tickets
void printUnavailableTickets(vector<ticket> ticketArr)
{
    for(int i = 0; i < ticketArr.size(); i++)
    {
        if(ticketArr[i].Getsold())
        {
            cout << "Section Number: " << ticketArr[i].GetsectionNum() << endl;
            cout << "Seat Number: " << ticketArr[i].GetseatNum() << endl;
            cout << "Price: " << ticketArr[i].Getprice() << endl;
            cout << "Available: " << ticketArr[i].Getsold() << endl;
            cout << "name: " << ticketArr[i].Getname() << "\n" <<endl;
        }
    }
}

//if a ticket has not been sold, make it sold, if the ticket has been sold, refund it, also adjust bank account
void sellRefundTicket(int section, int seat, vector<ticket> &ticketArr, bankAccount b)
{
    for(int i = 0; i < ticketArr.size(); i++)
    {
        if(ticketArr[i].GetsectionNum() == section && ticketArr[i].GetseatNum() == seat)
        {
            if(ticketArr[i].Getsold())
                b.SetcashOnHand(b.GetcashOnHand()-ticketArr[i].Getprice());
            else
                b.SetcashOnHand(b.GetcashOnHand()+ticketArr[i].Getprice());
            ticketArr[i].Setsold(!ticketArr[i].Getsold());
        }

    }
}

//updates the info of the ticket
void updateTicket(int section, int seat, vector<ticket> &ticketArr)
{
    int choice = 0;
    double temp = 0;
    string tempstr = "";
    cout << "What aspect of the ticket would you like to update?" << endl;
    cout << "1. Section Number" << endl;
    cout << "2. Seat Number" << endl;
    cout << "3. Price" << endl;
    cout << "4. name" << endl;
    cin >> choice;

    switch(choice)
    {
    case 1:
        cout << "Enter the new section number" << endl;
        cin >> temp;
        for(int i = 0; i < ticketArr.size(); i++)
        {
            if(ticketArr[i].GetsectionNum() == section && ticketArr[i].GetseatNum() == seat)
                    ticketArr[i].SetsectionNum((int)temp);
        }
        break;
    case 2:
        cout << "Enter the new seat number" << endl;
        cin >> temp;
        for(int i = 0; i < ticketArr.size(); i++)
        {
            if(ticketArr[i].GetsectionNum() == section && ticketArr[i].GetseatNum() == seat)
                    ticketArr[i].SetseatNum((int)temp);
        }
        break;
    case 3:
        cout << "Enter the new price" << endl;
        cin >> temp;
        for(int i = 0; i < ticketArr.size(); i++)
        {
            if(ticketArr[i].GetsectionNum() == section && ticketArr[i].GetseatNum() == seat)
                    ticketArr[i].Setprice(temp);
        }
        break;
    case 4:
        cout << "Enter the new name" << endl;
        cin >> tempstr;
        for(int i = 0; i < ticketArr.size(); i++)
        {
            if(ticketArr[i].GetsectionNum() == section && ticketArr[i].GetseatNum() == seat)
                    ticketArr[i].Setname(tempstr);
        }
        break;
    }
}

//prints a ticket given an id by the user
void printTicketByID(string temp, vector<ticket> ticketArr)
{
    for(int i = 0; i < ticketArr.size(); i++)
    {
        if(ticketArr[i].Getname() == temp)
        {
            cout << "Section Number: " << ticketArr[i].GetsectionNum() << endl;
            cout << "Seat Number: " << ticketArr[i].GetseatNum() << endl;
            cout << "Price: " << ticketArr[i].Getprice() << endl;
            cout << "Available: " << ticketArr[i].Getsold() << endl;
            cout << "name: " << ticketArr[i].Getname() << "\n" <<endl;
        }
    }
}

//given a section, the function will refund all tickets within that section
void refundTickerBySection(int temp, vector<ticket> &ticketArr, bankAccount b)
{
    for(int i = 0; i < ticketArr.size(); i++)
    {
        if(ticketArr[i].GetsectionNum() == temp)
        {
            b.SetcashOnHand(b.GetcashOnHand()-ticketArr[i].Getprice());
            ticketArr[i].Setsold(false);
        }
    }
}

//main menu for tickets
void ticketMenu(int selection, vector<ticket> &ticketArr, bankAccount b)
{
    date tmpDate;
    int temp = 0;
    int temp2 = 0;
    string tmpstr = "";
    char choice = ' ';

    switch(selection)
    {
    case 1:
        printTickets(ticketArr);
        break;
    case 2:
        printAvailableTickets(ticketArr);
        break;
    case 3:
        printUnavailableTickets(ticketArr);
        break;
    case 4:
        cout << "Would you like to refund a ticket?(y/n)" << endl;
        cin >> choice;
        if(choice == 'y')
        {
            cout << "Would you like to refund a ticket by section number? (y/n)" << endl;
            cin >> choice;
            if(choice == 'y')
            {
                cout << "Enter the section number to refund" << endl;
                cin >> temp;
                refundTickerBySection(temp, ticketArr, b);
            }
            else
            {
                cout << "Enter the section number of the ticket you want to refund" << endl;
                cin >> temp;
                cout << "Enter the seat number of the ticket you want to refund" << endl;
                cin >> temp2;
                sellRefundTicket(temp, temp2, ticketArr, b);
            }
        }
        else
        {
            cout << "Enter the section number of the ticket you want to buy" << endl;
            cin >> temp;
            cout << "Enter the seat number of the ticket you want to buy" << endl;
            cin >> temp2;
            sellRefundTicket(temp, temp2, ticketArr, b);
        }
        break;
    case 5:
        cout << "Enter the section number of the ticket you want to buy" << endl;
            cin >> temp;
            cout << "Enter the seat number of the ticket you want to buy" << endl;
            cin >> temp2;
        updateTicket(temp, temp2, ticketArr);
        break;
    case 6:
        cout << "Enter the year of the event" << endl;
        cin >> temp;
        tmpDate.Setyear(temp);
        cout << "Enter the month of the event" << endl;
        cin >> temp;
        tmpDate.Setmonth(temp);
        cout << "Enter the day of the event" << endl;
        cin >> temp;
        tmpDate.Setday(temp);
        cout << "Enter the hour of the event" << endl;
        cin >> temp;
        tmpDate.Sethour(temp);
        cout << "Enter the minutes of the event" << endl;
        cin >> temp;
        tmpDate.Setminutes(temp);
        for(int i = 0; i < ticketArr.size(); i++)
            if(ticketArr[i].GetticketDate().Getyear() == tmpDate.Getyear() && ticketArr[i].GetticketDate().Getmonth() == tmpDate.Getmonth() && ticketArr[i].GetticketDate().Getday() == tmpDate.Getday() && ticketArr[i].GetticketDate().Gethour() == tmpDate.Gethour() && ticketArr[i].GetticketDate().Getminutes() == tmpDate.Getminutes())
            {
                cout << "Section Number: " << ticketArr[i].GetsectionNum() << endl;
                cout << "Seat Number: " << ticketArr[i].GetseatNum() << endl;
                cout << "Price: " << ticketArr[i].Getprice() << endl;
                cout << "Available: " << ticketArr[i].Getsold() << endl;
                cout << "name: " << ticketArr[i].Getname() << "\n" <<endl;
            }
        break;
    case 7:
        break;
    }
}
