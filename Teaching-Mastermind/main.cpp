#include <iostream>

using namespace std;

void playGame();

int main()
{
    playGame();
    return 0;
}

void playGame()
{
    int difficulty = 0;
    int perfectMatches = 0;
    int nonPerfectMatches = 0;

    cout << "Welcome To Modified Mastermind!" << endl;
    //enter difficulty
    cout << "Enter a difficulty (1-10)" << endl;
    cin >> difficulty;
    cout << "Difficulty = " << difficulty << "\nYou will be trying to guess " << difficulty << " numbers from 1-" << difficulty << endl;

    //create data structures after getting difficulty
    int numbersToGuess[difficulty];
    int guesses[difficulty];
    int temp[difficulty];

    //initialize data structures while creating the random pattern
    for(int i = 0; i < difficulty; i++)
    {
        numbersToGuess[i] = (rand() % difficulty) +1;
        guesses[i] = 0;
        temp[i] = numbersToGuess[i];
    }

    //now for the main part of the game where player guesses combination
    for(int i = 0; i < difficulty; i++)
    {
        cout << "Turn " << i+1 << " of 10" << endl;
        cout << "Please enter " <<  difficulty << " numbers from 1-" << difficulty << " separated by spaces:"<< endl;
        for(int j = 0; j < difficulty; j++)
            cin >> guesses[j];

        for(int j = 0; j < difficulty; j++)
        {
            if(numbersToGuess[i] == guesses[i])
                perfectMatches++;
        }
        for(int j = 0; j < difficulty; j++)
        {
            for(int k = 0; k < difficulty; k++)
            {
                if(guesses[j] == temp[k])
                {
                    nonPerfectMatches++;
                    temp[k] = 0;
                    break;
                }
            }
        }
        nonPerfectMatches = nonPerfectMatches - perfectMatches;
        cout << perfectMatches << " of your guesses are correct and in the correct position" << endl;
        cout << nonPerfectMatches << " of your guesses are correct but in the wrong position\n" << endl;

        if(perfectMatches == difficulty)
        {
            cout << "CONGRATS! You guessed the pattern!" << endl;
            break;
        }

        //fix temp since it was destroyed during turn
        for(int j = 0; j < difficulty; j++)
            temp[j] = numbersToGuess[j];

        perfectMatches = 0;
        nonPerfectMatches = 0;

        if(i == 10)
            cout << "Sorry, you did not guess the pattern" << endl;
    }


}
