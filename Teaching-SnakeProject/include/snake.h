#ifndef SNAKE_H
#define SNAKE_H
#include "orderedPair.h"
#include "food.h"
#include <vector>
#include <string>
using namespace std;
class food;

class snake
{
    public:
        snake();
        snake(orderedPair head);
        snake(orderedPair head, bool isAComputer);

        vector<orderedPair> getAllCoordinates();
        void setAllCoordinates(vector<orderedPair> newCoordinates);
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        orderedPair getHeadLoction();
        void addToSnake();
        bool checkIfCollisionWithWall();
        bool checkIfCollisionWithSelf();
        bool checkIfCollisionWithOtherSnake(vector<snake> &snakesOnBoard, int callingSnakeIndex);
        void decideNextMovement(vector<snake> snakesOnBoard, vector<food> foodOnBoard);
        void continueStrait();
        bool checkForUpcomingCollision();
        bool checkForUpcomingWallCollision();
        void MoveInRandomDirection();
        void MoveTowardsFood(food closeFood);
        bool thereIsNearbyFood(vector<food> foodOnBoard);
        void setToAdd(int newAdd);
        int getToAdd();
        bool checkForCollisionWithSelf();
        void setRepresentingCharacter(char c);
        char getRepresentingCharacter();
        bool getBeingEaten();
        void setBeingEaten(bool newValue);
        bool isComputer();
        void moveHumanSnakes();


    private:
        vector<orderedPair> coordinate; //all the coordinates of the snake
        bool computer; //if the snake is a computer this variable is true
        orderedPair headLocation; //the ordered pair representing the head location of the snake
        string lastDirection; //the last direction the snake has traveled
        int toAdd; //how many links are left to be added to the snake
        char representingCharacter; //the character representing the snake on the board
        bool beingEaten; //if the snake is being eaten, this variable is true
};

#endif // SNAKE_H
