#include "Board.h"
#include <iostream>
using namespace std;

//default constructor for the board, initializes all spaces to be empty
Board::Board()
{
    for(int i = 0; i < yLength; i++)
        for(int j = 0; j < xLength; j++)
            boardSpaces[i][j] = 0;
}

//prints the board and all things located on the board
void Board::printBoard()
{
    for(int i = 0; i < yLength; i++)
        for(int j = 0; j < xLength; j++)
        {
            if(boardSpaces[i][j] == 0)
                cout << " ";
            else if(boardSpaces[i][j] == 1)
                cout << "_";
            else if(boardSpaces[i][j] == 2)
                cout << "|";
            else if(boardSpaces[i][j] == 3)
                cout << "O";
            else if(boardSpaces[i][j] == 4)
                cout << snakesOnBoard[4-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 5)
                cout << snakesOnBoard[5-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 6)
                cout << snakesOnBoard[6-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 7)
                cout << snakesOnBoard[7-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 8)
                cout << snakesOnBoard[8-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 9)
                cout << snakesOnBoard[9-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 10)
                cout << snakesOnBoard[10-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 11)
                cout << snakesOnBoard[11-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 12)
                cout << snakesOnBoard[12-4].getRepresentingCharacter();
            else if(boardSpaces[i][j] == 13)
                cout << snakesOnBoard[13-4].getRepresentingCharacter();
            if(j == xLength-1)
                cout << endl;
        }
}

//returns the xLength of the board
int Board::getXLength()
{
    return xLength;
}

//returns the yLength of the board
int Board::getYLength()
{
    return yLength;
}

//updates the objects on the board
void Board::updateBoard()
{
    for(int i = 0; i < yLength; i++)
        for(int j = 0; j < xLength; j++)
        {
            ///1 and 2 are the walls, 0 is empty
            if(i == 0 || i == yLength-1)
                boardSpaces[i][j] = 1;
            else if(j == 0 || j == xLength-1)
                boardSpaces[i][j] = 2;
            else
                boardSpaces[i][j] = 0;

            ///3 is the food on the board
            for(int k = 0; k < foodOnBoard.size(); k++)
                if(i == foodOnBoard[k].getLocation().getX() && j == foodOnBoard[k].getLocation().getY())
                    boardSpaces[i][j] = 3;

            ///The rest are snakes
            for(int k = 0; k < snakesOnBoard.size(); k++)
            {
                vector<orderedPair> snakeCoordinates = snakesOnBoard[k].getAllCoordinates();
                for(int m = 0; m < snakeCoordinates.size(); m++)
                    if(snakeCoordinates[m].getX() == i && snakeCoordinates[m].getY() == j)
                        boardSpaces[i][j] = k+4;
            }
        }
}

//creates a new snake on the board
void Board::addSnake(snake newSnake)
{
    snakesOnBoard.push_back(newSnake);
}

//creates a new piece of food on the board
void Board::addFood(food newFood)
{
    foodOnBoard.push_back(newFood);
}

//moves each snake according to their logic
void Board::moveSnakes()
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
    {
        if(snakesOnBoard[i].isComputer())
            snakesOnBoard[i].decideNextMovement(snakesOnBoard, foodOnBoard);
        else
            snakesOnBoard[i].moveHumanSnakes();
    }
}

//moves any food that needs to be moved (if it was eaten)
void Board::updateFood()
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
        for(int j = 0; j < foodOnBoard.size(); j++)
            if(snakesOnBoard[i].getHeadLoction() == foodOnBoard[j].getLocation())
            {
                foodOnBoard[j].moveFoodLocation(snakesOnBoard);
                snakesOnBoard[i].setToAdd(snakesOnBoard[i].getToAdd()+3);
            }
}

//lengthen a snake by one each time step
void Board::lengthenSnakes()
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
        if(snakesOnBoard[i].getToAdd() > 0 && snakesOnBoard[i].getBeingEaten() == false)
        {
            snakesOnBoard[i].addToSnake();
            snakesOnBoard[i].setToAdd(snakesOnBoard[i].getToAdd()-1);
        }
}

//remove any snakes that have collided with the wall, a snake, or themselves
void Board::DeleteDeadSnakes()
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
    {
        vector<orderedPair> curCoords = snakesOnBoard[i].getAllCoordinates();
        if(snakesOnBoard[i].checkIfCollisionWithWall()  || snakesOnBoard[i].checkIfCollisionWithSelf() || curCoords.size() < 3 || snakesOnBoard[i].checkIfCollisionWithOtherSnake(snakesOnBoard, i))
            snakesOnBoard.erase(snakesOnBoard.begin()+i);
    }

}

//sets the characters that represent a snake
void Board::setRepresentingCharacters()
{
    char c = ' ';

    for(int i = 0; i < snakesOnBoard.size(); i++)
    {
        c = i+65;
        snakesOnBoard[i].setRepresentingCharacter(c);
    }
}

//logic for cutting a snakes size down (not currently implemented)
void Board::chopSnakes()
{
    for(int m = 0; m < snakesOnBoard.size(); m++)
    {
        for(int i = 0; i < snakesOnBoard.size(); i++)
        {
            if(m != i)
            {
                vector<orderedPair> curCoords = snakesOnBoard[i].getAllCoordinates();
                for(int j = 0; j < curCoords.size(); j++)
                {
                    if(snakesOnBoard[m].getHeadLoction() == curCoords[j])
                    {
                        for(int k = j; k < curCoords.size(); k++)
                            curCoords.erase(curCoords.begin()+k);
                        snakesOnBoard[i].setAllCoordinates(curCoords);
                        snakesOnBoard[i].setBeingEaten(true);
                    }
                }
            }
        }
    }
}
