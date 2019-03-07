#include <iostream>
using namespace std;

struct movieData
{
    string title, director, runTime;

}one,two;

int main()
{
    string title, director, runTime;
    getline(cin, title);
    getline(cin, director);
    getline(cin, runTime);

    one.title == title;
    one.director == director;
    one.runTime == runTime;

    getline(cin, title);
    getline(cin, director);
    getline(cin, runTime);

    two.title == title;
    two.director == director;
    two.runTime == runTime;

    cout << one.title << "   " << two.title << endl;
}
