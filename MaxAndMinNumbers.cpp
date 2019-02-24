/*
MAX AND MIN
LINCOLN BARTLETT

Write a program whose inputs are three integers, 
and whose outputs are the largest of the three values 
and the smallest of the three values.

*/

#include <iostream>
using namespace std;

int LargestNumber(int num1, int num2, int num3);
int SmallestNumber(int num1, int num2, int num3);

int main()
{
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    cout << "largest: " << LargestNumber(num1, num2, num3) << endl;
    cout << "smallest: " << SmallestNumber(num1, num2, num3) << endl;
    return 0;
}

int LargestNumber(int num1, int num2, int num3)
{
    if (num1 > num2 && num1 > num3)
    {
        return num1;
    }

    if (num2 > num1 && num2 > num3)
    {
        return num2;
    }

    if (num3 > num1 && num3 > num2)
    {
        return num3;
    }
    return 0;
}
int SmallestNumber(int num1, int num2, int num3)
{
    if (num1 < num2 && num1 < num3)
    {
        return num1;
    }

    if (num2 < num1 && num2 < num3)
    {
        return num2;
    }

    if (num3 < num1 && num3 < num2)
    {
        return num3;
    }
    return 0;
}
