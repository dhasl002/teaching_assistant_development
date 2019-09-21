#include "concessionStand.h"
#include <iostream>

using namespace std;

//default constructor
concessionStand::concessionStand()
{
    hotDogInventory = 0;
    peanutInventory = 0;
    burgerInventory = 0;
    softDrinkInventory = 0;
    beerInventory = 0;
    jerseyInventory = 0;
    hotDogPrice = 3;
    peanutPrice = 1;
    burgerPrice = 5;
    softDrinkPrice = 1.5;
    beerPrice = 8;
    jerseyPrice = 100;
    totalSales = 0;
}

//prints all concession stand info including amount left in inventory and price
void printConcessionStand(concessionStand conStand)
{
    cout << "Hot Dog Inventory: " << conStand.GethotDogInventory() << endl;
    cout << "Price: " << conStand.GethotDogPrice() << endl;
    cout << "Peanut Inventory: " << conStand.GetpeanutInventory() << endl;
    cout << "Price: " << conStand.GetpeanutPrice() << endl;
    cout << "burger Inventory: " << conStand.GetburgerInventory() << endl;
    cout << "Soft Drink inventory: " << conStand.GetsoftDrinkInventory() << endl;
    cout << "Price: " << conStand.GetsoftDrinkPrice() << endl;
    cout << "Beer Inventory: " << conStand.GetbeerInventory() << endl;
    cout << "Price: " << conStand.GetbeerPrice() << endl;
    cout << "Jersey Inventory: " << conStand.GetjerseyInventory() << endl;
    cout << "Price: "<< conStand.GetjerseyPrice() << "\n" << endl;
}

//prints the total amount of sales the concession stand has made during its lifetime
void printLifeSales(concessionStand conStand)
{
    cout << "Total Sales: " << conStand.GettotalSales() << "\n" << endl;
}

//orders inventory are 50% of the selling value, bank account is adjusted and inventory is also adjusted
void orderInventory(int amount, int selection2, concessionStand &conStand, bankAccount &b)
{
    switch(selection2)
    {
    case 1:
        conStand.SethotDogInventory(conStand.GethotDogInventory()+amount);
        b.SetcashOnHand(b.GetcashOnHand()-(amount*.5*conStand.GethotDogPrice()));
        break;
    case 2:
        conStand.SetpeanutInventory(conStand.GetpeanutInventory()+amount);
        b.SetcashOnHand(b.GetcashOnHand()-(amount*.5*conStand.GetpeanutPrice()));
        break;
    case 3:
        conStand.SetburgerInventory(conStand.GetburgerInventory()+amount);
        b.SetcashOnHand(b.GetcashOnHand()-(amount*.5*conStand.GetburgerPrice()));
        break;
    case 4:
        conStand.SetsoftDrinkInventory(conStand.GetsoftDrinkInventory()+amount);
        b.SetcashOnHand(b.GetcashOnHand()-(amount*.5*conStand.GetsoftDrinkPrice()));
        break;
    case 5:
        conStand.SetbeerInventory(conStand.GetbeerInventory()+amount);
        b.SetcashOnHand(b.GetcashOnHand()-(amount*.5*conStand.GetbeerPrice()));
        break;
    case 6:
        conStand.SetjerseyInventory(conStand.GetjerseyInventory()+amount);
        b.SetcashOnHand(b.GetcashOnHand()-(amount*.5*conStand.GetjerseyPrice()));
        break;
    }
}

//sells an item to a customer. Checks that there is enough stock left to fulfill the sale and adjusts inventory and bank account accordingly
void sellItems(int selection2, concessionStand &conStand, bankAccount &b, int amount)
{
    double beginAmount = 0;
    beginAmount = conStand.GettotalSales();
    switch(selection2)
    {
    case 1:
        if(conStand.GethotDogInventory()-amount > 0)
        {
            conStand.SethotDogInventory(conStand.GethotDogInventory()-amount);
            conStand.SettotalSales(conStand.GettotalSales()+(amount*(conStand.GethotDogPrice())));
        }
        else
        {
            cout << "Sold out!" << endl;
            conStand.SettotalSales(conStand.GettotalSales()+conStand.GethotDogInventory()*conStand.GethotDogPrice());
            conStand.SethotDogInventory(0);
        }
        break;
    case 2:
        if(conStand.GetpeanutInventory()-amount > 0)
        {
            conStand.SetpeanutInventory(conStand.GetpeanutInventory()-amount);
            conStand.SettotalSales(conStand.GettotalSales()+amount*conStand.GetpeanutPrice());
        }
        else
        {
            cout << "Sold out!" << endl;
            conStand.SettotalSales(conStand.GettotalSales()+conStand.GetpeanutInventory()*conStand.GetpeanutPrice());
            conStand.SetpeanutInventory(0);
        }
        break;
    case 3:
        if(conStand.GetburgerInventory()-amount > 0)
        {
            conStand.SetburgerInventory(conStand.GetburgerInventory()-amount);
            conStand.SettotalSales(conStand.GettotalSales()+amount*conStand.GetburgerPrice());
        }
        else
        {
            cout << "Sold out!" << endl;
            conStand.SettotalSales(conStand.GettotalSales()+conStand.GetburgerInventory()*conStand.GetburgerPrice());
            conStand.SetburgerInventory(0);
        }
        break;
    case 4:
        if(conStand.GetsoftDrinkInventory()-amount > 0)
        {
            conStand.SetsoftDrinkInventory(conStand.GetsoftDrinkInventory()-amount);
            conStand.SettotalSales(conStand.GettotalSales()+amount*conStand.GetsoftDrinkPrice());
        }
        else
        {
            cout << "Sold out!" << endl;
            conStand.SettotalSales(conStand.GettotalSales()+conStand.GetsoftDrinkInventory()*conStand.GetsoftDrinkPrice());
            conStand.SetsoftDrinkInventory(0);
        }
        break;
    case 5:
        if(conStand.GetbeerInventory()-amount > 0)
        {
            conStand.SetbeerInventory(conStand.GetbeerInventory()-amount);
            conStand.SettotalSales(conStand.GettotalSales()+amount*conStand.GetbeerPrice());
        }
        else
        {
            cout << "Sold out!" << endl;
            conStand.SettotalSales(conStand.GettotalSales()+conStand.GetbeerInventory()*conStand.GetbeerPrice());
            conStand.SetbeerInventory(0);
        }
        break;
    case 6:
        if(conStand.GetjerseyInventory()-amount > 0)
        {
            conStand.SetjerseyInventory(conStand.GetjerseyInventory()-amount);
            conStand.SettotalSales(conStand.GettotalSales()+amount*conStand.GetjerseyPrice());
        }
        else
        {
            cout << "Sold out!" << endl;
            conStand.SettotalSales(conStand.GettotalSales()+conStand.GetjerseyInventory()*conStand.GetjerseyPrice());
            conStand.SetjerseyInventory(0);
        }
        break;
        b.SetcashOnHand(b.GetcashOnHand() + (conStand.GettotalSales()-beginAmount));
    }
}
//main menu for concession stand
void concessionMenu(int selection, concessionStand &conStand, bankAccount &b)
{
    int selection2 = 0;
    int amount = 0;
    switch(selection)
    {
    case 1:
        printConcessionStand(conStand);
        break;
    case 2:
        cout << "Which Item would you like to sell?" << endl;
        cout << "1. Hot dog" << endl;
        cout << "2. Peanuts" << endl;
        cout << "3. Burger" << endl;
        cout << "4. Soft drink" << endl;
        cout << "5. Beer" << endl;
        cout << "6. Jersey" << "\n" << endl;
        cin >> selection2;
        cout << "How many would you like to buy?" << endl;
        cin >> amount;
        sellItems(selection2, conStand, b, amount);
        break;
    case 3:
        printLifeSales(conStand);
        break;
    case 4:
        cout << "What item would you like to order?" << endl;
        cout << "1. Hot dog" << endl;
        cout << "2. Peanuts" << endl;
        cout << "3. Burger" << endl;
        cout << "4. Soft drink" << endl;
        cout << "5. Beer" << endl;
        cout << "6. Jersey" << "\n" << endl;
        cin >> selection2;
        cout << "How many would you like to buy?" << endl;
        cin >> amount;
        orderInventory(amount, selection2, conStand, b);
        break;
    case 5:
        break;
    }
}
