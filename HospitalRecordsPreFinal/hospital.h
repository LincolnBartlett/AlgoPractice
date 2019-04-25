#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Global Declarations 
int const SIZE = 4;
struct Record
{
    int patientNumber;
    string patientName;
    string patientId;
    long phoneNumber;
    double bill;
    Record()
    {
    }
    Record(int thispatientNumber, string thispatientName, string thispatientId, long thisphoneNumber, double thisbill)
    {
        patientNumber = thispatientNumber;
        patientName = thispatientName;
        patientId = thispatientId;
        phoneNumber = thisphoneNumber;
        bill = thisbill;
    }
};



int readDataFromFile(string fileName, Record dataArray[])
{
    int size = 0;
    string s;

    ifstream inputFile(fileName);
    if (inputFile.fail())
    {
        cout << "Error reading file";
        return -1;
    }

    else
    {
        while (inputFile)
        {
            getline(inputFile, s, ',');
            dataArray[size].patientNumber = stoi(s);
            getline(inputFile, dataArray[size].patientName, ',');
            getline(inputFile, dataArray[size].patientId, ',');
            inputFile >> dataArray[size].phoneNumber;
            getline(inputFile, s, '\n');
            dataArray[size].bill = stod(s);

            size++;
        }
        return size;
    }
}


int binarySearch(vector<Record> &vectorData, int number)
{

    int first, last, middle;
    first = last = middle = 0;
    bool found = false;
    last = vectorData.size() - 1;
    while (first <= last && !found)
    {
        middle = (first + last) / 2;
        if (vectorData[middle].patientNumber == number)
        {
            found = true;
            return middle;
        }
        else if (number < vectorData[middle].patientNumber)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return -1;
}



int getPrefixNum(long number)
{
    return (number / 10000) % 1000;
}


void bubbleSort(Record myArray[], int size)
{
    bool swap = true;
    //int size=SIZE;//this is not right!
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
    int size = vectorData.size(); //this is not right!
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
        int prefix = getPrefixNum(vectorData[i].phoneNumber);
        cout << setw(10) << vectorData[i].patientNumber << setw(20) << left << vectorData[i].patientName << setw(20) << left << vectorData[i].patientId << setw(10)
             << prefix << setw(10) << fixed << setprecision(2) << vectorData[i].bill << endl;
    }
}



void printData(Record dataArray[], int size)
{
    printBanner();
    for (int i = 0; i < size; i++)
    {
        int prefix = getPrefixNum(dataArray[i].phoneNumber);
        cout << setw(10) << dataArray[i].patientNumber << setw(20) << left << dataArray[i].patientName << setw(20) << left << dataArray[i].patientId << setw(10)
             << prefix << setw(10) << fixed << setprecision(2) << dataArray[i].bill << endl;
    }
}



bool getInformation(Record &rec)
{
    string s;
    long n;
    double b;
    cout << "Please Enter patient number : ";
    if (cin >> n)
    {
        rec.patientNumber = n;
        cin.ignore(999, '\n');
        cout << "Please enter patient name : ";
        getline(cin, rec.patientName);
        cout << "Please enter patient Id in BCRO-456-87473-GEN format :";
        getline(cin, rec.patientId);
        cout << "Please enter the phone number in 2018712653 format :";
        if (cin >> n)
        {
            rec.phoneNumber = n;
            cout << "Please enter the bill amount :";
            if (cin >> b)
                rec.bill = b;
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
        cin >> s;
        cin.ignore(999, '\n');
        return false;
    }
    return true;
}



void addPatient(vector<Record> &vectorData)
{
    Record rec;
    if (getInformation(rec))
    {
        vectorData.push_back(rec);
        bubbleSortVector(vectorData);
    }
}



int getPatientNumber()
{
    int number;
    cout << "Patient Number? ";
    cin >> number;
    return number;
}

void removePatient(vector<Record> &vectorData, int number)
{
    int found = binarySearch(vectorData, number);
    if (found < 0)
        cout << "Patient Not Found" << endl;
    else
    {
        auto it = vectorData.begin();
        vectorData.erase(it + found);
        cout << "Removed Patient " << number;
    }
}



void displayPatient(vector<Record> &vectorData, int number)
{
    int found = binarySearch(vectorData, number);
    if (found < 0)
        cout << "Patient Not Found" << endl;
    else
    {
        cout << "Found Patient " << vectorData[found].patientName << endl;
        cout << setw(10) << vectorData[found].patientNumber << setw(20) << left << vectorData[found].patientName << setw(20) << left << vectorData[found].patientId << setw(10)
             << getPrefixNum(vectorData[found].phoneNumber) << setw(10) << fixed << setprecision(2) << vectorData[found].bill << endl;
    }
}



char printMenu(vector<Record> &vectorData)
{
    char choice;
    string toFind;
    int number;

    cout << endl
         << "MENU" << endl;
    cout << "f - Find a patient" << endl;
    cout << "r - Remove a patient" << endl;
    cout << "a - Add a patient" << endl;
    cout << "d - Display patient list" << endl;
    cout << "q - Quit" << endl
         << endl;

    choice = ' ';

    while (choice != 'd' && choice != 'a' && choice != 'f' &&
           choice != 'r'
           && choice != 'q')
    {
        cout << "Choose an option: "; 
        cin >> choice;
        choice = tolower(choice);
    }

    if (choice == 'r')
    {
        number = getPatientNumber();
        removePatient(vectorData, number);
        choice = ' ';
    }
    else if (choice == 'd')
    {


        displayData(vectorData);
        choice = ' ';
    }

    else if (choice == 'f')
    {
        cin.ignore();
        number = getPatientNumber();
        displayPatient(vectorData, number);
        choice = ' ';
        choice = ' ';
    }

    else if (choice == ' ')
    {
        choice = ' ';
    }

    else if (choice == 'a')
    {
        cout << "Add Patient : " << endl;
        addPatient(vectorData);
        cin.clear();
        cin.ignore(999, '\n');
        choice = ' ';
    }

    return choice;
}
