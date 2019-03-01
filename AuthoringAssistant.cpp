#include <iostream>
using namespace std;

int GetNumOfNonWSCharacters(string input)
{
    int count = 0;
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input.at(i) != 32)
        {
            count++;
        }
    }
    return count;
}

int GetNumOfWords(string input)
{
    int count = 0;
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input.at(i) == 32 && input.at(i - 1) != 32)
        {
            count++;
        }

        if (input.at(i) == '.')
        {
            count++;
        }
    }

    return count;
}

int FindText(string searchString, string input)
{
    int count = 0;
    int length = input.length();
    int buffer = 0;

    for (int i = 0; i < length; i++)
    {
        if (buffer != input.find(searchString, i))
        {
            if (buffer != 0)
            {
                count++;
            }

            buffer = input.find(searchString, i);
        }
    }
    return count;
}

string ReplaceExclamation(string &input)
{
    string fixedString = "";
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input.at(i) == '!')
        {
            fixedString += ".";
        }
        else
        {
            fixedString += input.at(i);
        }
    }
    input = fixedString;
    return input;
}

string ShortenSpace(string input)
{
    string fixedString = "";
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input.at(i) == ' ' && input.at(i + 1) == ' ')
        {
        }
        else
        {
            fixedString += input.at(i);
        }
    }
    input = fixedString;
    return input;
}

void PrintMenu(string input)
{
    char choice;
    string searchString;

    cout << "\nMENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;

    cin >> choice;

    switch (choice)
    {
    case 'c':
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(input) << endl;
        PrintMenu(input);
        break;

    case 'w':
        cout << "Number of words: " << GetNumOfWords(input) << endl;
        PrintMenu(input);
        break;

    case 'f':

        cin.ignore();
        cout << "Enter a word or phrase to be found:\n";
        getline(cin, searchString);
        cout << "\"" << searchString << "\""
             << " instances: " << FindText(searchString, input) << endl;
        PrintMenu(input);
        break;

    case 'r':
        cout << "Edited Text: " << ReplaceExclamation(input) << endl;
        PrintMenu(input);
        break;

    case 's':
        cout << "Edited Text: " << ShortenSpace(input) << endl;
        PrintMenu(input);
        break;

    case 'q':
        break;

    default:
        break;
    }
}

int main()
{
    string input;

    //cout << "Enter a sample text:\n" << endl;

    getline(cin, input);

    //cout << "You entered: " << input << endl;

    PrintMenu(input);
    return 0;
}
