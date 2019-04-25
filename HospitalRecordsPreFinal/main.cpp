#include <iostream>
#include <iomanip>
#include "hospital.h"
#include <vector>

using namespace std;

int main()
{
    Record recordDataArray[SIZE];
    vector<Record> vectorData;
    char character = ' ';

    int size = readDataFromFile("hospitaldata.txt", recordDataArray);
    if (size < 0)
    {
        cout << "File Open Error";
        exit(-1);
    }
    else if (size == 0)
    {
        cout << "Empty File" << endl;
    }

    else
    {
        bubbleSort(recordDataArray, size);
        printData(recordDataArray, size - 1);

        auto vectorStart = vectorData.begin();

        vectorData.insert(vectorStart, recordDataArray, recordDataArray + size - 1);

        for (int i = 0; i < vectorData.size(); i++)
            while (character != 'q')
            {
                character = printMenu(vectorData);
            }

        cout << "Good bye!" << endl;
    }
}