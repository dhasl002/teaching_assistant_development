#ifndef PASSENGERS_H_INCLUDED
#define PASSENGERS_H_INCLUDED

#include <stdlib.h>		//for rand#include <iostream>#include <stdio.h>int randNum(int max);class Passenger{    std::string first,last,seat;    char diet;    int zone;    bool specialNeeds, isMinor;public:    Passenger();    bool getSpecialNeeds();    int getZone();    void setZone(int newZone);    std::string getSeat();    void setSeat(std::string newSeat);
    void setName(std::string newFirst, std::string newLast);
    std::string getName();};void readPassengers(Passenger passList[]);bool findPassenger(Passenger passList[], std::string name);

#endif // PASSENGERS_H_INCLUDED
