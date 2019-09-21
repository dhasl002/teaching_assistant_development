#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// check if a certain position on the board is occupied by a red or black piece
string checkPos(int x, int y, int red[][6], int black[][6])
{
    string str = "";
    if(red[x][y] != 0)
        if(red[x][y] == 1)
            str = "r1";
        else
            str = "r2";
    else if(black[x][y] != 0)
        if(black[x][y] == 1)
            str = "b1";
        else
            str = "b2";
    else
        str = "  ";

    return str;
}

//print board according to red and black arrays indicating positions on the board
void printBoard(int red[][6], int black[][6])
{
    cout << "\n";
    cout << "   ____ ____ ____ ____ ____ ____ " << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "5 | " << checkPos(0, 5, red, black) << " |    | " << checkPos(2, 5, red, black) << " |    | " << checkPos(4, 5, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "4 |    | " << checkPos(1, 4, red, black) << " |    | " << checkPos(3, 4, red, black) << " |    | " << checkPos(5, 4, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "3 | " << checkPos(0, 3, red, black) << " |    | " << checkPos(2, 3, red, black) << " |    | " << checkPos(4, 3, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "2 |    | " << checkPos(1, 2, red, black) << " |    | " << checkPos(3, 2, red, black) << " |    | " << checkPos(5, 2, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "1 | " << checkPos(0, 1, red, black) << " |    | " << checkPos(2, 1, red, black) << " |    | " << checkPos(4, 1, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "0 |    | " << checkPos(1, 0, red, black) << " |    | " << checkPos(3, 0, red, black) << " |    | " << checkPos(5, 0, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "    0    1    2    3    4    5   \n" << endl;
}

void initializePieces(int red[][6], int black[][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            red[i][j] = 0;
            black[i][j] = 0;
        }
    red[0][1] = 1;
    red[1][0] = 2;
    red[2][1] = 1;
    red[3][0] = 2;
    red[4][1] = 1;
    red[5][0] = 2;

    black[0][5] = 2;
    black[1][4] = 1;
    black[2][5] = 2;
    black[3][4] = 1;
    black[4][5] = 2;
    black[5][4] = 1;

}

void playGame(int red[][6], int black[][6], int &redPoints, int &blackPoints)
{
    int x = 0;
    int y = 0;
    int newX = 0;
    int newY = 0;
    bool notValid = true;
    bool gameOver = false;

    while(gameOver == false)
    {
        bool notValid = true;
        ///RED PLAYER
        //ask red player to select piece, check if input is a valid selection
        do{
            cout << "Red Player, select the piece you would like to move(x y): ";
            cin >> x >> y;
            cout << endl;

            while(cin.fail())
            {
                cout << "Red Player: You have not entered an integer. Try Again" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> x >> y;
            }

            if(x > -1 && x < 7 && y > -1 && y < 7 && red[x][y] != 0)
                notValid = false;
            if(notValid)
                cout << "Red Player, this is not a valid piece to move!\n" << endl;

        }while(notValid);

        notValid = true;

        //ask red player to select position to move piece
        do{
            cout << "Red Player, select the place to move your piece(i.e. x y)(-1 -1 to pass): ";
            cin >> newX >> newY;
            cout << endl;
            if(newX != -1 && newY != -1)
            {
                //for moving one space
                if(red[newX][newY] == 0 && black[newX][newY] == 0 && abs(newX-x) == 1 && abs(newY-y) == 1 && newX > -1 && newY > -1 && newX < 6 && newY < 6)
                {
                    notValid = false;
                    //move red piece
                    red[newX][newY] = red[x][y];
                    red[x][y] = 0;
                }
                //for jumping, make sure that piece being jumped has the correct number and is not landing on any pieces
                else if(red[newX][newY] == 0 && black[newX][newY] == 0 && abs(newX-x) == 2 && abs(newY-y) == 2 && black[(x+newX)/2][(y+newY)/2] == red[x][y] && newX > -1 && newY > -1 && newX < 6 && newY < 6)
                {
                    notValid = false;
                    //jumped pieces are discarded from board
                    black[(x+newX)/2][(y+newY)/2] = 0;
                    redPoints++;
                    //move red piece
                    red[newX][newY] = red[x][y];
                    red[x][y] = 0;
                }
                if(notValid)
                    cout << "Red Player, this is not a valid place to move! Remember, only pieces that are numbered the same can jump each other\n" << endl;
            }
            else
                notValid = false;
        }while(notValid);

        cout << "\nRed Points: " << redPoints << endl;
        cout << "Black Points: " << blackPoints << endl;

        //check if red has won
        if(redPoints >=3)
        {
            cout << "\nGAME OVER! RED WINS!\n\n";
            gameOver = true;
            continue;
        }

        printBoard(red, black);
        notValid = true;

        ///BLACK PLAYER
        //ask black player to select piece, check if input is a valid selection
        do{
            cout << "Black Player, select the piece you would like to move(x y): ";
            cin >> x >> y;
            cout << endl;

            while(cin.fail())
            {
                cout << "Black Player: You have not entered an integer. Try Again" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> x >> y;
            }

            if(x > -1 && x < 7 && y > -1 && y < 7 && black[x][y] != 0)
                notValid = false;
            if(notValid)
                cout << "Black Player, this is not a valid piece to move!\n" << endl;

        }while(notValid);

        notValid = true;

        //ask black player to select position to move piece
        do{
            cout << "Black Player, select the place to move your piece(i.e. x y)(-1 -1 to pass): ";
            cin >> newX >> newY;
            cout << endl;
            //for passing turn
            if(newX != -1 && newY != -1)
            {
                //for moving one space
                if(black[newX][newY] == 0 && red[newX][newY] == 0 && abs(newX-x) == 1 && abs(newY-y) == 1 && newX > -1 && newY > -1 && newX < 6 && newY < 6)
                {
                    notValid = false;
                    //move red piece
                    black[newX][newY] = black[x][y];
                    black[x][y] = 0;
                }
                //for jumping, make sure that piece being jumped has the correct number and is not landing on any pieces
                else if(black[newX][newY] == 0 && red[newX][newY] == 0 && abs(newX-x) == 2 && abs(newY-y) == 2 && red[(x+newX)/2][(y+newY)/2] == black[x][y] && newX > -1 && newY > -1 && newX < 6 && newY < 6)
                {
                    notValid = false;
                    //jumped pieces are discarded from board
                    red[(x+newX)/2][(y+newY)/2] = 0;
                    blackPoints++;
                    //move red piece
                    black[newX][newY] = black[x][y];
                    black[x][y] = 0;
                }
                if(notValid)
                    cout << "Black Player, this is not a valid place to move! Remember, only pieces that are numbered the same can jump each other\n" << endl;
            }
            else
                notValid = false;
        }while(notValid);

        cout << "\nRed Points: " << redPoints << endl;
        cout << "Black Points: " << blackPoints << endl;

        //check if red has won
        if(blackPoints >= 3)
        {
            cout << "GAME OVER! BLACK WINS!\n\n";
            gameOver = true;
            continue;
        }

        printBoard(red, black);
    }
}

int main()
{
    int red[6][6];
    int black[6][6];
    int redPoints = 0;
    int blackPoints = 0;
    initializePieces(red, black);
    printBoard(red, black);
    playGame(red, black, redPoints, blackPoints);
    return 0;
}
