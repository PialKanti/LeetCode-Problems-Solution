#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int magazineLetter[26];
    memset(magazineLetter, 0, sizeof(magazineLetter));

    for (int i = 0; i < magazine.size(); i++)
    {
        int index = magazine[i] - 'a';
        magazineLetter[index]++;
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
        int index = ransomNote[i] - 'a';
        if (magazineLetter[index] > 0)
        {
            magazineLetter[index]--;
        }
        else
        {
            return false;
        }
    }

    return true;
}