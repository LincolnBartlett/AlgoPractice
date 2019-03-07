#include <iostream>
#include <iomanip>
using namespace std;

struct movieData
{
    string title, director, year, runTime;

}one,two;

int main()
{


    one.title = "The Funny Kids";
    one.director = "Steven Shpeelberg";
    one.year = "1990";
    one.runTime = "200";

    two.title = "The Shining";
    two.director = "Steven King";
    two.year = "1980";
    two.runTime = "190";


    cout << setw(20) << "Title" << setw(20) << "Director" << setw(20) << "Year Released" << setw(20)<< "Running Time" << endl;
    cout << setw(20) << one.title << setw(20) << one.director << setw(20) << one.year << setw(20)<< one.runTime << endl;
    cout << setw(20) << two.title << setw(20) << two.director << setw(20) << two.year << setw(20)<< two.runTime << endl;

    return 0;
}
