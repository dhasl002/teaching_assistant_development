#include <iostream>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <random>
#include <math.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void printBoard(int board[][80])
{
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 80; j++)
        {
            if(board[i][j] == 0)
                cout << " ";
            else if(board[i][j] == 1)
                cout << "_";
            else if(board[i][j] == 2)
                cout << "|";
            else if(board[i][j] == 3)
                cout << "X";
            else if(board[i][j] == 4)
                cout << "O";
            if(j == 79)
                cout << endl << flush;
        }
}

void moveRight(vector<int> &xCoord, vector<int> &yCoord)
{

    for(int k = xCoord.size()-1; k > 0; k--)
    {
        xCoord[k] = xCoord[k-1];
        yCoord[k] = yCoord[k-1];
    }
    yCoord[0] = yCoord[0]+1;
}

void moveLeft(vector<int> &xCoord, vector<int> &yCoord)
{
    for(int k = xCoord.size()-1; k > 0; k--)
    {
        xCoord[k] = xCoord[k-1];
        yCoord[k] = yCoord[k-1];
    }
    yCoord[0] = yCoord[0]-1;
}

void moveUp(vector<int> &xCoord, vector<int> &yCoord)
{
    for(int k = xCoord.size()-1; k > 0; k--)
    {
        yCoord[k] = yCoord[k-1];
        xCoord[k] = xCoord[k-1];
    }
    xCoord[0] = xCoord[0]-1;
}

void moveDown(vector<int> &xCoord, vector<int> &yCoord)
{
    for(int k = xCoord.size()-1; k > 0; k--)
    {
        yCoord[k] = yCoord[k-1];
        xCoord[k] = xCoord[k-1];
    }
    xCoord[0] = xCoord[0]+1;
}

void getKeyPressed(vector<int> &xCoord, vector<int> &yCoord, bool &first, int &last)
{
    //Only get key from keyboard if one is being pressed
    char c = ' ';
    if(first == false)
    {
        if(_kbhit() == 1)
        {
            c=getch();
            c=getch();
        }
    }
    first = false;

    //move in the direction of the key being pressed, or continue in same direction
    switch((c)) {
        case KEY_UP:
            if(last != 2)
            {
                moveUp(xCoord, yCoord);
                last = 3;
            }
            else
                moveDown(xCoord, yCoord);
            break;
        case KEY_DOWN:
            if(last != 3)
            {
                moveDown(xCoord, yCoord);
                last = 2;
            }
            else
                moveUp(xCoord, yCoord);
            break;
        case KEY_LEFT:
            if(last != 0)
            {
                moveLeft(xCoord, yCoord);
                last = 1;
            }
            else
                moveRight(xCoord, yCoord);
            break;
        case KEY_RIGHT:
            if(last != 1)
            {
                moveRight(xCoord, yCoord);
                last = 0;
            }
            else
                moveLeft(xCoord, yCoord);
            break;
        default:
            switch(last)
            {
            case 0:
                moveRight(xCoord, yCoord);
                break;
            case 1:
                moveLeft(xCoord, yCoord);
                break;
            case 2:
                moveDown(xCoord, yCoord);
                break;
            case 3:
                moveUp(xCoord, yCoord);
                break;
            }
            break;
    }
}

void constructBoard(const int xLength, const int yLength, int foodX, int foodY, int (&board)[20][80], vector<int> xCoord, vector<int> yCoord)
{
    for(int i = 0; i < xLength; i++)
        for(int j = 0; j < yLength; j++)
        {
            if(i == 0 || i == 19)
                board[i][j] = 1;
            else if(j == 0 || j == 79)
                board[i][j] = 2;
            else if(i == foodX && j == foodY)
                board[i][j] = 4;
            else
                board[i][j] = 0;

            for(int k = 0; k < xCoord.size(); k++)
                if(xCoord[k] == i && yCoord[k] == j)
                {
                    board[i][j] = 3;
                }
        }
}

void checkCollision(vector<int> xCoord, vector<int> yCoord, bool &endGame)
{
    if(xCoord[0] == 0 || xCoord[0] == 19 || yCoord[0] == 0 || yCoord[0] == 79)
    {
        cout << "GAME OVER" << endl;
        endGame = true;
    }
    for(int i = 1; i < xCoord.size(); i++)
    {
        if(xCoord[0] == xCoord[i] && yCoord[0] == yCoord[i])
        {
            cout << "GAME OVER" << endl;
            endGame = true;
        }
    }
}

void placeFood(int &foodX, int &foodY, const int xLength, const int yLength, bool &foodSpaceOpen, vector<int> xCoord, vector<int> yCoord)
{
    while(foodSpaceOpen)
    {
        foodX = rand()%xLength;
        foodY = rand()%yLength;
        for(int i = 0; i < xCoord.size(); i++)
        {
            if(!(xCoord[i] == foodX && yCoord[i] == foodY))
                foodSpaceOpen = false;
        }
    }
}

void foodEaten(int foodX, int foodY,  vector<int> &xCoord, vector<int> &yCoord, bool &foodSpaceOpen, bool &startCounting, int &it)
{
    if(xCoord[0] == foodX && yCoord[0] == foodY)
    {
        foodSpaceOpen = true;
        it = 0;
        startCounting = true;
    }
    if(startCounting)
        it++;
    //wait three steps before adding
    if(it > 0)
    {
        if(it == 3)
        {
            startCounting = false;
            it = 0;
        }
        //lengthen snake
        if(abs(xCoord[xCoord.size()-1]-xCoord[xCoord.size()-2]) == 1)
        {
            yCoord.push_back(yCoord[yCoord.size()-1]);
            if(xCoord[xCoord.size()-2]-xCoord[xCoord.size()-1] == 1)
                xCoord.push_back(xCoord[xCoord.size()-1]-1);
            else if(xCoord[xCoord.size()-2]-xCoord[xCoord.size()-1] == -1)
                xCoord.push_back(xCoord[xCoord.size()-1]+1);
        }
        else if(abs(yCoord[yCoord.size()-1]-yCoord[yCoord.size()-2]) == 1)
        {
            xCoord.push_back(xCoord[xCoord.size()-1]);
            if(yCoord[yCoord.size()-2]-yCoord[yCoord.size()-1] == 1)
                yCoord.push_back(yCoord[yCoord.size()-1]-1);
            else if(yCoord[yCoord.size()-2]-yCoord[yCoord.size()-1] == -1)
                yCoord.push_back(yCoord[yCoord.size()-1]+1);
        }
    }
}

int main()
{
    const int xLength = 20;
    const int yLength = 80;
    int c = KEY_RIGHT;
    int last = 0;
    bool first = true;
    bool endGame = false;
    int foodX = 0;
    int foodY = 0;
    bool foodSpaceOpen = true;
    int it = 0;
    bool startCounting = false;
    vector<int> xCoord;
    vector<int> yCoord;
    int board[xLength][yLength];

    //initialize snake to center of screen
    xCoord.push_back(10);
    yCoord.push_back(42);
    xCoord.push_back(10);
    yCoord.push_back(41);
    xCoord.push_back(10);
    yCoord.push_back(40);
    xCoord.push_back(10);
    yCoord.push_back(39);
    xCoord.push_back(10);
    yCoord.push_back(38);

    while(true)
    {
        //place "food" in random location
        placeFood(foodX, foodY, xLength, yLength, foodSpaceOpen, xCoord, yCoord);
        //if eaten, make snake longer
        foodEaten(foodX, foodY, xCoord, yCoord, foodSpaceOpen, startCounting, it);
        //check for collision
        checkCollision(xCoord, yCoord, endGame);
        //end game if collision was detected
        if(endGame)
            break;
        //edits board array based on what the board should look like after a step in time
        constructBoard(xLength, yLength, foodX, foodY, board, xCoord, yCoord);
        //prints the board to the screen
        printBoard(board);
        //wait 50 miliseconds so that you can actually tell what is happening
        Sleep(50);
        //clear the console
        system("cls");
        //get input from user
        getKeyPressed(xCoord, yCoord, first, last);
    }

    return 0;
}
