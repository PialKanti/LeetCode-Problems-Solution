#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countGoodSubstrings(string s)
{
    int result = 0;
    for (int low = 0, high = 0; high < s.size(); high++)
    {
        if (high - low == 2)
        {
            if (s[low] != s[low + 1] && s[low + 1] != s[high] && s[high] != s[low])
            {
                result++;
            }
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