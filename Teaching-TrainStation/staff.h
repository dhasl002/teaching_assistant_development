#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED

#include <stdio.h>#include <fstream>#include "passengers.h"class Staff{private:    int ID, zone;    std::string first, last, duty;public:    Staff();    std::string getName();    void setName(std::string firstN, std::string lastN);    void setDuty(std::string newDuty);
    void setZone(int newZone);
    void setId(int newId);};void readStaff(Staff allStaff[]);
bool findStaff(Staff allStaff[], std::string name);

#endif // STAFF_H_INCLUDED
