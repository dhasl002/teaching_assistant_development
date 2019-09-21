#ifndef FOOD_H
#define FOOD_H
#include "orderedPair.h"
#include <vector>
#include "snake.h"
#include "Board.h"
#include "snake.h"
class Board;
class snake;

using namespace std;

class food
{
    public:
        food();
        food(orderedPair newLocation);
        food(int x, int y);
        orderedPair getLocation() {return location;}
        bool checkIfFoodIsEaten(vector<snake> snakesOnBoard);
        void moveFoodLocation(vector<snake> snakesOnBoard);
        bool checkIfFoodLocationIsValid(vector<snake> snakesOnBoard);

    private:
        orderedPair location; //the location of the food on the board
};

#endif // FOOD_H
