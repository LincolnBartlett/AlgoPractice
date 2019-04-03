//methods to read from datafile and print the vector of moviedata
void printMovie(vector<MovieData> movies, int i)
{
    cout << left << setw(18) << movies[i].title << left << setw(22) << left << movies[i].director << setw(20) << left << movies[i].yearReleased;
    cout << left << setw(15) << to_string(movies[i].runningTime) << endl;
}

bool readMovies(vector<MovieData> &movies)
{
    ifstream infile("MovieData.txt");
    string title, director, yearReleased, srunningTime, space;
    int runningTime;
    //int count=0;

    if (infile)
    {
        while (infile)
        {
            getline(infile, title, ',');
            getline(infile, director, ',');
            getline(infile, yearReleased, ',');
            getline(infile, srunningTime);
            runningTime = stoi(srunningTime);
            //infile>>runningTime;
            movies.push_back(MovieData(title, director, yearReleased, runningTime));
        }
        //size=count-1;
        //cout<<"SIZE OF VECTOR " <<movies.size()<<endl;
        // printMovies(movies, size);
        return true;
    }
    else
        return false;
}