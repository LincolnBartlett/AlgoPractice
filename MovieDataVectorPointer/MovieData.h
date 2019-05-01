#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
const int SIZE = 5;

class MovieData
{
private:
  string title, director, yearReleased;
  int runningTime;

public:
  MovieData()
  {
    title = "";
    director = "";
    yearReleased = "";
    runningTime = 0;
  }
  MovieData(string title, string director, string yearReleased, int runningTime)
  {
    this->title = title;
    this->director = director;
    this->yearReleased = yearReleased;
    this->runningTime = runningTime;
  }

  string getTitle()
  {
    return title;
  }
  string getDirector()
  {
    return director;
  }
  string getYearReleased()
  {
    return yearReleased;
  }
  int getRunningTime()
  {
    return runningTime;
  }
  void printMovieDetails()
  {
    cout << "Title         : " << title << endl;
    cout << "Director      : " << director << endl;
    cout << "Year Released : " << yearReleased << endl;
    cout << "Running Time  : " << runningTime << endl;
  }
};
