#include "date_time.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

//default constructor
date_time::date_time()
{
    id = -1;
    day = -1;
    month = -1;
    year = -1;
    hours = -1;
    minutes = -1;
    am_pm = 'a';
}
//constructor with parameters
date_time::date_time(int newID, int newDay, int newMonth, int newYear, int newHours, int newMinutes, char newAMPM)
{
    id = newID;
    day = newDay;
    month = newMonth;
    year = newYear;
    hours = newHours;
    minutes = newMinutes;
    am_pm = newAMPM;
}
//get date id
int date_time::getID()
{
    return id;
}
//get date time
int date_time::getDay()
{
    return day;
}
//get date month
int date_time::getMonth()
{
    return month;
}
//get date year
int date_time::getYear()
{
    return year;
}
//get date hours
int date_time::getHours()
{
    return hours;
}
//get date minutes
int date_time::getMinutes()
{
    return minutes;
}
//get date am or pm
char date_time::getAM_PM()
{
    return am_pm;
}
//set date id
void date_time::setID(int newID)
{
    id = newID;
}
//set date day
void date_time::setDay(int newDay)
{
    day = newDay;
}
//set date month
void date_time::setMonth(int newMonth)
{
    month = newMonth;
}
//set date year
void date_time::setYear(int newYear)
{
    year = newYear;
}
//set date hours
void date_time::setHours(int newHours)
{
    hours = newHours;
}
//set date minutes
void date_time::setMinutes(int newMinutes)
{
    minutes = newMinutes;
}
//set date am or pm
void date_time::setAM_PM(char newAM_PM)
{
    am_pm - newAM_PM;
}
//read in date_time information to data structure
void initializeDateTime(date_time dateTimeArr[])
{
    int num = 0;
    int tempInt1 = 0;
    int tempInt2 = 0;
    int tempInt3 = 0;
    int tempInt4 = 0;
    int tempInt5 = 0;
    int tempInt6 = 0;
    char tempChar = ' ';
    ifstream inFile;
    inFile.open("Date_Time.txt");
    inFile >> num;
    for(int i = 0; i < num; i++)
    {
        inFile >> tempInt1 >> tempInt2 >> tempInt3 >> tempInt4 >> tempInt5 >> tempInt6 >> tempChar;
        dateTimeArr[i] = date_time(tempInt1, tempInt2, tempInt3, tempInt4, tempInt5, tempInt6, tempChar);
    }
    inFile.close();
}






















