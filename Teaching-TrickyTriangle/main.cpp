#include <iostream>
#include <cmath>

using namespace std;

//check data structures to see if position is occupied by peg or not
string checkRow(int row, int pos, bool row0[], bool row1[], bool row2[], bool row3[], bool row4[], bool row5[], bool row6[])
{
    if(row == 0)
        if(row0[pos])
            return "o";
        else
            return " ";
    if(row == 1)
        if(row1[pos])
            return "o";
        else
            return " ";
    if(row == 2)
        if(row2[pos])
            return "o";
        else
            return " ";
    if(row == 3)
        if(row3[pos])
            return "o";
        else
            return " ";
    if(row == 4)
        if(row4[pos])
            return "o";
        else
            return " ";
    if(row == 5)
        if(row5[pos])
            return "o";
        else
            return " ";
    if(row == 6)
        if(row6[pos])
            return "o";
        else
            return " ";
}
//print board
void printBoard(bool row0[], bool row1[], bool row2[], bool row3[], bool row4[], bool row5[], bool row6[])
{
    cout << "                             /\\" << endl;
    cout << "6                           /  \\" << endl;
    cout << "                           /  " << checkRow(6, 0, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "                          /______\\" << endl;
    cout << "                         /\\\\\\\\////\\" << endl;
    cout << "5                       /  \\\\\\///  \\" << endl;
    cout << "                       /  " << checkRow(5, 0, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(5, 1, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "                      /______\\/______\\" << endl;
    cout << "                     /\\\\\\\\////\\\\\\\\////\\" << endl;
    cout << "4                   /  \\\\\\///  \\\\\\///  \\" << endl;
    cout << "                   /  " << checkRow(4, 0, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(4, 1, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(4, 2, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "                  /______\\/______\\/______\\" << endl;
    cout << "                 /\\\\\\\\////\\\\\\\\////\\\\\\\\////\\" << endl;
    cout << "3               /  \\\\\\///  \\\\\\///  \\\\\\///  \\" << endl;
    cout << "               /  " << checkRow(3, 0, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(3, 1, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(3, 2, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(3, 3, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "              /______\\/______\\/______\\/______\\" << endl;
    cout << "             /\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\" << endl;
    cout << "2           /  \\\\\\///  \\\\\\///  \\\\\\///  \\\\\\///  \\" << endl;
    cout << "           /  " << checkRow(2, 0, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(2, 1, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(2, 2, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(2, 3, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(2, 4, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "          /______\\/______\\/______\\/______\\/______\\" << endl;
    cout << "         /\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\" << endl;
    cout << "1       /  \\\\\\///  \\\\\\///  \\\\\\///  \\\\\\///  \\\\\\///  \\" << endl;
    cout << "       /  " << checkRow(1, 0, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(1, 1, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(1, 2, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(1, 3, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(1, 4, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(1, 5, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "      /______\\/______\\/______\\/______\\/______\\/______\\" << endl;
    cout << "     /\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\" << endl;
    cout << "0   /  \\\\\\///  \\\\\\///  \\\\\\///  \\\\\\///  \\\\\\///  \\\\\\///  \\" << endl;
    cout << "   /  " << checkRow(0, 0, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(0, 1, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(0, 2, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(0, 3, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(0, 4, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(0, 5, row0, row1, row2, row3, row4, row5, row6) << " \\\\//  " << checkRow(0, 6, row0, row1, row2, row3, row4, row5, row6) << " \\" << endl;
    cout << "  /______\\/______\\/______\\/______\\/______\\/______\\/______\\" << endl;
}
//checks that selection is on the board (DOES NOT LOOK AT DATA STRUCTURE POSTIONS)
bool validPegSelection(int row, int column)
{
    if(row >= 0 && row <= 6)
    {
        //check valid column
        if(row == 0 && column >= 0 && column <= 6)
            return true;
        if(row == 1 && column >= 0 && column <= 5)
            return true;
        if(row == 2 && column >= 0 && column <= 4)
            return true;
        if(row == 3 && column >= 0 && column <= 3)
            return true;
        if(row == 4 && column >= 0 && column <= 2)
            return true;
        if(row == 5 && column >= 0 && column <= 1)
            return true;
        if(row == 6 && column == 0)
            return true;
    }
    return false;
}
//removes peg based on row and column passed to function
void removePeg(int tempRow, int tempColumn, bool row0[], bool row1[], bool row2[], bool row3[], bool row4[], bool row5[], bool row6[])
{
    if(tempRow == 0 && row0[tempColumn])
        row0[tempColumn] = false;
    if(tempRow == 1 && row1[tempColumn])
        row1[tempColumn] = false;
    if(tempRow == 2 && row2[tempColumn])
        row2[tempColumn] = false;
    if(tempRow == 3 && row3[tempColumn])
        row3[tempColumn] = false;
    if(tempRow == 4 && row4[tempColumn])
        row4[tempColumn] = false;
    if(tempRow == 5 && row5[tempColumn])
        row5[tempColumn] = false;
    if(tempRow == 6 && row6[tempColumn])
        row6[tempColumn] = false;
}
//move peg from row1,column1 to row2,column2
void movePeg(int tempRow1, int tempColumn1, int tempRow2, int tempColumn2, bool row0[], bool row1[], bool row2[], bool row3[], bool row4[], bool row5[], bool row6[])
{
    //delete first peg
    removePeg(tempRow1, tempColumn1, row0, row1, row2, row3, row4, row5, row6);

    //move peg
    if(tempRow2 == 0 && !row0[tempColumn2])
        row0[tempColumn2] = true;
    if(tempRow2 == 1 && !row1[tempColumn2])
        row1[tempColumn2] = true;
    if(tempRow2 == 2 && !row2[tempColumn2])
        row2[tempColumn2] = true;
    if(tempRow2 == 3 && !row3[tempColumn2])
        row3[tempColumn2] = true;
    if(tempRow2 == 4 && !row4[tempColumn2])
        row4[tempColumn2] = true;
    if(tempRow2 == 5 && !row5[tempColumn2])
        row5[tempColumn2] = true;
    if(tempRow2 == 6 && !row6[tempColumn2])
        row6[tempColumn2] = true;
}

void playGame(bool row0[], bool row1[], bool row2[], bool row3[], bool row4[], bool row5[], bool row6[])
{
    int firstRow = 0;
    int firstColumn = 0;
    int secondRow = 0;
    int secondColumn = 0;
    int newRow = 0;
    int newColumn = 0;
    int newRow2 = 0;
    int newColumn2 = 0;
    bool valid = false;
    bool gameOver = false;

    //ask for 4 pegs to remove, check that it is valid
    for(int i = 0; i < 4; i++)
    {
        do{
            cout << "Choose a position on the board to remove a peg (i.e. \"0 6\")(\"-1 -1\" to quit)" << endl;
            cin >> firstRow >> firstColumn;
            //check that they do not want to quit
            if(firstRow != -1 && firstColumn != -1)
            {
                //check valid row
                valid = validPegSelection(firstRow, firstColumn);
                if(valid == false)
                    cout << "invalid input!!" << endl;
                else
                    removePeg(firstRow, firstColumn, row0, row1, row2, row3, row4, row5, row6);
            }
            else
            {
                i = 4;
                valid = true;
                gameOver = true;
            }
        }while(!valid);

        printBoard(row0, row1, row2, row3, row4, row5, row6);
        valid = false;
    }

    while(!gameOver)
    {
         //ask for peg to use as jump
        do{
            cout << "Choose a peg to move (i.e. \"0 6\")(\"-1 -1\" to quit)" << endl;
            cin >> newRow >> newColumn;
            if(newRow != -1 && newColumn != -1)
            {
                //check valid row
                valid = validPegSelection(newRow, newColumn);
                //check that peg actually exists in that position
                if(valid && newRow == 0 && !row0[newColumn])
                    valid = false;
                if(valid && newRow == 1 && !row1[newColumn])
                    valid = false;
                if(valid && newRow == 2 && !row2[newColumn])
                    valid = false;
                if(valid && newRow == 3 && !row3[newColumn])
                    valid = false;
                if(valid && newRow == 4 && !row4[newColumn])
                    valid = false;
                if(valid && newRow == 5 && !row5[newColumn])
                    valid = false;
                if(valid && newRow == 6 && !row6[newColumn])
                    valid = false;

                if(valid == false)
                    cout << "invalid input!!" << endl;
            }
            else
            {
                gameOver = true;
                valid = true;
            }
        }while(!valid);

        if(gameOver)
            continue;
        valid = false;

        //jumping
        for(int i = 0; i < 2; i++)
        {
            if(i != 0)
            {
                newRow = newRow2;
                newColumn = newColumn2;
            }
            //ask for jump position
            do{
                if(i == 0)
                    cout << "Choose the position of the first jump (i.e. \"0 6\")(\"-1 -1\" to quit)" << endl;
                else
                    cout << "Choose the position of the second jump (i.e. \"0 6\")(\"-1 -1\" to quit)" << endl;
                cin >> newRow2 >> newColumn2;
                if(newRow2 != -1 && newColumn2 != -1)
                {
                    //check valid row
                    valid = validPegSelection(newRow2, newColumn2);

                    //check that peg actually does not exist in that position
                    if(valid && newRow2 == 0 && row0[newColumn2])
                        valid = false;
                    if(valid && newRow2 == 1 && row1[newColumn2])
                        valid = false;
                    if(valid && newRow2 == 2 && row2[newColumn2])
                        valid = false;
                    if(valid && newRow2 == 3 && row3[newColumn2])
                        valid = false;
                    if(valid && newRow2 == 4 && row4[newColumn2])
                        valid = false;
                    if(valid && newRow2 == 5 && row5[newColumn2])
                        valid = false;
                    if(valid && newRow2 == 6 && row6[newColumn2])
                        valid = false;

                    //check that it is a valid jump
                    if(newColumn == newColumn2 && abs(newRow-newRow2) == 2)
                        valid = true;
                    else if(newRow == newRow2 && abs(newColumn-newColumn2) == 2)
                        valid = true;
                    else if(newRow != newRow2 && newColumn != newColumn2 && abs(newRow-newRow2) == 2 && abs(newColumn-newColumn2) == 2)
                        valid = true;
                    else
                        valid = false;

                    if(valid == false)
                        cout << "invalid input!!" << endl;
                    else
                    {
                        movePeg(newRow, newColumn, newRow2, newColumn2, row0, row1, row2, row3, row4, row5, row6);
                        removePeg((newRow+newRow2)/2, (newColumn+newColumn2)/2, row0, row1, row2, row3, row4, row5, row6);
                    }
                }
                else
                {
                    gameOver = true;
                    valid = true;
                }
            }while(!valid);
            if(gameOver)
                continue;
            printBoard(row0, row1, row2, row3, row4, row5, row6);
            valid = false;
        }
    }
}


int main()
{
    //initialize data structures
    bool row0[7] = {true,true,true,true,true,true,true};
    bool row1[6] = {true,true,true,true,true,true};
    bool row2[5] = {true,true,true,true,true};
    bool row3[4] = {true,true,true,true};
    bool row4[3] = {true,true,true};
    bool row5[2] = {true,true};
    bool row6[1] = {true};

    printBoard(row0, row1, row2, row3, row4, row5, row6);
    playGame(row0, row1, row2, row3, row4, row5, row6);
    return 0;
}
