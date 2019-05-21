#include <string>
using namespace std;

class Item
{
    
private:
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
    Item(string barcode, string description, double price)
    {
        this->description = description;
        this->barcode = barcode;
        this->price = price;
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
    void setPrice(double price)
    {
        this->price = price;
    }
};