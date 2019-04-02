#include <iostream>
#include <vector>
using namespace std;

void PrintData(vector<int> &listInts)
{

    int size = listInts.size();
    for (int i = 0; i < size; i++)
    {
        cout << listInts[i] << " ";
    }
    cout << "\n";
}

void NormalizeData(vector<int> &listInts, int lownum)
{

    int size = listInts.size();
    for (int i = 0; i < size; i++)
    {
        listInts[i] -= lownum;
    }
}

int GetMinimumInt(vector<int> &listInts)
{

    int check = listInts[0];
    int size = listInts.size();

    for (int i = 0; i < size; i++)
    {
        if (check > listInts[i])
        {
            check = listInts[i];
        }
    }

    return check;
}

void GetInput(vector<int> &listInts)
{
    int size;
    cin >> size;
    listInts.resize(size);
    for (int i = 0; i < size; i++)
    {
        cin >> listInts[i];
    }
}

int main()
{
    vector<int> listInts;
    int lownum;
    GetInput(listInts);
    lownum = GetMinimumInt(listInts);
    NormalizeData(listInts, lownum);
    PrintData(listInts);
    return 0;
}
