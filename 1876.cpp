#include <iostream>
#include <unordered_set>
using namespace std;

int countGoodSubstrings(string s)
{
    int result = 0;
    unordered_set<char> window;
    for (int low = 0, high = 0; high < s.size(); high++)
    {
        window.insert(s[high]);
        if (high - low == 2)
        {
            if (window.size() == 3)
            {
                result++;
            }
            window.erase(s[low]);
            low++;
        }
    }

    return result;
}
int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;

    cout << countGoodSubstrings(str) << endl;
    return 0;
}