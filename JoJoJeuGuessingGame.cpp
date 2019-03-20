#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getGuess(int guessCount, int target)
{

    int guess;
    bool check = true;

    while (check)
    {
        cout << "What is your guess? (" << guessCount << " tries left)";

        cin >> guess;
        if (cin.fail())
        {

            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input, try again.\n";
        }
        else if (guess < 1 || guess > 100)
        {

            cin.clear();
            cin.ignore();
            cout << "Guess out of bounds, try again.\n";
        }
        else if (guess >= 1 && guess <= 100)
        {

            if (guess == target)
            {
                cout << "You guessed correctly in " << 11 - guessCount << " tries!\n";
            }
            else if (guess < target)
            {
                cout << "Your guess is too small! (" << guessCount << " tries left)\n";
            }
            else if (guess > target)
            {
                cout << "Your guess is too big! (" << guessCount << " tries left)\n";
            }
            check = false;
        }
    }

    return guess;
}

int main()
{
    srand(time(0));
    int target = rand() % 100;
    int guessCount = 10;
    for (int i = 10; i > 0; i--)
    {
        int guess = getGuess(guessCount, target);
        if (guess == target)
        {
            break;
        }
        guessCount--;
    }
    if (guessCount == 0)
    {
        cout << "You lose!\n";
    }
}
