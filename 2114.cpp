#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getWordCount(string sentence)
{
    int count = 0;
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
    }
    return ++count;
}

int mostWordsFound(vector<string> &sentences)
{
    int result = 0;
    for (int i = 0; i < sentences.size(); i++)
    {
        result = max(result, getWordCount(sentences[i]));
    }
    return result;
}