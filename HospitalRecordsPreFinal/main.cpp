#define SIZE 4
#include <iostream>
#include <iomanip>
#include "hospital.h"
#include <vector>

using namespace std;

int main()
{

    Record recordDataArray[SIZE];
    vector<Record> recordDataVector;
    char character = ' ';

    bool fileRead = getRecordsFromFile("hospitaldata.txt", recordDataArray);

    if (fileRead)
    {
        bubbleSort(recordDataArray, SIZE);
        printData(recordDataArray, SIZE);
        recordDataVector.insert(recordDataVector.begin(), recordDataArray, recordDataArray + SIZE - 1);

        while (character != 'q')
        {
            character = printMenu(recordDataVector);
        }

        cout << "Good bye!" << endl;
    }
}