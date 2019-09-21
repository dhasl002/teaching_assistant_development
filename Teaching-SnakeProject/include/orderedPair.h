#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H


class orderedPair
{
    public:
        orderedPair();
        orderedPair(int newX, int newY);
        int getX() {return x;}
        int getY() {return y;}
        void setX(int newX) {x = newX;}
        void setY(int newY) {y = newY;}

        bool operator==(orderedPair coordinate);
        void operator=(orderedPair coordinate);
        double calculateDistance(orderedPair coordinate);

    private:
        int x; //x coordinate in an ordered pair
        int y; //y coordinate in an ordered pair
};

orderedPair generatePairToLeft(orderedPair coordinate);

#endif // ORDEREDPAIR_H
