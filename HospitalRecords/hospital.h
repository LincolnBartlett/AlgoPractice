
const int SIZE = 3;

struct Record
{
    long patientNumber,
        phoneNumber,
        prefix;
    string patientName,
        patientID;
    double patientBill;

    Record()
    {
        patientNumber = 0;
        phoneNumber = 0;
        patientName = "";
        patientID = "";
        patientBill = 0.0;
        prefix = 0;
    }
};

bool getRecordsFromFile(Record Patients[])
{
    string junk;
    ifstream records("data.txt");

    if (records.is_open())
    {
        for (int i = 0; i < SIZE; i++)
        {

            records >> Patients[i].patientNumber;
            records.ignore(1);
            getline(records, Patients[i].patientName, ':');
            records >> Patients[i].patientID;
            records >> Patients[i].phoneNumber;
            records >> Patients[i].patientBill;

            Patients[i].prefix = (Patients[i].phoneNumber % 10000000 - Patients[i].phoneNumber % 10000) / 10000;

        }
        records.close();
        return true;
    }
    else
    {
        return false;
    }
}

void sortRecordsByPatientID(Record Patients[])
{

    bool swap = true;
    int count = SIZE;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < count - 1; i++)
            if (Patients[i].patientID > Patients[i + 1].patientID)
            {
                Record temp = Patients[i];
                Patients[i] = Patients[i + 1];
                Patients[i + 1] = temp;
                swap = true;
            }
        count--;
    }
}

void printBanner(Record Patients[])
{

    cout << endl
         << "    WELCOME TO AMERICAN HEALTH SERVICES DATA MANAGEMENT" << endl
         << endl;

    cout << setw(15) << left << "Patient Num"
         << setw(19) << left << "Patient Name"
         << setw(28) << left << "Patient Id "
         << setw(15) << "Prefix "
         << setw(10) << "Patient Dues" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(15) << left << Patients[i].patientNumber
             << setw(19) << left << Patients[i].patientName
             << setw(28) << left << Patients[i].patientID
             << setw(15) << Patients[i].prefix
             << setw(10) << setprecision(2) << fixed << Patients[i].patientBill << "    " << endl;
    }
}