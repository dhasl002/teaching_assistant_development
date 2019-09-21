#include "Staff.h"using namespace std;/** * Constructor for Staff member */Staff::Staff(){    zone = 0;    first = "";    last = "";}/** * Function sets the name of a Staff member * @param firstN first name * @param lastN last name */void Staff::setName(string firstN, string lastN){    first = firstN;    last = lastN;}/** * Function that gets Staff member name * @return name string */string Staff::getName(){    string name = first + " " + last;    return name;}/** * Function that sets duty to Staff members * @param newDuty new value of Staff member duty */void Staff::setDuty(string newDuty){    duty = newDuty;}

/** * Function that sets zone to Staff members * @param newZone new value of Staff member zone */void Staff::setZone(int newZone){    zone = newZone;}/** * Function that reads Staff members from Staff.txt * @param allStaff Staff members array */void readStaff(Staff allStaff[]){    string first,last;
    string duty;
    int zone, id;
    int i = 0;    ifstream inFile ("Staff.txt");    while(!inFile.eof()){        inFile >> first >> last;        allStaff[i].setName(first,last);
        inFile >> duty;
        allStaff[i].setDuty(duty);
        inFile >> id;
        allStaff[i].setId(id);
        inFile >> zone;
        allStaff[i].setZone(zone);
        i++;    }}

/** * Function that sets id to Staff members * @param newID new value of Staff member id */
void Staff::setId(int newId)
{
    ID = newId;
}

/** * Function that finds a staff in the array given their seat value * @param staffList staff list array * @param name the name of the passenger we are looking for * @return the true or false */
bool findStaff(Staff allStaff[], std::string name)
{
    for (int j = 0; j < 10; ++j){        if (allStaff[j].getName() == name)            return true;    }
    return false;
}