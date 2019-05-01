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
    //your code goes here
}

int searchVector(vector<MovieData *> movieVector, string title)
{

    //your code goes here
}

int searchVector(vector<MovieData *> movieVector, int time)
{
    // your code goes here
}

void bubbleSort(vector<MovieData *> &movieVector)
{

    //your code goes here
}
void displayVector(vector<MovieData *> movieVector)
{
    // your code goes here
}
