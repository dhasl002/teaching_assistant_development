#include "orderedPair.h"
#include <math.h>

//default constructor for ordered pair
orderedPair::orderedPair()
{
    x = 0;
    y = 0;
}

//given an x and y coordinate, this constructor creates that ordered pair
orderedPair::orderedPair(int newX, int newY)
{
    x = newX;
    y = newY;
}

//given an ordered pair, a new ordered pair is generated one to the left
orderedPair generatePairToLeft(orderedPair coordinate)
{
    return orderedPair(coordinate.getX(), coordinate.getY()-1);
}

//overloaded operator for comparing if two coordinates are equal
bool orderedPair::operator==(orderedPair coordinate)
{
    if(x == coordinate.getX() && y == coordinate.getY())
        return true;
    else
        return false;
}

//overloaded operator for setting one ordered pair to another
void orderedPair::operator=(orderedPair coordinate)
{
    x = coordinate.getX();
    y = coordinate.getY();
}

//calculates euclidean distance of two coordinates
double orderedPair::calculateDistance(orderedPair coordinate)
{
    return (sqrt(pow(y-coordinate.getY(),2)+pow(x-coordinate.getX(),2)));
}
