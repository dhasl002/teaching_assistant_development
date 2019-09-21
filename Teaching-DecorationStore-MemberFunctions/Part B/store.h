#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct Date{
	int day;
	int month;
	int year;
};

struct Dimension{
    double width;
    double height;
    double depth;
};

struct Furniture{
    string name;
    string color;
    int inventory;
    Date dateCreated;
    double cost;

    Furniture();


    void swapFurniture(Furniture& furniture2);
};

struct Art{
    string name;
    double cost;
    int inventory;
    Date dateCreated;
    Dimension artSize;

    Art();
    /*
    returns -1 when Art 1 is before Art 2
    returns 0 when Art 1 is equal to Art 2
    returns 1 when Art 1 is after than Art 2
    */
    int artIsBefore(Art& art2);
    void swapArt(Art& art2);
};

struct Fabric{
    string name;
    string color;
    int inventory;
    double cost;

    Fabric();
    /*
    returns -1 when Fabric 1 is before Fabric 2
    returns 0 when Fabric 1 is equal to Fabric 2
    returns 1 when Fabric 1 is after than Fabric 2
    */
    int fabricIsBefore(Fabric& fabric2);
    void swapFabric(Fabric& fabric2);
};

struct Book{
    string name;
    bool hardCover;
    int numPages;
    double cost;
    int inventory;
    Date datePublished;

    Book();
    /*
    returns -1 when Book 1 is before Book 2
    returns 0 when Book 1 is equal to Book 2
    returns 1 when Book 1 is after than Book 2
    */
    int bookIsBefore(Book& book2);
    void swapBook(Book& book2);
};

/*
    returns -1 when Furniture 1 is before Furniture 2
    returns 0 when Furniture 1 is equal to Furniture 2
    returns 1 when Furniture 1 is after than Furniture 2
*/
int furnitureIsBefore(Furniture& furniture1, Furniture& furniture2);

#endif // STORE_H_INCLUDED
