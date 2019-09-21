#include <iostream>
#include "passengers.h"
#include "staff.h"

using namespace std;

int main()
{
    Passenger passList[50];
    Staff staffList[10];
    string tmp;
    string noTravelList = "";
    string answer = "";

    readPassengers(passList);
    readStaff(staffList);

    do{
        cout << "Enter a person's name that should not be traveling" << endl;
        cin >> noTravelList >> tmp;
        noTravelList = noTravelList + " " + tmp;

        if(findPassenger(passList, noTravelList) || findStaff(staffList, noTravelList))
            cout << "Security has been called!" << endl;
        else
            cout << "This person is not riding this train" << endl;

        cout << "\nWould you like to search for another person? (y/n)" << endl;
        cin >> answer;
    }while(answer == "y" || answer == "Y");

    return 0;
}
