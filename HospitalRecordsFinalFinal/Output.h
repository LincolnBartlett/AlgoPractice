class Output
{
    string insuranceCompany;
    int numOfPatients;
    double outstandingAmount;

public:
    Output()
    {
        insuranceCompany = "";
        numOfPatients = 0;
        outstandingAmount = 0;
    }
    Output(string insuranceCompany, int numOfPatients, double outstandingAmount)
    {
        this->outstandingAmount = outstandingAmount;
        this->numOfPatients = numOfPatients;
        this->insuranceCompany = insuranceCompany;
    }

    string getInsuranceCompany()
    {
        return insuranceCompany;
    }

    double getOutstandingAmount()
    {
        return outstandingAmount;
    }

    int getNumOfPatients()
    {
        return numOfPatients;
    }

    void setInsuranceCompany(string insuranceCompany)
    {
        this->insuranceCompany = insuranceCompany;
    }

    void setOutstandingAmount(double outstandingAmount)
    {
        this->outstandingAmount = outstandingAmount;
    }
    
    void setNumOfPatients(int numOfPatients)
    {
        this->numOfPatients = numOfPatients;
    }
};