#include <iomanip>
#include "discount.cpp"

bool fillCart(vector<Item> &cart)
{
    ifstream infile("cart.dat");
    if (infile)
    {
        while (!infile.eof())
        {
            string description;
            string barcode;
            string price;
            double cost;

            getline(infile, barcode, ',');
            getline(infile, description, ',');
            getline(infile, price, '\n');
            cost = stod(price);
            Item item(barcode, description, cost);
            cart.push_back(item);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool fillDiscount(Discount savings[], int &size)
{
    ifstream infile("discount.dat");
    string barcode;
    double percentage;
    int i = 0;
    if (infile)
    {
        while (!infile.eof())
        {
            getline(infile, barcode, ',');
            cin >> percentage;
            savings[i].setBarcode(barcode);
            savings[i].setPercentage(percentage);
            i++;
        }
        size = i;
        return true;
    }
    else
    {
        return false;
    }
}

void displayCart(vector<Item> &cart)
{
    cout << "-------------------------" << endl;
    for (auto i = cart.begin(); i < cart.end(); i++)
        cout << setw(20) << i->getDescription() << " " << fixed << setprecision(2) << i->getPrice() << endl;
    cout << "--------------------------" << endl;
}

void displayDiscount(Discount savings[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << savings[i].getBarcode() << " "
             << savings[i].getPercentage() << endl;
    }
}

double checkOut(vector<Item> &cart)
{
    double total = 0;
    for (int i = 0; i < cart.size(); i++)
        total += cart[i].getPrice();
    return total;
}

void applyDiscount(vector<Item> &cart, Discount savings[], int size)
{
    for (int i = 0; i < cart.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (cart[i].getBarcode() == savings[j].getBarcode())
            {
                cart[i].setPrice(cart[i].getPrice() - cart[i].getPrice() * savings[j].getPercentage() / 100);
            }
        }
    }
}

void printBill(vector<Item> &cart, double total)
{
    cout << "Printing Bill" << endl;
    displayCart(cart);
    cout << setw(21) << "Total " << setprecision(2) << fixed << total << endl;
}