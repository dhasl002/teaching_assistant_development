#ifndef TICKET_H
#define TICKET_H
#include "date.h"
#include <vector>
#include <iostream>
#include "bankAccount.h"

class bankAccount;

using namespace std;

class ticket
{
    public:
        ticket();
        int GetsectionNum() { return sectionNum; }
        void SetsectionNum(int val) { sectionNum = val; }
        int GetseatNum() { return seatNum; }
        void SetseatNum(int val) { seatNum = val; }
        double Getprice() { return price; }
        void Setprice(double val) { price = val; }
        date GetticketDate() { return ticketDate; }
        void SetticketDate(date val) { ticketDate = val; }
        bool Getsold() { return sold; }
        void Setsold(bool val) { sold = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        void printTickets();
    private:
        int sectionNum;
        int seatNum;
        double price;
        date ticketDate;
        bool sold;
        string name;
};
//main menu for tickets
void ticketMenu(int selection, vector<ticket> &ticketArr, bankAccount b);
//prints all tickets
void printTickets(vector<ticket> ticketArr);
//prints all available tickets
void printAvailableTickets(vector<ticket> ticketArr);
//prints all unavailable tickets
void printUnavailableTickets(vector<ticket> ticketArr);
//if a ticket has not been sold, make it sold, if the ticket has been sold, refund it, also adjust bank account
void sellRefundTicket(int section, int seat, vector<ticket> &ticketArr, bankAccount b);
//updates the info of the ticket
void updateTicket(int section, int seat, vector<ticket> &ticketArr);
//prints a ticket given an id by the user
void printTicketByID(string temp, vector<ticket> ticketArr);
//given a section, the function will refund all tickets within that section
void refundTickerBySection(int temp, vector<ticket> &ticketArr, bankAccount b);
#endif // TICKET_H
