/*
BINARY CONVERTER

Write a program that takes in a positive integer as input, 
and outputs a string of 1's and 0's representing the integer in binary
*/

#include <iostream>
#include <string>
using namespace std;

string IntegerToReverseBinary(int integerValue);
string ReverseString(string userString);

int main()
{
   int integerValue;
   string userString;

   cin >> integerValue;

   userString = IntegerToReverseBinary(integerValue);

   cout << ReverseString(userString) << endl;

   return 0;
}

string IntegerToReverseBinary(int integerValue)
{
   string result;
   int buffer;
   int i = integerValue;

   while (i > 0)
   {
      buffer = i % 2;
      result.append(to_string(buffer));
      i /= 2;
   }

   return result;
}

string ReverseString(string userString)
{
   string result = "";

   for (int i = userString.length() - 1; i >= 0; i--)
   {
      string buffer;
      buffer = userString.at(i);
      result.append(buffer);
   }

   return result;
}