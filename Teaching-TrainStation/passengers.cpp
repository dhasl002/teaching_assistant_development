#include <fstream>
#include "passengers.h"using namespace std;/** * Function that generates a random integer * @param max roof for random integer that will be generated * @return a random integer between 0 and max */int randNum(int max){    int result = rand()%max;    return result;}/** * Constructor for passengers */Passenger::Passenger(){    zone = 100;    int perc = randNum(100);    if (perc > 50)        specialNeeds = true;
    else
        specialNeeds = false;
    perc = randNum(100);    if (perc < 50)        isMinor = true;
    else
        isMinor = false;    int j = randNum(100);    if (j < 40)        diet = 'A'; //A for no dietary restrictions    else if (j < 70)        diet = 'G'; //G for gluetn free    else        diet = 'V'; //V for vegetarian}

/** * Function that reads passengers from passenger.txt * @param passList */void readPassengers(Passenger passList[]){    string first,last,seat;
    int zone, id;
    int i = 0;    ifstream inFile ("Passengers.txt");    while(!inFile.eof()){        inFile >> first >> last;        passList[i].setName(first,last);
        inFile >> seat;
        passList[i].setSeat(seat);
        inFile >> zone;
        passList[i].setZone(zone);
        i++;    }}
/** * Function that gets special needs info * @return true if a passenger has special needs, false otherwise */bool Passenger::getSpecialNeeds(){    return specialNeeds;}/** * Function that gets zone info * @return the zone number of the passenger */int Passenger::getZone(){    return zone;}/** * Function that assigns zones to passengers * @param newZone the zone that will be assigned to the passenger */void Passenger::setZone(int newZone){    zone = newZone;}
/** * Function that gets seat info * @return the seat of a passenger */string Passenger::getSeat(){    return seat;}/** * Function that assigns seats to passengers * @param newSeat the seat that will be assigned to the passenger */void Passenger::setSeat(string newSeat){    seat = newSeat;}

/** * Function that gets passenger name * @return the full name of the passenger */
string Passenger::getName()
{
    return (first + " " + last);
}

/** * Function that assigns names to passengers * @param newName the name that will be assigned to the passenger */
void Passenger::setName(string newFirst, string newLast)
{
    first = newFirst;
    last = newLast;
}/** * Function that finds a passenger in the array given their seat value * @param passList passenger list array * @param name the name of the passenger we are looking for * @return the true or false */bool findPassenger(Passenger passList[], string name){    for (int j = 0; j < 50; ++j){        if (passList[j].getName() == name)            return true;    }
    return false;}