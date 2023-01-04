#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> cellsInRange(string s)
{
    string cell = "";
    vector<string> result;
    for (char i = s[0]; i <= s[3]; i++)
    {
        for (char j = s[1]; j <= s[4]; j++)
        {
            cell = i;
            cell += j;
            result.push_back(cell);
        }
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    vector<string> result = cellsInRange(str);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}