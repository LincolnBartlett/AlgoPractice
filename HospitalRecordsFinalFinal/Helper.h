
#include "Output.h"
//Data Processing Functions
bool getRecordsFromFile(string file, vector<Record> &dataVector)
{
    string junk;
    long phonenumber;
    int size = 0;
    ifstream records(file);
    Record record;
    if (records.is_open())
    {
        while (!records.eof())
        {
            getline(records, junk, ',');
            record.setPatientNumber(stoi(junk));
            getline(records, junk, ',');
            record.setPatientName(junk);
            getline(records, junk, ',');
            record.setPatientId(junk);
            records >> phonenumber;
            record.setPhoneNumber(phonenumber);
            getline(records, junk, '\n');
            record.setBill(stod(junk));
            dataVector.push_back(record);
        }
        return dataVector.size();

    }
    else
    {
        return -1;
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

        if (vectorData[middle].getPatientNumber() == number)
        {
            found = true;
            return middle;
        }
        else if (number < vectorData[middle].getPatientNumber())
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

void bubbleSort(vector<Record> &vectorData)
{
    bool swap = true;
    int size = vectorData.size();
    while (swap)
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
            if (vectorData[i].getPatientNumber() > vectorData[i + 1].getPatientNumber())
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
        int prefix = getPhonePrefix(vectorData[i].getPhoneNumber());
        cout << setw(10) << vectorData[i].getPatientNumber() << setw(20) << left << vectorData[i].getPatientName() << setw(20) << left << vectorData[i].getPatientId() << setw(10) << prefix << setw(10) << fixed << setprecision(2) << vectorData[i].getBill() << endl;
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
        rec.setPatientNumber(n);
        cin.ignore(999, '\n');
        cout << "Please enter patient name : ";
        getline(cin, s);
        rec.setPatientName(s);
        cout << "Please enter patient Id in BCRO-456-87473-GEN format :";
        getline(cin, s);
        rec.setPatientId(s);
        cout << "Please enter the phone number in 2018712653 format :";
        if (cin >> n)
        {
            rec.setPhoneNumber(n);
            cout << "Please enter the bill amount :";
            if (cin >> b)
                rec.setBill(b);
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

int getPatientNumber()
{
    int number;
    cout << "Patient Number? \n";
    cin >> number;
    return number;
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
    case mercy:
        return 0.05;
    case bluecross:
        return 0;
    case aetna:
        return 0;
    case wha:
        return 0.05;
    case cigna:
        return 0;
    case medicare:
        return 0.1;
    case medical:
        return 0.075;
    case unknown:
        return 0;
    default:
        return 0;
    }
}

double calculateAreaDiscount(int prefix)
{
    switch (prefix)
    {
    case 916:
        return .02;
    case 558:
        return .02;
    default:
        return 0;
    }
}

double getRoomType(string roomType)
{
    string type = roomType.substr(15);
    if (type == "PRV")
        return -0.2;
    else
        return 0;
}
void calculateFinalBill(vector<Record> &vectorData)
{
    int patientNumber = getPatientNumber();
    int found = binarySearch(vectorData, patientNumber);
    if (found >= 0)
    {
        InsuranceType carrier = getInsurance(vectorData[found].getPatientId());
        double insDiscount = calculateInsuranceDiscount(carrier);
        cout << "Current Bill                : $" << fixed << setprecision(2) << vectorData[found].getBill() << endl;
        cout << "Insurance Carrier Discount  :  " << fixed << setprecision(2) << insDiscount * 100 << "%" << endl;
        int prefix = getPhonePrefix(vectorData[found].getPhoneNumber());
        double areaDiscount = calculateAreaDiscount(prefix);
        cout << "Resident Area Discount      :  " << fixed << setprecision(2) << areaDiscount * 100 << "%" << endl;
        double roomCostPercentage = getRoomType(vectorData[found].getPatientId());
        cout << "Room Type Adjustment        :  " << fixed << setprecision(2) << roomCostPercentage * 100 << "%" << endl;
        cout << "Final Total Bill            : $" << fixed << setprecision(2) << (vectorData[found].getBill() - vectorData[found].getBill() * (insDiscount + areaDiscount + roomCostPercentage)) << endl;
        cout << "------------------------------------------" << endl;
    }
    else
    {
        cout << "Invalid patient number " << endl;
    }
}

string convertCarrier(InsuranceType carrier)
{
    switch (carrier)
    {
    case mercy:
        return "MRCY";
    case bluecross:
        return "BCRO";
    case aetna:
        return "AETN";
    case wha:
        return "WHAA";
    case cigna:
        return "CIGN";
    case medicare:
        return "MDCA";
    case medical:
        return "MDCL";
    case unknown:
        return "UNKN";
    default:
        return 0;
    }
}

void calculateFinalBill(vector<Record> vectorData, vector<Output> &vectorOutput)
{
    
    int patientNumber;
    for (int i = 0; i < vectorData.size(); i++)
    {
        patientNumber = vectorData[i].getPatientNumber();
        int found = binarySearch(vectorData, patientNumber);
        if (found >= 0)
        {
            InsuranceType carrier = getInsurance(vectorData[found].getPatientId());
            cout << "Patient Number              : " << patientNumber << endl;
            double insDiscount = calculateInsuranceDiscount(carrier);
            cout << "Current Bill                : $" << fixed << setprecision(2) << vectorData[found].getBill() << endl;
            cout << "Insurance Carrier Discount  :  " << fixed << setprecision(2) << insDiscount * 100 << "%" << endl;
            int prefix = getPhonePrefix(vectorData[found].getPhoneNumber());
            double areaDiscount = calculateAreaDiscount(prefix);
            cout << "Resident Area Discount      :  " << fixed << setprecision(2) << areaDiscount * 100 << "%" << endl;
            double roomCostPercentage = getRoomType(vectorData[found].getPatientId());
            cout << "Room Type Adjustment        :  " << fixed << setprecision(2) << roomCostPercentage * 100 << "%" << endl;
            cout << "Final Total Bill            : $" << fixed << setprecision(2) << (vectorData[found].getBill() - vectorData[found].getBill() * (insDiscount + areaDiscount + roomCostPercentage)) << endl;
            cout << "------------------------------------------" << endl;
            double totalBill = vectorData[found].getBill() - vectorData[found].getBill() * (insDiscount + areaDiscount + roomCostPercentage);
            bool foundIndex = false;
            string insurance = convertCarrier(carrier);

            for (int i = 0; i < vectorOutput.size(); i++)
            {

                if (vectorOutput[i].getInsuranceCompany() == insurance)
                {
                    vectorOutput[i].setOutstandingAmount(vectorOutput[i].getOutstandingAmount() + totalBill);
                    vectorOutput[i].setNumOfPatients(vectorOutput[i].getNumOfPatients() + 1);
                    foundIndex = true;
                }
            }
            if (!foundIndex)
            {

                Output temp;
                temp.setInsuranceCompany(insurance);
                temp.setNumOfPatients(1);
                temp.setOutstandingAmount(totalBill);
                vectorOutput.push_back(temp);
            }
        }
        else
        {
            cout << "Invalid patient number " << endl;
        }
    }
}

//Patient functions
void addPatient(vector<Record> &vectorData)
{
    Record rec;
    if (getInformation(rec))
    {

        vectorData.push_back(rec);
        bubbleSort(vectorData);
    }
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
        cout << "Found Patient " << vectorData[found].getPatientName() << endl;
        cout << setw(10) << vectorData[found].getPatientNumber() << setw(20) << left << vectorData[found].getPatientName() << setw(20) << left << vectorData[found].getPatientId() << setw(10) << getPhonePrefix(vectorData[found].getPhoneNumber()) << setw(10) << fixed << setprecision(2) << vectorData[found].getBill() << endl;
    }
}

void getStats(vector<Record> vectorData)
{
    ofstream output("Report.csv");
    vector<Output> vectorOutput;
    if (output)
    {
        output << "CARRIER,NUM_PATIENTS,TOTAL_OUTSTANDING" << endl;
        calculateFinalBill(vectorData, vectorOutput);

        for (int i = 0; i < vectorOutput.size(); i++)
            output << vectorOutput[i].getInsuranceCompany() << "," << vectorOutput[i].getNumOfPatients() << "," << vectorOutput[i].getOutstandingAmount() << endl;
    }
    else
        cout << "Statistics File Write Error" << endl;
}

//Menu
char printMenu(vector<Record> &vectorData)
{
    char choice;
    string toFind;
    int number;

    cout << endl
         << "MENU" << endl;

    cout << "d - Display patient list" << endl;
    cout << "f - Find a patient" << endl;
    cout << "a - Add a patient" << endl;
    cout << "r - Remove a patient" << endl;
    cout << "b - Calculate final bill" << endl;
    cout << "s - Generate Insurance Statistics" << endl;
    cout << "q - Quit" << endl
         << endl;

    choice = ' ';

    while (choice != 'd' && choice != 'a' && choice != 'f' &&
           choice != 'r' && choice != 'b' && choice != 's' &&
           choice != 'q')
    {
        cout << "Choose an option: ";
        cin >> choice;
        choice = tolower(choice);
    }

    switch (choice)
    {
    case 'r':
        number = getPatientNumber();
        removePatient(vectorData, number);
        choice = ' ';
        break;

    case 'd':
        displayData(vectorData);
        choice = ' ';
        break;

    case 'f':
        cin.ignore();

        number = getPatientNumber();
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
        break;

    case 'b':
        cout << endl
             << "Calculate Final Bill : " << endl;
        calculateFinalBill(vectorData);
        cin.clear();
        cin.ignore(999, '\n');
        choice = ' ';
        break;

    case 's':

        getStats(vectorData);
        choice = ' ';
        break;

    default:
        break;
    }

    return choice;
}
