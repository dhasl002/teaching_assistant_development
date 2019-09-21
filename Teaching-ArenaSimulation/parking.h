#ifndef PARKING_H
#define PARKING_H
#include <vector>
#include "bankAccount.h"
using namespace std;

class parking
{
    public:
        parking();
        int GetsectionNum() { return sectionNum; }
        void SetsectionNum(int val) { sectionNum = val; }
        int GetspaceNum() { return spaceNum; }
        void SetspaceNum(int val) { spaceNum = val; }
        double Getprice() { return price; }
        void Setprice(double val) { price = val; }
        bool Getavailable() { return available; }
        void Setavailable(bool val) { available = val; }
    protected:
    private:
        int sectionNum;
        int spaceNum;
        double price;
        bool available;
};
//if the parking spot is available, make it available and vise versa. Also adjust bank account if a spot is sold
void changeAvailableParkingSpot(int section, int space, vector<parking> & parkingArr, bankAccount b);
//prints information about every parking spot
void printParkingInfo(vector<parking> parkingArr);
//main menu for parking
void parkingMenu(int selection, vector<parking> &parkingArr, bankAccount b);
//given a parking section, the program will print that section's information
void printParkingBySection(int section, vector<parking> parkingArr);
//given a minimum amount of available parking spaces, the function finds sections that have that amount of available spaces
void printSectionGivenMinSpaces(int section, vector<parking> parkingArr);
#endif // PARKING_H
