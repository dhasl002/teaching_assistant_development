#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "snake.h"
#include "food.h"
class food;
class snake;

using namespace std;

class Board
{
    public:
        Board();
        void printBoard();
        int getXLength();
        int getYLength();
        void updateBoard();
        void addSnake(snake newSnake);
        void addFood(food newFood);
        void moveSnakes();
        void updateFood();
        void lengthenSnakes();
        void DeleteDeadSnakes();
        void setRepresentingCharacters();
        void chopSnakes();

    private:
        const int xLength = 70; //xLength of board
        const int yLength = 20; //yLength of board
        int boardSpaces[20][70]; //the array holding all characters on board
        vector<snake> snakesOnBoard; //vector containing all snakes on board
        vector<food> foodOnBoard; //vector containing all pieces of food on board
};

#endif // BOARD_H
