#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "ticket.h"
#include <vector>
class ticket;

using namespace std;

class bankAccount
{
    public:
        bankAccount();
        double GettotalSales() { return totalSales; }
        void SettotalSales(double val) { totalSales = val; }
        double GetcashOnHand() { return cashOnHand; }
        void SetcashOnHand(double val) { cashOnHand = val; }
        double Getdebt() { return debt; }
        void Setdebt(double val) { debt = val; }
    protected:
    private:
        double totalSales;
        double cashOnHand;
        double debt;
};
//prints all information about bank account to console
void printBankInfo(bankAccount b);
//main menu for bank account
void bankMenu(int selection, bankAccount &b, vector<ticket> ticketVector);
//calculates the latest 3 months of ticket sales, averages the 3 months and calculates approximately how long it will take to pay off the debt
void debtFreeTime(bankAccount b, vector<ticket> ticketVector);
#endif // BANKACCOUNT_H
