#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//initial declaration
struct MovieData
{
    string title, director, year;
    int runTime;
    //Default constructor
    MovieData()
    {
        title = "";
        director = "";
        year = "";
        runTime = 0;
    }
    //Overloaded constructor
    MovieData(string newtitle, string newdirector, string newyear, int newrunTime)
    {
        title = newtitle;
        director = newdirector;
        year = newyear;
        runTime = newrunTime;
    }
};

//generates output
void printBanner() { cout << left << setw(18) << "Title" << setw(22) << left << "Director" << setw(20) << left << "Year Released" << setw(15) << left << "Running Time" << endl; }

//bubble sort
void sortList(MovieData list[], int SIZE)
{
    bool swap = true;
    int count = SIZE;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < count - 1; i++)
            if (list[i].runTime > list[i + 1].runTime)
            {
                MovieData temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                swap = true;
            }
        count--;
    }
}

int binarySearch(MovieData list[], int bottom, int top, int binarySearchNumber)
{
    top = top - 1;
    while (bottom <= top)
    {
        if (top >= 1)
        {
            int mid = (bottom + top) / 2;

            if (list[mid].runTime == binarySearchNumber)
            {

                return mid;
            }

            if (list[mid].runTime > binarySearchNumber)
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

void printMovies(MovieData movies[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << left << setw(18) << movies[i].title << left << setw(22) << left << movies[i].director << setw(20) << left << movies[i].year;
        cout << left << setw(15) << to_string(movies[i].runTime) << endl;
    }
}

int main()
{
    const int SIZE = 5;

    MovieData movieListArray[SIZE];

    string title, director, year;
    int runTime;
    int count = 0;
    int binarySearchNumber = 0;

    ifstream movieListFile("MovieData.txt");
    if (movieListFile.is_open())
    {
        while ((movieListFile) && (count < SIZE))
        {
            getline(movieListFile, title, ',');
            getline(movieListFile, director, ',');
            getline(movieListFile, year, ',');
            movieListFile >> runTime;
            movieListArray[count] = MovieData(title, director, year, runTime);
            count++;
        }
        movieListFile.close();
    }

    else
        cout << "Unable to open file";

    //output functions

    printBanner();
    sortList(movieListArray, SIZE);
    printMovies(movieListArray, SIZE);

    cin >> binarySearchNumber;

    int result = binarySearch(movieListArray, 0, SIZE, binarySearchNumber);
    if (result == -1)
    {
        cout << "-1 Movie not found";
    }
    else
    {
        cout << "Found your movie !\n";
        cout << left << setw(18) << movieListArray[result].title << setw(22) << movieListArray[result].director << setw(20) << movieListArray[result].year << setw(15) << movieListArray[result].runTime << endl;
    }

    return 0;
}
