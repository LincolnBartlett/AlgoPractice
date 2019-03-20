#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void ReadFile(int magicsquareArray[7][7], ifstream &magicSquare)
{

    if (magicSquare.is_open())
    {
        for (int i = 0; i < 7; i++)
        {
            //cout << endl;
            for (int j = 0; j < 7; j++)
            {
                string textnum;
                int num = 0;

                magicSquare >> textnum;
                num = stoi(textnum);
                magicsquareArray[i][j] = num;
                //cout << setw(2) << magicsquareArray[i][j] << " ";
            }
        }
    }

    else
        cout << "Unable to open file";
}

bool SumOfColumns(int magicsquareArray[7][7], string &sums)
{
    int sumArray[7];
    bool magictest = false;

    for (int i = 0; i < 7; i++)
    {
        int sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum += magicsquareArray[i][j];
        }
        sumArray[i] = sum;
    }
    for (int i = 0; i < 7; i++)
    {
        sums += to_string(sumArray[i]) + " ";
    }
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        if (sumArray[i] == sumArray[0])
        {
            magictest = true;
        }
    }

    return magictest;
}
bool SumOfColumns(int magicsquareArray[7][7])
{
    int sumArray[7];
    bool magictest = false;

    for (int i = 0; i < 7; i++)
    {
        int sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum += magicsquareArray[i][j];
        }
        sumArray[i] = sum;
    }

    for (int i = 0; i < 7; i++)
    {
        if (sumArray[i] == sumArray[0])
        {
            magictest = true;
        }
    }

    return magictest;
}

bool SumOfRows(int magicsquareArray[7][7], string &sums)
{
    int sumArray[7];
    bool magictest = false;

    for (int i = 0; i < 7; i++)
    {
        int sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum += magicsquareArray[j][i];
        }
        sumArray[i] = sum;
    }
    for (int i = 0; i < 7; i++)
    {
        sums += to_string(sumArray[i]) + " ";
    }
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        if (sumArray[i] == sumArray[0])
        {
            magictest = true;
        }
    }

    return magictest;
}
bool SumOfRows(int magicsquareArray[7][7])
{
    int sumArray[7];
    bool magictest = false;

    for (int i = 0; i < 7; i++)
    {
        int sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum += magicsquareArray[j][i];
        }
        sumArray[i] = sum;
    }

    for (int i = 0; i < 7; i++)
    {
        if (sumArray[i] == sumArray[0])
        {
            magictest = true;
        }
    }

    return magictest;
}

int sumOfDiagonal(int magicsquareArray[7][7])
{
    int answer = 0;
    for (int i = 0; i < 7; i++)
    {
        answer += magicsquareArray[i][i];
    }
    return answer;
}

int SumOfReverseDiagonal(int magicsquareArray[7][7])
{
    int answer = 0;
    int down = 6;
    for (int i = 0; i < 7; i++)
    {
        answer += magicsquareArray[down][i];
        down--;
    }
    return answer;
}
bool isMagicSquare(int magicsquareArray[7][7])
{
    if (SumOfColumns(magicsquareArray) && SumOfRows(magicsquareArray) && sumOfDiagonal(magicsquareArray) == SumOfReverseDiagonal(magicsquareArray))
    {
        return true;
    }

    return false;
}
void formatOutput(int magicsquareArray[7][7], int &count)
{

    string columnSums = "";
    string rowSums = "";
    int diagSums = sumOfDiagonal(magicsquareArray);
    int revDiagSums = SumOfReverseDiagonal(magicsquareArray);

    SumOfColumns(magicsquareArray, columnSums);
    SumOfRows(magicsquareArray, rowSums);

    cout << "Matrix #" << count << "...\n"
         << "Column Sum:\n"
         << columnSums
         << "\nRow Sum:\n"
         << rowSums
         << "\nDiagonal Sum:\n"
         << diagSums
         << "\nReverse Diagonal Sum:\n"
         << revDiagSums
         << endl;

    if (isMagicSquare(magicsquareArray))
    {
        cout << "\nThe first matrix is a magic square!";
    }
    else
    {
        cout << "\nThe second matrix is not a magic square.";
    }

    count += 1;
}

int main()
{
    int count = 1;
    ifstream magicSquare("360magicText.txt");

    int magicsquareArrayOne[7][7];
    int magicsquareArrayTwo[7][7];

    ReadFile(magicsquareArrayOne, magicSquare);
    formatOutput(magicsquareArrayOne, count);

    ReadFile(magicsquareArrayTwo, magicSquare);
    formatOutput(magicsquareArrayTwo, count);

    magicSquare.close();
}
