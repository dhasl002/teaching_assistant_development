#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// check if a certain position on the board is occupied by a human or computer piece
string checkPos(int x, int y, int human[][6])
{
    string str = "";
    if(human[x][y] == 1)
        str = "O";
    else if(human[x][y] == 2)
        str = "X";
    else
        str = " ";

    return str;
}

//print board according to human and computer arrays indicating positions on the board
void printBoard(int human[][6], int computer[][6])
{
    cout << "\n";
    cout << "   ___ ___ ___ ___ ___ ___ " << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "5 | " << checkPos(0, 5, human) << " | " << checkPos(1, 5, human) <<" | " << checkPos(2, 5, human) << " | " << checkPos(3, 5, human) << " | " << checkPos(4, 5, human) << " | " <<  checkPos(5, 5, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "4 | " <<  checkPos(0, 4, human) << " | " << checkPos(1, 4, human) << " | " << checkPos(2, 4, human) << " | " << checkPos(3, 4, human) << " | " << checkPos(4, 4, human) << " | " << checkPos(5, 4, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "3 | " << checkPos(0, 3, human) << " | " <<  checkPos(1, 3, human) << " | " << checkPos(2, 3, human) << " | " <<  checkPos(3, 3, human) << " | " << checkPos(4, 3, human) << " | " <<  checkPos(5, 3, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "2 | " <<  checkPos(0, 2, human) << " | " << checkPos(1, 2, human) << " | " <<  checkPos(2, 2, human) << " | " << checkPos(3, 2, human) << " | " <<  checkPos(4, 2, human) << " | " << checkPos(5, 2, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "1 | " << checkPos(0, 1, human) << " | " <<  checkPos(1, 1, human) << " | " << checkPos(2, 1, human) << " | " << checkPos(3, 1, human) << " | " << checkPos(4, 1, human) << " | " <<  checkPos(5, 1, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "  |   |   |   |   |   |   |" << endl;
    cout << "0 | " << checkPos(0, 0, human) << " | " << checkPos(1, 0, human) << " | " <<  checkPos(2, 0, human) << " | " << checkPos(3, 0, human) << " | " <<  checkPos(4, 0, human) << " | " << checkPos(5, 0, human) << " |" << endl;
    cout << "  |___|___|___|___|___|___|" << endl;
    cout << "    0   1   2   3   4   5   \n" << endl;
}

void initializePieces(int human[][6], int computer[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            human[i][j] = 0;
            computer[i][j] = 0;
        }
}

void playGame(int human[][6], int computer[][6])
{
    int x = 0;
    int y = 0;
    int x2 = 0;
    int y2 = 0;
    int tmp = 0;
    int humanPoints = 0;
    int computerPoints = 0;
    bool gameOver = false;


    cout << "WELCOME TO MODIFIED BATTLESHIP \n" << endl;

    ///Human places ships
    //first ship placement
    do{
        //first coordinate of first ship
        do{
            cout << "Player, please place your first ship of length 2" << endl;
            cout << "Enter the coordinates of the front of the ship (ex: 1 3)" << endl;
            cin >> x >> y;
            if(x > 5 || x < 0 || y > 5 || y < 0) //check that coordinates are in grid
                cout << "Invalid Entry! Coordinates must be between 0 and 5" << endl;
        }while(x > 5 || x < 0 || y > 5 || y < 0); //if coordinates are invalid have user select placement again

        //second coordinate of first ship
        do{
            cout << "Enter the coordinates of the end of the ship (ex: 1 3)" << endl;
            cin >> x2 >> y2;
            if(x2 > 5 || x2 < 0 || y2 > 5 || y2 < 0) //check that coordinates are in grid
                cout << "Invalid Entry! Coordinates must be between 0 and 5" << endl;
        }while(x2 > 5 || x2 < 0 || y2 > 5 || y2 < 0);

        if(abs(x-x2)+abs(y-y2) != 1) //check that coordinates are valid (ship is actually 2 long and not diagonal)
            cout << "Invalid placement! (ships cannot be placed diagonally) \n" << endl;
        else //actually place the ships
        {
            human[x][y] = 1;
            human[x2][y2] = 1;
        }
    }while(abs(x-x2)+abs(y-y2) != 1);

    //second ship placement
    do{
        //first coordinate of second ship
        do{
            cout << "\n\nPlayer, please place your second ship of length 2" << endl;
            cout << "Enter the coordinates of the front of the ship (ex: 1 3)" << endl;
            cin >> x >> y;
            if(x > 5 || x < 0 || y > 5 || y < 0) //check that coordinates are in grid
                cout << "Invalid Entry! Coordinates must be between 0 and 5" << endl;
        }while(x > 5 || x < 0 || y > 5 || y < 0); //if coordinates are invalid have user select placement again

        //second coordinate of second ship
        do{
            cout << "Enter the coordinates of the end of the ship (ex: 1 3)" << endl;
            cin >> x2 >> y2;
            if(x2 > 5 || x2 < 0 || y2 > 5 || y2 < 0) ///check that coordinates are in grid
                cout << "Invalid Entry! Coordinates must be between 0 and 5" << endl;
        }while(x2 > 5 || x2 < 0 || y2 > 5 || y2 < 0); //if coordinates are invalid have user select placement again

        if(abs(x-x2)+abs(y-y2) != 1 || human[x][y] == 1 || human[x2][y2] == 1) //ship placement is valid and is not on top of first ship
            cout << "Invalid placement! (ships cannot be placed diagonally or on top of first ship) \n" << endl;
        else
        {
            human[x][y] = 1;
            human[x2][y2] = 1;
        }
    }while(abs(x-x2)+abs(y-y2) != 1);

    printBoard(human, computer);

    ///Computer places ships
    for(int i = 0; i < 2; i++)
    {
        //select first position
        do{
            x = rand() % 6;
            y = rand() % 6;
        }while(computer[x][y] == 1); //ensure that we are not placing a ship on top of a ship

        //select second position
        do{
            //ensure that we are not placing the sip outside the board
            do{
                tmp = rand() % 4;
                if(tmp == 0 && x+1 < 6)
                {
                    x2 = x+1;
                    y2 = y;
                }
                else if (tmp  == 1 && x-1 > -1)
                {
                    x2 = x-1;
                    y2 = y;
                }
                else if(tmp == 2 && y+1 < 6)
                {
                    x2 = x;
                    y2 = y+1;
                }
                else if(tmp == 3 && y-1 > -1)
                {
                    x2 = x;
                    y2 = y-1;
                }
                else
                    tmp = -1;
            }while(tmp == -1); //ensure that we actually place ship if all if statements are false
        }while(computer[x2][y2] == 1); //ensure that we are not placing a ship on top of a ship

        computer[x][y] = 1;
        computer[x2][y2] = 1;
    }
    cout << "Computer has placed his ships randomly\n" << endl;

    ///Players Attack
    while(gameOver == false)
    {
        //human's turn
        cout << "Player, enter the position you would like to attack (ex: 1 1)\n" << endl;
        cin >> x >> y;
        //check if hit or miss
        if(computer[x][y] == 1)
        {
            cout << "HIT!\n" << endl;
            humanPoints++;
        }
        else
            cout << "Miss...\n" << endl;

        if(humanPoints >= 4)
        {
            cout << "YOU WIN!!!\n" << endl;
            gameOver = true;
            break;
        }

        //computer's turn
        x = rand() % 6;
        y = rand() % 6;
        cout << "Computer has attacked position " << x << " " << y << endl;
        //check if hit or miss
        if(human[x][y] == 1)
        {
            cout << "HIT!\n" << endl;
            human[x][y] = 2;
            computerPoints++;
            printBoard(human, computer);
        }
        else
            cout << "Miss...\n" << endl;

        if(computerPoints >= 4)
        {
            cout << "COMPUTER WINS!!!\n" << endl;
            gameOver = true;
            break;
        }
    }
}

int main()
{
    int human[6][6];
    int computer[6][6];
    initializePieces(human, computer);
    playGame(human, computer);
    return 0;
}
