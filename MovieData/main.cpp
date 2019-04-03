#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//initial declaration
struct MovieData
{
    string title, director, yearReleased;
    int runningTime;
    //Default constructor
    MovieData()
    {
        title = "";
        director = "";
        yearReleased = "";
        runningTime = 0;
    }
    //Overloaded constructor
    MovieData(string newtitle, string newdirector, string newyearReleased, int newrunningTime)
    {
        title = newtitle;
        director = newdirector;
        yearReleased = newyearReleased;
        runningTime = newrunningTime;
    }
};

//generates output
void printBanner()
{
    cout << left << setw(18) << "Title" << setw(22) << left << "Director" << setw(20) << left << "Year Released" << setw(15) << left << "Running Time" << endl;
}

//bubble sort
void bubbleSort(vector<MovieData> &list, int SIZE)
{
    bool swap = true;
    int count = SIZE;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < count - 1; i++)
            if (list[i].runningTime > list[i + 1].runningTime)
            {
                MovieData temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                swap = true;
            }
        count--;
    }
}

int binarySearch(vector<MovieData> &list, int bottom, int top, int binarySearchNumber)
{
    top = top - 1;
    while (bottom <= top)
    {
        if (top >= 1)
        {
            int mid = (bottom + top) / 2;

            if (list[mid].runningTime == binarySearchNumber)
            {

                return mid;
            }

            if (list[mid].runningTime > binarySearchNumber)
            {
                top = mid - 1;
            }
            else
            {
                bottom = mid + 1;
            }
        }
    }

    return -1;
}
#include "MovieData.h"
int main()
{
    vector<MovieData> movieList;
    readMovies(movieList);
    int SIZE = movieList.size();

    printBanner();

    bubbleSort(movieList, SIZE);
    for (int i = 0; i < SIZE -1; i++)
    {
        printMovie(movieList, i);
    }
    int binarySearchNumber;
    cin >> binarySearchNumber;

    int result = binarySearch(movieList, 0, SIZE, binarySearchNumber);
    if (result == -1)
    {
        cout << "\nMovie not found\n";
    }
    else
    {
        cout << "\nFound Movie! \n";
        cout << left << setw(18) << movieList[result].title << setw(22) << movieList[result].director << setw(20) << movieList[result].yearReleased << setw(15) << movieList[result].runningTime << endl;
    }

    return 0;
}
