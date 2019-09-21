#include <iostream>
#include <fstream>
#include <iomanip>

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
};

struct Art{
    string name;
    double cost;
    int inventory;
    Date dateCreated;
    Dimension artSize;
};

struct Fabric{
    string name;
    string color;
    int inventory;
    double cost;
};

struct Book{
    string name;
    bool hardCover;
    int numPages;
    double cost;
    int inventory;
    Date datePublished;
};

/**
These four functions are mandatory as instructed in the Assignment
**/
void getFurnitureData(ifstream& inFile);
void getArtData(ifstream& inFile);
void getFabricData(ifstream& inFile);
void getBookData(ifstream& inFile);

/**
Optional Helper Functions
**/
void displayFurniture(Furniture furniture[], int totalFurniture);
void displayArt(Art art[], int totalArt);
void displayFabric(Fabric fabric[], int totalFabric);
void displayBook(Book book[], int totalBook);

void printHorizontalLine( int width, char border_char);
void printHeading( string title, int width );

int main()
{
    cout << "This is Assignment 1 (Structs) - Restaurant" << endl;

    /**
    Declaring the input streams for each file
    **/
    ifstream inFileFurniture;
    ifstream inFileArt;
    ifstream inFileFabric;
    ifstream inFileBook;

    /**
    Opening the files. You can either hardcode the name of the files or ask the user to give the names
    **/
    inFileFurniture.open("Furniture.txt");
    inFileArt.open("Art.txt");
    inFileFabric.open("Fabric.txt");
    inFileBook.open("Book.txt");

    /**
    If the any of the file cannot be opened then the program terminates displaying
    the error message
    **/
    if (!inFileFurniture)
    {
        cout << "The Furniture input file does not exist. Program terminates!" << endl;
        //return 1;
    }
    if (!inFileArt)
    {
        cout << "The Art input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!inFileFabric)
    {
        cout << "The Fabric input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!inFileBook)
    {
        cout << "The Book input file does not exist. Program terminates!" << endl;
        return 1;
    }

    /**
    Display the prompt and do the requested action. Keep repeating the prompt until exit.
    If the number entered is not an option, just repeat the prompt.
    **/
    int chosenOption;

    do{
        cout << "\n\n\nSelect which option you would like to see \n"
         << "1. Print all Furniture \n"
         << "2. Print all Art \n"
         << "3. Print all Fabric \n"
         << "4. Print all Book \n"
         << "5. Exit \n"
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
            Furniture
            Function call to read data from input file. That function then calls a print Function
            **/
            getFurnitureData(inFileFurniture);
            break;
        case 2:
            /**
            Art
            Function call to read data from input file. That function then calls a print Function
            **/
            getArtData(inFileArt);

            break;
        case 3:
            /**
            Fabric
            Function call to read data from input file. That function then calls a print Function
            **/
            getFabricData(inFileFabric);

            break;
        case 4:
            /**
            Book
            Function call to read data from input file. That function then calls a print Function
            **/
            getBookData(inFileBook);
            break;
        default:
            break;
        }

    }while(chosenOption != 5);

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
Using the input stream sent as parameter we are reading the content from the Furniture.txt and storing it in the Furniture struct array
**/
void getFurnitureData(ifstream& inFile){

    int totalFurniture;
    inFile >> totalFurniture;

    Furniture furniture[totalFurniture];

    char decimal;

    for(int i = 0; i < totalFurniture; i++){
        inFile >> furniture[i].name;
        inFile >> furniture[i].color;
        inFile >> furniture[i].inventory;
        inFile >> furniture[i].dateCreated.month >> decimal >> furniture[i].dateCreated.day >> decimal >> furniture[i].dateCreated.year;
        inFile >> furniture[i].cost;
    }

    inFile.close();

    printHeading("Furniture", 60);

    displayFurniture(furniture,totalFurniture);
}

/**
Using the input stream sent as parameter we are reading the content from the fabric.txt and storing it in the fabric struct array
**/
void getFabricData(ifstream& inFile){

    int totalFabric;
    inFile >> totalFabric;

    Fabric fabric[totalFabric];

    for(int i = 0; i < totalFabric; i++){
        inFile >> fabric[i].name;
        inFile >> fabric[i].color;
        inFile >> fabric[i].inventory;
        inFile >> fabric[i].cost;
    }

    inFile.close();

    printHeading("Fabric", 60);

    displayFabric(fabric,totalFabric);
}


/**
Using the input stream sent as parameter we are reading the content from the Art.txt and storing it in the art struct array
**/
void getArtData(ifstream& inFile){

    int totalArt;
    inFile >> totalArt;

    Art art[totalArt];

    char decimal;

    for(int i = 0; i < totalArt; i++){
        inFile >> art[i].name;
        inFile >> art[i].cost;
        inFile >> art[i].inventory;
        inFile >> art[i].dateCreated.month >> decimal >> art[i].dateCreated.day >> decimal >> art[i].dateCreated.year;
        inFile >> art[i].artSize.width >> decimal >> art[i].artSize.height >> decimal >> art[i].artSize.depth;
    }

    inFile.close();

    printHeading("Art", 60);

    displayArt(art,totalArt);
}

/**
Using the input stream sent as parameter we are reading the content from the Personnel.txt and storing it in the Book struct array
**/
void getBookData(ifstream& inFile){

    int totalBook;
    inFile >> totalBook;

    Book book[totalBook];

    char decimal;

    for(int i = 0; i < totalBook; i++){
        inFile >> book[i].name;
        inFile >> book[i].hardCover;
        inFile >> book[i].numPages;
        inFile >> book[i].cost;
        inFile >> book[i].inventory;
        inFile >> book[i].datePublished.month >> decimal >> book[i].datePublished.day >> decimal >> book[i].datePublished.year;
    }

    inFile.close();

    printHeading("Books", 60);

    displayBook(book,totalBook);
}


/**
Displaying the content from the Furniture struct array on the monitor
**/
void displayFurniture(Furniture furniture[], int totalFurniture){
   cout << setw(10) << "Name" << "    | "
        << "Color" << "  | "
        << "Inventory" << "  | "
        << "Date Created" << "  | "
        << "Cost" << endl;

    printHorizontalLine(80,'-');

    for(int i = 0; i < totalFurniture; i++){
        cout << left << setw(13) << furniture[i].name << "   | "
             << right << setw(6) << setfill(' ') << furniture[i].color << "   | "
             << right << setw(6) << setfill(' ') << furniture[i].inventory << "   | "
             << right <<setw(2) << setfill('0') << furniture[i].dateCreated.month <<":" << setw(2) << setfill('0') << furniture[i].dateCreated.day <<":" << setw(2) << setfill('0') << furniture[i].dateCreated.year << " | "
             << right <<setw(9) << setfill(' ') << furniture[i].cost << " "
             << setfill(' ') << endl;
    }
}

/**
Displaying the content from the Fabric struct array on the monitor
**/
void displayFabric(Fabric fabric[], int totalFabric){

   cout << setw(15) << "Name" << " | "
        << "Color" << " | "
        << "Inventory" << " | "
        << "Cost" <<  endl;


    printHorizontalLine(80,'-');

    for(int i = 0; i < totalFabric; i++){
        cout << left << setw(15) << setfill(' ') << fabric[i].name << " | "
             << right << setw(5) << setfill(' ') << fabric[i].color << " |  "
             << right << setw(5) << setfill(' ') << fabric[i].inventory << " |  "
             << right << setw(3) << setfill(' ') << fabric[i].cost << " "
             << setfill(' ') << endl;
    }
}


/**
Displaying the content from the Art struct array on the monitor
**/
void displayArt(Art art[], int totalArt){
   cout << setw(18) << "Name" << "   |  "
        << " Cost" << "     |  "
        << "Inventory" << "  | "
        << "Date Created" << " | "
        << "Art Dimensions" <<  endl;

    printHorizontalLine(80,'-');

    for(int i = 0; i < totalArt; i++){
        cout << left  << setw(18) << art[i].name << "   |   "
             << right << setw(5) << art[i].cost << "    |  "
             << right << setw(4) << setfill(' ') << art[i].inventory << "    |  "
             << right << setw(2) << setfill('0') << art[i].dateCreated.month <<":" << setw(2) << setfill('0') << art[i].dateCreated.day <<":" << setw(2) << setfill('0') << art[i].dateCreated.year << "   |  "
             << right << setw(2) << setfill('0') << art[i].artSize.width <<":" << setw(2) << setfill('0') << art[i].artSize.height <<":" << setw(2) << setfill('0') << art[i].artSize.depth << "   |  "
             << setfill(' ') << endl;
    }
}

/**
Displaying the content from the Personnel struct array on the monitor
**/
void displayBook(Book book[], int totalBook){
   cout << setw(25) << "Name" << " | "
        << "Is Hardcover" << " | "
        << "Number Pages" << " | "
        << "Cost" << " | "
        << "Inventory" << " | "
        << "Date Published" <<  endl;


    printHorizontalLine(80,'-');

    for(int i = 0; i < totalBook; i++){
        cout << left  << setw(25) << book[i].name << "   |  "
             << right << setw(7) << setfill(' ') << book[i].hardCover << "   | "
             << right << setw(9) << setfill(' ') << book[i].numPages << "   | "
             << right << setw(9) << setfill(' ') << book[i].cost << "   | "
             << right << setw(9) << setfill(' ') << book[i].inventory << "   | "
             << right << setw(2) << setfill('0') << book[i].datePublished.month <<":" << setw(2) << setfill('0') << book[i].datePublished.day <<":" << setw(2) << setfill('0') << book[i].datePublished.year << "   |  "
             << setfill(' ') << endl;
    }
}
