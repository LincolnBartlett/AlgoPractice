#include <string>
using namespace std;

class Discount
{
    
private:
    string barcode;
    double percentage;

public:
    Discount()
    {
        barcode = "";
        percentage = 0;
    }
    Discount(string barcode, double percentage)
    {
        this->barcode = barcode;
        this->percentage = percentage;
    }
    string getBarcode()
    {
        return barcode;
    }
    double getPercentage()
    {
        return percentage;
    }
    void setBarcode(string barcode)
    {
        this->barcode = barcode;
    }
    void setPercentage(double percentage)
    {
        this->percentage = percentage;
    }
};