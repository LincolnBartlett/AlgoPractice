#include <iostream>
#include <iomanip>
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
    cout << setw(20) << "Title" << setw(20) << "Director" << setw(20) << "Year Released" << setw(20) << "Running Time" << endl;
}

void movieList(MovieData list[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(20) << list[i].title << setw(20) << list[i].director << setw(20) << list[i].year << setw(20) << list[i].runTime << endl;
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

    //Creating new struct variables

    //using default constructor
    MovieData movieOne;

    //add properties with dot operator
    movieOne.title = "The Funny Kids";
    movieOne.director = "Steven Shpeelberg";
    movieOne.year = "1990";
    movieOne.runTime = 200;

    //using overloaded constructor
    MovieData movieTwo("The Shining", "Steven King", "1980", 190);
    MovieData movieThree("The Pond", "Larry Cosca", "1967", 183);
    MovieData movieFour("Inception", "Recursive Robert", "2010", 220);
    MovieData movieFive("Mary Poppins", "F F Coppola", "2001", 212);

    MovieData movieListArray[SIZE] = {movieOne, movieTwo, movieThree, movieFour, movieFive};

    //output functions
    printBanner();
    sortList(movieListArray, SIZE);
    movieList(movieListArray, SIZE);

    return 0;
}
