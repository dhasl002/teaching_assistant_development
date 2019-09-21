#include "snake.h"
#include "orderedPair.h"
#include "food.h"
#include <math.h>
#include <stdlib.h>
#include <random>
#include <iostream>
#include <conio.h>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//default constructor for snake
snake::snake()
{
    computer = true;
    lastDirection = "right";
    toAdd = 0;
    representingCharacter = ' ';
    beingEaten = false;
}

//constructor for snake given a coordinate for the head location
snake::snake(orderedPair head)
{
    computer = true;
    coordinate.push_back(head);
    for(int i = 0; i < 4; i++)
        coordinate.push_back(generatePairToLeft(coordinate[coordinate.size()-1]));
    lastDirection = "right";
    toAdd = 0;
    representingCharacter = ' ';
    beingEaten = false;
}

//constructor for snake given a coordinate for the head location and the decision of whether the snake will be computer or human controlled
snake::snake(orderedPair head, bool isAComputer)
{
    computer = isAComputer;
    coordinate.push_back(head);
    for(int i = 0; i < 4; i++)
        coordinate.push_back(generatePairToLeft(coordinate[coordinate.size()-1]));
    lastDirection = "right";
    toAdd = 0;
    representingCharacter = ' ';
    beingEaten = false;
}

//moves a snake's head up one space and moves the rest of the body accordingly
void snake::moveUp()
{
    for(int i = coordinate.size()-1; i > 0; i--)
        coordinate[i] = orderedPair(coordinate[i-1].getX(), coordinate[i-1].getY());
    coordinate[0].setX(coordinate[0].getX()-1);
    headLocation = coordinate[0];
    lastDirection = "up";
}

//moves a snake's head down one space and moves the rest of the body accordingly
void snake::moveDown()
{
    for(int i = coordinate.size()-1; i > 0; i--)
        coordinate[i] = orderedPair(coordinate[i-1].getX(), coordinate[i-1].getY());
    coordinate[0].setX(coordinate[0].getX()+1);
    headLocation = coordinate[0];
    lastDirection = "down";
}

//moves a snake's head right one space and moves the rest of the body accordingly
void snake::moveRight()
{
    for(int i = coordinate.size()-1; i > 0; i--)
        coordinate[i] = orderedPair(coordinate[i-1].getX(), coordinate[i-1].getY());
    coordinate[0].setY(coordinate[0].getY()+1);
    headLocation = coordinate[0];
    lastDirection = "right";
}

//moves a snake's head left one space and moves the rest of the body accordingly
void snake::moveLeft()
{
    for(int i = coordinate.size()-1; i > 0; i--)
        coordinate[i] = orderedPair(coordinate[i-1].getX(), coordinate[i-1].getY());
    coordinate[0].setY(coordinate[0].getY()-1);
    headLocation = coordinate[0];
    lastDirection = "left";
}

//returns the vector that contains all the snake's coordinates
vector<orderedPair> snake::getAllCoordinates()
{
    return coordinate;
}

//returns the head location of the snake
orderedPair snake::getHeadLoction()
{
    return coordinate[0];
}

//adds a single link to the snake
void snake::addToSnake()
{
    //determines the direction of the tail
    if(abs(coordinate[coordinate.size()-1].getX()-coordinate[coordinate.size()-2].getX()) == 1)
    {
        if(coordinate[coordinate.size()-2].getX()-coordinate[coordinate.size()-1].getX() == 1)
            coordinate.push_back(orderedPair(coordinate[coordinate.size()-1].getX()-1, coordinate[coordinate.size()-1].getY()));
        else if(coordinate[coordinate.size()-2].getX()-coordinate[coordinate.size()-1].getX() == -1)
            coordinate.push_back(orderedPair(coordinate[coordinate.size()-1].getX()+1, coordinate[coordinate.size()-1].getY()));
    }
    else if(abs(coordinate[coordinate.size()-1].getY()-coordinate[coordinate.size()-2].getY()) == 1)
    {
        if(coordinate[coordinate.size()-2].getY()-coordinate[coordinate.size()-1].getY() == 1)
            coordinate.push_back(orderedPair(coordinate[coordinate.size()-1].getX(), coordinate[coordinate.size()-1].getY()-1));
        else if(coordinate[coordinate.size()-2].getY()-coordinate[coordinate.size()-1].getY() == -1)
            coordinate.push_back(orderedPair(coordinate[coordinate.size()-1].getX(), coordinate[coordinate.size()-1].getY()+1));
    }
}

//checks if the snake has collided with a wall
bool snake::checkIfCollisionWithWall()
{
    if(coordinate[0].getX() == 0 || coordinate[0].getX() == 19 || coordinate[0].getY() == 0 || coordinate[0].getY() == 69)
        return true;
    return false;
}

//checks if the snake has collided with itself
bool snake::checkIfCollisionWithSelf()
{
    for(int i = 1; i < coordinate.size(); i++)
        if(coordinate[0].getX() == coordinate[i].getX() && coordinate[0].getY() == coordinate[i].getY())
            return true;
    return false;
}

//decides the next movement for a computer snake
void snake::decideNextMovement(vector<snake> snakesOnBoard, vector<food> foodOnBoard)
{
    double minDistance = 99999;
    int minIndex = -1;

    //the highest priority is for the snake to not collide with anything
    if(this->checkForUpcomingCollision())
        this->MoveInRandomDirection();
    //the second priority is to move towards food
    else if(thereIsNearbyFood(foodOnBoard))
    {
        for(int i = 0; i < foodOnBoard.size(); i++)
            if(headLocation.calculateDistance(foodOnBoard[i].getLocation()) < 10)
            {
                if(headLocation.calculateDistance(foodOnBoard[i].getLocation()) < minDistance)
                {
                    minIndex = i;
                    minDistance = headLocation.calculateDistance(foodOnBoard[i].getLocation());
                }
            }
        this->MoveTowardsFood(foodOnBoard[minIndex]);
    }
    //if the snake will not collide with anything and is not close to food, move forward
    else
    {
        //have a small chance to turn
        if(rand() % 11 != 0)
            continueStrait();
        else
            this->MoveInRandomDirection();
    }
}

//instruct snake to move in the same direction that it last moved
void snake::continueStrait()
{
    if(lastDirection == "right")
        this->moveRight();
    else if(lastDirection == "left")
        this->moveLeft();
    else if(lastDirection == "up")
        this->moveUp();
    else if(lastDirection == "down")
        this->moveDown();
}

//check if a snake is going to collide with a wall or itself soon
bool snake::checkForUpcomingCollision()
{
    if(checkIfCollisionWithSelf())
        return true;
    if(this->checkForUpcomingWallCollision())
        return true;
    return false;
}

//check if snake is on a path to collide with itself
bool snake::checkForCollisionWithSelf()
{
    if(lastDirection == "right")
    {
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < coordinate.size(); k++)
                if(headLocation.getY()+j == coordinate[k].getY() && headLocation.getX() == coordinate[k].getX())
                    return true;
    }
    else if(lastDirection == "left")
    {
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < coordinate.size(); k++)
                if(headLocation.getY()-j == coordinate[k].getY() && headLocation.getX() == coordinate[k].getX())
                    return true;
    }
    else if(lastDirection == "up")
    {
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < coordinate.size(); k++)
                if(headLocation.getY() == coordinate[k].getY() && headLocation.getX()-j == coordinate[k].getX())
                    return true;
    }
    else if(lastDirection == "down")
    {
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < coordinate.size(); k++)
                if(headLocation.getY() == coordinate[k].getY() && headLocation.getX()+j == coordinate[k].getX())
                    return true;
    }

}

//check if snake is on a path to collide with a wall soon
bool snake::checkForUpcomingWallCollision()
{
    if(lastDirection == "right")
    {
        for(int j = 0; j < 3; j++)
            if(headLocation.getY()+j == 69)
                    return true;
    }
    else if(lastDirection == "left")
    {
        for(int j = 0; j < 3; j++)
                if(headLocation.getY()-j == 0)
                    return true;
    }
    else if(lastDirection == "up")
    {
        for(int j = 0; j < 3; j++)
        {
            if(headLocation.getX()-j == 0)
                    return true;
        }
    }
    else if(lastDirection == "down")
    {
        for(int j = 0; j < 3; j++)
                if(headLocation.getX()+j == 19)
                    return true;
    }
    return false;
}

//move the snake randomly left or right
void snake::MoveInRandomDirection()
{
    if(lastDirection == "right" || lastDirection == "left")
    {
        if(rand() % 2 == 0)
            this->moveUp();
        else
            this->moveDown();
    }
    else if(lastDirection == "up" || lastDirection == "down")
    {
        if(rand() % 2 == 0)
            this->moveRight();
        else
            this->moveLeft();
    }
}

//have the snake make a move that will result it being closer to food
void snake::MoveTowardsFood(food closeFood)
{
    bool directionNotPicked = true;

    double upDist = 0;
    double downDist = 0;
    double leftDist = 0;
    double rightDist = 0;

    orderedPair up(headLocation.getX()-1,headLocation.getY());
    orderedPair down(headLocation.getX()+1,headLocation.getY());
    orderedPair left(headLocation.getX(),headLocation.getY()-1);
    orderedPair right(headLocation.getX(),headLocation.getY()+1);

    upDist = up.calculateDistance(closeFood.getLocation());
    downDist = down.calculateDistance(closeFood.getLocation());
    leftDist = left.calculateDistance(closeFood.getLocation());
    rightDist = right.calculateDistance(closeFood.getLocation());

    //cout << upDist << " " << downDist << " " << leftDist << " " << rightDist << endl;

    while(directionNotPicked)
    {
        if(upDist-downDist <= 0 && upDist-leftDist <= 0 && upDist-rightDist <= 0)
        {
            if(lastDirection == "down")
                upDist = 9999999;
            else
            {
                directionNotPicked = false;
                this->moveUp();
            }

        }
        else if(downDist-upDist <= 0 && downDist-leftDist <= 0 && downDist-rightDist <= 0)
        {
            if(lastDirection == "up")
                downDist = 9999999;
            else
            {
                directionNotPicked = false;
                this->moveDown();
            }

        }
        else if(leftDist-upDist <= 0 && leftDist-downDist <= 0 && leftDist-rightDist <= 0)
        {
            if(lastDirection == "right")
                leftDist = 9999999;
            else
            {
                directionNotPicked = false;
                this->moveLeft();
            }

        }
        else if(rightDist-upDist <= 0 && rightDist-downDist <= 0 && rightDist-leftDist <= 0)
        {
            if(lastDirection == "left")
                rightDist = 9999999;
            else
            {
                directionNotPicked = false;
                this->moveRight();
            }

        }
    }
}

//check if there is food nearby
bool snake::thereIsNearbyFood(vector<food> foodOnBoard)
{
    for(int i = 0; i < foodOnBoard.size(); i++)
        if(headLocation.calculateDistance(foodOnBoard[i].getLocation()) < 10)
            return true;
    return false;
}

//sets the member variable toAdd
void snake::setToAdd(int newAdd)
{
    toAdd = newAdd;
}

//returns the member variable toAdd
int snake::getToAdd()
{
    return toAdd;
}

//sets the character that the snake will be represented by on the board
void snake::setRepresentingCharacter(char c)
{
    representingCharacter = c;
}

//returns the character that the snake is represented by on the board
char snake::getRepresentingCharacter()
{
    return representingCharacter;
}

//sets all the coordinates of the snake
void snake::setAllCoordinates(vector<orderedPair> newCoordinates)
{
    coordinate = newCoordinates;
}

//check if the snake is being eaten
bool snake::getBeingEaten()
{
    return beingEaten;
}

//set the variable that determines if the snake is being eaten
void snake::setBeingEaten(bool newValue)
{
    beingEaten = newValue;
}

//check if a snake has collided with another snake
bool snake::checkIfCollisionWithOtherSnake(vector<snake> &snakesOnBoard, int callingSnakeIndex)
{
    for(int i = 0; i < snakesOnBoard.size(); i++)
    {
        if(i != callingSnakeIndex)
        {
            vector<orderedPair> curCoords = snakesOnBoard[i].getAllCoordinates();
            for(int j = 0; j < curCoords.size(); j++)
            {
                if(headLocation == snakesOnBoard[i].getHeadLoction())
                    snakesOnBoard.erase(snakesOnBoard.begin()+i);
                if(headLocation == curCoords[j])
                    return true;
            }
        }
    }
    return false;
}

//movement keyboard logic for the human snake
void snake::moveHumanSnakes()
{
    //Only get key from keyboard if one is being pressed
    char c = ' ';
    if(_kbhit() == 1)
    {
        c=getch();
        c=getch();
    }


    //move in the direction of the key being pressed, or continue in same direction
    switch((c)) {
        case KEY_UP:
            if(lastDirection != "down")
                this->moveUp();
            else
                this->moveDown();
            break;
        case KEY_DOWN:
            if(lastDirection != "up")
                this->moveDown();
            else
                this->moveUp();
            break;
        case KEY_LEFT:
            if(lastDirection != "right")
                this->moveLeft();
            else
                this->moveRight();
            break;
        case KEY_RIGHT:
            if(lastDirection != "left")
                this->moveRight();
            else
                this->moveLeft();
            break;
        default:
            if(lastDirection == "right")
                this->moveRight();
            else if(lastDirection == "left")
                this->moveLeft();
            else if(lastDirection == "down")
                this->moveDown();
            else if(lastDirection == "up")
                this->moveUp();
    }
}

//returns true if the current snake is a computer
bool snake::isComputer()
{
    return computer;
}
