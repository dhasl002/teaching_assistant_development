#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <string>
using namespace std;

struct Date{
	int day;
	int month;
	int year;
};

struct Food{
    string name;
    int numberLeft;
    Date sellByDate;
    double cost;

    Food();
    /*
    returns -1 when Food 1 is before Food 2
    returns 0 when Food 1 is equal to Food 2
    returns 1 when Food 1 is after than Food 2
    */
    int foodIsBefore(Food& food2);
    void swapFood(Food& food2);
};

struct Condiment{
    string name;
    double ouncesLeft;
    Date sellByDate;
    double cost;

    Condiment();
    /*
    returns -1 when Condiment 1 is before Condiment 2
    returns 0 when Condiment 1 is equal to Condiment 2
    returns 1 when Condiment 1 is after than Condiment 2
    */
    int condimentIsBefore(Condiment& condiment2);
    void swapCondiment(Condiment& condiment2);
};

struct PlasticItem{
    string name;
    int numberLeft;
    double cost;

    PlasticItem();
    /*
    returns -1 when PlasticItem 1 is before PlasticItem 2
    returns 0 when PlasticItem 1 is equal to PlasticItem 2
    returns 1 when PlasticItem 1 is after than PlasticItem 2
    */
    int plasticItemIsBefore(PlasticItem& plasticItem2);
    void swapPlasticItem(PlasticItem& plasticItem2);
};

#endif // STORE_H_INCLUDED
