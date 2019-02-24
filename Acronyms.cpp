/*
AUTO ACRONYM
Lincoln Bartlett

An acronym is a word formed from the initial letters of words in a set phrase. 
Write a program whose input is a phrase and whose output is an acronym of the input. 
If a word begins with a lower case letter, don't include that letter in the acronym. 
Assume there will be at least one upper case letter in the input. 
*/

#include <iostream>
#include <string>

using namespace std;

string CreateAcronym(string userPhrase);

int main() 
{
  string userPhrase;
  getline(cin, userPhrase);

  cout << CreateAcronym(userPhrase) <<endl;

   return 0;
}

string CreateAcronym(string userPhrase)
{
   string result;

   for(int i = 0; i < userPhrase.length(); i++)
   {
     
      if(userPhrase[i] == toupper(userPhrase[i]) && userPhrase[i] != ' ')
      {
         string buffer;
         buffer = userPhrase.at(i);
         result.append(buffer);

      }

   } 
   return result;
}