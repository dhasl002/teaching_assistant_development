#include "food.h"
#include <random>
#include "snake.h"
#include <vector>
using namespace std;

//default constructor for food
food::food()
{
    location = orderedPair(0,0);
}

//given an ordered pair, a food will be generated in that location
food::food(orderedPair newLocation)
{
    location = newLocation;
}

//given an x and y coordinate, food will be generated in that location
food::food(int x, int y)
{
    location = orderedPair(x, y);
}

//check if the food has been eaten during this time step
bool food::checkIfFoodIsEaten(vector<snake> snakesOnBoard)
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
        if(location == snakesOnBoard[i].getHeadLoction())
            return true;
    return false;
}

//once food is eaten, put a new piece of food on the board
void food::moveFoodLocation(vector<snake> snakesOnBoard)
{
    bool foodIsOnSnake = true;

    while(foodIsOnSnake)
    {
        foodIsOnSnake = false;
        location.setX(rand() % 11 + 5);
        location.setY(rand() % 61 + 5);

        for(int i = 0; i < snakesOnBoard.size(); i++)
        {
            vector<orderedPair> currentSnakeCoordinates = snakesOnBoard[i].getAllCoordinates();
            for(int j = 0; j < currentSnakeCoordinates.size(); j++)
                if(currentSnakeCoordinates[j] == location)
                    foodIsOnSnake = true;
        }

    }
}

//make sure that a new piece of food is in a valid location (not on top of a snake)
bool food::checkIfFoodLocationIsValid(vector<snake> snakesOnBoard)
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
    {
        vector<orderedPair> snakeCoordinates = snakesOnBoard[i].getAllCoordinates();
        for(int j = 0; j < snakeCoordinates.size(); i++)
            if(location == snakeCoordinates[j])
                return false;
    }
    return true;
}
