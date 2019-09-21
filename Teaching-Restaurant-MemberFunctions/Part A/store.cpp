#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>

#include "store.h"

using namespace std;

Food::Food()
{
    name = "";
    numberLeft = 0;
    sellByDate.day = 0;
    sellByDate.month = 0;
    sellByDate.year = 0;
    cost = 0;
}

Condiment::Condiment()
{
    name = "";
    ouncesLeft = 0.0;
    sellByDate.day = 0;
    sellByDate.month = 0;
    sellByDate.year = 0;
    cost = 0.0;
}

PlasticItem::PlasticItem()
{
    name = "";
    numberLeft = 0;
    cost = 0.0;
}

/*
returns -1 when Food 1 is before Food 2
returns 0 when Food 1 is equal to Food 2
returns 1 when Food 1 is after than Food 2
*/
int Food::foodIsBefore(Food &food2){

    if(cost > food2.cost)
        return 1;
    else if(cost < food2.cost)
        return -1;

    return 0;
}

/*
returns -1 when Condiment 1 is before Condiment 2
returns 0 when Condiment 1 is equal to Condiment 2
returns 1 when Condiment 1 is after than Condiment 2
*/
int Condiment::condimentIsBefore(Condiment &condiment2){

    if(cost > condiment2.cost)
        return 1;
    else if(cost < condiment2.cost)
        return -1;

    return 0;
}

/*
returns -1 when PlasticItem 1 is before PlasticItem 2
returns 0 when PlasticItem 1 is equal to PlasticItem 2
returns 1 when PlasticItem 1 is after than PlasticItem 2
*/
int PlasticItem::plasticItemIsBefore(PlasticItem &plasticItem2){

    if(cost > plasticItem2.cost)
        return 1;
    else if(cost < plasticItem2.cost)
        return -1;

    return 0;
}

/**
This function is used for swapping the records of the Furniture array
**/
void Food :: swapFood(Food &food){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;

    tempString = this->name;
    this->name = food.name;
    food.name = tempString;

    tempInt = this->numberLeft;
    this->numberLeft = food.numberLeft;
    food.numberLeft = tempInt;

    tempInt = this->sellByDate.day;
    this->sellByDate.day = food.sellByDate.day;
    food.sellByDate.day = tempInt;

    tempInt = this->sellByDate.month;
    this->sellByDate.month = food.sellByDate.month;
    food.sellByDate.month = tempInt;

    tempInt = this->sellByDate.year;
    this->sellByDate.year = food.sellByDate.year;
    food.sellByDate.year = tempInt;

    tempDouble = this->cost;
    this->cost = food.cost;
    food.cost = tempDouble;
}

/**
This function is used for swapping the records of the Furniture array
**/
void Condiment :: swapCondiment(Condiment &condiment){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;

    tempString = this->name;
    this->name = condiment.name;
    condiment.name = tempString;

    tempDouble = this->ouncesLeft;
    this->ouncesLeft = condiment.ouncesLeft;
    condiment.ouncesLeft = tempDouble;

    tempInt = this->sellByDate.day;
    this->sellByDate.day = condiment.sellByDate.day;
    condiment.sellByDate.day = tempInt;

    tempInt = this->sellByDate.month;
    this->sellByDate.month = condiment.sellByDate.month;
    condiment.sellByDate.month = tempInt;

    tempInt = this->sellByDate.year;
    this->sellByDate.year = condiment.sellByDate.year;
    condiment.sellByDate.year = tempInt;

    tempDouble = this->cost;
    this->cost = condiment.cost;
    condiment.cost = tempDouble;
}

/**
This function is used for swapping the records of the Furniture array
**/
void PlasticItem :: swapPlasticItem(PlasticItem &plasticItem){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;

    tempString = this->name;
    this->name = plasticItem.name;
    plasticItem.name = tempString;

    tempInt = this->numberLeft;
    this->numberLeft = plasticItem.numberLeft;
    plasticItem.numberLeft = tempInt;

    tempDouble = this->cost;
    this->cost = plasticItem.cost;
    plasticItem.cost = tempDouble;
}
