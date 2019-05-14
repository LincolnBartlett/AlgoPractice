#include <fstream>
#include <string>
#include <vector>

using namespace std;
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
class Record
{
    int patientNumber;
    string patientName;
    string patientId;
    long phoneNumber;
    double bill;

public:
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
    int getPatientNumber()
    {
        return patientNumber;
    }

    string getPatientName()
    {
        return patientName;
    }
    string getPatientId()
    {
        return patientId;
    }
    double getBill()
    {
        return bill;
    }

    long getPhoneNumber()
    {
        return phoneNumber;
    }
    void setPatientNumber(int number)
    {
        patientNumber = number;
    }

    void setPatientName(string name)
    {
        patientName = name;
    }
    void setPatientId(string id)
    {
        patientId = id;
    }
    void setBill(double thisBill)
    {
        bill = thisBill;
    }

    void setPhoneNumber(long pn)
    {
        phoneNumber = pn;
    }
};
