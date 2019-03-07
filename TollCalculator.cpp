/*
TOLL CACLULATOR

Write a program that incrementally calculates the toll amount for travel along a toll road or toll lane. 
The toll amount is based on the time of day, day of the week, and number of persons in the vehicle. 

*/

#include <iostream>
#include <iomanip>
using namespace std;

double FindToll(int timeint, int isWeekend)
{
    double toll;
    if (isWeekend == 0)
    {
        if (timeint < 6 || timeint >= 18)
        {
            toll = 1.55;
        }
        else if (timeint >= 6 && timeint <= 9)
        {
            toll = 4.65;
        }
        else if (timeint >= 10 && timeint <= 17)
        {
            toll = 2.35;
        }
    }
    else
    {
        if (timeint < 8 || timeint >= 22)
        {
            toll = 1.55;
        }
        else if (timeint >= 8 && timeint <= 11)
        {
            toll = 3.05;
        }
        else if (timeint >= 12 && timeint <= 15)
        {
            toll = 3.45;
        }
        else if (timeint >= 16 && timeint <= 18)
        {
            toll = 3.60;
        }
        else if (timeint >= 19 && timeint <= 21)
        {
            toll = 3.05;
        }
    }

    return toll;
}

void CheckCarpoolAndApplyDiscount(int numOfPeople, int isWeekend, int timeint, double &toll)
{
    if (numOfPeople >= 3)
    {
        if (isWeekend == 0 && timeint >= 6 && timeint <= 10)
        {
            toll /= 2;
        }
        else
        {
            toll = 0.00;
        }
    }
}

string ConvertTime(string time, int timeint)
{
    string fixedString = "";

    if (timeint >= 13)
    {
        timeint -= 12;

        fixedString = to_string(timeint) + time.substr(2) + " PM";
    }
    else
    {
        fixedString = time + " AM";
    }

    return fixedString;
}

int main()
{
    string time;
    int timeint;
    int isWeekend;
    int numOfPeople;
    double toll;

    cin >> time >> isWeekend >> numOfPeople;

    timeint = stoi(time.substr(0, 2));
    time = ConvertTime(time, timeint);
    toll = FindToll(timeint, isWeekend);

    CheckCarpoolAndApplyDiscount(numOfPeople, isWeekend, timeint, toll);

    if (isWeekend == 0)
    {
        cout << "\n\nOn a weekday, toll at " << time << " is $" << setprecision(2) << fixed << toll << endl;
    }
    else
    {
        cout << "\n\nOn a weekend or holiday, toll at " << time << " is $" << setprecision(2) << fixed << toll << endl;
    }
}
