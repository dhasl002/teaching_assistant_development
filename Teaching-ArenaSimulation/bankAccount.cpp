#include "bankAccount.h"

//default constructor for bank account
bankAccount::bankAccount()
{
    totalSales = 0;
    cashOnHand = 500;
    debt = 5000;
}

//prints all information about bank account to console
void printBankInfo(bankAccount b)
{
    cout << "TotalSales: "  << b.GettotalSales() << endl;
    cout << "Cash on hand: " << b.GetcashOnHand() << endl;
    cout << "Debt: " << b.Getdebt() << "\n" << endl;
}

//calculates the latest 3 months of ticket sales, averages the 3 months and calculates approximately how long it will take to pay off the debt
void debtFreeTime(bankAccount b, vector<ticket> ticketVector)
{
    int result;
    double concatenation = 0;
    int yearHigh = 0;
    int monthHigh = 0;
    for(int i = 0; i < ticketVector.size(); i++)
    {
        if(ticketVector[i].GetticketDate().Getyear() > yearHigh)
        {
            yearHigh = ticketVector[i].GetticketDate().Getyear();
            monthHigh = ticketVector[i].GetticketDate().Getmonth();
        }
        else if(ticketVector[i].GetticketDate().Getyear() == yearHigh && ticketVector[i].GetticketDate().Getmonth() > monthHigh)
        {
            monthHigh = ticketVector[i].GetticketDate().Getmonth();
        }
    }

    for(int j = 0; j< ticketVector.size(); j++)
    {
        if(ticketVector[j].GetticketDate().Getyear() == yearHigh && ticketVector[j].GetticketDate().Getmonth() < monthHigh+1 && ticketVector[j].GetticketDate().Getmonth() < monthHigh-4)
        {
            concatenation += ticketVector[j].Getprice();
        }
    }
    concatenation/=3;
    result= b.Getdebt()/concatenation;
    cout << "it will take approximately " << result << " months to pay off the debt\n" << endl;
}

//main menu for bank account
void bankMenu(int selection, bankAccount &b, vector<ticket> ticketVector)
{
    int temp = 0;
    double newVal = 0;
    int year = 0;
    int month = 0;
    double monthSales = 0;
    switch(selection)
    {
    case 1:
        printBankInfo(b);
        break;
    case 2:
        cout << "Which information would you like to adjust?" << endl;
        cout << "1. Total Sales" << endl;
        cout << "2. Cash on hand" << endl;
        cout << "3. Debt" << endl;
        cin >> temp;
        switch(temp)
        {
        case 1:
            cout << "enter the new total sales" << endl;
            cin >> newVal;
            b.SettotalSales(newVal);
            break;
        case 2:
            cout << "enter the new amount of Cash on hand" << endl;
            cin >> newVal;
            b.SetcashOnHand(newVal);
            break;
        case 3:
            cout << "enter the amount of debt" << endl;
            cin >> newVal;
            b.Setdebt(newVal);
            break;
        }
        break;
    case 3:
        cout << "enter the year" << endl;
        cin >> year;
        cout << "enter the month" << endl;
        cin >> month;
        for(int i = 0; i < ticketVector.size(); i++)
        {
            if(ticketVector[i].GetticketDate().Getyear() == year && ticketVector[i].GetticketDate().Getmonth() == month)
                monthSales += ticketVector[i].Getprice();
        }
        cout << "\nTicket Sales " << month << "/" << year << ": " << monthSales << "/n" << endl;
        break;
    case 4:
        cout << "how much debt would you like to pay off?" << endl;
        cin >> newVal;
        if(b.GetcashOnHand() >= newVal)
        {
            b.SetcashOnHand(b.GetcashOnHand()-newVal);
            b.Setdebt(b.Getdebt()-newVal);
        }
        else
            cout << "not enough cash on hand!" << endl;
        break;
    case 5:
        debtFreeTime(b, ticketVector);
        break;
    case 6:
        break;
    }
}
