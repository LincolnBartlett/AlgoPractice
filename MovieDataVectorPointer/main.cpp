#include "MovieData.h"
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
void fillVector(vector<MovieData *> &movieVector, string fileName); //implement all these methods
int searchVector(vector<MovieData *> movieVector, int time);        //
int searchVector(vector<MovieData *> movieVector, string title);
void bubbleSort(vector<MovieData *> &movieVector);
void displayVector(vector<MovieData *> movieVector);

int main()
{ // do NOT change main program
    string title;
    string director;
    string temp;
    string yearReleased;
    //int runningTime=0;
    string fileName = "MovieData.txt";
    vector<MovieData *> movieVector;
    fillVector(movieVector, fileName);
    cout << endl;
    cout << "Displaying unsorted vector of movies" << endl;
    displayVector(movieVector);
    bubbleSort(movieVector);
    cout << endl;
    cout << endl
         << "Displaying the sorted vector of movies" << endl;
    for (int i = 0; i < movieVector.size(); i++)
        movieVector[i]->printMovieDetails();
    int found = searchVector(movieVector, 200);
    cout << endl;
    cout << "Searching for movie with running time 200" << endl;
    ;
    if (found >= 0)
    {
        cout << "Found Movie :" << endl;
        movieVector[found]->printMovieDetails();
    }
    else
        cout << "Movie Not Found " << endl;
    cout << endl;
    cout << "Searching for movie with running time 165" << endl;
    found = searchVector(movieVector, 165);
    if (found >= 0)
    {
        cout << "Found Movie :" << endl;
        movieVector[found]->printMovieDetails();
    }
    else
        cout << "Movie Not Found " << endl;
    found = searchVector(movieVector, "Inception");
    cout << endl;
    cout << "Searching for movie : Inception " << endl;
    if (found >= 0)
    {
        cout << "Found Movie :" << endl;
        movieVector[found]->printMovieDetails();
    }
    else
        cout << "Movie Not Found " << endl; //to find by movie we will need to do linear search
    cout << endl;
    cout << "Searching for movie : Golden Pond " << endl;
    found = searchVector(movieVector, "Golden Pond");
    if (found >= 0)
    {
        cout << "Found Movie :" << endl;
        movieVector[found]->printMovieDetails();
    }
    else
        cout << "Movie Not Found " << endl; //to find by movie we will need to do linear search
}

void fillVector(vector<MovieData *> &movieVector, string fileName)
{
    ifstream data(fileName);
    string title;
    string director;
    string temp;
    string yearReleased;
    int runningTime = 0;
    if (data)
        while (!data.eof())
        {
            getline(data, title, ',');
            getline(data, director, ',');
            getline(data, yearReleased, ',');
            getline(data, temp);
            runningTime = stoi(temp);

            MovieData *movie = new MovieData(title, director, yearReleased, runningTime);
            movie->printMovieDetails();
            movieVector.push_back(movie);
            cout << endl;
            if (movie->getDirector() == "Steven Shpeelberg")
                cout << endl
                     << "Steven Shpeelberg! Thats my favorite director! " << endl;
            if (movie->getRunningTime() > 200)
                cout << endl
                     << "Thats a long movie ! " << endl
                     << endl;
            if (movie->getTitle() == "Inception")
                cout << endl
                     << "That was a fun recursive movie ! " << endl
                     << endl;
        }
    else
        cout << "File Open Error " << endl;
}

int searchVector(vector<MovieData *> movieVector, string title)
{

    int size = movieVector.size();

    int found = -1;

    for (int i = 0; i < size; i++)
    {
        if (movieVector[i]->getTitle() == title)
        {
            found = i;
            return found;
        }
    }
    return found;
}

int searchVector(vector<MovieData *> movieVector, int time)
{
    int first, last, middle;
    int size = movieVector.size();

    first = last = middle = 0;
    bool found = false;
    last = size - 1;
    while (first <= last && !found)
    {
        middle = (first + last) / 2;

        if (movieVector[middle]->getRunningTime() == time)
        {
            found = true;
            return middle;
        }
        else if (time < movieVector[middle]->getRunningTime())
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
        return -1;
    }
}
void bubbleSort(vector<MovieData *> &movieVector)
{
    bool swap = true;
    int size = movieVector.size();
    while (swap)
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
            if (movieVector[i]->getRunningTime() > movieVector[i + 1]->getRunningTime())
            {
                MovieData *temp = movieVector[i];
                movieVector[i] = movieVector[i + 1];
                movieVector[i + 1] = temp;
                swap = true;
            }
    }
    size--;
}
void displayVector(vector<MovieData *> movieVector)
{
    for (int i = 0; i < movieVector.size(); i++)
        movieVector[i]->printMovieDetails();
}

