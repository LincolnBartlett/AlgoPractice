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
void printBanner()
{
    cout << left <<  setw(25) << "Title" << setw(25) << "Director" << setw(20) << "Year Released" << setw(15) << "Running Time" << endl;
}

void movieList(MovieData list[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << left <<setw(25) << list[i].title << setw(25) << list[i].director << setw(20) << list[i].year << setw(15) << list[i].runTime  << endl;
    }
}

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

int main()
{
    const int SIZE = 5;

    MovieData movieListArray[SIZE];

    ifstream movieListFile("MovieData.txt");
    string title, director, year;
    int runTime;
    int count = 0;

    if (movieListFile.is_open())
    {
        while ((movieListFile)&&(count < SIZE))
        {
            getline(movieListFile,title,',');
            getline(movieListFile,director,',');
            getline(movieListFile,year,',');
            movieListFile >> runTime;
            movieListArray[count] = MovieData(title, director, year,runTime);
            count++;
        }
        movieListFile.close();
    }

    else
        cout << "Unable to open file";



    //output functions
    printBanner();
    sortList(movieListArray, SIZE);
    movieList(movieListArray, SIZE);

    return 0;
}
