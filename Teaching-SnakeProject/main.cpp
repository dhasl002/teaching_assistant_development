#include <iostream>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <conio.h>
#include <windows.h>
#include "food.h"
#include "Board.h"
#include "snake.h"
#include "orderedPair.h"

using namespace std;

int main()
{
    //creat board
    Board mainBoard;

    //create snakes
    snake s1(orderedPair(5,20));
    snake s2(orderedPair(10,35));
    snake s3(orderedPair(15,43));
    snake s4(orderedPair(16,10));
    snake s5(orderedPair(5,58));
    snake s6(orderedPair(10,62));
    snake s7(orderedPair(17,55));
    snake s8(orderedPair(5,5));
    snake s9(orderedPair(11,10));
    snake s10(orderedPair(3,65), false);

    //cerate food
    for(int i = 0; i < 10; i++)
        mainBoard.addFood(food(rand() % 11 + 5, rand() % 61 + 5));

    //add snakes to board
    mainBoard.addSnake(s1);
    mainBoard.addSnake(s2);
    mainBoard.addSnake(s3);
    mainBoard.addSnake(s4);
    mainBoard.addSnake(s5);
    mainBoard.addSnake(s6);
    mainBoard.addSnake(s7);
    mainBoard.addSnake(s8);
    mainBoard.addSnake(s9);
    mainBoard.addSnake(s10);

    //sets the representing character for each snake
    mainBoard.setRepresentingCharacters();

    //start simulation
    while(true)
    {
        //mainBoard.chopSnakes();
        mainBoard.lengthenSnakes();
        mainBoard.moveSnakes();
        mainBoard.updateFood();
        mainBoard.DeleteDeadSnakes();
        mainBoard.updateBoard();
        mainBoard.printBoard();
        Sleep(500);
        system("cls");
    }

    return 0;
}
