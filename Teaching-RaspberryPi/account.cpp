#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <stdlib.h>
#include "account.h"

void account::create_account()
{
	cout<<"\nEnter The Card Number (no spaces):";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter the credit limit: ";
	cin>>creditLimit;
	do
    {
        cout<<"\nEnter The Initial balance(use negative numbers if there is debt) : ";
        cin>>balance;
        if(balance*-1 > creditLimit)
            cout << "\nInitial balance cannot be greater than credit limit : ";
    }while(balance*-1 > creditLimit);
	cout<<"\n\n\nAccount Created..";
}

void account::show_account() const
{
	cout<<"\nCard Number:: "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nCredit Limit : "<<creditLimit;
	cout<<"\nBalance amount : "<<balance;
}


void account::modify()
{
	cout<<"\nCard Number:"<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Credit Limit : ";
	cin>>creditLimit;
	cout<<"\nModify Balance amount : ";
	cin>>balance;
}


void account::dep(int x)
{
	balance+=x;
}

void account::draw(int x)
{
	balance-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<creditLimit<<setw(6)<<balance<<endl;
}


int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return balance;
}

int account::rettype() const
{
	return creditLimit;
}
