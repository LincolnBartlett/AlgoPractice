#include <iostream>
using namespace std;
const int SIZE = 5;
void reverse(int *pointer)
{
    int copy[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        copy[i] = pointer[SIZE - i - 1];
    }

    for (int i = 0; i < SIZE; i++)
    {
        pointer[i] = copy[i];
    }
}
void shiftRight(int *dataPointer)
{
    int save = *(dataPointer + SIZE - 1);
    int *shiftpointer = dataPointer;
    for (int i = 0; i < SIZE - 1; i++)
    {
        *(dataPointer + i + 1) = *(shiftpointer + i);
        cout << *(dataPointer + i + 1) << " " << *(shiftpointer + i);
    }
    *dataPointer = save;
}
int main()
{

    int data[SIZE];
    int *dataPointer = data;

    for (int i = 0; i < SIZE; i++)
    {

        cin >> data[i];
    }

    cout << "The Original Array" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i] << endl;
    }
    reverse(dataPointer);
    cout << "The Reversed Array " << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << *(dataPointer + i) << endl;
    }
    shiftRight(dataPointer);
    cout << "The Shifted Array " << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << dataPointer[i] << endl;
    }
}