#ifndef CONCESSIONSTAND_H
#define CONCESSIONSTAND_H
#include <vector>
#include "bankAccount.h"

class concessionStand
{
    public:
        concessionStand();
        int GethotDogInventory() { return hotDogInventory; }
        void SethotDogInventory(int val) { hotDogInventory = val; }
        int GetpeanutInventory() { return peanutInventory; }
        void SetpeanutInventory(int val) { peanutInventory = val; }
        int GetburgerInventory() { return burgerInventory; }
        void SetburgerInventory(int val) { burgerInventory = val; }
        int GetsoftDrinkInventory() { return softDrinkInventory; }
        void SetsoftDrinkInventory(int val) { softDrinkInventory = val; }
        int GetbeerInventory() { return beerInventory; }
        void SetbeerInventory(int val) { beerInventory = val; }
        int GetjerseyInventory() { return jerseyInventory; }
        void SetjerseyInventory(int val) { jerseyInventory = val; }
        double GethotDogPrice() { return hotDogPrice; }
        void SethotDogPrice(double val) { hotDogPrice = val; }
        double GetpeanutPrice() { return peanutPrice; }
        void SetpeanutPrice(double val) { peanutPrice = val; }
        double GetburgerPrice() { return burgerPrice; }
        void SetburgerPrice(double val) { burgerPrice = val; }
        double GetsoftDrinkPrice() { return softDrinkPrice; }
        void SetsoftDrinkPrice(double val) { softDrinkPrice = val; }
        double GetbeerPrice() { return beerPrice; }
        void SetbeerPrice(double val) { beerPrice = val; }
        double GetjerseyPrice() { return jerseyPrice; }
        void SetjerseyPrice(double val) { jerseyPrice = val; }
        double GettotalSales() {return totalSales;}
        void SettotalSales(double val) {totalSales = val;}
    protected:
    private:
        int hotDogInventory;
        int peanutInventory;
        int burgerInventory;
        int softDrinkInventory;
        int beerInventory;
        int jerseyInventory;
        double hotDogPrice;
        double peanutPrice;
        double burgerPrice;
        double softDrinkPrice;
        double beerPrice;
        double jerseyPrice;
        double totalSales;
};
//main menu for concession stand
void concessionMenu(int selection, concessionStand &conStand, bankAccount &b);
//prints all concession stand info including amount left in inventory and price
void printConcessionStand(concessionStand conStand);
//prints the total amount of sales the concession stand has made during its lifetime
void printLifeSales(concessionStand conStand);
//orders inventory are 50% of the selling value, bank account is adjusted and inventory is also adjusted
void orderInventory(int amount, int selection2, concessionStand &conStand, bankAccount &b);
//sells an item to a customer. Checks that there is enough stock left to fulfill the sale and adjusts inventory and bank account accordingly
void sellItems(int selection2, concessionStand &constand, bankAccount &b, int amount);

#endif // CONCESSIONSTAND_H
