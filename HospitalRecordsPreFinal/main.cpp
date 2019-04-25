#include <iostream>
#include <iomanip>
#include "hospital.h"
#include <vector>

using namespace std;

int main()
{
    Record recordDataArray[SIZE];
    char ch = ' ';

    int size = readDataFromFile("hospitaldata.txt", recordDataArray);
    if (size < 0)
    {
        cout << "File Open Error";
        exit(-1);
    }
    else if (size == 0)
        cout << "Empty File" << endl;
    else
    {
        bubbleSort(recordDataArray, size);
        printData(recordDataArray, size - 1);


        vector<Record> vectorData;
        auto it = vectorData.begin();
        vectorData.insert(it, recordDataArray, recordDataArray + size - 1);
        for (int i = 0; i < vectorData.size(); i++)
            while (ch != 'q')
                ch = printMenu(vectorData);
        cout << "Good bye!" << endl;
    }
}