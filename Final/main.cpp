#define SIZE 10
#include <iostream>
#include <fstream>
#include <vector>
#include "item.cpp"
#include <cstdlib>
#include "cartHelper.h"


int main()
{
    vector<Item> cart;
    Discount savings[SIZE];
    int size = 0;
    char answer = 'n';

    if (fillCart(cart))
    {
        cout << "Displaying Cart\n";
        displayCart(cart);
        printBill(cart, checkOut(cart));
        cin >> answer;
        if (answer == 'y')
        {
            if (fillDiscount(savings, size))
            {
                applyDiscount(cart, savings, size);
                cout << "After applying discount\n";
                printBill(cart, checkOut(cart));
            }
            else
            {
                cout << "Discount File Open Error\n";
            }
        }
    }
    else
    {
        cout << "Cart File Open Error\n";
    }
}