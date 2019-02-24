/*
COUNT CHARACTERS
Lincoln Bartlett

Write a program whose input is a character and a string,
and whose output indicates the number of times the character 
appears in the string.
*/
#include <iostream>
#include <string>
using namespace std;


int CountCharacters(char userChar, string userString);

int main() {
   char userChar;
   string userString;

   cin >> userChar >> userString;

   cout << CountCharacters(userChar, userString)<< endl;
   return 0;
}

int CountCharacters(char userChar, string userString){
   int length = userString.length();
   int count;

   for (int i = 0; i < length; i++){
      if (userString.at(i) == userChar){
         count++;
      }
   }
   return count;
}
