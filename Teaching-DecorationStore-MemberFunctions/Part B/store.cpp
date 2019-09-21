#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>

#include "Store.h"

using namespace std;

Furniture::Furniture()
{
    name = "";
    color = "";
    inventory = 0;
    dateCreated.day = 0;
    dateCreated.month = 0;
    dateCreated.year = 0;
    cost = 0;
}

Fabric::Fabric()
{
    name = "";
    color = "";
    inventory = 0;
    cost = 0;
}

Art::Art()
{
    string name = "";
    double cost = 0;
    int inventory = 0;
    dateCreated.day = 0;
    dateCreated.month = 0;
    dateCreated.year = 0;
    artSize.height = 0;
    artSize.width = 0;
    artSize.depth = 0;
}

Book::Book()
{
    name = "";
    hardCover = 0;
    numPages = 0;
    cost = 0;
    inventory = 0;
    datePublished.day = 0;
    datePublished.month = 0;
    datePublished.year = 0;
}

/*
returns -1 when Art 1 is before Art 2
returns 0 when Art 1 is equal to Art 2
returns 1 when Art 1 is after than Art 2
*/
int Art::artIsBefore(Art &art2){

    if(cost > art2.cost)
        return 1;
    else if(cost < art2.cost)
        return -1;

    return 0;
}

/*
returns -1 when Furniture 1 is before Furniture 2
returns 0 when Furniture 1 is equal to Furniture 2
returns 1 when Furniture 1 is after than Furniture 2
*/
int furnitureIsBefore(Furniture &furniture1, Furniture &furniture2){

    if(furniture1.cost > furniture2.cost)
        return 1;
    else if(furniture1.cost < furniture2.cost)
        return -1;

    return 0;
}

/*
returns -1 when Fabric 1 is before Fabric 2
returns 0 when Fabric 1 is equal to Fabric 2
returns 1 when Fabric 1 is after than Fabric 2
*/
int Fabric::fabricIsBefore(Fabric &fabric2){

    if(cost > fabric2.cost)
        return 1;
    else if(cost < fabric2.cost)
        return -1;

    return 0;
}

/*
returns -1 when Book 1 is before Book 2
returns 0 when Book 1 is equal to Book 2
returns 1 when Book 1 is after than Book 2
*/
int Book::bookIsBefore(Book &book2){

    if(cost > book2.cost)
        return 1;
    else if(cost < book2.cost)
        return -1;

    return 0;
}


/**
This function is used for swapping the records of the Furniture array
**/
void Furniture :: swapFurniture(Furniture &furniture){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;

    tempString = this->name;
    this->name = furniture.name;
    furniture.name = tempString;

    tempString = this->color;
    this->color = furniture.color;
    furniture.color = tempString;

    tempInt = this->inventory;
    this->inventory = furniture.inventory;
    furniture.inventory = tempInt;

    tempInt = this->dateCreated.day;
    this->dateCreated.day = furniture.dateCreated.day;
    furniture.dateCreated.day = tempInt;

    tempInt = this->dateCreated.month;
    this->dateCreated.month = furniture.dateCreated.month;
    furniture.dateCreated.month = tempInt;

    tempInt = this->dateCreated.year;
    this->dateCreated.year = furniture.dateCreated.year;
    furniture.dateCreated.year = tempInt;

    tempDouble = this->cost;
    this->cost = furniture.cost;
    furniture.cost = tempDouble;
}

/**
This function is used for swapping the records of the Furniture array
**/
void Art :: swapArt(Art &art){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;

    tempString = this->name;
    this->name = art.name;
    art.name = tempString;

    tempDouble = this->cost;
    this->cost = art.cost;
    art.cost = tempDouble;

    tempInt = this->inventory;
    this->inventory = art.inventory;
    art.inventory = tempInt;

    tempInt = this->dateCreated.day;
    this->dateCreated.day = art.dateCreated.day;
    art.dateCreated.day = tempInt;

    tempInt = this->dateCreated.month;
    this->dateCreated.month = art.dateCreated.month;
    art.dateCreated.month = tempInt;

    tempInt = this->dateCreated.year;
    this->dateCreated.year = art.dateCreated.year;
    art.dateCreated.year = tempInt;

    tempInt = this->artSize.width;
    this->artSize.width = art.artSize.width;
    art.artSize.width = tempInt;

    tempInt = this->artSize.height;
    this->artSize.height = art.artSize.height;
    art.artSize.height = tempInt;

    tempInt = this->artSize.depth;
    this->artSize.depth = art.artSize.depth;
    art.artSize.depth = tempInt;

}

/**
This function is used for swapping the records of the Furniture array
**/
void Fabric :: swapFabric(Fabric &fabric){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;

    tempString = this->name;
    this->name = fabric.name;
    fabric.name = tempString;

    tempString = this->color;
    this->color = fabric.color;
    fabric.color = tempString;

    tempInt = this->inventory;
    this->inventory = fabric.inventory;
    fabric.inventory = tempInt;

    tempDouble = this->cost;
    this->cost = fabric.cost;
    fabric.cost = tempDouble;
}

/**
This function is used for swapping the records of the Furniture array
**/
void Book :: swapBook(Book &book){

    int tempInt;
    string tempString;
    char tempChar;
    double tempDouble;
    bool tempBool;

    tempString = this->name;
    this->name = book.name;
    book.name = tempString;

    tempBool = this->hardCover;
    this->hardCover = book.hardCover;
    book.hardCover = tempBool;

    tempInt = this->numPages;
    this->numPages = book.numPages;
    book.numPages = tempInt;

    tempDouble = this->cost;
    this->cost = book.cost;
    book.cost = tempDouble;

    tempInt = this->inventory;
    this->inventory = book.inventory;
    book.inventory = tempInt;

    tempInt = this->datePublished.day;
    this->datePublished.day = book.datePublished.day;
    book.datePublished.day = tempInt;

    tempInt = this->datePublished.month;
    this->datePublished.month = book.datePublished.month;
    book.datePublished.month = tempInt;

    tempInt = this->datePublished.year;
    this->datePublished.year = book.datePublished.year;
    book.datePublished.year = tempInt;
}
