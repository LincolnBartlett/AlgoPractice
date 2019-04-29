#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Record
{

    int patientNumber;
    string patientName;
    string patientId;
    long phoneNumber;
    double bill;
    Record()
    {
        patientNumber = 0;
        patientName = "";
        patientId = "";
        phoneNumber = 0;
        bill = 0;
    }
    Record(int newpatientNumber, string newpatientName, string newpatientId, long newphoneNumber, double newbill)
    {
        patientNumber = newpatientNumber;
        patientName = newpatientName;
        patientId = newpatientId;
        phoneNumber = newphoneNumber;
        bill = newbill;
    }
};

enum InsuranceType
{
    cigna,
    wha,
    mercy,
    bluecross,
    medicare,
    medical,
    sutter,
    aetna,
    unknown
};

//Data Processing Functions
bool getRecordsFromFile(string file, Record Patients[])
{
    string junk;
    ifstream records(file);

    if (records.is_open())
    {
        for (int i = 0; i < SIZE; i++)
        {
            getline(records, junk, ',');
            Patients[i].patientNumber = stoi(junk);
            getline(records, Patients[i].patientName, ',');
            getline(records, Patients[i].patientId, ',');
            records >> Patients[i].phoneNumber;
            getline(records, junk, '\n');
            Patients[i].bill = stod(junk);
        }
        records.close();
        return true;
    }
    else
    {
        return false;
    }
}

int binarySearch(vector<Record> &vectorData, int number)
{

    int bottom, top, middle;
    bottom = top = middle = 0;
    bool flag = false;
    top = vectorData.size() - 1;

    while (bottom <= top && !flag)
    {
        middle = (bottom + top) / 2;
        if (vectorData[middle].patientNumber == number)
        {
            flag = true;
            return middle;
        }
        else if (number < vectorData[middle].patientNumber)
        {
            top = middle - 1;
        }
        else
        {
            bottom = middle + 1;
        }
    }
    return -1;
}

void bubbleSort(Record myArray[], int size)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
            if (myArray[i].patientNumber > myArray[i + 1].patientNumber)
            {
                Record temp = myArray[i];
                myArray[i] = myArray[i + 1];
                myArray[i + 1] = temp;
                swap = true;
            }
        size--;
    }
}

void bubbleSortVector(vector<Record> &vectorData)
{
    bool swap = true;
    int size = vectorData.size();
    while (swap)
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
            if (vectorData[i].patientNumber > vectorData[i + 1].patientNumber)
            {
                Record temp = vectorData[i];
                vectorData[i] = vectorData[i + 1];
                vectorData[i + 1] = temp;
                swap = true;
            }
        size--;
    }
}

int getPhonePrefix(long number)
{
    return (number / 10000) % 1000;
}
//UI Components
void printBanner()
{
    cout << endl
         << "    WELCOME TO AMERICAN HEALTH SERVICES DATA MANAGEMENT" << endl
         << endl;
    cout << setw(10) << left << "Number" << setw(20) << left << "Patient Name" << setw(20) << left << "Patient Id " << setw(10) << "Prefix " << setw(10) << "Patient Dues" << endl;
}

void displayData(vector<Record> &vectorData)
{
    printBanner();
    int size = vectorData.size();
    for (int i = 0; i < size; i++)
    {
        int prefix = getPhonePrefix(vectorData[i].phoneNumber);
        cout << setw(10) << vectorData[i].patientNumber << setw(20) << left << vectorData[i].patientName << setw(20) << left << vectorData[i].patientId << setw(10)
             << prefix << setw(10) << fixed << setprecision(2) << vectorData[i].bill << endl;
    }
}

void printData(Record dataArray[], int size)
{
    printBanner();
    for (int i = 0; i < size; i++)
    {
        int prefix = getPhonePrefix(dataArray[i].phoneNumber);
        cout << setw(10) << dataArray[i].patientNumber << setw(20) << left << dataArray[i].patientName << setw(20) << left << dataArray[i].patientId << setw(10)
             << prefix << setw(10) << fixed << setprecision(2) << dataArray[i].bill << endl;
    }
}

void displayPatient(vector<Record> &vectorData, int number)
{
    int patientData = binarySearch(vectorData, number);
    if (patientData < 0)
        cout << "Patient Not Found" << endl;
    else
    {
        cout << "Found Patient " << vectorData[patientData].patientName << endl;
        cout << setw(10) << vectorData[patientData].patientNumber << setw(20) << left << vectorData[patientData].patientName << setw(20) << left << vectorData[patientData].patientId << setw(10)
             << getPhonePrefix(vectorData[patientData].phoneNumber) << setw(10) << fixed << setprecision(2) << vectorData[patientData].bill << endl;
    }
}

//Patient functions
bool getPatientInformation(Record &record)
{
    long number;
    double bill;
    cout << "Please Enter patient number : ";
    if (cin >> number)
    {
        record.patientNumber = number;
        cin.ignore(999, '\n');

        cout << "Please enter patient name : ";
        getline(cin, record.patientName);

        cout << "Please enter patient Id in BCRO-456-87473-GEN format :";
        getline(cin, record.patientId);

        cout << "Please enter the phone number in 2018712653 format :";

        if (cin >> number)
        {
            record.phoneNumber = number;
            cout << "Please enter the bill amount :";
            if (cin >> bill)
                record.bill = bill;
            else
            {
                cout << "Sorry thats not a valid format ";
                cin.ignore(999, '\n');
                return false;
            }
        }
        else
        {
            cout << "Sorry thats not a valid number ";
            cin.ignore(999, '\n');
            return false;
        }
    }
    else
    {
        cout << "Sorry thats not a valid format ";
        cin.ignore(999, '\n');
        return false;
    }
    return true;
}

void addPatient(vector<Record> &vectorData)
{
    Record rec;
    if (getPatientInformation(rec))
    {
        vectorData.push_back(rec);
        bubbleSortVector(vectorData);
    }
}

void removePatient(vector<Record> &vectorData, int number)
{
    int patientData = binarySearch(vectorData, number);
    if (patientData < 0)
        cout << "Patient Not Found" << endl;
    else
    {
        vectorData.erase(vectorData.begin() + patientData);
        cout << "Removed Patient " << number;
    }
}

//Bill Calculation
InsuranceType getInsurance(string patientId)
{
    patientId.erase(4, patientId.length());

    if (patientId == "MDCA")
    {
        return medicare;
    }
    else if (patientId == "AETN")
    {
        return aetna;
    }
    else if (patientId == "WHAA")
    {
        return wha;
    }
    else if (patientId == "BCRO")
    {
        return bluecross;
    }
    else if (patientId == "MRCY")
    {
        return mercy;
    }
    else if (patientId == "MDCL")
    {
        return medical;
    }
    else if (patientId == "SUTT")
    {
        return sutter;
    }

    return unknown;
}

double calculateInsuranceDiscount(InsuranceType carrier)
{
    switch (carrier)
    {
    case cigna:
        return 0.0;
    case wha:
        return 5.0;
    case mercy:
        return 5.0;
    case bluecross:
        return 0.0;
    case medicare:
        return 10.0;
    case medical:
        return 7.5;
    case sutter:
        return 0.0;
    case aetna:
        return 0.0;
    case unknown:
        return 0.0;
    default:
        return 0.0;
    }
}

double calculateAreaDiscount(int prefix)
{
    switch (prefix)
    {
    case 916:
    case 558:
        return 2.0;
    default:
        return 0;
    }
}

double getRoomType(string roomType)
{
    roomType.erase(0, roomType.length() - 3);

    if (roomType == "PRV")
    {
        return -20.0;
    }
    else if (roomType == "GEN")
    {
        return 0.0;
    }
    return 0.0;
}

Record getPatient(vector<Record> &vectorData, int number)
{
    int patientData = binarySearch(vectorData, number);
    if (patientData < 0)
    {
        cout << "Invalid patient number" << endl;
        return Record();
    }
    return vectorData[patientData];
}

void calculateFinalBill(vector<Record> &vectorData)
{
    int number;

    cout << "Patient Number? ";
    cin >> number;

    Record patientData = getPatient(vectorData, number);

    if (patientData.patientNumber > 0)
    {
        InsuranceType insurance = getInsurance(patientData.patientId);
        double finalAmount = patientData.bill;

        double insuranceDiscount = calculateInsuranceDiscount(insurance);
        double areaDiscount = calculateAreaDiscount(getPhonePrefix(patientData.phoneNumber));
        double roomTypeAdjustment = getRoomType(patientData.patientId);

        cout << setw(29) << "Current Bill" << right << ": $" << patientData.bill << endl;
        cout << setw(29) << left << "Insurance Carrier Discount" << right << ":  " << insuranceDiscount << "%" << endl;
        cout << setw(29) << left << "Residential Area Discount" << right << ":  " << areaDiscount << "%" << endl;
        cout << setw(29) << left << "Room Type Adjustment" << right << ":  " << roomTypeAdjustment << "%" << endl;

        double discountAmount = 0.0;
        discountAmount = insuranceDiscount + areaDiscount + roomTypeAdjustment;
        if (discountAmount != 0)
        {
            discountAmount /= -100;
            discountAmount += 1;
            finalAmount *= discountAmount;
        }

        cout << setw(29) << left << "Final Total Bill" << right << ": $" << finalAmount << endl;
        cout << left << setfill('-') << setw(42) << "\n"
             << setfill(' ');
    }
}

//Menu
char printMenu(vector<Record> &vectorData)
{
    char choice;
    string toFind;
    int number;

    cout << endl
         << "MENU" << endl;
    cout << "b - Calculate final bill" << endl;
    cout << "f - Find a patient" << endl;
    cout << "r - Remove a patient" << endl;
    cout << "a - Add a patient" << endl;
    cout << "d - Display patient list" << endl;
    cout << "q - Quit" << endl
         << endl;

    choice = ' ';

    while (choice != 'd' && choice != 'a' && choice != 'f' && choice != 'r' && choice != 'q' && choice != 'b')
    {
        cout << "Choose an option: ";
        cin >> choice;
        choice = tolower(choice);
    }

    switch (choice)
    {
    case 'r':

        cout << "Patient Number? ";
        cin >> number;
        removePatient(vectorData, number);
        choice = ' ';
        break;

    case 'd':
        displayData(vectorData);
        choice = ' ';
        break;

    case 'f':
        cin.ignore();
        cout << "Patient Number? ";
        cin >> number;
        displayPatient(vectorData, number);
        choice = ' ';
        choice = ' ';
        break;

    case ' ':
        choice = ' ';
        break;

    case 'a':
        cout << "Add Patient : " << endl;
        addPatient(vectorData);
        cin.clear();
        cin.ignore(999, '\n');
        choice = ' ';

    case 'b':
        cout << "Calculate final bill : " << endl;
        calculateFinalBill(vectorData);

        cin.clear();
        cin.ignore(999, '\n');
        choice = ' ';

    default:
        break;
    }

    return choice;
}
