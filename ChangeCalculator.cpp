/*
CHANGE CALCULATOR
Lincoln Bartlett

Write a program that calculates number of coins for a given positive cash amount in pennies. 

So if you input 59, then the output would look like:

59 has 2 quarters, 0 dimes, 1 nickels, 4 pennies

*/
#include <iostream>
using namespace std;

int quarters(int &cash)
{
    int mod;
    int answer;

    mod = cash % 25;
    answer = (cash - mod) / 25;

    return answer;
}

int dimes(int &cash)
{
    int mod;
    int answer;

    mod = cash % 10;
    answer = (cash - mod) / 10;

    return answer;
}

int nickels(int &cash)
{
    int mod;
    int answer;

    mod = cash % 5;
    answer = (cash - mod) / 5;

    return answer;
}

int pennies(int &cash)
{
    int mod;
    int answer;

    mod = cash % 1;
    answer = cash - mod;

    return answer;
}

void calculateChange(int &cash)
{
    if (cash <= 0)
    {
        cout << "Sorry no change to give " << endl;
    }
    else
    {
        int minusquarters;
        int minusdimes;
        int minusnickels;
        int minuspennies;
        int newamount;

        minusquarters = quarters(cash);
        newamount = cash - (minusquarters * 25);
        minusdimes = dimes(newamount);
        newamount = newamount - (minusdimes * 10);
        minusnickels = nickels(newamount);
        newamount = newamount - (minusnickels * 5);
        minuspennies = pennies(newamount);

        cout << cash << " has ";
        cout << minusquarters << " quarters, ";
        cout << minusdimes << " dimes, ";
        cout << minusnickels << " nickels, ";
        cout << minuspennies << " pennies" << endl;
    }
}

int main()
{
    int cash;
    cout << "Please enter the cash for change ";
    cin >> cash;
    calculateChange(cash);
}
