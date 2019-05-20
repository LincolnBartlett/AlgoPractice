#include <string>
class Discount
{
    std::string barcode;
    double percentage;

public:
    Discount()
    {
        barcode = "";
        percentage = 0;
    }
    Discount(std::string b, double p)
    {
        barcode = b;
        percentage = p;
    }
    std::string getBarcode()
    {
        return barcode;
    }
    double getPercentage()
    {
        return percentage;
    }
    void setBarcode(std::string b)
    {
        barcode = b;
    }
    void setPercentage(double p)
    {
        percentage = p;
    }
};