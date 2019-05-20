#include <string>
using namespace std;
class Item
{
    string description;
    string barcode;
    double price;

public:
    Item()
    {
        description = "";
        barcode = "";
        price = 0;
    }
    Item(string b, string d, double p)
    {
        description = d;
        barcode = b;
        price = p;
    }
    string getDescription()
    {
        return description;
    }
    double getPrice()
    {
        return price;
    }
    string getBarcode()
    {
        return barcode;
    }
    void setPrice(double p)
    {
        price = p;
    }
};