#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    string merged;

    for (int i = 0; i < word1.size(); i++)
    {
        merged += word1[i];
        if (i < word2.size())
        {
            merged += word2[i];
        }
    }

    for (int i = word1.size(); i < word2.size(); i++)
    {
        merged += word2[i];
    }

    return merged;
}