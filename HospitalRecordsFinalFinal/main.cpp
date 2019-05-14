#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Hospital.h"
#include "Helper.h"
#include <vector>

int main()
{
    vector<Record> dataVector;
    char character = ' ';
    bool fileRead = getRecordsFromFile("data.txt", dataVector);

    if (fileRead)
    {
        bubbleSort(dataVector);
        displayData(dataVector);

        while (character != 'q')
        {
            character = printMenu(dataVector);
        }

        cout << "Good bye!" << endl;
    }
}
