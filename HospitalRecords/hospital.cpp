#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "hospital.h"

int main()
{

    Record Patients[SIZE];

    getRecordsFromFile(Patients);
    if (!getRecordsFromFile(Patients))
    {
        cout << "Error!\n";
        return 1;
    }
    sortRecordsByPatientID(Patients);
    printBanner(Patients);
}
