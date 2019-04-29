#define SIZE 7
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

    bool fileRead = getRecordsFromFile("newdata.txt", recordDataArray);

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
