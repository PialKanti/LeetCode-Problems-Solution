#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string decodeMessage(string key, string message)
{
    unordered_map<char, int> table;

    int count = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] == ' ')
            continue;

        if (table.find(key[i]) == table.end())
        {
            table[key[i]] = count;
            count++;
        }
    }

    string decodedMsg = "";
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == ' ')
        {
            decodedMsg += ' ';
        }
        else
        {
            decodedMsg += ((char)(table[message[i]] + 'a'));
        }
    }

    return decodedMsg;
}

int main()
{
    freopen("input.txt", "r", stdin);

    return 0;
}