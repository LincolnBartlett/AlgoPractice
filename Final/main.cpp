#include <iostream>
#include <fstream>
#include <vector>
#include "item.cpp"
#include <cstdlib>
#include "cartHelper.h"
const int SIZE = 10;
int main()
{
    vector<Item> cart;
    Discount savings[SIZE];
    int size = 0;
    string answer = "n";
    if (fillCart(cart))
    {
        cout << "Displaying Cart" << endl;
        displayCart(cart);
        printBill(cart, checkOut(cart));
        cin >> answer;
        if (answer == "y")
        {
            if (fillDiscount(savings, size))
            {
                applyDiscount(cart, savings, size);
                cout << "After applying discount" << endl;
                printBill(cart, checkOut(cart));
            }
            else
            {
                cout << "Discount File Open Error" << endl;
            }
        }
    }
    else
    {
        cout << "Cart File Open Error" << endl;
    }
}