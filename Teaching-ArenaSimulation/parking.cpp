#include "parking.h"
#include <iostream>

using namespace std;

//default constructor for parking
parking::parking()
{
    sectionNum = 0;
    spaceNum = 0;
    price = 0;
    available = true;
}

//prints information about every parking spot
void printParkingInfo(vector<parking> parkingArr)
{
    for(int i = 0; i < parkingArr.size(); i++)
    {
        cout << "Section: " << parkingArr[i].GetsectionNum() << endl;
        cout << "Space: " << parkingArr[i].GetspaceNum() << endl;
        cout << "Price: " << parkingArr[i].Getprice() << endl;
        cout << "Available: " << parkingArr[i].Getavailable() << "\n" << endl;
    }
}

//given a parking section, the program will print that section's information
void printParkingBySection(int section, vector<parking> parkingArr)
{
    for(int i = 0; i < parkingArr.size(); i++)
    {
        if(section == parkingArr[i].GetsectionNum())
        {
            cout << "Section: " << parkingArr[i].GetsectionNum() << endl;
            cout << "Space: " << parkingArr[i].GetspaceNum() << endl;
            cout << "Price: " << parkingArr[i].Getprice() << endl;
            cout << "Available: " << parkingArr[i].Getavailable() << "\n" << endl;
        }
    }
}

//given a minimum amount of available parking spaces, the function finds sections that have that amount of available spaces
void printSectionGivenMinSpaces(int section, vector<parking> parkingArr)
{
    //get all unique sections
    bool uniqueNum = true;
    vector<int> sectionNum;
    int it = 0;
    for(int i = 0; i < parkingArr.size(); i++)
    {
        uniqueNum = true;
        for(int j = 0; j < sectionNum.size(); j++)
        {
            if(parkingArr[i].GetsectionNum() == sectionNum[j])
            {
                uniqueNum = false;
                break;
            }
        }
        if(uniqueNum)
            sectionNum.push_back(parkingArr[i].GetsectionNum());
    }
    for(int i = 0; i < sectionNum.size(); i++)
    {
        it = 0;
        for(int j = 0; j < parkingArr.size(); j++)
        {
            if(parkingArr[j].GetsectionNum() == sectionNum[i] && parkingArr[j].Getavailable())
                it++;
            if(it >= section)
            {
                cout << sectionNum[i] << endl;
                break;
            }
        }
    }
}

//if the parking spot is available, make it available and vise versa. Also adjust bank account if a spot is sold
void changeAvailableParkingSpot(int section, int space, vector<parking> &parkingArr, bankAccount b)
{
    for(int i = 0; i < parkingArr.size(); i++)
    {
        if(section == parkingArr[i].GetsectionNum() && space == parkingArr[i].GetspaceNum())
        {
            if(parkingArr[i].Getavailable())
                b.SetcashOnHand(b.GetcashOnHand()+parkingArr[i].Getprice());

            parkingArr[i].Setavailable(!parkingArr[i].Getavailable());
            break;
        }
    }
}

//main menu for parking
void parkingMenu(int selection, vector<parking> &parkingArr, bankAccount b)
{
    int section = 0;
    int space = 0;
    switch(selection)
    {
    case 1:
        printParkingInfo(parkingArr);
        break;
    case 2:
        cout << "Enter the parking section to print" << endl;
        cin >> section;
        printParkingBySection(section, parkingArr);
        break;
    case 3:
        cout << "Enter the number of spaces needed in the section to Print" << endl;
        cin >> section;
        printSectionGivenMinSpaces(section, parkingArr);
        break;
    case 4:
        cout << "Enter the section that the space is in" << endl;
        cin >> section;
        cout << "Enter the space" << endl;
        cin >> space;
        changeAvailableParkingSpot(section, space, parkingArr, b);
        break;
    case 5:
        break;
    }
}
