#include <iostream>
#include <fstream>
#include <iomanip>
#include "store.h"

using namespace std;

/**
These four functions are mandatory as instructed in the Assignment
**/
void getFoodData(ifstream& inFile);
void getCondimentData(ifstream& inFile);
void getPlasticItemsData(ifstream& inFile);

/**
Optional Helper Functions
**/
void displayFood(Food food[], int totalFood);
void displayCondiments(Condiment condiment[], int totalCondiments);
void displayPlasticItems(PlasticItem plasticItem[], int totalPlastiicItems);

void printHorizontalLine( int width, char border_char);
void printHeading( string title, int width );

int main()
{
    cout << "This is Assignment 1 (Structs) - Restaurant" << endl;

    /**
    Declaring the input streams for each file
    **/
    ifstream inFileFood;
    ifstream inFileEmployee;
    ifstream inFileCondiment;
    ifstream inFilePlasticItem;

    /**
    Opening the files. You can either hardcode the name of the files or ask the user to give the names
    **/
    inFileFood.open("Food.txt");
    inFileEmployee.open("Employee.txt");
    inFileCondiment.open("Condiment.txt");
    inFilePlasticItem.open("PlasticItem.txt");

    /**
    If the any of the file cannot be opened then the program terminates displaying
    the error message
    **/
    if (!inFileFood)
    {
        cout << "The Food input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!inFileCondiment)
    {
        cout << "The Condiment input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!inFilePlasticItem)
    {
        cout << "The PlasticItem input file does not exist. Program terminates!" << endl;
        return 1;
    }

    /**
    Display the prompt and do the requested action. Keep repeating the prompt until exit.
    If the number entered is not an option, just repeat the prompt.
    **/
    int chosenOption;

    do{
        cout << "\n\n\nSelect which option you would like to see \n"
         << "1. Print all Food \n"
         << "2. Print all Condiments \n"
         << "3. Print all Plastic Items \n"
         << "4. Exit \n"
         << "\n"
         << "Enter Option (1-5): ";
        cin >> chosenOption;

        /**
        Do the correct action according to the chosenOption
        **/
        switch(chosenOption)
        {
        case 1:
            /**
            Food
            Function call to read data from input file. That function then calls a print Function
            **/
            getFoodData(inFileFood);
            break;
        case 2:
            /**
            Condiments
            Function call to read data from input file. That function then calls a print Function
            **/
            getCondimentData(inFileCondiment);

            break;
        case 3:
            /**
            Plastic Items
            Function call to read data from input file. That function then calls a print Function
            **/
            getPlasticItemsData(inFilePlasticItem);
            break;
        default:
            break;
        }

    }while(chosenOption != 4);

    return 0;
}

void printHorizontalLine( int width, char border_char){
    cout.fill( border_char );
    cout << setw( width ) << border_char << "\n";
    cout.fill(' ');
}

void printHeading( string title, int width ){
    //Declare Variables
    int magic_width = 0;

    magic_width =  (width/2) - (title.length()/2) + title.length();

    cout << "\n";
    cout << left  << setfill('=') << setw( width ) << "=" << "\n";
    cout << right << setfill(' ') << setw( magic_width ) << title << "\n";
    cout << right << setfill('=') << setw( width ) << "=" << endl;

    //reset count
    cout.clear();
    cout.fill(' ');

    //VOID functions do NOT return a value
}

/**
Using the input stream sent as parameter we are reading the content from the Food.txt and storing it in the food struct array
**/
void getFoodData(ifstream& inFile){

    int totalFood;
    inFile >> totalFood;

    Food food[totalFood];

    char decimal;

    for(int i = 0; i < totalFood; i++){
        inFile >> food[i].name;
        inFile >> food[i].numberLeft;
        inFile >> food[i].sellByDate.month >> decimal >> food[i].sellByDate.day >> decimal >> food[i].sellByDate.year;
        inFile >> food[i].cost;
    }

    inFile.close();

    printHeading("Food", 60);

    displayFood(food,totalFood);
}

/**
Using the input stream sent as parameter we are reading the content from the condiments.txt and storing it in the condiments struct array
**/
void getCondimentData(ifstream& inFile){

    int totalCondiments;
    inFile >> totalCondiments;

    Condiment condiments[totalCondiments];

    char decimal;

    for(int i = 0; i < totalCondiments; i++){
        inFile >> condiments[i].name;
        inFile >> condiments[i].ouncesLeft;
        inFile >> condiments[i].sellByDate.month >> decimal >> condiments[i].sellByDate.day >> decimal >> condiments[i].sellByDate.year;
        inFile >> condiments[i].cost;
    }

    inFile.close();

    printHeading("Condiments", 60);

    displayCondiments(condiments,totalCondiments);
}

/**
Using the input stream sent as parameter we are reading the content from the Personnel.txt and storing it in the plasticItem struct array
**/
void getPlasticItemsData(ifstream& inFile){

    int totalPlasticItems;
    inFile >> totalPlasticItems;

    PlasticItem plasticItem[totalPlasticItems];

    for(int i = 0; i < totalPlasticItems; i++){
        inFile >> plasticItem[i].name;
        inFile >> plasticItem[i].numberLeft;
        inFile >> plasticItem[i].cost;
    }

    inFile.close();

    printHeading("Plastic Items", 60);

    displayPlasticItems(plasticItem,totalPlasticItems);
}


/**
Displaying the content from the food struct array on the monitor
**/
void displayFood(Food food[], int totalFood){
   cout << setw(10) << "Name" << "  | "
        << "Number left" << "  | "
        << "Sell By Date" << "  | "
        << "Cost" << endl;

    printHorizontalLine(80,'-');

    for(int i = 0; i < totalFood; i++){
        cout << left << setw(9) << food[i].name << "   | "
             << right << setw(6) << setfill(' ') << food[i].numberLeft << "     | "
             << right <<setw(2) << setfill('0') << food[i].sellByDate.month <<":" << setw(2) << setfill('0') << food[i].sellByDate.day <<":" << setw(2) << setfill('0') << food[i].sellByDate.year << " | "
             << right <<setw(9) << setfill(' ') << food[i].cost << " "
             << setfill(' ') << endl;
    }
}

/**
Displaying the content from the Condiments struct array on the monitor
**/
void displayCondiments(Condiment condiment[], int totalCondiments){

   cout << setw(8) << "Name" << " | "
        << "Ounces Left" << " | "
        << "Date of Birth" << " | "
        << "Sell By Date" << " | "
        << "Cost" <<  endl;

    printHorizontalLine(80,'-');

    for(int i = 0; i < totalCondiments; i++){
        cout << left << setw(15) << setfill(' ') << condiment[i].name << " | "
             << right << setw(5) << setfill(' ') << condiment[i].ouncesLeft << " |  "
             << right <<setw(2) << setfill('0') << condiment[i].sellByDate.month <<":" << setw(2) << setfill('0') << condiment[i].sellByDate.day <<":" << setw(2) << setfill('0') << condiment[i].sellByDate.year << "   |    "
             << right << setw(3) << setfill(' ') << condiment[i].cost << " "
             << setfill(' ') << endl;
    }
}

/**
Displaying the content from the Personnel struct array on the monitor
**/
void displayPlasticItems(PlasticItem plasticItem[], int totalPlasticItems){
   cout << setw(10) << "Name" << " | "
        << "Number Left" << " | "
        << "Cost" <<  endl;

    printHorizontalLine(80,'-');

    for(int i = 0; i < totalPlasticItems; i++){
        cout << left  << setw(9) << plasticItem[i].name << "   |  "
             << right << setw(7) << setfill(' ') << plasticItem[i].numberLeft << "  | "
             << right << setw(9) << setfill(' ') << plasticItem[i].cost << " "
             << setfill(' ') << endl;
    }
}
