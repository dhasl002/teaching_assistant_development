#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

class account
{
	unsigned long long int acno;
	char name[50];
	int balance;
	int creditLimit;
public:
	void create_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	int rettype() const;	//function to return type of account
};         //class ends here


#endif // ACCOUNT_H_INCLUDED
